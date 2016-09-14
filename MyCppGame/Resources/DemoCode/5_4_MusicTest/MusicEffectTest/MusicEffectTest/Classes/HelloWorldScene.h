#ifndef __HELLOWORLD_SCENE_H__
#define __HELLOWORLD_SCENE_H__

#include "cocos2d.h"
class HelloWorld : public cocos2d::CCLayer
{
public:
  
    virtual bool init(); 
    static cocos2d::CCScene* scene();
    CREATE_FUNC(HelloWorld);
    //menuitem回调函数
    void menuBack(CCObject * pSender);
    //用以记录音效ID
    int effectId ;
};

#endif // __HELLOWORLD_SCENE_H__
