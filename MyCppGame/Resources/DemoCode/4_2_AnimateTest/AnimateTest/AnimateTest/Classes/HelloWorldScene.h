#ifndef __HELLOWORLD_SCENE_H__
#define __HELLOWORLD_SCENE_H__

#include "cocos2d.h"
class HelloWorld : public cocos2d::CCLayer
{
public:
    virtual bool init();  
    static cocos2d::CCScene* scene();
    CREATE_FUNC(HelloWorld);
    
    //定义一个变量用以标识当前显示的帧下标
    int currentFrameIndex;
    //自定义的更新函数
    void myUpdate(float dt);
    
};

#endif // __HELLOWORLD_SCENE_H__
