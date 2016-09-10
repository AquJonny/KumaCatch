//
//  TitleScene.cpp
//  MyCppGame
//
//  Created by Xuhao on 16/9/9.
//
//

#include "TitleScene.h"

USING_NS_CC;

TitleScene::TitleScene()
{
    
}

TitleScene::~TitleScene()
{

}

Scene* TitleScene::creatScene()
{
    auto scene = Scene::create();
    auto layer = TitleScene::create();
    scene -> addChild(layer);
    
    return scene;

}

bool TitleScene::init()
{
    if(!Layer::init())
    {
        return false;
    }

	//添加标题画面背景
	auto size			 = Director::getInstance()->getWinSize();

	auto titleBackground = Sprite::create("nonretina/title_background.png");

	titleBackground->setPosition(size.width/2.0, size.height/2.0);
	
	this->addChild(titleBackground);
	
	//添加标题Logo
	auto Logo			 = Sprite::create("nonretina/title_logo.png");
	
	Logo->setPosition(size.width/2.0, size.height*0.75);
	
	this->addChild(Logo);
	
	//添加标题画面按钮
    auto StartButten	 = MenuItemImage::create("nonretina/title_start.png",
                                                 "nonretina/title_start.png",
                                                 CC_CALLBACK_1(TitleScene::GameStart, this));
	
	auto TitleMenu		 = Menu::create(StartButten, nullptr);
	
	TitleMenu->setPosition(size.width/2.0, size.height*0.2);
    
	this->addChild(TitleMenu);

	//添加标题画面背景音乐
	CocosDenshion::SimpleAudioEngine::getInstance()->playBackgroundMusic("bgm/wav/title.wav", true);
    
    CocosDenshion::SimpleAudioEngine::getInstance()->setBackgroundMusicVolume(0.5);
    
    return true;
}


void TitleScene::update(float dt)
{

}

void TitleScene::GameStart(Ref* pSender)
{
	auto scene = Mainscene::creatScene();	
	
	auto active = TransitionProgressRadialCCW::create(1.0f, scene);
	
	auto director = Director::getInstance();
	
	director->replaceScene(active);
}

