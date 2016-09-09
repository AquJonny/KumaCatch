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
	
	this->addchild(titleBackground);
	
	//添加标题Logo
	auto Logo			 = Sprite::create("nonretina/title_logo.png");
	
	Logo->setPosition(size.width/2.0, size.height*0.75);
	
	this->addchild(Logo);
	
	//添加标题画面按钮
	auto StartButten	 = MenuItemImage::create("nonretina/title_start.png",GameStart);
	
	StartButten->setPosition(size.width/2.0, size.height*0.2);
	
	auto TitleMenu		 = Menu::create(StartButten, Null);
	
	this->addchild(TitleMenu);

	//添加标题画面背景音乐
	SimpleAudioEngine::sharedEngine()->playBackgroundMusic("bgm/wav/title.wav", true);

    return true;
}


void TitleScene::update(float dt)
{

}

void TitleSecen::GameStart()
{
	auto scene = Mainscene::creatScene();	
	
	auto active = TransitionProgressRadialCCW::create(1.0f, scene);
	
	auto director = Director::getInstance();
	
	director->repleceScene(active);
}

