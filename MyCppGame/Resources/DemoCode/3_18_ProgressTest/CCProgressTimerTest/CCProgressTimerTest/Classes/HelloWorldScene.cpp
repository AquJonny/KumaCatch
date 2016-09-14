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
    
    CCProgressTimer * pross = CCProgressTimer::create(CCSprite::create("Icon.png"));
    pross->setPosition(ccp(100,180));
    //设置进度条的样式
    pross->setType( kCCProgressTimerTypeRadial);
    //设置进度值范围[0,100]
    pross->setPercentage(100);
    //反进度计时
    pross->setReverseProgress(true);
    addChild(pross);
    CCProgressTo *to1 = CCProgressTo::create(2, 100);
    pross->runAction( CCRepeatForever::create(to1));
    
    
    CCProgressTimer * prossR = CCProgressTimer::create(CCSprite::create("Icon.png"));
    prossR->setPosition(ccp(210,180));
    prossR->setType( kCCProgressTimerTypeBar );
    //设置计时器运动方向
    prossR->setMidpoint(ccp(0,1));
    //设置计时器的宽高起始比例
    prossR->setBarChangeRate(ccp(0, 1));
    
    
    addChild(prossR);
    CCProgressTo *to2 = CCProgressTo::create(2, 100);
    prossR->runAction( CCRepeatForever::create(to2));
    
    
    return true;
}