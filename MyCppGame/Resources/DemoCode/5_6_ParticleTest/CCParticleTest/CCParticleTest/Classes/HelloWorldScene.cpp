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
    
//--------------------------自带的11种粒子效果
//    //---爆炸粒子效果
//    CCParticleSystem* particleSyetem = CCParticleExplosion::create();
//    particleSyetem->setTexture( CCTextureCache::sharedTextureCache()->addImage("stars.png"));
// 
//    //---火焰粒子效果
//    CCParticleSystem* particleSyetem = CCParticleFire::create();
//    particleSyetem->setTexture( CCTextureCache::sharedTextureCache()->addImage("fire.png"));
// 
//    //---花束粒子效果
//    CCParticleSystem* particleSyetem = CCParticleFlower::create();
//    particleSyetem->setTexture( CCTextureCache::sharedTextureCache()->addImage("fire.png"));
// 
//    //---烟花粒子效果
//    CCParticleSystem* particleSyetem = CCParticleFireworks::create();
//    particleSyetem->setTexture( CCTextureCache::sharedTextureCache()->addImage("fire.png"));
// 
//    //---星系粒子效果
//    CCParticleSystem* particleSyetem = CCParticleGalaxy::create();
//    particleSyetem->setTexture( CCTextureCache::sharedTextureCache()->addImage("fire.png"));
// 
//    //---流星粒子效果
//    CCParticleSystem* particleSyetem = CCParticleMeteor::create();
//    particleSyetem->setTexture( CCTextureCache::sharedTextureCache()->addImage("fire.png"));
// 
//    //---下雨粒子效果
//    CCParticleSystem* particleSyetem = CCParticleRain::create();
//    particleSyetem->setTexture( CCTextureCache::sharedTextureCache()->addImage("fire.png"));
// 
//    //---烟雾粒子效果
//    CCParticleSystem* particleSyetem = CCParticleSmoke::create();
//    particleSyetem->setTexture( CCTextureCache::sharedTextureCache()->addImage("fire.png"));
// 
//    //---下雪粒子效果
//    CCParticleSystem* particleSyetem = CCParticleSnow::create();
//    particleSyetem->setTexture( CCTextureCache::sharedTextureCache()->addImage("snow.png"));
// 
//    //---漩涡粒子效果
//    CCParticleSystem* particleSyetem = CCParticleSpiral::create();
//    particleSyetem->setTexture( CCTextureCache::sharedTextureCache()->addImage("fire.png"));
// 
//    //---太阳粒子效果
//    CCParticleSystem* particleSyetem = CCParticleSun::create();
//    particleSyetem->setTexture( CCTextureCache::sharedTextureCache()->addImage("fire.png"));
// 
//    particleSyetem->setPosition(ccp(240,160));
//    addChild(particleSyetem);
    
    
//-----------------------------函数、移动类型对比
    
//    CCParticleSystem* particleSyetemFree = CCParticleSun::create();
//    //设置贴图
//    particleSyetemFree->setTexture( CCTextureCache::sharedTextureCache()->addImage("fire.png"));
//    //设置自动释放
//    particleSyetemFree->setAutoRemoveOnFinish(true);
//    //设置移动类型 kCCPositionTypeFree
//    particleSyetemFree->setPositionType(kCCPositionTypeFree);
//    particleSyetemFree->setPosition(ccp(90,160));
//    addChild(particleSyetemFree);
//    
//    CCParticleSystem* particleSyetemRel = CCParticleSun::create();
//    particleSyetemRel->setTexture( CCTextureCache::sharedTextureCache()->addImage("fire.png"));
//    //设置移动类型 kCCPositionTypeRelative
//    particleSyetemRel->setPositionType(kCCPositionTypeRelative);
//    particleSyetemRel->setPosition(ccp(200,160));
//    addChild(particleSyetemRel);
//    
//    //让当前layer来回移动，观察两个移动模式不同的粒子特效
//    CCFiniteTimeAction * move = CCMoveBy::create(3, ccp(290,0));
//    CCFiniteTimeAction* back = move->reverse();
//    this->runAction(CCSequence::create(move,back,NULL));
    
    
//---------------------------创建自定义粒子
//    CCParticleSystem* myParticle = CCParticleSystemQuad::create("himiParticle.plist");
//    addChild(myParticle);
    
//---------------------------CCParticleBatchNode
//    //不使用CCParticleBatchNode
//    for (int i =0 ; i<10; i++) {
//        CCParticleSystem* particleSyetem = CCParticleSun::create();
//        particleSyetem->setTexture( CCTextureCache::sharedTextureCache()->addImage("fire.png"));
//        particleSyetem->setPosition(ccp(150+i*20,160));
//        addChild(particleSyetem);
//    }
    
    //使用CCParticleBatchNode
    CCTexture2D* texture = CCTextureCache::sharedTextureCache()->addImage("fire.png");
    CCParticleBatchNode* particleNode =CCParticleBatchNode::createWithTexture(texture);
    for (int i =0 ; i<10; i++) {
        CCParticleSystem* particleSyetem = CCParticleSun::create();
        particleSyetem->setTexture(texture);
        particleSyetem->setPosition(ccp(150+i*20,160));
        particleNode->addChild(particleSyetem);
    }
    addChild(particleNode);
    
    return true;
}

