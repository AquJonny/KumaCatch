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
     

    CCControlSwitch *pSwitch= CCControlSwitch::create(
                                                       CCSprite::create("switch-mask.png"),
                                                       CCSprite::create("switch-on.png"),
                                                       CCSprite::create("switch-off.png"),
                                                       CCSprite::create("switch-thumb.png"),
                                                       CCLabelTTF::create("开", "Arial-BoldMT", 16),
                                                       CCLabelTTF::create("关", "Arial-BoldMT", 16)
                                                       );
    pSwitch->setPosition(ccp(200,200));
    //设置关闭状态
    pSwitch->setOn(false);
    //设置可操作
    pSwitch->setEnabled(true);
    //获取是否为打开（on）
    CCLOG("是否打开状态:%i",pSwitch->isOn());
     //获取当前开关状态是否为手动拖动开关进行的
    CCLOG("是否手动拖动的开关:%i",pSwitch->hasMoved());
    addChild(pSwitch);
        
   
    return true;
}
