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

//一局游戏的时间
const int GAME_TIME_SECOND = 10;

//UserDefault存取数据用Key
const char* HIGHSCORES = "highscroesKey";

//金苹果出现的基础概率
const float GOLDEN_PROBABILITY_BASE = 0.02;

//金苹果出现概率增加幅度
//增量式变化
const float GOLDEN_PROBABILITY_RATE = 0.005;

//炸弹出现的基础概率
const float BOMB_PROBABILITY_BASE   = 0.02;

//炸弹出现的概率增加幅度
const float BOMB_PROBABILITY_RATE   = 0.005;

//普通水果的数量
//意义何在?
const int   FRUITS_COUNT            = 5;

Mainscene::Mainscene()
:_Kuma(nullptr)
,_IsCrash(false)
,_Scores(0)
,_ScoresLabel(nullptr)
,_Time(GAME_TIME_SECOND)
,_TimeLabel(nullptr)
,_GameLayer(GameSTS::ready)
,_FruitsNode(nullptr)
,_HighScoresL(nullptr)
{
    //随机数初期化
    std::random_device rdev;
    _MTRand.seed(rdev());
}

Mainscene::~Mainscene()
{
    //把Player释放掉 ＊为什么只释放player？？？=>定义player时候调用了retain方法，为其计数＋1了
    CC_SAFE_RELEASE_NULL(_Kuma);
    CC_SAFE_RELEASE_NULL(_ScoresLabel);
    CC_SAFE_RELEASE_NULL(_TimeLabel);
    CC_SAFE_RELEASE_NULL(_FruitsNode);
    
	//释放 场景结束时候释放合适么???->游戏结束时候end
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
    
    //为角色添加动画
    //如何添加动画角色？？？SpriteCatch？SpriteNode？
    
    //创建容纳动画帧的容器
    cocos2d::Vector<SpriteFrame*>frames;
    
    //每一帧动画的尺寸，用于从一张图片中提取动画帧
    auto PlayerSizeW = 85;
    auto PlayerSizeH = 63;
    
    auto PlayerAnimeFrame = 3;
    for (int i = 0; i < PlayerAnimeFrame; i++)
    {
        //循环3次按照尺寸提取动画帧
        auto rect = Rect(PlayerSizeW * i, 0, PlayerSizeW, PlayerSizeH);
        
        auto frame = SpriteFrame::create("nonretina/player.png", rect);
        
        frames.pushBack(frame);
        
    }
    
    //使用动画帧创建动画，动画循环3次 也就是1秒
    auto anime = Animation::createWithSpriteFrames(frames, 20.0/60.0);
    anime->setLoops(3);
    
    //动画播放完成后恢复到最初画面，false为不恢复
    anime->setRestoreOriginalFrame(true);
    
    //创建animate对象
    auto action = Animate::create(anime);

    auto acRea  = RepeatForever::create(action);
    
    //运行动作
    _Kuma->runAction(acRea);
    
    //加载水果SpriteNode
    auto fruitSpriteNode = SpriteBatchNode::create("nonretina/fruits.png");
    this->addChild(fruitSpriteNode);
    this->setFruitsNode(fruitSpriteNode);
    
    TTFConfig ScroesTTF("Marker Felt.ttf", 20);
    
    //创建记分板(Lable)
    auto scroesLabel = Label::createWithTTF(ScroesTTF, "Scroes 0");
    //create方法的返回值是一个自动释放的文本对象。->因此需要set到_ScoresLable中?? 
    this->setScoresLabel(scroesLabel);
    _ScoresLabel->setPosition(Point(size.width*0.75, size.height - FRUITS_TOP_POINT/2));
    this->addChild(_ScoresLabel, 1);
    
    //创建计时器(Lable)
    auto timeLabel   = Label::createWithTTF(ScroesTTF, StringUtils::format("Time %d", (int)_Time));
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
        
        if( _GameLayer == GameSTS::game )
        {
            if( !getIsCrash() )
            {
                _Kuma->setPosition(Target);
        
            }
        }
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

void Mainscene::ReadyForGame()
{
    auto WinSize = Director::getInstance()->getWinSize();
    auto Center  = Point(WinSize.width/2.0, WinSize.height/2.0);
    
    //创建ready画面
    auto ready   = Sprite::create("nonretina/ready.png");
    ready->setPosition(Center);
    this->addChild(ready);
    
    //创建start画面
    auto start   = Sprite::create("nonretina/start.png");
    start->setScale(0.5);
    start->setPosition(Center);
    
    //创建start动画（扩大并渐隐，然后删除自己
    auto Scale   = Sequence::create(Spawn::create( ScaleTo::create(1.0, 5.0),
                                                   FadeOut::create(1.0),
                                                   nullptr),
                                    RemoveSelf::create(),
                                    nullptr);
    start->runAction(Scale);
    start->retain();
    
    //创建ready动画（渐隐渐现，调用start，删除自己
    auto blink   = Sequence::create(FadeTo::create(0.5, 150),
                                    FadeTo::create(0.5, 250),
                                    DelayTime::create(1),
                                    CallFunc::create([this, start]
                                                     {
                                                         this->addChild(start);
                                                         CocosDenshion::SimpleAudioEngine::getInstance()->setEffectsVolume(0.2);
                                                         CocosDenshion::SimpleAudioEngine::getInstance()->playEffect("se/wav/start.wav");
                                                         _GameLayer = GameSTS::game;
                                                         start->release();
                                                     }),
                                    RemoveSelf::create(),
                                    nullptr);
    
    ready->runAction(blink);
    
}

void Mainscene::FinishForGame()
{
    auto WinSize = Director::getInstance()->getWinSize();
    auto Center  = Point(WinSize.width/2.0, WinSize.height/2.0);
    
    auto Finish  = Sprite::create("nonretina/finish.png");
    Finish->setScale(0.1);
    Finish->setPosition(Center);
    
    auto Scale   = ScaleTo::create(1.0, 1);
    auto ScaleRe = ScaleTo::create(0.1, 1);
    auto Rotate  = RotateTo::create(1, 360);
    
    auto active  = Sequence::create(Spawn::create(Scale, Rotate, nullptr),
                                    DelayTime::create(1),
                                    Spawn::create(ScaleRe, Rotate, nullptr),
                                    CallFunc::create([this]
                                    {
                                        _GameLayer = GameSTS::result;
                                        Mainscene::GameResult();
                                    }),
                                    RemoveSelf::create(),
                                    nullptr);
    Finish->runAction(active);
    this->addChild(Finish);
}

Sprite* Mainscene::addFruits()
{

    auto size       = Director::getInstance()->getWinSize();
    
	//
	float rand = this->getRandom(0, 1);
    
    //随机获取一个数字，范围是0～COUNT_MAX（最大水果数）
    int  Type       = 0;
	float goldenP = GOLDEN_PROBABILITY_BASE + ( GOLDEN_PROBABILITY_RATE * ( GAME_TIME_SECOND - _Time ) );
	float bombP = BOMB_PROBABILITY_BASE + ( BOMB_PROBABILITY_RATE * ( GAME_TIME_SECOND - _Time ) );

	if( rand < goldenP )
	{
		//概率小于金苹果时候,掉落金苹果
		Type = FruitsType::GOLDEN;
	}
	else if( rand < (goldenP+bombP) )
	{
		//概率小于炸弹高于金苹果时候,掉落金苹果
		Type = FruitsType::BOMB;
	}
	else
	{
		//其余时候随机产生普通水果
		Type = (int)this->getRandom(0, FRUITS_COUNT-1);
	}

    //根据获得的数字创建文件名，水果枚举列表需要和图片文件的序号对应
    //std::string filename = StringUtils::format("nonretina/fruit%d.png",Type);
    //auto fruits     = Sprite::create(filename);
    
    //从载入的图片集中取出水果的图片
    auto fruitW     = (_FruitsNode->getTextureAtlas()->getTexture()->getContentSize().width)
                        /static_cast<int>(FruitsType::COUNT_MAX);
    auto fruitH     = _FruitsNode->getTextureAtlas()->getTexture()->getContentSize().height;
    
    auto fruits     = Sprite::create("nonretina/fruits.png", Rect(fruitW * Type, 0, fruitW, fruitH));
    
    //设置Tag便于之后查找
    fruits->setTag(Type);
    
    //Y轴固定，X轴随机的方式放置水果
    auto fruitsXPoint    = rand() % static_cast<int>(size.width - ( ACTIVE_ENABLE_OFFSET * 2 ));
    fruits->setPosition(Point(fruitsXPoint + ACTIVE_ENABLE_OFFSET, size.height - FRUITS_TOP_POINT));

    //把水果放到屏幕中，将屏幕中存在的水果保存至Fruits的仓库中
    //this->addChild(fruits);
    
    //为何要在Node集里面addchild？
    //因为_FritsNode是this的Child
    _FruitsNode->addChild(fruits);
    _Fruits.pushBack(fruits);
    
	//水果的移动和动作的追加
	//出现后等待0.5秒
    fruits->setScale(0);
    auto delay     = ScaleTo::create(0.5, 1);
    //DelayTime::create(1.0f);
	
	//3秒内掉落至指定坐标
	auto move      = MoveTo::create(2.0f, Point(fruitsXPoint + ACTIVE_ENABLE_OFFSET, (0)));
	
	//每秒旋转360度
	auto rotate    = RotateTo::create(2.0f, 1080);
	
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
    if( _GameLayer == GameSTS::game )
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
                if( !getIsCrash() )
                {
                    this->catchFruits(fruit);
            
                }
            }
        
        }
    
        _Time = _Time - dt;
        
        _TimeLabel->setString(StringUtils::format("Time  %d", (int)_Time));
    
        if( _Time < 0 )
        {
            _GameLayer = GameSTS::finish ;
            
            //添加音效
            CocosDenshion::SimpleAudioEngine::getInstance()->playEffect("se/wav/finish.wav");
            
            Mainscene::FinishForGame();
        }
    }
}

bool Mainscene::catchFruits(cocos2d::Sprite *fruits)
{
    auto AudioEngine = CocosDenshion::SimpleAudioEngine::getInstance();
    
    auto Type   = static_cast<FruitsType>(fruits->getTag());
    
    switch (Type) {
        case Mainscene::FruitsType::GOLDEN:
            _Scores = _Scores + 5;
            AudioEngine->playEffect("se/wav/catch_golden.wav");
            break;
        
        case Mainscene::FruitsType::BOMB:
            AudioEngine->playEffect("se/wav/catch_bomb.wav");
            Mainscene::CatchBoom();
            AudioEngine->playEffect("se/wav/crash.wav");
            break;
            
        default:
            _Scores = _Scores + 1;
            AudioEngine->playEffect("se/wav/catch_fruit.wav");
            
            break;
    }

    
    _ScoresLabel->setString(StringUtils::format("Scroes %d", _Scores));
    
    this->removeFruits(fruits);
    
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

    auto MenuScore  = MenuItemFont::create(StringUtils::format("Scroes %d", _Scores));
	
    auto HighScore  = UserDefault::getInstance()->getIntegerForKey(HIGHSCORES, 0);
    
    if( _Scores > HighScore )
    {
        HighScore = _Scores;
        UserDefault::getInstance()->setIntegerForKey(HIGHSCORES, HighScore);
    }
    
	auto MenuScoreH = MenuItemFont::create(StringUtils::format("Best Scroes %d", HighScore));
	
    auto MenuUp     = Menu::create(MenuScore, MenuScoreH, nullptr);
	
    MenuUp->setPosition(Point(size.width/2, size.height*0.6));
    
    MenuUp->alignItemsVerticallyWithPadding(20);
    
	this->addChild(MenuUp);
    
    auto MenuRetry = MenuItemImage::create("nonretina/replay_button.png",
                                           "nonretina/replay_button_pressed.png",
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

void Mainscene::onEnterTransitionDidFinish()
{
    
    Layer::onEnterTransitionDidFinish();
    
    //添加背景音乐并循环
    //sharedEngine是什么意思?virtual类别的函数是什么意思?
    CocosDenshion::SimpleAudioEngine::getInstance()->playBackgroundMusic("bgm/wav/main.wav", true);
    
    CocosDenshion::SimpleAudioEngine::getInstance()->setBackgroundMusicVolume(0.2);

    Mainscene::ReadyForGame();
    
}

void Mainscene::CatchBoom()
{
    _IsCrash = true;
    
    cocos2d::Vector<SpriteFrame*>frames;
    
    auto PlayerSizeW = 85;
    auto PlayerSizeH = 63;
    
    auto PlayerAnimeFrame = 3;
    for (int i = 0; i < PlayerAnimeFrame; i++)
    {
        auto rect = Rect(PlayerSizeW * i, 0, PlayerSizeW, PlayerSizeH);
        
        auto frame = SpriteFrame::create("nonretina/player_crash.png", rect);
        
        frames.pushBack(frame);
        
    }
    
    auto anime = Animation::createWithSpriteFrames(frames, 20.0/60.0);
    anime->setLoops(3);
    
    
    anime->setRestoreOriginalFrame(true);
    
    auto action = Animate::create(anime);
    
    _Kuma->runAction(Sequence::create(action,CallFunc::create([this]{ _IsCrash = false; }), nullptr));

}

float Mainscene::getRandom(float min, float max)
{
    float random = 0;
    
    std::uniform_real_distribution<float> dest(min, max);
    
    random = dest(_MTRand);
    
    return random;
}