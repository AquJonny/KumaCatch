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
    // 1. super init first
    if ( !CCLayer::init() )
    {
        return false;
    }
    
    //－－－－CCMenuItemFont
    CCMenuItemFont*  itemFont = CCMenuItemFont::create("开始游戏", this,menu_selector(HelloWorld::menuFun));
    itemFont->setPosition(ccp(-120,80));
    
    //－－－－CCMenuItemImage
    CCMenuItemImage* imageItem = CCMenuItemImage::create("CloseNormal.png","CLoseSelected.png", this,menu_selector(HelloWorld::menuFun));
    imageItem->setPosition(ccp(-20,80));
         
    //－－－－CCMenuItemLabel
    CCLabelTTF * lableTTF = CCLabelTTF::create("返回主菜单", "Helvetica", 20); 
    CCMenuItemLabel * labelItem =CCMenuItemLabel::create(lableTTF,this,menu_selector(HelloWorld::menuFun));
    labelItem->setPosition(ccp(80,80));

    //－－－－CCMenuItemSprite
    CCSprite* spNor = CCSprite::create("Icon.png");
    spNor->setColor(ccc3(255, 255, 0 ));
    CCSprite* spSelected =CCSprite::create("Icon.png");
    CCMenuItemSprite* spriteItem = CCMenuItemSprite::create(spNor,spSelected, this,menu_selector(HelloWorld::menuFun));
    spriteItem->setPosition(ccp(-80,-20));
    
    
    //－－－－CCMenuItemToggle
    CCMenuItemFont * fontItem1 = CCMenuItemFont::create("音乐开");
    CCMenuItemFont * fontItem2 = CCMenuItemFont::create("音乐关");
    CCMenuItemToggle* toggleItem = CCMenuItemToggle::createWithTarget(this,menu_selector(HelloWorld::menuFun), fontItem1,fontItem2,NULL);
    toggleItem->setPosition(ccp(20,-20));
    
    CCMenu* menu = CCMenu::create(itemFont,imageItem,labelItem,spriteItem,toggleItem,NULL);
    addChild(menu);
    
    return true;
}

void HelloWorld::menuFun(){
    
}



