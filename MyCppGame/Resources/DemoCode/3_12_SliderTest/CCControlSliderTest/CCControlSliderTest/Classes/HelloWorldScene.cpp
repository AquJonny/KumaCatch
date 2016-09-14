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
    CCControlSlider*slider= CCControlSlider::create("sliderBg.png","sliderProgress.png","sliderThumb.png");
    slider->setPosition(ccp(200,170));
    //设置滑动条最大值
    slider->setMaximumValue(100);
    //设置滑动条最小值
    slider->setMinimumValue(0);
    addChild(slider,0,921);
    //设置监听，当滑动条的值发生变化后，会响应valueChanged函数
    //CCControlEventValueChanged 值改变
    slider->addTargetWithActionForControlEvent(this, cccontrol_selector(HelloWorld::valueChanged), CCControlEventValueChanged);
    
    //用于展示当前滑动条的滑动值
    CCLabelTTF * ttf = CCLabelTTF::create("", "Helvetica", 20);
    ttf->setPosition(ccp(200,210));
    ttf->setString(CCString::createWithFormat("滑动条当前值 = %.02f", slider->getValue())->getCString());
    addChild(ttf,0,922);
    return true;
}
void HelloWorld::valueChanged(){
    CCControlSlider*slider= (CCControlSlider*)this->getChildByTag(921);
    CCLabelTTF * ttf = (CCLabelTTF*)this->getChildByTag(922);
    ttf->setString(CCString::createWithFormat("滑动条当前值 = %.02f", slider->getValue())->getCString());
}
