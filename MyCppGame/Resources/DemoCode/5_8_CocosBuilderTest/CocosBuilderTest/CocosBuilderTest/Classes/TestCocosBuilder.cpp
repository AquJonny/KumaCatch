//
//  TestCocosBuilder.cpp
//  CocosBuilderTest
//
//  Created by Himi on 12-9-26.
//
//

#include "TestCocosBuilder.h"

SEL_MenuHandler TestCocosBuilder::onResolveCCBCCMenuItemSelector(cocos2d::CCObject * pTarget, cocos2d::CCString * pSelectorName){
    //将ccbi中的“menu_backfunc”回调函数映射成本类的menu_backfunc函数
    CCB_SELECTORRESOLVER_CCMENUITEM_GLUE(this, "menu_backfunc", TestCocosBuilder::menu_backfunc);

    return NULL;
}

SEL_CCControlHandler TestCocosBuilder::onResolveCCBCCControlSelector(cocos2d::CCObject * pTarget, cocos2d::CCString * pSelectorName){

    return NULL;
}


bool TestCocosBuilder::onAssignCCBMemberVariable(CCObject * pTarget, cocos2d::CCString * pMemberVariableName, CCNode * pNode){
    //将ccbi中的“cbbiTTF”映射成本类的cbbiTTF对象
    CCB_MEMBERVARIABLEASSIGNER_GLUE(this, "cbbiTTF", CCLabelTTF *, this->cbbiTTF);
    
    return false;
}


void TestCocosBuilder::menu_backfunc(cocos2d::CCObject * pSender){
    if(cbbiTTF!=NULL){ 
        cbbiTTF->setString("MenuItemImage 事件被触发");
    }
}