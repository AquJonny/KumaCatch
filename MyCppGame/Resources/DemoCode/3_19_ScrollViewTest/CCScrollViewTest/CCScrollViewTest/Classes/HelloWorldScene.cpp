#include "HelloWorldScene.h" 

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
    //创建一个layer作为容器
    CCLayer * containLayer = CCLayer::create();
    
    CCSprite *sp =CCSprite::create("HelloWorld.png");
    sp->setPosition(ccp(size.width*0.5,size.height*0.5));
    CCSprite *sp2 =CCSprite::create("Default.png");
    sp2->setPosition(ccp(sp->getContentSize().width,size.height*0.5));
    //往容器中添加节点
    containLayer->addChild(sp);
    containLayer->addChild(sp2);
    containLayer->setContentSize(CCSizeMake(size.width*3, size.height));
    
    //创建视图添加当前layer
    CCScrollView * scrollView = CCScrollView::create(CCSizeMake(size.width*2, size.height));
    addChild(scrollView);
    
    scrollView->isDragging();//用户是否正在CCScrollView中操作
    scrollView->isTouchMoved();//用户是否正在CCScrollView移动操作
    scrollView->isBounceable();//是否开启弹性效果
    scrollView->setBounceable(true);//设置scrollview有弹跳效果(默认为true)
    scrollView->setViewSize(CCSizeMake(size.width*2, size.height));//设置scrollView尺寸
    scrollView->setContainer(containLayer);//设置容器
    scrollView->getViewSize();//获取视图尺寸
    
    //务必在AppController.mm中开启iOS对多触点的支持
    //[__glView setMultipleTouchEnabled:YES];
    scrollView->setTouchEnabled(true);//开启监听多触点
    scrollView->setDelegate(this);//注册监听
    
    return true;
}

void HelloWorld::scrollViewDidScroll(CCScrollView* view){
    CCLOG("ScrollView移动");
}

void HelloWorld::scrollViewDidZoom(CCScrollView* view){
    
    CCLOG("ScrollView缩放");
}

