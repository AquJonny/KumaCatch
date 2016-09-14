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
    CCSize size = CCDirector::sharedDirector()->getWinSize();
    CCTextFieldTTF* textField = CCTextFieldTTF::textFieldWithPlaceHolder("点击输入...", "Helvetica", 24);
    textField->setPosition(ccp(size.width*0.5,size.height*0.7));
    addChild(textField);
    
    //绑定接口
    textField->setDelegate(this);
    //开启输入
    textField->attachWithIME();
    //关闭输入
//    textField->detachWithIME();
    return true;
}

bool HelloWorld::onTextFieldAttachWithIME(CCTextFieldTTF * pSender){
    CCLOG("启动输入");
    return false;
    //return true:不启动
}
bool HelloWorld::onTextFieldDetachWithIME(CCTextFieldTTF * pSender){
    CCLOG("关闭输入");
    return false;
    //return true:不关闭
}
bool HelloWorld::onTextFieldInsertText(CCTextFieldTTF * pSender, const char * text, int nLen){
    CCLOG("输入字符...");
    return false;
    //return true:不会输入进字符
}
bool HelloWorld::onTextFieldDeleteBackward(CCTextFieldTTF * pSender, const char * delText, int nLen){
    CCLOG("删除字符");
    return false;
    //return true:不删除
}
