//
//  MainScene.h
//  MyCppGame
//
//  Created by Xuhao on 16/9/2.
//
//

#ifndef MainScene_h
#define MainScene_h

#include <stdio.h>
#include "cocos2d.h"
#include <random>
#include "TitleScene.h"
#include "Menu.h"
//#include "MenuItem.h"
#include "SimpleAudioEngine.h"

class Mainscene : public cocos2d::Layer
{
protected:
    
    //构造函数
    Mainscene();
    
    //析构函数
    virtual ~Mainscene();
    
    //初期化函数（重构父类的初期化）
    bool init() override;

public:
    
    //创建方法
    static cocos2d::Scene* creatScene();
    
    //利用创建的工厂方法来构造此类
    CREATE_FUNC(Mainscene);

    //Get a random between min to max
    float getRandom(float min, float max);
    
    enum class GameSTS
    {
        title,      //标题
        ready,      //游戏开始前
        game,       //游戏中
        finish,     //游戏结束
        result,     //结果显示
        setting,    //设定
        
        COUNT_MAX   //最大值
        
    };
    
    //getKuma(),setKuma()方法声明 ＊追加retain处理
    CC_SYNTHESIZE_RETAIN(cocos2d::Sprite*, _Kuma, Kuma);
    
    //创建用于显示分数的Label
    CC_SYNTHESIZE_RETAIN(cocos2d::Label*, _ScoresLabel, ScoresLabel);

    //创建用于显示高分的Label
    CC_SYNTHESIZE_RETAIN(cocos2d::Label*, _HighScoresL, HighScoresL);
    
	//创建用于显示时间的Label
	CC_SYNTHESIZE_RETAIN(cocos2d::Label*, _TimeLabel, TimeLabel);
    
    //创建用于存放SpriteNode的节点
    CC_SYNTHESIZE_RETAIN(cocos2d::SpriteBatchNode*, _FruitsNode, FruitsNode);
    
    //getFruits(),setFruits()方法声明 ＊没有retain处理，主处理结束后被release！！！
    //cocos2d::Vector<T> 并不是 cocos2d::Object 的子类，
    //所以不要像使用其他cocos2d类一样来用retain/release和引用计数内存管理。
    //创建用于存放复数个水果对象的容器(Pool)，全局
    CC_SYNTHESIZE(cocos2d::Vector<cocos2d::Sprite* >, _Fruits, Fruits);
    
    //创建显示用分数变量，全局
    CC_SYNTHESIZE(int, _Scores, Scoress);
    
    //创建显示用时间变量,全局
    CC_SYNTHESIZE(float, _Time, Time);
    
    //创建管理用状态寄存器（画面状态&游戏状态）
    CC_SYNTHESIZE(GameSTS, _GameLayer, GameLayer);
    
    //增加Flag用于标志角色是否被炸弹眩晕
    CC_SYNTHESIZE(bool, _IsCrash, IsCrash);
    
    CC_SYNTHESIZE(std::mt19937, _MTRand, MTRand);
    
    //画面更新 ＊dt是什么？？=>deltaTime =>单位为秒（例如：0.3123秒）
    //函数名称updata不可以随便改动，因为需要使用scheduleUpdata方法进行登录
    void update(float dt);
    
    //场景载入完成时候调用一次的方法
    void onEnterTransitionDidFinish() override;
    
private:
    
    //添加准备画面方法
    //@para    无
    //@return  无
    void ReadyForGame();
    
    //添加结束画面方法
    //@para    无
    //@return  无
    void FinishForGame();
    
    enum class FruitsType
    {
        APPLE,      //リンゴ
        GRAPE,      //ブドウ
        ORANGE,     //オレンジ
        BANANA,     //バナナ
        CHERRY,     //さくらんぼ
        
        GOLDEN,     //黄金のリンゴ
        BOMB,       //爆弾
        
        COUNT_MAX   //最大値
    };
    
    //水果添加方法
    //@para    无
    //@return  创建之后的对象（水果）
    cocos2d::Sprite* addFruits();
    
    //水果消除方法
    //@para    需要消除的对象（水果）
    //@return  是否消除成功
    bool removeFruits(cocos2d::Sprite* fruits);
    
    //接住水果方法
    //@para    接住的对象（水果）
    //@return  是否处理成功
    bool catchFruits(cocos2d::Sprite* fruits);
    
    //接住水果方法
    //@para    无
    //@return  无
    void GameResult();
    
    //游戏重开
    //@para    无
    //@return  无
    void GameRestart(Ref* pSender);
    
    //返回标题
    //@para    无
    //@return  无
    void ShowTitle(Ref* pSender);

    //接住炸弹后的特殊处理方法
    //@para    无
    //@return  无
    void CatchBoom();
};



#endif /* MainScene_h */
