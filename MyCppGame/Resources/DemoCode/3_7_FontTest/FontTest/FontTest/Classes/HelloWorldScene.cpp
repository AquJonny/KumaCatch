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

// on "init" you need to initialize your instance
bool HelloWorld::init()
{
    if ( !CCLayer::init() )
    {
        return false;
    }
    
//－－－－－－CCLabelTTF
    CCLabelTTF* pLabel = CCLabelTTF::create("CCLabelTTF-Thonburi", "Thonburi", 24);
    pLabel->setPosition( ccp(170,280) );
    this->addChild(pLabel);

    CCLabelTTF* pLabel2 = CCLabelTTF::create();
    //设置字体大小
    pLabel2->setFontSize(20);
    //设置字符串
    pLabel2->setString("CCLabelTTF-Helvetica"); 
    pLabel2->setPosition( ccp(170,250) );
    this->addChild(pLabel2);
    
//－－－－－－CCLabelAtlas
    CCLabelAtlas* label = CCLabelAtlas::create("Atlas-823", "testfont.png", 48, 64, ' ');
    label->setPosition(ccp(0,190));
    addChild(label);
    //设置字体颜色
    label->setColor(ccc3(255, 0, 0));
    
    CCLabelAtlas* label2 = CCLabelAtlas::create("LabelAtlas", "testfont.plist");
    label2->setPosition(ccp(0,140));
    addChild(label2);
    
//－－－－－－CCLabelBMFont
    CCLabelBMFont* labelBM = CCLabelBMFont::create("Himi站立", "testChinese.fnt");
    labelBM->setPosition(ccp(180,100));
    addChild(labelBM);
    
    return true;
}









































