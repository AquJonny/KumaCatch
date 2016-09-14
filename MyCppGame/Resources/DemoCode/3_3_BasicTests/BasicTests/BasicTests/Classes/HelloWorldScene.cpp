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
    //////////////////////////////
    // 1. super init first
    if ( !CCLayer::init() )
    {
        return false;
    }
    //－－－－－－－精灵的创建的四种方式
//    //图片生成
//    CCSprite* spr1 = CCSprite::create("Icon.png");
//    spr1->setPosition(ccp(70,150));
//    addChild(spr1);
//    
//    //图片＋区域生成
//    CCSprite* spr2 = CCSprite::create("Icon.png", CCRectMake(0, 0, 30, 30));
//    spr2->setPosition(ccp(150,150));
//    addChild(spr2);
//    
//    //通过祯缓存中的一祯名字生成
//    CCSpriteFrameCache::sharedSpriteFrameCache()->addSpriteFramesWithFile("test_icon.plist");
//    CCSprite* spr3 =CCSprite::createWithSpriteFrameName("Icon.png");
//    spr3->setPosition(ccp(230,150));
//    addChild(spr3);
//    
//    
//    //通过另外一祯生成一个生成
//    CCSpriteFrame* frame= CCSpriteFrame::create("Icon.png", CCRectMake(0, 0, 40, 30));
//    CCSprite* spr4 = CCSprite::createWithSpriteFrame(frame);
//    spr4->setPosition(ccp(310,150));
//    addChild(spr4);
    
//－－－－－－－－－精灵的基本操作
//    //创建
//    CCSprite* sp = CCSprite::create("Icon.png");
//    //设置坐标
//    sp->setPosition(ccp(80,100));
//    //设置旋转
//    sp->setRotation(100);
//    //设置缩放
//    sp->setScale(1.5);
//    addChild(sp);
//    
//    
//    CCSprite*sp2=CCSprite::create("Icon.png");
//    sp2->setPosition(ccp(200,230));
//    //设置x轴镜像反转
//    sp2->setFlipX(true);
//    //设置y轴镜像反转
//    sp2->setFlipY(true); 
//    //仅设置缩放X轴
//    sp2->setScaleX(2);
//    addChild(sp2);
//    
//    
//    CCSprite*sp3=CCSprite::create("Icon.png");
//    sp3->setPosition(ccp(310,160));
//    //设置半透明
//    sp3->setOpacity(127);
//    //设置混合色
//    sp3->setColor(ccc3(255, 255, 0));
//    //设置贴图尺寸大小
//    sp3->setTextureRect(CCRectMake(0, 0, 35, 35));
//    addChild(sp3);
//
//    
//    CCSprite*sp4=CCSprite::create("Icon.png");
//    sp4->setPosition(ccp(300,70));
//    //设置不可见
//    sp4->setVisible(false);
//    addChild(sp4);
    
//－－－－－－－两种常用层Layer
//    //默认黑色
//    CCLayer * layer= CCLayer::create();
//    addChild(layer);
//    //红色
//    CCLayerColor * layerColor = CCLayerColor::create(ccc4(255, 0, 0, 255));
//    addChild(layerColor);
//    layerColor->setContentSize(CCSizeMake(250, 250));
//    //蓝色
//    CCLayerColor * layerColor2 = CCLayerColor::create(ccc4(0, 0, 255, 255),150,150);
//    addChild(layerColor2);
    
//－－－－－－CCNode的添加
    
//    CCLayer*layer =CCLayer::create();
//    layer->setPosition(ccp(240,200));
//    CCSprite*sprChild = CCSprite::create("Icon.png");
//    layer->addChild(sprChild);
//    addChild(layer);
//    
//    CCSprite* spr = CCSprite::create("Icon.png");
//    spr->setPosition(ccp(100,100));
//    CCLayerColor* layerChild = CCLayerColor::create(ccc4(255, 0, 0, 255),50,50);
//    spr->addChild(layerChild);
//    addChild(spr);
    
//－－－－－－Tag的作用与使用
//    CCSprite* spY = CCSprite::create("Icon.png");
//    spY->setPosition(ccp(100,200));
//    addChild(spY);
//    
//    
//    CCSprite * spr = CCSprite::create("Icon.png");
//    spr->setPosition(ccp(200,200));
//    addChild(spr,0,823);
//    this->testSprite();
    
//－－－－－－－坐标系
//    CCSprite * spr =CCSprite::create("Icon.png");
//    spr->setPosition(ccp(100,100));
//    addChild(spr);
//    
//    CCSprite*spr2 = CCSprite::create("Icon.png");
//    spr2->setPosition(ccp(200,200));
//    addChild(spr2);
    
//－－－－－－－锚点
//    CCSprite* sp1 = CCSprite::create("Icon.png");
//    addChild(sp1);
////    sp1->setAnchorPoint(ccp(0,0));
//    sp1->setPosition(ccp(sp1->getContentSize().width*0.5,sp1->getContentSize().height*0.5));
    
//    //layer 默认充满屏幕
//    CCLayerColor* layer = CCLayerColor::create(ccc4(255, 0, 0, 255));
//    addChild(layer);
//    CCLOG("%f,%f",layer->getAnchorPoint().x,layer->getAnchorPoint().y);
//    CCLOG("%f,%f",layer->getPositionX(),layer->getPositionY());
//    CCLOG("%f,%f",layer->getContentSize().width,layer->getContentSize().height);
    
//－－－－－－－Z轴与遮盖关系
      
    CCSprite* spA1 =CCSprite::create("Icon.png");
    spA1->setPosition(ccp(150,200));
    addChild(spA1);
    
    CCSprite* spA2 =CCSprite::create("Icon.png");
    spA2->setPosition(ccp(100,200));
    spA2->setScale(2);
    addChild(spA2);
    
    
    
    CCSprite* spB1 =CCSprite::create("Icon.png");
    spB1->setPosition(ccp(380,140));
    addChild(spB1,1);
    
    CCSprite* spB2 =CCSprite::create("Icon.png");
    spB2->setPosition(ccp(330,140));
    spB2->setScale(2);
    addChild(spB2);
    
    
    
    return true;
}
//－－－－－Tag的作用与使用
void HelloWorld::testSprite(){
    CCSprite* sp=(CCSprite*)this->getChildByTag(823);
    sp->setScale(2);
}


























































