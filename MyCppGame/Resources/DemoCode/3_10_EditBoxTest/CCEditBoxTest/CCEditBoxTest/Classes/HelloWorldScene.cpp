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
    
//    CCSize size=  CCDirector::sharedDirector()->getWinSize();
//    
//    CCScale9Sprite * sacel9SprY = CCScale9Sprite::create("yellow_edit.png");
//    CCEditBox* box = CCEditBox::create(CCSizeMake(300, 60), sacel9SprY);
//    
//    //设置编辑框内的文字
//    box->setText("");
//    //获取编辑框内的文字
//    CCLOG("Text:%s",box->getText());
//
//    //设置文本的颜色
//    //  
//    box->setFontColor(ccc3(255, 0, 0));
//    
//    //当编辑框中没有任何字符的提示
//    box->setPlaceHolder("请输入帐号");
//    CCLOG("PlaceHolder:%s",box->getPlaceHolder());;
//    
//    //最大输入文本长度
//    box->setMaxLength(10);
//    CCLOG("Length:%i",box->getMaxLength());
//    
//     /**
//      kEditBoxInputModeAny:         开启任何文本的输入键盘,包括换行
//      kEditBoxInputModeEmailAddr:   开启 邮件地址 输入类型键盘
//      kEditBoxInputModeNumeric:     开启 数字符号 输入类型键盘   
//      kEditBoxInputModePhoneNumber: 开启 电话号码 输入类型键盘   
//      kEditBoxInputModeUrl:         开启 URL 输入类型键盘     
//      kEditBoxInputModeDecimal:     开启 数字 输入类型键盘，允许小数点   
//      kEditBoxInputModeSingleLine:  开启任何文本的输入键盘,不包括换行
//     */
//    //设置输入模式
//    box->setInputMode(kEditBoxInputModeAny);
//    
//     /**
//      kEditBoxInputFlagPassword:  密码形式输入
//      kEditBoxInputFlagSensitive: 敏感数据输入、存储输入方案且预测自动完成
//      kEditBoxInputFlagInitialCapsWord: 每个单词首字母大写,并且伴有提示
//      kEditBoxInputFlagInitialCapsSentence: 第一句首字母大写,并且伴有提示
//      kEditBoxInputFlagInitialCapsAllCharacters: 所有字符自动大写
//     */
//    //设置输入类型
//    box->setInputFlag(kEditBoxInputFlagSensitive);
//    
//     /**
//      kKeyboardReturnTypeDefault:  默认使用键盘return 类型
//      kKeyboardReturnTypeDone:     默认使用键盘return类型为“Done”字样
//      kKeyboardReturnTypeSend:     默认使用键盘return类型为“Send”字样
//      kKeyboardReturnTypeSearch:   默认使用键盘return类型为“Search”字样
//      kKeyboardReturnTypeGo:       默认使用键盘return类型为“Go”字样
//      */
//    //设置返回类型
//    box->setReturnType(kKeyboardReturnTypeDone);
//    
//    box->setPosition(ccp(size.width*0.5,220));
//    addChild(box);
//    
//    CCScale9Sprite * sacel9SprG = CCScale9Sprite::create("green_edit.png");
//    CCEditBox* box2 = CCEditBox::create(CCSizeMake(300, 60), sacel9SprG);
//    box2->setInputFlag(kEditBoxInputFlagPassword);
//    box2->setReturnType(kKeyboardReturnTypeGo);
//    box2->setMaxLength(12);
//    box2->setPlaceHolder("请输入密码");
//    box2->setPosition(ccp(size.width*0.5,120));
//    addChild(box2);
    
    //-------------Delegate
    
    CCScale9Sprite * sacel9SprG = CCScale9Sprite::create("green_edit.png");
    CCEditBox* box2 = CCEditBox::create(CCSizeMake(300, 60), sacel9SprG);
    box2->setPlaceHolder("Delegate");
    box2->setPosition(ccp(220,120));
    addChild(box2);
    //接口绑定
    box2->setDelegate(this);
    
    return true;
}


//开始进入编辑
void HelloWorld::editBoxEditingDidBegin(cocos2d::extension::CCEditBox* editBox){
    CCLOG("Start Edit");
}

//结束编辑
void HelloWorld::editBoxEditingDidEnd(cocos2d::extension::CCEditBox* editBox){
    CCLOG("End Edit");
}

//编辑框文本改变
void HelloWorld::editBoxTextChanged(cocos2d::extension::CCEditBox* editBox, const std::string& text){
    CCLOG("TextChanged");
}

//当触发return后的回调函数
void HelloWorld::editBoxReturn(cocos2d::extension::CCEditBox* editBox){
    CCLOG("editBoxReturn");
}






























