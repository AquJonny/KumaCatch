#include "HelloWorldScene.h"
#include "SimpleAudioEngine.h"

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
    //高清资源
//    CCSprite * spr = CCSprite::create("himi.png");
//    spr->setPosition(ccp(200,170));
//    addChild(spr);
    
//    高清与给高清坐标
    CCSize size= CCDirector::sharedDirector()->getWinSize();
    CCSprite* sp = CCSprite::create("Icon.png");
    //屏幕最右上角
    sp->setPosition(ccp(480,320));
    addChild(sp);
    //打印屏幕大小
    CCLOG("ScreenSize--Width:%f,height:%f",size.width,size.height);
    
    return true;
}






































