//
//  TestCocosBuilderLoader.h
//  CocosBuilderTest
//
//  Created by Himi on 12-9-26.
//
//

#ifndef CocosBuilderTest_TestCocosBuilderLoader_h
#define CocosBuilderTest_TestCocosBuilderLoader_h

#include "TestCocosBuilder.h"

class CCBReader;

class TestCocosBuilderLoader : public cocos2d::extension::CCLayerLoader {
public:
    CCB_STATIC_NEW_AUTORELEASE_OBJECT_METHOD(TestCocosBuilderLoader, loader);
    
protected:
    CCB_VIRTUAL_NEW_AUTORELEASE_CREATECCNODE_METHOD(TestCocosBuilder);
};

#endif
