#include "HelloWorldScene.h"
#include "SimpleAudioEngine.h"
#include "ClipLayer.h"

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
    //------精灵的裁切区域
//    CCLabelTTF * label=CCLabelTTF::create("正常精灵", "Helvetica", 24);
//    label->setPosition(ccp(100,260));
//    addChild(label);
//    
//    CCLabelTTF* clipLabel= CCLabelTTF::create("裁切后的精灵", "Helvetica", 24);
//    clipLabel->setPosition(ccp(300,260));
//    addChild(clipLabel);
//    
//    CCSprite* sprite= CCSprite::create("Icon.png");
//    sprite->setPosition(ccpAdd(label->getPosition(), ccp(0,-100)));
//    addChild(sprite);
//    
//    CCSprite* clipSprite= CCSprite::create("Icon.png");
//    clipSprite->setPosition(ccpAdd(clipLabel->getPosition(), ccp(0,-100)));
//    clipSprite->setTextureRect(CCRectMake(0, 0, 30, 30));
//    addChild(clipSprite);
    
    
    
    //------CCLayer的裁切区域
    CCSize size = CCDirector::sharedDirector()->getWinSize();
    CCLayerColor* colorBg = CCLayerColor::create(ccc4(255, 127, 0, 255), size.width,size.height);
    addChild(colorBg);
    
//    //默认layer,没有设置其裁切区域
//    CCLayer* Layer = CCLayer::create();
//    Layer->setPosition(ccp(190,110));
//    Layer->addChild(CCSprite::create("Icon.png"));
//    addChild(Layer);
    
    //自定义的带裁切的Layer
    ClipLayer* clipLayer = ClipLayer::create(CCSizeMake(100, 100));
    clipLayer->setPosition(ccp(190,110));
    clipLayer->addChild(CCSprite::create("Icon.png"));
    addChild(clipLayer);
    

    return true;
}
