#ifndef __HELLOWORLD_SCENE_H__
#define __HELLOWORLD_SCENE_H__

#include "cocos2d.h"
#include "cocos-ext.h"

using namespace cocos2d;
using namespace extension;

class HelloWorld : public cocos2d::CCLayer,public CCScrollViewDelegate
{
public:
    virtual bool init();  
    static cocos2d::CCScene* scene();
    CREATE_FUNC(HelloWorld);
    
    //当scrollview发生移动时响应
    virtual void scrollViewDidScroll(CCScrollView* view);
    //当scrollview发生缩放时响应
    virtual void scrollViewDidZoom(CCScrollView* view);
};

#endif // __HELLOWORLD_SCENE_H__
