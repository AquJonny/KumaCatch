#ifndef __HELLOWORLD_SCENE_H__
#define __HELLOWORLD_SCENE_H__

#include "cocos2d.h"
using namespace cocos2d;
class HelloWorld : public cocos2d::CCLayer, public cocos2d::CCTextFieldDelegate
{
public:
    virtual bool init();  

    static cocos2d::CCScene* scene();
    
    CREATE_FUNC(HelloWorld);
    
    //重写CCTextFieldDelegate的回调函数
    //当用户启动虚拟键盘时的回调函数
    virtual bool onTextFieldAttachWithIME(CCTextFieldTTF * pSender);
    //当用户关闭虚拟键盘时的回调函数
    virtual bool onTextFieldDetachWithIME(CCTextFieldTTF * pSender);
    //当用户进行输入时的回调函数
    virtual bool onTextFieldInsertText(CCTextFieldTTF * pSender, const char * text, int nLen);
    //当用户删除文字时的回调函数
    virtual bool onTextFieldDeleteBackward(CCTextFieldTTF * pSender, const char * delText, int nLen);
    
};

#endif // __HELLOWORLD_SCENE_H__
