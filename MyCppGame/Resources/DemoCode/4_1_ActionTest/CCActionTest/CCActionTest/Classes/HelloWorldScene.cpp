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
    CCSprite* sp = CCSprite::create("Icon.png");
    sp->setPosition(ccp(150,150));
    addChild(sp,0,922);
    
//---------CCMoveBy
//    CCActionInterval * moveBy = CCMoveBy::create(5, ccp(300,200));
//    CCActionInterval*  actionByBack = moveBy->reverse();
//    sp->runAction(actionByBack);

//---------CCScaleTo
//    CCActionInterval* scaleTo = CCScaleTo::create(2, 2);
//    sp->runAction(scaleTo);
    
//---------CCScaleBy
//    CCActionInterval* scaleBy = CCScaleBy::create(2, 2);
//    CCActionInterval*  actionByBack = scaleBy->reverse();
//    sp->runAction(actionByBack);
    
//---------CCRotateTo
//    CCActionInterval* rotateTo = CCRotateTo::create(2, 90);
//    sp->runAction(rotateTo);
    
//---------CCRotateBy
//    CCActionInterval* rotateBy = CCRotateBy::create(2, 90);
//    CCActionInterval*  actionByBack = rotateBy->reverse();
//    sp->runAction(actionByBack);
    
//---------CCSkewTo
//    CCActionInterval* skewTo =CCSkewTo::create(2, 10, 10);
//    sp->runAction(skewTo);
    
//---------CCSkewBy    
//    CCActionInterval* skewBy =CCSkewBy::create(2, 10, 10);
//    CCActionInterval*  actionByBack = skewBy->reverse();
//    sp->runAction(actionByBack);
    
//---------CCJumpTo
//    CCActionInterval* jumpTo =CCJumpTo::create(2, ccp(300,200), 50, 4);
//    sp->runAction(jumpTo);
    
//---------CCJumBy
//    CCActionInterval* jumpBy =CCJumpBy::create(2, ccp(300,200), 50, 4);
//    CCActionInterval*  actionByBack = jumpBy->reverse();
//    sp->runAction(actionByBack);
    
//---------CCBezier 
//    ccBezierConfig bezierCon;
//    bezierCon.controlPoint_1 = CCPointMake(200, 150);
//    bezierCon.controlPoint_2 = CCPointMake(200, 260);
//    bezierCon.endPosition = CCPointMake(340,100);
//    
//    //--CCBezierTo
//    CCActionInterval* bezierTo =CCBezierTo::create(2, bezierCon);
//    sp->runAction(bezierTo);
//    
//    //--CCBezierBy
//    CCActionInterval* bezierBy =CCBezierBy::create(2, bezierCon);
//    CCActionInterval*  actionByBack = bezierBy->reverse();
//    sp->runAction(actionByBack);
    
//---------CCFadeIn     
//    CCActionInterval * fadeIn = CCFadeIn::create(2);
//    sp->runAction(fadeIn);
    
//---------CCFadeOut
//    CCActionInterval * fadeOut = CCFadeOut::create(2);
//    sp->runAction(fadeOut);
    
//---------CCTintTo    
//    CCActionInterval* tintTo =CCTintTo::create(2, 255, 0, 0);
//    sp->runAction(tintTo);
    
//---------CCTintBy   
//    CCActionInterval* tintBy =CCTintBy::create(2, 255, 0, 0);
//    CCActionInterval* actionByBack = tintBy->reverse();
//    sp->runAction(actionByBack);
    
//---------CCBlink
//    CCActionInterval* blink = CCBlink::create(10, 3);
//    sp->runAction(blink);
    

//---------CCDelayTime
//    CCActionInterval* delayTime = CCDelayTime::create(2);
//    sp->runAction(delayTime);
    
    
//---------CCOrbitCamera
//    CCActionInterval* orbitCamera = CCOrbitCamera::create(3,1, 0, 45, 180, 90, 0);
//    sp->runAction(orbitCamera);

//---------CCCardinalSpline
//    CCPointArray *array = CCPointArray::create(20);
//    array->addControlPoint(ccp(0, 0));
//    array->addControlPoint(ccp(210, 0));
//    array->addControlPoint(ccp(210, 240));
//    array->addControlPoint(ccp(0, 160));
//    array->addControlPoint(ccp(0, 0));
//    
//    //--CCCardinalSplineTo
//    CCActionInterval* splineTo = CCCardinalSplineTo::create(4, array, 0);
//    sp->runAction(splineTo);
//    
//    //--CCCardinalSplineBy
//    CCActionInterval* splineBy = CCCardinalSplineBy::create(4, array, 0);
//    CCActionInterval* actionByBack =splineBy->reverse();
//    sp->runAction(actionByBack);
    
    
//---------CCCatmullRom 
//    CCPointArray *array = CCPointArray::create(20);
//    array->addControlPoint(ccp(240, 30));
//    array->addControlPoint(ccp(400, 30));
//    array->addControlPoint(ccp(400, 240));
//    array->addControlPoint(ccp(240, 240));
//    array->addControlPoint(ccp(240, 30));
//    
//    //--CCCatmullRomTo
//    CCCatmullRomTo * romTo = CCCatmullRomTo::create(2, array);
//    sp->runAction(romTo);
//    
//    //--CCCatmullRomTo
//    CCActionInterval * romBy = CCCatmullRomBy::create(2, array);
//    CCActionInterval* actionByBack =romBy->reverse();
//    sp->runAction(actionByBack);
    

//---------CCFollow 
//    //创建一个参照物spT
//    CCSprite*spT = CCSprite::create("icon.png");
//    spT->setPosition(ccp(420,40));
//    addChild(spT);
//    
//    sp->runAction(CCMoveTo::create(3,ccp(940,sp->getPositionY())));
//    CCFollow* follow = CCFollow::create(sp,CCRectMake(0, 0, 960, 320));
//    this->runAction(follow);
    

    
//-------CCEaseBounce
//    CCActionInterval* move = CCMoveTo::create(5, ccp(300,sp->getPositionY()));
//    //---CCEaseBounceIn
//    CCActionInterval* easeBounceIn = CCEaseBounceIn::create(move);
//    sp->runAction(easeBounceIn);
    
//    //---CCEaseBounceIn
//    CCActionInterval* easeBounceOut = CCEaseBounceOut::create(move);
//    sp->runAction(easeBounceOut);
    
      //CCEaseBounceInOut
//    CCActionInterval* easeInOut = CCEaseBounceInOut::create(move);
//    sp->runAction(easeInOut);
    
//------CCEaseBack
//    CCActionInterval* move = CCMoveTo::create(5, ccp(300,sp->getPositionY()));
//    //--CCEaseBackIn
//    CCActionInterval* easeBackIn =  CCEaseBackIn::create(move);
//    sp->runAction(easeBackIn);
    
//    //--CCEaseBackOut
//    CCActionInterval* easeBackOut =  CCEaseBackOut::create(move);
//    sp->runAction(easeBackOut);
    
//    //--CCEaseBackInOut
//    CCActionInterval* easeBackInOut =  CCEaseBackInOut::create(move);
//    sp->runAction(easeBackInOut);
    
//------easeElastic
//    CCActionInterval* move = CCMoveTo::create(5, ccp(300,sp->getPositionY()));
//    //--easeElasticIn
//    CCActionInterval * easeElasticIn = CCEaseElasticIn::create(move);
//    sp->runAction(easeElasticIn);
    
//    //--CCEaseElasticOut
//    CCActionInterval * easeElasticOut = CCEaseElasticOut::create(move);
//    sp->runAction(easeElasticOut);
    
//    //--CCEaseElasticInOut
//    CCActionInterval * easeElasticInOut = CCEaseElasticInOut::create(move);
//    sp->runAction(easeElasticInOut);
    
    
//-------CCEaseExponential
//    CCActionInterval* move = CCMoveTo::create(5, ccp(300,sp->getPositionY()));
//    //--CCEaseExponentialIn
//    CCActionInterval * exponentinalIn = CCEaseExponentialIn::create(move);
//    sp->runAction(exponentinalIn);
    
//    //--CCEaseExponentialOut
//    CCActionInterval * exponentinalOut = CCEaseExponentialOut::create(move);
//    sp->runAction(exponentinalOut);
    
//    //--CCEaseExponentialInOut
//    CCActionInterval * exponentinalInOut = CCEaseExponentialInOut::create(move);
//    sp->runAction(exponentinalInOut);
    
//--------CCEaseRateAction
//    CCActionInterval* move = CCMoveTo::create(5, ccp(300,sp->getPositionY()));
//    CCActionInterval* easeRateAction = CCEaseRateAction::create(move,0.5);
//    sp->runAction(easeRateAction);
    
    
//--------CCEaseSine
//    CCActionInterval* move = CCMoveTo::create(2, ccp(300,sp->getPositionY()));
//    //--CCEaseSineIn
//    CCActionInterval *easeSineIn = CCEaseSineIn::create(move);
//    sp->runAction(easeSineIn);
    
//    //--CCEaseSineOut
//    CCActionInterval *easeSineOut = CCEaseSineOut::create(move);
//    sp->runAction(easeSineOut);
    
//    //--CCEaseSineInOut
//    CCActionInterval *easeSineInOut = CCEaseSineInOut::create(move);
//    sp->runAction(easeSineInOut);
    
    
//-------CCSpeed
//    CCActionInterval* move = CCMoveTo::create(10, ccp(300,sp->getPositionY()));
//    CCSpeed * speed= CCSpeed::create(move, 10);
//    sp->runAction(speed);
    
    
//-------CCSpawn
//    CCActionInterval* move = CCMoveTo::create(5, ccp(300,sp->getPositionY()));
//    CCActionInterval* scale = CCScaleTo::create(2, 3);
//    CCActionInterval* rotate = CCRotateTo::create(4, 190);
//    CCFiniteTimeAction *spwn = CCSpawn::create(move,scale,rotate,NULL);
//    sp->runAction(spwn);
    
//-------CCSequence
//    CCActionInterval* move = CCMoveTo::create(2, ccp(300,sp->getPositionY()));
//    CCActionInterval* scale = CCScaleTo::create(2, 3);
//    CCFiniteTimeAction * seq = CCSequence::create(move,scale,NULL);
//    sp->runAction(seq);
    
//-------Reverse CCSequence
//    CCActionInterval* move = CCMoveBy::create(2, ccp(300,sp->getPositionY()));
//    CCActionInterval* scale = CCScaleBy::create(2, 3);
//    CCFiniteTimeAction * seq = CCSequence::create(move,scale,NULL);
//    CCFiniteTimeAction * reverseSeq = CCSequence::create(seq,seq->reverse(),NULL);
//    sp->runAction(reverseSeq);
    
//-------CCRepeat
//    CCActionInterval* move = CCMoveTo::create(2, ccp(300,sp->getPositionY()));
//    CCActionInterval* move2 =CCMoveTo::create(2,ccp(100,100));
//    CCFiniteTimeAction *seq =CCSequence::create(move,move2,NULL);
//    CCActionInterval* repeat =CCRepeat::create(seq, 2);
//    sp->runAction(repeat);
    
//-------CCRepeatForever
//    CCActionInterval* move = CCMoveTo::create(1, ccp(300,sp->getPositionY()));
//    CCActionInterval* move2 =CCMoveTo::create(1,ccp(100,100));
//    CCFiniteTimeAction *seq =CCSequence::create(move,move2,NULL);
//    CCActionInterval* repeatForever =CCRepeatForever::create((CCActionInterval*)seq);
//    sp->runAction(repeatForever);

   
//-------CCCallFunc
//    CCActionInterval* move = CCMoveTo::create(1, ccp(300,sp->getPositionY()));
//    CCCallFunc * funCall =CCCallFunc::create(this, callfunc_selector(HelloWorld::callbackC));
//    CCFiniteTimeAction *seq =CCSequence::create(move,funCall,NULL);
//    sp->runAction(seq);
    
//-------CCCallFuncN
//    CCActionInterval* move = CCMoveTo::create(1, ccp(300,sp->getPositionY()));
//    CCCallFuncN * funCall =CCCallFuncN::create(this, callfuncN_selector(HelloWorld::callbackN));
//    CCFiniteTimeAction *seq =CCSequence::create(move,funCall,NULL);
//    sp->runAction(seq);
//
//-------CCCallFuncND
    CCActionInterval* move = CCMoveTo::create(1, ccp(300,sp->getPositionY()));
    CCCallFuncND * funCall =CCCallFuncND::create(this, callfuncND_selector(HelloWorld::callbackND), (void*)0xbebabeba);
    CCFiniteTimeAction *seq =CCSequence::create(move,funCall,NULL);
    sp->runAction(seq);
    
   
    
    return true;
}

void HelloWorld::callbackC()
{
    CCLOG("callbackC");
}

void HelloWorld::callbackN(CCNode* sender)
{
    CCLOG("callbackN");
}

void HelloWorld::callbackND(CCNode* sender, void* data)
{
    CCLOG("callbackND");
}
