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
    CCLabelTTF *titleButton = CCLabelTTF::create("未选中文字", "Marker Felt", 25);
    CCControlButton * btn  = CCControlButton::create(titleButton,CCScale9Sprite::create("button.png"));
    btn->setPosition(ccp(240,170));
    
    //按钮被选中后背景图响应的状态
    btn->setBackgroundSpriteForState(CCScale9Sprite::create("buttonHighlighted.png"), CCControlStateHighlighted);
    //按钮被选中后文字颜色响应的状态
    btn->setTitleColorForState(ccc3(255, 0, 0), CCControlStateHighlighted);
    //按钮被选中后文字响应的状态
    btn->setTitleForState(CCString::create("选中文字"), CCControlStateHighlighted);
    addChild(btn);
    
    //按钮按下事件回调
    btn->addTargetWithActionForControlEvent(this, cccontrol_selector(HelloWorld::touchDownAction), CCControlEventTouchDown);
    //按钮在其内部抬起事件回调
    btn->addTargetWithActionForControlEvent(this, cccontrol_selector(HelloWorld::touchUpInsideAction), CCControlEventTouchUpInside);
    //按钮在其外部抬起事件回调
    btn->addTargetWithActionForControlEvent(this, cccontrol_selector(HelloWorld::touchUpOutsideAction), CCControlEventTouchUpOutside);
    
    //用于显示按钮状态
    CCLabelTTF *titleButtonState = CCLabelTTF::create("", "Marker Felt", 25);
    addChild(titleButtonState,0,923);
    titleButtonState->setPosition(ccp(240,220));
    return true;

}
void HelloWorld::touchDownAction(CCObject *senderz, CCControlEvent controlEvent)
{
    CCLabelTTF *m_pDisplayValueLabel = (CCLabelTTF*)this->getChildByTag(923);
    m_pDisplayValueLabel->setString(CCString::createWithFormat("按下")->getCString());
}
void HelloWorld::touchUpInsideAction(CCObject *sender, CCControlEvent controlEvent)
{
    CCLabelTTF *m_pDisplayValueLabel = (CCLabelTTF*)this->getChildByTag(923);
    m_pDisplayValueLabel->setString(CCString::createWithFormat("内部抬起")->getCString());
}
void HelloWorld::touchUpOutsideAction(CCObject *sender, CCControlEvent controlEvent){
    CCLabelTTF *m_pDisplayValueLabel = (CCLabelTTF*)this->getChildByTag(923);
    m_pDisplayValueLabel->setString(CCString::createWithFormat("外部抬起")->getCString());

}
