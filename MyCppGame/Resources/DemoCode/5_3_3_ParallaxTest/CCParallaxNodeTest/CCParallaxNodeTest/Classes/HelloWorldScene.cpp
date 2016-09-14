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
    
    CCSprite* spFont = CCSprite::create("front.png");
    CCSprite* spMiddle = CCSprite::create("middle.png");
    CCSprite* spFar = CCSprite::create("far.png");
    
    CCParallaxNode * parallaxNode = CCParallaxNode::create();
    addChild(parallaxNode);
    
    //近景
    parallaxNode->addChild(spFont,3, ccp(4.8f,0), ccp(spFont->getContentSize().width*0.5,spFont->getContentSize().height*0.5) );
    //中景
    parallaxNode->addChild(spMiddle, 2, ccp(1.6f,0), ccp(spMiddle->getContentSize().width*0.5,spMiddle->getContentSize().height*0.5+spFont->getContentSize().height*0.5) );
    //远景
    parallaxNode->addChild(spFar, 1, ccp(0.5f,0), ccp(spFar->getContentSize().width*0.5,spFar->getContentSize().height*0.5+spFont->getContentSize().height*0.5+spMiddle->getContentSize().height*0.5) );
    
    
    CCActionInterval* go = CCMoveBy::create(8, ccp(-200,0) );
    CCActionInterval* goBack = go->reverse();
    CCFiniteTimeAction* seq = CCSequence::create(go,goBack, NULL);
    parallaxNode->runAction( (CCRepeatForever::create((CCActionInterval*) seq) ));

    return true;
}

