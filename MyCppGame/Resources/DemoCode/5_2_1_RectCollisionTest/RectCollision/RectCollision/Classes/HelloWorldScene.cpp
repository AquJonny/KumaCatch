#include "HelloWorldScene.h"
#include "SimpleAudioEngine.h"
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
    CCLayerColor*colorLayer = CCLayerColor::create(ccc4(255, 255, 255, 255), 480, 320);
    addChild(colorLayer);
    
    CCLabelTTF* pLabel = CCLabelTTF::create("～还米有碰撞～", "Thonburi", 24);
    pLabel->setColor(ccc3(255, 0, 0));
    CCSize size = CCDirector::sharedDirector()->getWinSize();
    pLabel->setPosition( ccp(size.width*0.5, size.height - 50) );
    this->addChild(pLabel, 1,900);
    
    CCSprite*sp1 =CCSprite::create("rect1.png");
    sp1->setPosition(ccp(100,230));
    addChild(sp1,0,921);
    
    CCSprite*sp2 =CCSprite::create("rect2.png");
    sp2->setPosition(ccp(240,140));
    addChild(sp2,0,922);
    return true;
}

bool HelloWorld::isRectCollision(CCRect rect1,CCRect rect2){
    float x1 = rect1.origin.x;
    float y1 = rect1.origin.y;
    float w1 = rect1.size.width;
    float h1 = rect1.size.height;
    float x2 = rect2.origin.x;
    float y2 = rect2.origin.y;
    float w2 = rect2.size.width;
    float h2 = rect2.size.height;
    if(x1+w1*0.5<x2-w2*0.5){
        return false;
        
    }else if(x1-w1*0.5>x2+w2*0.5){
        return false;
        
    }else if(y1+h1*0.5<y2-h2*0.5){
        return false;
        
    }else if(y1-h1*0.5>y2+h2*0.5){
        return false;
        
    }
    return true;
}


bool HelloWorld::ccTouchBegan(CCTouch *pTouch, CCEvent *pEvent){
    CCSprite* sp1 =(CCSprite*)this->getChildByTag(921);
    sp1->setPosition(pTouch->getLocation());
    
    return true;
}

void HelloWorld::ccTouchMoved(CCTouch *pTouch, CCEvent *pEvent){
    
    CCSprite* sp1 =(CCSprite*)this->getChildByTag(921);
    sp1->setPosition(pTouch->getLocation());
    
    CCSprite*sp2 =(CCSprite*)this->getChildByTag(922);
    
    CCLabelTTF* pLabel = (CCLabelTTF*)this->getChildByTag(900);
    
//    //利用自定义判断矩形碰撞函数
//    if(this->isRectCollision(
//                             CCRectMake(sp1->getPositionX(), sp1->getPositionY(), sp1->getContentSize().width, sp1->getContentSize().height),
//                             CCRectMake(sp2->getPositionX(), sp2->getPositionY(), sp2->getContentSize().width, sp2->getContentSize().height))){
//        pLabel->setString("碰撞拉！");
//    }else{
//        pLabel->setString("～还米有碰撞～");
//    }
    
    //利用intersectsRect函数检测碰撞
    if(sp1->boundingBox().intersectsRect(sp2->boundingBox())){
        pLabel->setString("碰撞拉！");
    }else{
        pLabel->setString("～还米有碰撞～");
    }
}

void HelloWorld::ccTouchEnded(CCTouch *pTouch, CCEvent *pEvent){
    
    
}

void HelloWorld::onEnter(){
    CCDirector::sharedDirector()->getTouchDispatcher()->addTargetedDelegate(this, 0, false);
    CCLayer::onEnter();
}

void HelloWorld::onExit(){
    CCDirector::sharedDirector()->getTouchDispatcher()->removeDelegate(this);
    CCLayer::onExit();
}
