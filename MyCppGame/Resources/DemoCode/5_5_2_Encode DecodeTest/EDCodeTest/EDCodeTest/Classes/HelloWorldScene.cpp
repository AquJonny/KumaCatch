#include "HelloWorldScene.h"
#include "SimpleAudioEngine.h"
#include "BaseData.h"


using namespace cocos2d;
using namespace CocosDenshion;

CCScene* HelloWorld::scene()
{
    CCScene *scene = CCScene::create();
    
    HelloWorld *layer = HelloWorld::create();
    scene->addChild(layer);

    // return the scene
    return scene;
}

bool HelloWorld::init()
{
    if ( !CCLayer::init() )
    {
        return false;
    }
    
    //需要存储的字符串
    string sValue = "Himi";
    //对存储的数据进行编码
    string saveBaseString = saveData(sValue.c_str(), sValue.length());
    //将得到编码后的数据进行存储
    CCUserDefault::sharedUserDefault()->setStringForKey("Base", saveBaseString);
    CCUserDefault::sharedUserDefault()->flush();
    
    //从存储中获取编码的数据
    string loadBaseString  =  CCUserDefault::sharedUserDefault()->getStringForKey("Base");
    //对编码数据进行解码得到真实数据
    string trueValue = parseData(loadBaseString);
    
    
    //---用以观察数据
    CCLabelTTF* label = CCLabelTTF::create("", "Helvetica", 20);
    label->setPosition(ccp(240,185));
    addChild(label);
    string logStr = "编码前的数据:";
    logStr+=sValue;
    logStr+="    编码后的数据:";
    logStr+=saveBaseString;
    label->setString(logStr.c_str());
   
    
    CCLabelTTF*label2 = CCLabelTTF::create("", "Helvetica", 20);
    label2->setPosition(ccp(240,140));
    addChild(label2);
    logStr = "解码前的数据:";
    logStr+=loadBaseString;
    logStr+="    解码后的数据:";
    logStr+=trueValue;
    label2->setString(logStr.c_str());
    //--
    
    
    
    
    return true;
}
































