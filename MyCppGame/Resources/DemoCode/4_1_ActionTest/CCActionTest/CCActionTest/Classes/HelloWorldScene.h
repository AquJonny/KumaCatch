#ifndef __HELLOWORLD_SCENE_H__
#define __HELLOWORLD_SCENE_H__

#include "cocos2d.h"

class HelloWorld : public cocos2d::CCLayer
{
public:
    
    virtual bool init();  
    static cocos2d::CCScene* scene();
    CREATE_FUNC(HelloWorld);
    
    void callbackC();
    void callbackN(CCNode* sender);
    void callbackND(CCNode* sender, void* data);
};

#endif // __HELLOWORLD_SCENE_H__
