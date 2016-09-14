#include "HelloWorldScene.h"
#include "SimpleAudioEngine.h"

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
    
    CCSprite * spr = CCSprite::create("Icon.png");
    spr->setPosition(ccp(150,150));
    addChild(spr,0,922);
    
    //back&menu
    setKeypadEnabled(true);
    
    return true;
}

void HelloWorld::onEnter(){
    
    CCDirector::sharedDirector()->getTouchDispatcher()->addTargetedDelegate(this,0,false);
    CCLayer::onEnter();
}

void HelloWorld::onExit(){
    
    CCDirector::sharedDirector()->getTouchDispatcher()->removeDelegate(this);
    CCLayer::onExit();
}

bool HelloWorld::ccTouchBegan(CCTouch* touch, CCEvent* event){
    CCLOG("ccTouchBegan");
    return true;
}

void HelloWorld::ccTouchMoved(CCTouch* touch, CCEvent* event){
    CCLOG("ccTouchMoved");
}

void HelloWorld::ccTouchEnded(CCTouch* touch, CCEvent* event){
    CCLOG("ccTouchEnded");
    //获取离开屏幕时对应的坐标
    CCPoint point = touch->getLocation();
    
    //获取到精tag=922的精灵
    CCSprite* sp = (CCSprite*)this->getChildByTag(922);
    //暂停所有动作
    sp->stopAllActions();
    //执行move动作到用户离开时的位置
    sp->runAction(CCMoveTo::create(1, point));
    
}

//back&menu
void HelloWorld::keyBackClicked()
{
    CCLog("Back clicked!");
}

void HelloWorld::keyMenuClicked()
{
    CCLog("Menu clicked!");
}




