#ifndef __HELLOWORLD_SCENE_H__
#define __HELLOWORLD_SCENE_H__

#include "cocos2d.h"

class HelloWorld : public cocos2d::CCLayer
{
public:
    //初始化函数
    virtual bool init();  

    //静态创建函数
    static cocos2d::CCScene* scene();
    
    //menu菜单的一个回调函数
    void menuCloseCallback(CCObject* pSender);

    //备注1
    CREATE_FUNC(HelloWorld);
    
};

#endif // __HELLOWORLD_SCENE_H__





