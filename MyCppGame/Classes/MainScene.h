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
    cocos2d::Sprite* addFruits();
    
};



#endif /* MainScene_h */
