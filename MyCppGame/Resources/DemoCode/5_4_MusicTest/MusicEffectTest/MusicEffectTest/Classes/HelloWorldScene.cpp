#include "HelloWorldScene.h"
#include "SimpleAudioEngine.h"

using namespace cocos2d;
using namespace CocosDenshion;

//根据不同平台使用预编译索引不同音频文件
#if (CC_TARGET_PLATFORM == CC_PLATFORM_ANDROID)
#define EFFECT_FILE        "effect2.ogg"
#elif( CC_TARGET_PLATFORM == CC_PLATFORM_MARMALADE)
#define EFFECT_FILE        "effect1.raw"
#else
#define EFFECT_FILE        "effect1.wav"
#endif

#if (CC_TARGET_PLATFORM == CC_PLATFORM_WIN32)
#define MUSIC_FILE        "music.mid"
#elif (CC_TARGET_PLATFORM == CC_PLATFORM_BLACKBERRY)
#define MUSIC_FILE        "background.ogg"
#else
#define MUSIC_FILE        "background.mp3"
#endif

std::string items[] = {
    "播放背景音乐","停止背景音乐","暂停背景音乐",
    "继续背景音乐","后退背景音乐","背景音乐是否正在播放",
    "播放音效","重复播放音效","停止音效","释放音效",
    "增加背景音乐音量","减少背景音乐音量",
    "增加音效音量","减少音效音量","暂停音效",
    "继续播放音效","暂停所有音效","继续所有音效",
    "停止所有音效"
};

CCScene* HelloWorld::scene()
{
    CCScene *scene = CCScene::create();
    
    HelloWorld *layer = HelloWorld::create();

    scene->addChild(layer);

    return scene;
}

bool HelloWorld::init()
{
    if ( !CCLayer::init() )
    {
        return false;
    }

    CCMenu* m_pItmeMenu = CCMenu::create();
    CCSize s = CCDirector::sharedDirector()->getWinSize();
    int m_nTestCount = sizeof(items) / sizeof(items[0]);
    
    for (int i = 0; i < m_nTestCount; i++){
        CCLabelTTF* label = CCLabelTTF::create(items[i].c_str(), "Arial", 15);
        
        CCMenuItemLabel* pMenuItem = CCMenuItemLabel::create(label, this, menu_selector(HelloWorld::menuBack));
        
        m_pItmeMenu->addChild(pMenuItem, i);
        pMenuItem->setPosition( CCPointMake(0, (s.height*0.5-20- (i + 1) * 15) ));
    }
    addChild(m_pItmeMenu,0,100);
    //预加载音乐和音效
    SimpleAudioEngine::sharedEngine()->preloadBackgroundMusic( CCFileUtils::sharedFileUtils()->fullPathFromRelativePath(MUSIC_FILE) );
    SimpleAudioEngine::sharedEngine()->preloadEffect( CCFileUtils::sharedFileUtils()->fullPathFromRelativePath(EFFECT_FILE) );
    //设置默认音量
    SimpleAudioEngine::sharedEngine()->setEffectsVolume(0.5);
    SimpleAudioEngine::sharedEngine()->setBackgroundMusicVolume(0.5);
    
    return true;
}

void HelloWorld::menuBack(CCObject * pSender){
    CCMenuItem* pMenuItem = (CCMenuItem *)(pSender);
    int nIdx = pMenuItem->getZOrder() ;
    switch(nIdx)
    {
        case 0:
            //播放背景音乐
            SimpleAudioEngine::sharedEngine()->playBackgroundMusic(std::string(CCFileUtils::sharedFileUtils()->fullPathFromRelativePath(MUSIC_FILE)).c_str(), true);
            break;
        case 1:
            //停止背景音乐
            SimpleAudioEngine::sharedEngine()->stopBackgroundMusic();
            break;
        case 2:
            //暂停背景音乐
            SimpleAudioEngine::sharedEngine()->pauseBackgroundMusic();
            break;
        case 3:
            //继续播放背景音乐
            SimpleAudioEngine::sharedEngine()->resumeBackgroundMusic();
            break;
        case 4:
            //后退背景音乐
            SimpleAudioEngine::sharedEngine()->rewindBackgroundMusic();
            break;
        case 5:
            //背景音乐是否正在播放
            if (SimpleAudioEngine::sharedEngine()->isBackgroundMusicPlaying()){
                CCLOG("背景音乐正在播放");
            }else{
                CCLOG("背景音乐没在播放");
            }
            break;
        case 6:
            //播放音效，并且得到此音效的ID
            effectId = SimpleAudioEngine::sharedEngine()->playEffect(std::string(CCFileUtils::sharedFileUtils()->fullPathFromRelativePath(EFFECT_FILE)).c_str());
            break;
        case 7:
            //重复播放音效
            effectId = SimpleAudioEngine::sharedEngine()->playEffect(std::string(CCFileUtils::sharedFileUtils()->fullPathFromRelativePath(EFFECT_FILE)).c_str(), true);
            break;
        case 8:
            //停止音效播放
            SimpleAudioEngine::sharedEngine()->stopEffect(effectId);
            break;
        case 9:
            //释放音效
            SimpleAudioEngine::sharedEngine()->unloadEffect(std::string(CCFileUtils::sharedFileUtils()->fullPathFromRelativePath(EFFECT_FILE)).c_str());
            break;
        case 10:
            //增加背景音乐的音量
            SimpleAudioEngine::sharedEngine()->setBackgroundMusicVolume(SimpleAudioEngine::sharedEngine()->getBackgroundMusicVolume() + 0.1f);
            break;
        case 11:
            //减少背景音乐的音量
            SimpleAudioEngine::sharedEngine()->setBackgroundMusicVolume(SimpleAudioEngine::sharedEngine()->getBackgroundMusicVolume() - 0.1f);
            break;
        case 12:
            //增加音效的音量
            SimpleAudioEngine::sharedEngine()->setEffectsVolume(SimpleAudioEngine::sharedEngine()->getEffectsVolume() + 0.1f);
            break;
        case 13:
            //减少音效的音量
            SimpleAudioEngine::sharedEngine()->setEffectsVolume(SimpleAudioEngine::sharedEngine()->getEffectsVolume() - 0.1f);
            break;
        case 14:
            //暂停音效
            SimpleAudioEngine::sharedEngine()->pauseEffect(effectId);
            break;
        case 15:
            //继续播放音效
            SimpleAudioEngine::sharedEngine()->resumeEffect(effectId);
            break;
        case 16:
            //暂停所有音效
            SimpleAudioEngine::sharedEngine()->pauseAllEffects();
            break;
        case 17:
            //继续所有音效
            SimpleAudioEngine::sharedEngine()->resumeAllEffects();
            break;
        case 18:
            //停止所有音效
            SimpleAudioEngine::sharedEngine()->stopAllEffects();
            break;
    }
}
