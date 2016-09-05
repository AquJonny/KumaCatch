//
//  MainScene.cpp
//  MyCppGame
//
//  Created by Xuhao on 16/9/2.
//
//

#include "MainScene.h"

USING_NS_CC;

//水果出现的最高点Y坐标差值
const int FRUITS_TOP_POINT = 40;

//水果刷新频率 20帧 ＊多少秒？？0.3秒？
const int FRUITS_REFRESH_RATE = 20;

Mainscene::Mainscene()
:_Kuma(nullptr)
{
    
}

Mainscene::~Mainscene()
{
    //把Player释放掉 ＊为什么只释放player？？？
    CC_SAFE_RELEASE_NULL(_Kuma);
    
}

Scene* Mainscene::creatScene()
{
    auto scene = Scene::create();
    auto layer = Mainscene::create();
    scene -> addChild(layer);
    
    return scene;

}

bool Mainscene::init()
{
    if(!Layer::init())
    {
        return false;
    }
    
    //创建背景
    auto director   = Director::getInstance();
    auto size       = director->getWinSize();
    auto background = Sprite::create("nonretina/background.png");
    background->setPosition(size.width/2.0, size.height/2.0);
    this->addChild(background);
    
    //创建角色（主角）
    this->setKuma(Sprite::create("nonretina/player.png"));
    _Kuma->setPosition(Point(size.width/2.0, size.height - 450));
    this->addChild(_Kuma);
    
    //创建触屏监听事件
    auto TouchEvent = EventListenerTouchOneByOne::create();
    
    //按下事件
    TouchEvent->onTouchBegan =
        [](Touch* touch, Event* event)
    {
        //log("Touch at x:%f, y:%f", touch->getLocation().x, touch->getLocation().y);
        return true;
    };
    
    //移动事件
    TouchEvent->onTouchMoved =
        [this, size](Touch* touch, Event* evnet)
    {
        
        //log("Delta is (%f,%f)",touch->getDelta().x,touch->getDelta().y);
        //获得偏移量
        Point Offset = touch->getDelta();
        
        //计算并设定新坐标
        /*
        Point Target = _Kuma->getPosition() + Offset;
    
        if( Target.x < size.width - 280 )
        {
            Target.x = size.width - 280;
        }
        else if ( Target.x > size.width - 40 )
        {
            Target.x = size.width - 40;
        }
        
        Target.y = _Kuma->getPosition().y;
        */
        
        //计算新坐标，取两点之间的区间
        Point Target = _Kuma->getPosition() + Offset;
        
        Target = Target.getClampPoint(Point(30, _Kuma->getPosition().y), Point(size.width - 30, _Kuma->getPosition().y));
        
        _Kuma->setPosition(Target);
        
    };
    
    //抬起事件
    TouchEvent->onTouchEnded =
        [](Touch* touch, Event* event)
    {
    
    };
    
    //将监听callback登陆到导演node里
    director->getEventDispatcher()->addEventListenerWithSceneGraphPriority(TouchEvent, this);
    
    //登录updata方法，在每一帧进行调用
    this->scheduleUpdate();
    
    return true;
}

Sprite* Mainscene::addFruits()
{
    auto size       = Director::getInstance()->getWinSize();
    
    //随机获取一个数字，范围是0～COUNT_MAX（最大水果数）
    int  Type       = rand() % static_cast<int>(FruitsType::COUNT_MAX);
    
    //根据获得的数字创建文件名，水果枚举列表需要和图片文件的序号对应
    std::string filename = StringUtils::format("nonretina/fruit%d.png",Type);
    auto fruits     = Sprite::create(filename);
    
    //设置Tag便于之后查找
    fruits->setTag(Type);
    
    //Y轴固定，X轴随机的方式放置水果
    auto fruitsXPoint    = rand() % static_cast<int>(size.width - 80);
    fruits->setPosition(Point(fruitsXPoint + 40, size.height - FRUITS_TOP_POINT));
    
    //把水果放到屏幕中，将屏幕中存在的水果保存至Fruits的仓库中
    this->addChild(fruits);
    _Fruits.pushBack(fruits);

    return fruits;
    
}

bool Mainscene::removeFruits(cocos2d::Sprite *fruits)
{
    //意图删除的对象是否存在于仓库中
    if(_Fruits.contains(fruits))
    {
        //YES
        //从父类中删除（从Scene中去除）
        fruits->removeFromParent();
        
        //从仓库中删除
        _Fruits.eraseObject(fruits);
        
        return true;
    }
    
    return false;
}

void Mainscene::update(float dt)
{
    int random = rand() % FRUITS_REFRESH_RATE;
    if(random == 0)
    {
        this->addFruits();
    }
}