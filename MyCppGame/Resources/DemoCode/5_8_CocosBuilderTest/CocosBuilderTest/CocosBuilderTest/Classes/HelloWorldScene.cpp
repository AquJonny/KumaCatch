#include "HelloWorldScene.h"
#include "SimpleAudioEngine.h"
#include "TestCocosBuilderLoader.h"

using namespace cocos2d;
using namespace CocosDenshion;

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
    CCLabelTTF* ttf = CCLabelTTF::create("2秒后自动读取cbbi文件", "Helvetica", 24);
    ttf->setPosition(ccp(240,160));
    addChild(ttf);
    schedule(schedule_selector(HelloWorld::autoOpen),2);
    return true;
}

void HelloWorld::autoOpen(){
    this->openCBBI("helloworldlayer.ccbi", "TestCocosBuilder", TestCocosBuilderLoader::loader());
}

void HelloWorld::openCBBI(const char * pCCBFileName, const char * pCCNodeName, CCNodeLoader * pCCNodeLoader) {
    //创建一个自动释放的CCNode加载库
    CCNodeLoaderLibrary * ccNodeLoaderLibrary = CCNodeLoaderLibrary::newDefaultCCNodeLoaderLibrary();
    ccNodeLoaderLibrary->registerCCNodeLoader(pCCNodeName, pCCNodeLoader);
    
    //创建一个自动释放的CCB读取类（CCBReader）
    cocos2d::extension::CCBReader * ccbReader = new cocos2d::extension::CCBReader(ccNodeLoaderLibrary);
    ccbReader->autorelease();
    
    //读取ccbi文件获取根节点
    CCNode * node = ccbReader->readNodeGraphFromFile("", pCCBFileName, this);
    
    //将根节点CCLayer加入到场景中
    CCScene * scene = CCScene::create();
    if(node != NULL) {
        scene->addChild(node);
    }
    //切换到cbbi生成的场景
    CCDirector::sharedDirector()->replaceScene(CCTransitionFade::create(0.5f, scene, ccc3(0, 0, 0)));
}

