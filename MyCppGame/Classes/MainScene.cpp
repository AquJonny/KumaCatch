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

//角色&水果的可活动范围偏移量(角色图的二分之一宽度)(单位:像素)
const int ACTIVE_ENABLE_OFFSET = 30;


Mainscene::Mainscene()
:_Kuma(nullptr)
{
    
}

Mainscene::~Mainscene()
{
    //把Player释放掉 ＊为什么只释放player？？？=>定义player时候调用了retain方法，为其计数＋1了
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
        
        Target = Target.getClampPoint(Point(ACTIVE_ENABLE_OFFSET, _Kuma->getPosition().y), Point(size.width - ACTIVE_ENABLE_OFFSET, _Kuma->getPosition().y));
        
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
    auto fruitsXPoint    = rand() % static_cast<int>(size.width - ( ACTIVE_ENABLE_OFFSET * 2 ));
    fruits->setPosition(Point(fruitsXPoint + ACTIVE_ENABLE_OFFSET, size.height - FRUITS_TOP_POINT));

    //把水果放到屏幕中，将屏幕中存在的水果保存至Fruits的仓库中
    this->addChild(fruits);
    _Fruits.pushBack(fruits);
    
	//水果的移动和动作的追加
	//出现后等待3秒
	auto delay     = DelayTime::create(3.0f);
	
	//3秒内掉落至指定坐标
	auto move      = MoveTo::create(3.0f, Point(fruitsXPoint, (0 /*- ACTIVE_ENABLE_OFFSET*/)));
	
	//每秒旋转360度
	auto rotate    = RotateTo::create(3.0f, 1080);
	
	//循环旋转
	//auto rotateRepeat = RepeatForever::create(rotate);
    //循环方法的参数必须是Action，rotate的类型是Rotate＊
    
	//旋转与下落同时进行
	auto dropAction   = Spawn::create(move, rotate, nullptr);

    //落出画面后消除
    //auto remove       = CallFuncN::create([this](Node* node){
    //                    auto sprite = dynamic_cast<Sprite*>(node);
    //                    this->removeFruits(sprite);
    //                    });
    
	//按照:等待3秒->下落并旋转 的顺序进行动作
	auto active       = Sequence::create(delay, dropAction, NULL);
	
	fruits->runAction(active);

    


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
	//是否删除水果
	//bool removeEnable = false;
	
	//随机添加水果
    int random = rand() % FRUITS_REFRESH_RATE;
    if(random == 0)
    {
        this->addFruits();
    }
    

    for( cocos2d::Sprite* fruit : _Fruits )
    {
        //是否删除水果
        bool removeEnable = false;
    	
        //获取水果的坐标
		//auto fruitsX = fruit->getPositionX();
		auto fruitsY = fruit->getPositionY();
        //获取熊的坐标
        Point kumaP    = _Kuma->getPosition();
        //获取水果图片区域信息
        Rect fruitBox  = fruit->getBoundingBox();
        
		//判断水果是否被熊接到(坐标区域碰撞)
		//判断水果是否掉地(下落出屏幕)
		/*
        if( fruitsY > (kumaY - ACTIVE_ENABLE_OFFSET) &&
			fruitsY < (kumaY + ACTIVE_ENABLE_OFFSET) )
		{
			if( fruitsX > (kumaX - ACTIVE_ENABLE_OFFSET) &&
				fruitsX < (kumaX + ACTIVE_ENABLE_OFFSET) )
			{
				removeEnable = true;
			}
		}
         */
		//判断水果是否落地
        if( fruitsY <= 0 )
		{
			removeEnable = true;
		}
		
        //判断Kuma的坐标是否在水果的范围内（是否接到水果）
        if( fruitBox.containsPoint(kumaP) )
        {
            removeEnable = true;
        }
        
		//删除水果
		if( removeEnable == true )
		{
	        this->removeFruits(fruit);
		}
	}
    
}

bool Mainscene::catchFruits(cocos2d::Sprite *fruits)
{
    this->removeFruits(fruits);
    
    
    
    return true;
}