//
//  ClipLayer.h
//  ClipTest
//
//  Created by Himi on 12-10-19.
//
//

#ifndef __ClipTest__ClipLayer__
#define __ClipTest__ClipLayer__

#include "cocos2d.h"
using namespace cocos2d;

class ClipLayer:public cocos2d::CCLayer{
public:
    static ClipLayer* create(CCSize size);
    void clipLayerInit(CCSize size);
    void visit();
    CCSize mSize;
};

#endif /* defined(__ClipTest__ClipLayer__) */
