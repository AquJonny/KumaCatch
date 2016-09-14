#ifndef __HELLOWORLD_SCENE_H__
#define __HELLOWORLD_SCENE_H__

#include "cocos2d.h"

class HelloWorld : public cocos2d::CCLayer
{
public:
    virtual bool init();  
    static cocos2d::CCScene* scene();
    CREATE_FUNC(HelloWorld);
    
    //更新函数
    void update(float dt);
    
    //自定义更新函数
    void myUpdate(float dt);
};

#endif // __HELLOWORLD_SCENE_H__
