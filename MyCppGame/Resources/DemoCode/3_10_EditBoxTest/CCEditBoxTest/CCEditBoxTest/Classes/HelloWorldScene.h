#ifndef __HELLOWORLD_SCENE_H__
#define __HELLOWORLD_SCENE_H__

#include "cocos2d.h"
#include "cocos-ext.h"
using namespace extension;

class HelloWorld : public cocos2d::CCLayer ,public extension::CCEditBoxDelegate
{
public:
    virtual bool init();  
    static cocos2d::CCScene* scene();
    CREATE_FUNC(HelloWorld);
    
    //开始进入编辑
    virtual void editBoxEditingDidBegin(cocos2d::extension::CCEditBox* editBox);
    //结束编辑
    virtual void editBoxEditingDidEnd(cocos2d::extension::CCEditBox* editBox);
    //编辑框文本改变
    virtual void editBoxTextChanged(cocos2d::extension::CCEditBox* editBox, const std::string& text);
    //当触发return后的回调函数
    virtual void editBoxReturn(cocos2d::extension::CCEditBox* editBox);
    
};

#endif // __HELLOWORLD_SCENE_H__
