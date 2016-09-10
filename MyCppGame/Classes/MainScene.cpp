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
:_Kuma(nullptr),
_Scores(0),
_ScoresLabel(nullptr),
_Time(10),
_TimeLabel(nullptr),
_GameLayer(GameSTS::title)
{
    
}

Mainscene::~Mainscene()
{
    //把Player释放掉 ＊为什么只释放player？？？=>定义player时候调用了retain方法，为其计数＋1了
    CC_SAFE_RELEASE_NULL(_Kuma);
    CC_SAFE_RELEASE_NULL(_ScoresLabel);
    CC_SAFE_RELEASE_NULL(_TimeLabel);
    
	//释放 场景结束时候释放合适么???
	//SimpleAudioEngine::sharedEngine()->end();
    //CocosDenshion::SimpleAudioEngine::end();
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
    
    TTFConfig ScroesTTF("Marker Felt.ttf", 20);
    
    //创建记分板(Lable)
    auto scroesLabel = Label::createWithTTF(ScroesTTF, "Scroes 0");
    //create方法的返回值是一个自动释放的文本对象。->因此需要set到_ScoresLable中?? 
    this->setScoresLabel(scroesLabel);
    _ScoresLabel->setPosition(Point(size.width*0.75, size.height - FRUITS_TOP_POINT/2));
    this->addChild(_ScoresLabel, 1);
    
    //创建计时器(Lable)
    auto timeLabel   = Label::createWithTTF(ScroesTTF, "Time  60");
    this->setTimeLabel(timeLabel);
    _TimeLabel->setPosition(Point(size.width*0.25, size.height - FRUITS_TOP_POINT/2));
    this->addChild(_TimeLabel, 1);
    
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
    
    _GameLayer = GameSTS::game;
    
    //登录updata方法，在每一帧进行调用
    this->scheduleUpdate();

    //添加背景音乐并循环
    //sharedEngine是什么意思?virtual类别的函数是什么意思?
    CocosDenshion::SimpleAudioEngine::getInstance()->playBackgroundMusic("bgm/wav/main.wav", true);
    
    CocosDenshion::SimpleAudioEngine::getInstance()->setBackgroundMusicVolume(0.5);
    
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
	auto move      = MoveTo::create(3.0f, Point(fruitsXPoint + ACTIVE_ENABLE_OFFSET, (0)));
	
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

    if(_GameLayer == GameSTS::game)
    {
        //随机添加水果
        int random = rand() % FRUITS_REFRESH_RATE;
        if(random == 0)
        {
            this->addFruits();
        }
        
        
        for( cocos2d::Sprite* fruit : _Fruits )
        {
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
                this->removeFruits(fruit);
            }
            
            //判断Kuma的坐标是否在水果的范围内（是否接到水果）
            if( fruitBox.containsPoint(kumaP) )
            {
                this->catchFruits(fruit);
            }
        
        }
    
        _Time = _Time - dt;
        
        _TimeLabel->setString(StringUtils::format("Time  %d", (int)_Time));
    
        if( _Time < 0 )
        {
            _GameLayer = GameSTS::result;
            
            //添加音效
            CocosDenshion::SimpleAudioEngine::getInstance()->playEffect("se/wav/finish.wav");
            
            this->GameResult();
        }
    }
}

bool Mainscene::catchFruits(cocos2d::Sprite *fruits)
{
    this->removeFruits(fruits);
    
    _Scores = _Scores + 1;
    
    _ScoresLabel->setString(StringUtils::format("Scroes %d", _Scores));
    
    return true;
}

void Mainscene::GameRestart(Ref* pSender)
{
    
    auto scene = Mainscene::creatScene();
    
    auto active = TransitionCrossFade::create(0.5f, scene);
    
    auto director = Director::getInstance();
    
    director->replaceScene(active);
    
}

void Mainscene::ShowTitle(Ref* pSender)
{
    
    auto scene = TitleScene::creatScene();
    
    auto active = TransitionProgressRadialCCW::create(0.5f, scene);
    
    auto director = Director::getInstance();
    
    director->replaceScene(active);
    
}

void Mainscene::GameResult()
{
	auto size       = Director::getInstance()->getWinSize();

    //添加背景音乐并循环
    //sharedEngine是什么意思?virtual类别的函数是什么意思?
    CocosDenshion::SimpleAudioEngine::getInstance()->playBackgroundMusic("bgm/wav/result.wav", true);
    
    CocosDenshion::SimpleAudioEngine::getInstance()->setBackgroundMusicVolume(0.5);

    auto MenuTitle = MenuItemFont::create("Finish");
	
	auto MenuLabel = MenuItemFont::create(StringUtils::format("Scroes %d", _Scores));
	
    auto MenuUp    = Menu::create(MenuTitle, MenuLabel, nullptr);
	
    MenuUp->setPosition(Point(size.width/2, size.height*0.6));
    
    MenuUp->alignItemsVerticallyWithPadding(20);
    
	this->addChild(MenuUp);
    
    auto MenuRetry = MenuItemImage::create("nonretina/replay_button.png",
                                           "nonretina/replya_botton_pressed.png",
                                           CC_CALLBACK_1(Mainscene::GameRestart, this));
    
    //MenuItemImage::create( "nonretina/replay_button.png", "nonretina/replay_button_pressed.png", CC_CALLBACK_1( Mainscene::GameRestart, this) );

    MenuRetry->setAnchorPoint(Point(0.6, 0.5));
	
	MenuRetry->setPosition(Point(size.width/2, size.height*0.3));
	
	auto MenuExit  = MenuItemImage::create( "nonretina/title_button.png", 
											"nonretina/title_button_pressed.png", 
                                           CC_CALLBACK_1( Mainscene::ShowTitle, this) );
    
	MenuExit->setAnchorPoint(Point(0.4, 0.5));

	MenuExit->setPosition(size.width/2, size.height*0.2);

	auto MenuDown  = Menu::create(MenuRetry, MenuExit, nullptr);

    MenuDown->alignItemsVerticallyWithPadding(20);
    
    MenuDown->setPosition(Point(size.width/2, size.height*0.3));
    
	this->addChild(MenuDown);

}



