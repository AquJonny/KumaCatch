//
//  MainScene.cpp
//  MyCppGame
//
//  Created by Xuhao on 16/9/2.
//
//

#include "MainScene.h"

USING_NS_CC;

const int FRUITS_TOP_POINT = 40;

Mainscene::Mainscene()
:_Kuma(nullptr)
{
    
}

Mainscene::~Mainscene()
{

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
    
    return true;
}

Sprite* Mainscene::addFruits()
{
    auto size       = Director::getInstance()->getWinSize();
    int  Type       = rand() % static_cast<int>(FruitsType::COUNT_MAX);
    
    std::string filename = StringUtils::format("nonretina/fruit%d.png",Type);
    auto fruits     = Sprite::create(filename);
    
    fruits->setTag(Type);
    auto fruitsXPoint    = rand() % static_cast<int>(size.width);
    
    fruits->setPosition(Point(fruitsXPoint,size.height - FRUITS_TOP_POINT));
    
    this->addChild(fruits);
    
    _Fruits.pushBack(fruits);
    return fruits;
    
}
