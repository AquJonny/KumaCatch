#ifndef __HELLOWORLD_SCENE_H__
#define __HELLOWORLD_SCENE_H__

#include "cocos2d.h"
using namespace cocos2d;

class HelloWorld : public cocos2d::CCLayer
{
public:
    virtual bool init();   
    static cocos2d::CCScene* scene(); 
    CREATE_FUNC(HelloWorld);
    
    //重写触屏回调函数
    virtual bool ccTouchBegan(CCTouch* touch, CCEvent* event);
    virtual void ccTouchMoved(CCTouch* touch, CCEvent* event);
    virtual void ccTouchEnded(CCTouch* touch, CCEvent* event);
    
    //重写生命周期函数
    virtual void onEnter();
    virtual void onExit();
    
    //Menu&Back
    virtual void keyBackClicked();
    virtual void keyMenuClicked();
};

#endif // __HELLOWORLD_SCENE_H__
