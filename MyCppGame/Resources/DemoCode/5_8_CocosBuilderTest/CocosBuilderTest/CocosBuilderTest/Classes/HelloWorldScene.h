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
    
    //用于定时加载显示cbbi）
    void autoOpen();
    //封装的打开cbbi文件函数
    void openCBBI(const char * pCCBFileName, const char * pCCNodeName, CCNodeLoader * pCCNodeLoader);
};

#endif // __HELLOWORLD_SCENE_H__
