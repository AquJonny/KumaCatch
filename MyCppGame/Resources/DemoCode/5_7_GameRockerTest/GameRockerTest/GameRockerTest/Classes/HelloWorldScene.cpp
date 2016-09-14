#include "HelloWorldScene.h"
#include "SimpleAudioEngine.h"
#include "HRocker.h"

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
    CCSize size = CCDirector::sharedDirector()->getWinSize();
    CCLayerColor * colorLayer = CCLayerColor::create(ccc4(200,200,200,200), size.width, size.height);
    addChild(colorLayer);
    
    
    HRocker* rocker = HRocker::createHRocker("rocker.png", "rockerBG.png", ccp(240,160));
    addChild(rocker);
    rocker->startRocker(true);
    
    return true;
}

