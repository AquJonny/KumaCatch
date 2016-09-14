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
    CCSize size=CCDirector::sharedDirector()->getWinSize();
    CCSprite* sp = CCSprite::create("Default.png");
    sp->setPosition(ccp(size.width*0.5,size.height*0.5));
    sp->setRotation(90);
    addChild(sp);
   
//------ CCShaky3D
//    CCActionInterval* shaky3D = CCShaky3D::create(15, false, ccg(15,10), 4);
//    sp->runAction(shaky3D);

//------ CCShakyTiles3D    
//    CCActionInterval* shakyTiles3D = CCShakyTiles3D::create(15, true, ccg(15,10), 4);
//    sp->runAction(shakyTiles3D);

//------ CCWaves

//    CCActionInterval* waves = CCWaves::create(10, 20, true, true, ccg(16,12), 4);
//    sp->runAction(waves);
    
//------ CCWaves3D
//    CCActionInterval* waves3D =CCWaves3D::create(10, 20, ccg(16,12), 3);
//    sp->runAction(waves3D);
    
//------ CCWavesTiles3D
//    CCActionInterval* wavesTiles3D =CCWavesTiles3D::create(10, 20, ccg(16,12), 3);
//    sp->runAction(wavesTiles3D);
        
//------ CCFlipX3D
//    CCActionInterval* flipX3D =CCFlipX3D::create(3);
//    sp->runAction(flipX3D);
    
//------ CCFlipY3D
//    CCActionInterval* flipY3D =CCFlipY3D::create(3);
//    sp->runAction(flipY3D);
    
//------ CCLens3D
//    CCActionInterval* lens3D =CCLens3D::create(CCPointMake(size.width/2,size.height/2), 240, ccg(15,10), 2);
//    sp->runAction(lens3D);

//------ CCRipple3D
//    CCActionInterval* ripple3D =CCRipple3D::create(CCPointMake(size.width/2,size.height/2), 240, 4, 160, ccg(32,24), 3);
//    sp->runAction(ripple3D);
    
//------ CCLiquid
//    CCActionInterval* liquid =CCLiquid::create(4, 20, ccg(16,12), 4);
//    sp->runAction(liquid);
    
//------ CCTwirl 
//    CCActionInterval* twirl =CCTwirl::create(CCPointMake(size.width/2, size.height/2), 2, 2.5f, ccg(12,8), 3);
//    sp->runAction(twirl); 
    
//------ CCShuffleTiles
//    CCActionInterval* shuffleTiles =CCShuffleTiles::create(16, ccg(16,12), 2);
//    sp->runAction(shuffleTiles);
    
//------ CCShatteredTiles3D    
//    CCActionInterval* shatteredTiles3D =CCShatteredTiles3D::create(25, true, ccg(16,12), 3);
//    sp->runAction(shatteredTiles3D);
    
//------ CCFadeOutTRTiles
//    CCActionInterval* fadeOutTRTiles =CCFadeOutTRTiles::create(ccg(16,12), 2);
//    sp->runAction(fadeOutTRTiles);
    
//------ CCFadeOutBLTiles
//    CCActionInterval* fadeOutBLTiles =CCFadeOutBLTiles::create(ccg(16,12), 2);
//    sp->runAction(fadeOutBLTiles);
    
//------ CCFadeOutUpTiles
//    CCActionInterval* fadeOutUpTiles =CCFadeOutUpTiles::create(ccg(16,12), 2);
//    sp->runAction(fadeOutUpTiles);
    
//------ CCFadeOutDownTiles
//    CCActionInterval* fadeOutDownTiles =CCFadeOutDownTiles::create(ccg(16,12), 2);
//    sp->runAction(fadeOutDownTiles);
    
//------ CCTurnOffTiles 
//    CCActionInterval* turnOffTiles =CCTurnOffTiles::create(ccg(48,32) , 2);
//    sp->runAction(turnOffTiles);
    
//------ CCJumpTiles3D
//    CCActionInterval* jumpTiles3D =CCJumpTiles3D::create(1, 30, ccg(15,10), 2);
//    sp->runAction(jumpTiles3D);
    
//------ CCSplitRows
//    CCActionInterval* splitRows =CCSplitRows::create(10,2);
//    sp->runAction(splitRows);

//------ CCSplitCols
//    CCActionInterval* splitCols =CCSplitCols::create(13, 3);
//    sp->runAction(splitCols);
    
//------ CCPageTurn3D
    CCActionInterval* pageTurn3D =CCPageTurn3D::create(ccg(15,10), 3);
    sp->runAction(pageTurn3D);
    
    
    return true;
}
