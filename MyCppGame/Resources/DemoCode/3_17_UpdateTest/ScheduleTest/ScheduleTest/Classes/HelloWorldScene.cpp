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

bool HelloWorld::init()
{ 
    // 1. super init first
    if ( !CCLayer::init() )
    {
        return false;
    }
//----------scheduleUpdate
//    CCSprite* sp = CCSprite::create("Icon.png");
//    sp->setPosition(ccp(80,100));
//    addChild(sp,0,922);
//    //更新函数
//    scheduleUpdate();
    
    
//----------schedule
    CCSprite* sp = CCSprite::create("Icon.png");
    sp->setPosition(ccp(80,100));
    addChild(sp,0,922);
    //自定义更新函数 每一帧都调用
    //schedule(schedule_selector(HelloWorld::myUpdate));
    //自定义更新函数 每秒执行一次
    schedule(schedule_selector(HelloWorld::myUpdate),1.f);
    
    return true;
}

void HelloWorld::update(float dt){
    //停止更新
//    unscheduleUpdate();
    
    CCSprite*sp =(CCSprite*)this->getChildByTag(922);
    if(sp->getPositionX()<260){
        sp->setPosition(ccpAdd(sp->getPosition(), ccp(1,1)));
    }else{
        sp->setPosition(ccpAdd(sp->getPosition(), ccp(1,-1)));
    }
}


void HelloWorld::myUpdate(float dt){
    //停止更新
//    unschedule(schedule_selector(HelloWorld::myUpdate));
    
    CCSprite*sp =(CCSprite*)this->getChildByTag(922);
    if(sp->getPositionX()<260){
        sp->setPosition(ccpAdd(sp->getPosition(), ccp(1,1)));
    }else{
        sp->setPosition(ccpAdd(sp->getPosition(), ccp(1,-1)));
    }
}
//unscheduleAllSelectors()停止所有更新函数
