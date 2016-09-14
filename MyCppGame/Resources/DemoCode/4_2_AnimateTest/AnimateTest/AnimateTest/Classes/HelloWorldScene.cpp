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
//----------------模拟动画实现
    
//    //添加4个精灵,每个精灵用来表示一帧
//    CCSprite* frame = CCSprite::create("crop1.png");
//    CCSprite* frame2 = CCSprite::create("crop2.png");
//    CCSprite* frame3 = CCSprite::create("crop3.png");
//    CCSprite* frame4 = CCSprite::create("crop4.png");
//    
//    //--另外一种方式：
//    //    CCSprite* frame = CCSprite::create("crop.png",CCRectMake(0, 0, 100, 86));
//    //    CCSprite* frame2 = CCSprite::create("crop.png",CCRectMake(100, 0, 100, 86));
//    //    CCSprite* frame3 = CCSprite::create("crop.png",CCRectMake(200, 0, 100, 86));
//    //    CCSprite* frame4 = CCSprite::create("crop.png",CCRectMake(300, 0, 100, 86));
//
//
//    //设置一样的坐标
//    frame ->setPosition(ccp(100,180));
//    frame2 ->setPosition(ccp(100,180));
//    frame3 ->setPosition(ccp(100,180));
//    frame4 ->setPosition(ccp(100,180));
//    
//    //设置2-4帧不可见，初始化时只显示第一帧
//    frame2->setVisible(false);
//    frame3->setVisible(false);
//    frame4->setVisible(false);
//    
//    //添加当前Lyaer中，tag按照顺序0～3
//    addChild(frame,0,0);
//    addChild(frame2,0,1);
//    addChild(frame3,0,2);
//    addChild(frame4,0,3);
//    
//    //每0.5秒调用一次myUpdate（每0.5切换一帧）
//    schedule(schedule_selector(HelloWorld::myUpdate), 0.5);
    
//---------------手动添加序列帧实现动画
//    CCSprite* sp = CCSprite::create("crop1.png");
//    sp->setPosition(ccp(170,200));
//    addChild(sp);
//    
//    CCAnimation* animation = CCAnimation::create();
//    animation->addSpriteFrameWithFileName("crop1.png");
//    animation->addSpriteFrameWithFileName("crop2.png");
//    animation->addSpriteFrameWithFileName("crop3.png");
//    animation->addSpriteFrameWithFileName("crop4.png");
//    animation->setDelayPerUnit(2.8f / 14.0f);//必须设置否则不会动态播放
//    animation->setRestoreOriginalFrame(true);//是否回到第一帧
//    animation->setLoops(-1);//重复次数 （-1:无限循环）
//    CCFiniteTimeAction * animate = CCAnimate::create(animation);
//    sp->runAction(animate);
    
//---------------通过资源文件创建动画
    CCTexture2D::PVRImagesHavePremultipliedAlpha(true);
    CCSpriteFrameCache::sharedSpriteFrameCache()->addSpriteFramesWithFile("crop.plist");
    
    //利用帧缓存创建精灵
    CCSprite* sp = CCSprite::createWithSpriteFrameName("crop1.png");
    sp->setPosition(ccp(170,200));
    addChild(sp);
    
    CCArray* animFrames = CCArray::createWithCapacity(4);
    char str[100] = {0};
    for(int i = 1; i < 5; i++)
    {
        sprintf(str, "crop%i.png", i);
        CCSpriteFrame *frame = CCSpriteFrameCache::sharedSpriteFrameCache()->spriteFrameByName(str);
        animFrames->addObject(frame);
    }
    CCAnimation *animation = CCAnimation::createWithSpriteFrames(animFrames, 0.3f);
    animation->setLoops(-1);
    sp->runAction(CCAnimate::create(animation));
    
//    CCSpriteFrameCache::sharedSpriteFrameCache()->removeSpriteFrameByName("crop.plist")
    return true;
    
}
void HelloWorld::myUpdate(float dt){
    currentFrameIndex++;
    //获取当前所有精灵
    CCArray* array = this->getChildren();
    //防止下标超过最大tag的精灵
    if(currentFrameIndex>=array->count()){
        currentFrameIndex=0;
    }
    //隐藏所有的精灵
    for (int i = 0; i<array->count(); i++) {
        //根据tag索引每一帧并设置不可见
        CCSprite* spT = (CCSprite*)this->getChildByTag(i);
        spT->setVisible(false);
    }
    //让下一帧显示出来
    CCSprite* sp = (CCSprite*)array->objectAtIndex(currentFrameIndex);
    sp->setVisible(true);
}































































