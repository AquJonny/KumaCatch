//
//  TestCocosBuilder.h
//  CocosBuilderTest
//
//  Created by Himi on 12-9-26.
//
//

#ifndef __CocosBuilderTest__TestCocosBuilder__
#define __CocosBuilderTest__TestCocosBuilder__

#include "cocos2d.h"
#include "cocos-ext.h"

using namespace cocos2d;
using namespace extension;

class TestCocosBuilder:public cocos2d::CCLayer
    , public cocos2d::extension::CCBSelectorResolver
    , public cocos2d::extension::CCBMemberVariableAssigner {

public:
    CCB_STATIC_NEW_AUTORELEASE_OBJECT_WITH_INIT_METHOD(TestCocosBuilder, create);
    
    //CCBSelectorResolver重写函数如下
    virtual SEL_MenuHandler onResolveCCBCCMenuItemSelector(cocos2d::CCObject * pTarget, cocos2d::CCString * pSelectorName);
    virtual SEL_CCControlHandler onResolveCCBCCControlSelector(cocos2d::CCObject * pTarget, cocos2d::CCString * pSelectorName);
        
    //CCItemImage 回调函数
    void menu_backfunc(cocos2d::CCObject * pSender);
        
    //CCBMemberVariableAssigner重写函数如下
    virtual bool onAssignCCBMemberVariable(CCObject * pTarget, cocos2d::CCString * pMemberVariableName, CCNode * pNode);

    CCLabelTTF* cbbiTTF;
    
};


#endif /* defined(__CocosBuilderTest__TestCocosBuilder__) */
