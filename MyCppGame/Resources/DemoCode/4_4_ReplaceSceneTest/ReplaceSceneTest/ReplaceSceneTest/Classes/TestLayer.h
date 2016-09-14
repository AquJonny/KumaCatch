//
//  TestLayer.h
//  ReplaceSceneTest
//
//  Created by Himi on 12-9-12.
//
//

#ifndef __ReplaceSceneTest__TestLayer__
#define __ReplaceSceneTest__TestLayer__

#include "cocos2d.h"


class TestLayer : public cocos2d::CCLayer
{
public:
    
    virtual bool init();
    static cocos2d::CCScene* scene();
    CREATE_FUNC(TestLayer);
    
   
    
    virtual void onEnter();
    virtual void onEnterTransitionDidFinish();
    virtual void onExit();
    
};

#endif /* defined(__ReplaceSceneTest__TestLayer__) */
