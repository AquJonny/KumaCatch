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
    CCLayerColor * color = CCLayerColor::create(ccc4(255, 255, 255, 255), 480, 320);
    addChild(color);
    
    CCSize size = CCDirector::sharedDirector()->getWinSize();
    CCLabelTTF* pLabel = CCLabelTTF::create("没相撞 ^. ^", "Helvetica", 24);
    pLabel->setColor(ccRED);
    pLabel->setPosition( ccp(size.width*0.5, size.height-50) );
    this->addChild(pLabel, 0, 920);

    CCSprite* sp1 = CCSprite::create("circle1.png");
    sp1->setPosition(ccp(100,170));
    addChild(sp1,0,921);
    
    CCSprite* sp2 = CCSprite::create("circle2.png");
    sp2->setPosition(ccp(350,170));
    addChild(sp2,0,922);
    
    return true;
}

bool HelloWorld::isCircleCollision(CCPoint pos1,float radius1,CCPoint pos2,float radius2){
    
    if(sqrt(pow(pos1.x-pos2.x, 2)+pow(pos1.y-pos2.y, 2))>radius1+radius2){
        return false;
    }
    return true;
}

bool HelloWorld::ccTouchBegan(CCTouch *pTouch, CCEvent *pEvent){
    CCPoint touchPoint = pTouch->getLocation();
    CCSprite* sp1 = (CCSprite*)this->getChildByTag(921);
    sp1->setPosition(touchPoint);
    return true;
}

void HelloWorld::ccTouchMoved(CCTouch *pTouch, CCEvent *pEvent){
    CCPoint touchPoint = pTouch->getLocation();
    CCSprite* sp1 = (CCSprite*)this->getChildByTag(921);
    CCSprite* sp2 = (CCSprite*)this->getChildByTag(922);
    CCLabelTTF* ttf = (CCLabelTTF*)this->getChildByTag(920);
    if(this->isCircleCollision(sp1->getPosition(), sp1->getContentSize().width*0.5, sp2->getPosition(), sp2->getContentSize().width*0.5)){
        ttf->setString("相撞啦 =w=||");
    }else{
        ttf->setString("没相撞 ^. ^");
    }
    //
    sp1->setPosition(touchPoint);
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