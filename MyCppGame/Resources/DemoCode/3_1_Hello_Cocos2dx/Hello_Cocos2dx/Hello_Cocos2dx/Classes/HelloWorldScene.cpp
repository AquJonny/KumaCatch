#include "HelloWorldScene.h"
#include "SimpleAudioEngine.h"

using namespace cocos2d;
using namespace CocosDenshion;

CCScene* HelloWorld::scene()
{
    //创建一个场景对象
    CCScene *scene = CCScene::create();
    //创建一个HelloWorld对象（Layer层）
    HelloWorld *layer = HelloWorld::create();
    //将层作为场景的孩子放入场景中
    scene->addChild(layer);
    return scene;
}

// on "init" you need to initialize your instance
bool HelloWorld::init()
{
    //先调用父类初始化函数
    if ( !CCLayer::init() )
    {
        return false;
    }

    //将一个“X”形状的图片创建成一个图片菜单项，
    //并将用户点击后的回调函数绑定在menuCloseCallback函数上
    CCMenuItemImage *pCloseItem = CCMenuItemImage::create(
                                        "CloseNormal.png",
                                        "CloseSelected.png",
                                        this,
                                        menu_selector(HelloWorld::menuCloseCallback) );
    //设置菜单项的位置
    pCloseItem->setPosition( ccp(CCDirector::sharedDirector()->getWinSize().width - 20, 20) );

    //将已经创建好的菜单项加入菜单中，生成一个菜单Menu对象实例
    CCMenu* pMenu = CCMenu::create(pCloseItem, NULL);
    
    //设置菜单作为  CCPointZero:x=0,y=0
    pMenu->setPosition( CCPointZero );
    
    //将菜单加入当前Layer中，并且设置z轴为1
    this->addChild(pMenu, 1);

    //创建一个文本对象
    CCLabelTTF* pLabel = CCLabelTTF::create("Hello World", "Thonburi", 34);

    // 获取当前设备尺寸，
    CCSize size = CCDirector::sharedDirector()->getWinSize();

    //设置文本坐标
    pLabel->setPosition( ccp(size.width / 2, size.height - 20) );

    //将文本添加到当前Layer中
    this->addChild(pLabel, 1);

    //利用 HelloWorld.png 图片创建一个精灵
    CCSprite* pSprite = CCSprite::create("HelloWorld.png");

    //设置精灵位置
    pSprite->setPosition( ccp(size.width/2, size.height/2) );

    //将精灵放置当前layer中
    this->addChild(pSprite, 0);

    return true;
}

void HelloWorld::menuCloseCallback(CCObject* pSender)
{
    //程序退出
    CCDirector::sharedDirector()->end();
    
    //判定当前设备是否为ios设备
#if (CC_TARGET_PLATFORM == CC_PLATFORM_IOS)
    exit(0);
#endif
}
