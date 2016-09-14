#ifndef __HELLOWORLD_SCENE_H__
#define __HELLOWORLD_SCENE_H__

#include "cocos2d.h"

class HelloWorld : public cocos2d::CCLayer
{
public:
    
    virtual bool init();  
    static cocos2d::CCScene* scene();
    CREATE_FUNC(HelloWorld);
    virtual ~HelloWorld();
    void changeScene();
    
    //生命周期函数
    virtual void onEnter();
    virtual void onEnterTransitionDidFinish();
    virtual void onExit();
};

#endif // __HELLOWORLD_SCENE_H__
