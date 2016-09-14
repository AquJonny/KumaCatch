#ifndef __HELLOWORLD_SCENE_H__
#define __HELLOWORLD_SCENE_H__

#include "cocos2d.h"
#include "cocos-ext.h"
using namespace extension;
class HelloWorld : public cocos2d::CCLayer
{
public:
    virtual bool init();  
    static cocos2d::CCScene* scene();
    CREATE_FUNC(HelloWorld);
    
    //按钮按下事件回调
    void touchDownAction(CCObject *sender, CCControlEvent controlEvent);
    //按钮在其内部抬起事件回调
    void touchUpInsideAction(CCObject *sender, CCControlEvent controlEvent);
    //按钮在其外部抬起事件回调
    void touchUpOutsideAction(CCObject *sender, CCControlEvent controlEvent);
};

#endif // __HELLOWORLD_SCENE_H__
