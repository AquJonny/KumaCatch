#include "HelloWorldScene.h"
#include "SimpleAudioEngine.h"

using namespace cocos2d;
using namespace CocosDenshion;

CCScene* HelloWorld::scene()
{
    // 'scene' is an autorelease object
    CCScene *scene = CCScene::create();
    
    // 'layer' is an autorelease object
    HelloWorld *layer = HelloWorld::create();

    // add layer as a child to scene
    scene->addChild(layer);

    // return the scene
    return scene;
}

// on "init" you need to initialize your instance
bool HelloWorld::init()
{
    //////////////////////////////
    // 1. super init first
    if ( !CCLayer::init() )
    {
        return false;
    }

    CCSize s = CCDirector::sharedDirector()->getWinSize();
    //用于显示当前设备语言
    CCLabelTTF *labelLanguage = CCLabelTTF::create("", "Arial", 20);
    labelLanguage->setPosition(ccp(s.width/2, s.height/2));
    //获取当前语言种类
    ccLanguageType currentLanguageType = CCApplication::sharedApplication()->getCurrentLanguage();
    switch (currentLanguageType)
    {
        case kLanguageEnglish:
            labelLanguage->setString("当前设备语言是： English");
            break;
        case kLanguageChinese:
            labelLanguage->setString("当前设备语言是： Chinese");
            break;
        case kLanguageFrench:
            labelLanguage->setString("当前设备语言是： French");
            break;
        case kLanguageGerman:
            labelLanguage->setString("当前设备语言是： German");
            break;
        case kLanguageItalian:
            labelLanguage->setString("当前设备语言是： Italian");
            break;
        case kLanguageRussian:
            labelLanguage->setString("当前设备语言是： Russian");
            break;
        case kLanguageSpanish:
            labelLanguage->setString("当前设备语言是： Spanish");
            break;
    }
    addChild(labelLanguage);
    
    return true;
}

void HelloWorld::menuCloseCallback(CCObject* pSender)
{
    CCDirector::sharedDirector()->end();

#if (CC_TARGET_PLATFORM == CC_PLATFORM_IOS)
    exit(0);
#endif
}


