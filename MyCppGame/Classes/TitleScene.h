//
//  TitleScene.h
//  MyCppGame
//
//  Created by Xuhao on 16/9/2.
//
//

#ifndef TitleScene_h
#define TitleScene_h

#include <stdio.h>
#include "cocos2d.h"
#include "MainScene.h"
#include "MenuItem.h"
#include "Menu.h"
#include "SimpleAudioEngine.h"

class TitleScene : public cocos2d::Layer
{
protected:
    
    //构造函数
    TitleScene();
    
    //析构函数
    virtual ~TitleScene();
    
    //初期化函数（重构父类的初期化）
    bool init() override;

public:
    
    //创建方法
    static cocos2d::Scene* creatScene();
    
    //利用创建的工厂方法来构造此类
    CREATE_FUNC(TitleScene);
    
    //画面更新 ＊dt是什么？？=>deltaTime =>单位为秒
    //函数名称updata不可以随便改动，因为需要使用scheduleUpdata方法进行登录
    void update(float dt);
    
private:
    
	//游戏开始(场景切换)
    //@para    无
    //@return  无
	void GameStart();
    
};



#endif /* TitleScene_h */
