//
//  TestLayer.cpp
//  ReplaceSceneTest
//
//  Created by Himi on 12-9-12.
//
//

#include "TestLayer.h"
using namespace cocos2d;


CCScene* TestLayer::scene()
{
    CCScene *scene = CCScene::create();
    TestLayer *layer = TestLayer::create();
    scene->addChild(layer);
    return scene;
}

bool TestLayer::init()
{
    if ( !CCLayer::init() )
    {
        return false;
    }
    CCLOG("TestLayer init");
    
    CCSprite * sp = CCSprite::create("background2.png");
    sp->setPosition(ccp(240,160));
    addChild(sp);
    
    return true;
}

//进入此类中的调用函数
void TestLayer::onEnter(){
    CCLOG("TestLayer onEnter");
    CCLayer::onEnter();
}

//切换动画完成后调用的函数
void TestLayer::onEnterTransitionDidFinish(){
    CCLOG("TestLayer onEnterTransitionDidFinish");
    CCLayer::onEnterTransitionDidFinish();
}

//退出时候调用的函数
void TestLayer::onExit(){
    CCLOG("TestLayer onExit");
    CCLayer::onExit();
}
