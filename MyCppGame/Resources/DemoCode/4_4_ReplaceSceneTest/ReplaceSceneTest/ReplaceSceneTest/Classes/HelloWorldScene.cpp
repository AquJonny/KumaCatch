#include "HelloWorldScene.h"
#include "SimpleAudioEngine.h"
#include "TestLayer.h"

using namespace cocos2d;
using namespace CocosDenshion;


CCScene* HelloWorld::scene()
{ 
    CCScene *scene = CCScene::create(); 
    HelloWorld *layer = HelloWorld::create(); 
    scene->addChild(layer); 
    return  scene;
}

bool HelloWorld::init()
{ 
    if ( !CCLayer::init() )
    {
          return false;
    }
    CCLOG("HelloWorld init");
    
    CCSprite * sp = CCSprite::create("background1.png");
    sp->setPosition(ccp(240,160));
    addChild(sp);
    
    
    CCLabelTTF* labelTTF =CCLabelTTF::create("点击切换场景", "Helvetica-Hald", 30);
    labelTTF->setColor(ccc3(255, 0, 0));
    CCMenuItemLabel * labelItem = CCMenuItemLabel::create(labelTTF, this, menu_selector(HelloWorld::changeScene));
    CCMenu* menu= CCMenu::create(labelItem,NULL);
    addChild(menu);
    
      return true;
}

void HelloWorld::changeScene(){

    
    
    
    CCTransitionScene* reScene =NULL;
    CCScene* s =TestLayer::scene();
    float t= 1.2f;
    
//--------  CCTransitionJumpZoom
    reScene = CCTransitionJumpZoom::create(t,s)  ;

//--------  CCTransitionProgressRadialCCW
    reScene = CCTransitionProgressRadialCCW::create(t,s);

//--------  CCTransitionProgressRadialCW
    reScene = CCTransitionProgressRadialCW::create(t,s);

//--------  CCTransitionProgressHorizontal
    reScene=CCTransitionProgressHorizontal::create(t, s); 

//--------  CCTransitionProgressVertical
     reScene=CCTransitionProgressVertical::create(t, s);

//--------  CCTransitionProgressInOut
    reScene=CCTransitionProgressInOut::create(t, s);

//--------  CCTransitionProgressOutIn
    reScene=CCTransitionProgressOutIn::create(t, s);

//--------  CCTransitionCrossFade
    reScene =CCTransitionCrossFade::create(t, s);

//--------  CCTransitionPageTurn
    reScene =CCTransitionPageTurn::create(t, s, false);

//--------  CCTransitionFadeTR
    reScene = CCTransitionFadeTR::create(t, s);
    
//--------  CCTransitionFadeBL
    reScene = CCTransitionFadeBL::create(t, s);

//--------  CCTransitionFadeUp
    reScene = CCTransitionFadeUp::create(t, s);

//--------  CCTransitionFadeDown
    reScene = CCTransitionFadeDown::create(t, s);

//--------  CCTransitionTurnOffTiles
    reScene = CCTransitionTurnOffTiles::create(t, s);

//--------  CCTransitionSplitRows
    reScene = CCTransitionSplitRows::create(t, s);

//--------  CCTransitionSplitCols
    reScene = CCTransitionSplitCols::create(t, s);

//--------  CCTransitionFade
    reScene = CCTransitionFade::create(t, s,ccRED);

//-------- CCTransitionFlipX
    reScene=CCTransitionFlipX::create(t, s,kOrientationLeftOver);

//--------  CCTransitionFlipY
    reScene=CCTransitionFlipY::create(t, s,kOrientationUpOver);

//--------  CCTransitionFlipAngular
    reScene=CCTransitionFlipAngular::create(t, s,kOrientationLeftOver);

//--------  CCTransitionZoomFlipX
//    reScene=CCTransitionZoomFlipX::create(t, s,kOrientationLeftOver);

//--------  CCTransitionZoomFlipY
    reScene=CCTransitionZoomFlipY::create(t, s,kOrientationLeftOver);

//--------  CCTransitionZoomFlipAngular
    reScene = CCTransitionZoomFlipAngular::create(t, s,kOrientationLeftOver);

//--------  CCTransitionShrinkGrow
    reScene = CCTransitionShrinkGrow::create(t, s);

//--------  CCTransitionRotoZoom
    reScene = CCTransitionRotoZoom::create(t, s);

//--------  CCTransitionMoveInL
    reScene  =CCTransitionMoveInL::create(t, s);
    
//--------  CCTransitionMoveInR
    reScene  =CCTransitionMoveInR::create(t, s);
    
//--------  CCTransitionMoveInT
    reScene  =CCTransitionMoveInT::create(t, s);
    
//--------  CCTransitionMoveInB
    reScene  =CCTransitionMoveInB::create(t, s);

//--------  CCTransitionSlideInL
    reScene = CCTransitionSlideInL::create(t, s);

//--------  CCTransitionSlideInR
    reScene = CCTransitionSlideInR::create(t, s);
    
//--------  CCTransitionSlideInT
    reScene = CCTransitionSlideInT::create(t, s);
    
//--------  CCTransitionSlideInB
    reScene = CCTransitionSlideInB::create(t, s);


    CCDirector::sharedDirector()->replaceScene(reScene);
    
}

void HelloWorld::onEnter(){
    CCLOG("HelloWorld onEnter");
    CCLayer::onEnter();//务必调用
}

void HelloWorld::onEnterTransitionDidFinish(){
    CCLOG("HelloWorld onEnterTransitionDidFinish");
    CCLayer::onEnterTransitionDidFinish();//务必调用
}

void HelloWorld::onExit(){
    CCLOG("HelloWorld onExit");
    CCLayer::onExit();//务必调用
}

HelloWorld:: ~HelloWorld(){
    CCLOG("HelloWorld 析构");
}

