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
    
    //getKuma(),setKuma()方法声明 ＊追加retain处理
    CC_SYNTHESIZE_RETAIN(cocos2d::Sprite*, _Kuma, Kuma);

    //getFruits(),setFruits()方法声明 ＊没有retain处理，主处理结束后被release！！！
    CC_SYNTHESIZE(cocos2d::Vector<cocos2d::Sprite* >, _Fruits, Fruits);
    
    //画面更新 ＊dt是什么？？=>deltaTime
    //函数名称updata不可以随便改动，因为需要使用scheduleUpdata方法进行登录
    void update(float dt);
    
private:
    
    enum class FruitsType
    {
        APPLE,      //リンゴ
        GRAPE,      //ブドウ
        ORANGE,     //オレンジ
        BANANA,     //バナナ
        CHERRY,     //さくらんぼ
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
    
};



#endif /* MainScene_h */
