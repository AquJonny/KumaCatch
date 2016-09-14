#include "HelloWorldScene.h"
#include "SimpleAudioEngine.h"

using namespace cocos2d;
using namespace CocosDenshion;

CCScene* HelloWorld::scene()
{
    
    CCScene *scene = CCScene::create();
    HelloWorld *layer = HelloWorld::create();
    scene->addChild(layer);
    return scene;
}

bool HelloWorld::init()
{
    if ( !CCLayer::init() )
    {
        return false;
    }
    CCLabelTTF *ttf = CCLabelTTF::create("", "Helvetica", 23);
    ttf->setPosition(ccp(240,160));
    addChild(ttf);
    
    if(CCUserDefault::sharedUserDefault()->getBoolForKey("bool",false)){
        ttf->setString("有存档，开始读取数据");
        
        //Load
        bool iBool      =  CCUserDefault::sharedUserDefault()->getBoolForKey("bool",false);
        double iDouble  =  CCUserDefault::sharedUserDefault()->getDoubleForKey("double",0.0);
        float iFloat    =  CCUserDefault::sharedUserDefault()->getFloatForKey("float",0.0);
        int iInt        =  CCUserDefault::sharedUserDefault()->getIntegerForKey("int",0);
        std::string iString  =  CCUserDefault::sharedUserDefault()->getStringForKey("string","");
        
        CCLOG("%b__%d__%f__%f__%i__%s",iBool,iDouble,iFloat,iInt,iString.c_str());

    }else{
         ttf->setString("还没有存档，开始存档数据");
        
        CCUserDefault::sharedUserDefault()->setBoolForKey("bool", true);
        CCUserDefault::sharedUserDefault()->setDoubleForKey("double", 9.22);
        CCUserDefault::sharedUserDefault()->setFloatForKey("float", 8.23);
        CCUserDefault::sharedUserDefault()->setIntegerForKey("int", 23);
        CCUserDefault::sharedUserDefault()->setStringForKey("string", "Himi");
        //提交
        CCUserDefault::sharedUserDefault()->flush();
    }
    return true;
}


































