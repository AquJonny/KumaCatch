#ifndef __HELLOWORLD_SCENE_H__
#define __HELLOWORLD_SCENE_H__

#include "cocos2d.h"

class HelloWorld : public cocos2d::CCLayer
{
public: 
    virtual bool init();   
    static cocos2d::CCScene* scene(); 
    CREATE_FUNC(HelloWorld);
    
    //重写draw函数
    virtual void draw();
};

#endif // __HELLOWORLD_SCENE_H__
