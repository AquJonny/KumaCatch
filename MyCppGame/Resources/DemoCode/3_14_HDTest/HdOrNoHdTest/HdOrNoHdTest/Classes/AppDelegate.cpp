//
//  HdOrNoHdTestAppDelegate.cpp
//  HdOrNoHdTest
//
//  Created by Himi on 12-9-8.
//  Copyright __MyCompanyName__ 2012年. All rights reserved.
//

#include "AppDelegate.h"

#include "cocos2d.h"
#include "HelloWorldScene.h"

USING_NS_CC;

AppDelegate::AppDelegate()
{

}

AppDelegate::~AppDelegate()
{
}

bool AppDelegate::applicationDidFinishLaunching()
{
    // initialize director
    CCDirector *pDirector = CCDirector::sharedDirector();
    pDirector->setOpenGLView(CCEGLView::sharedOpenGLView());

    // enable High Resource Mode(2x, such as iphone4) and maintains low resource on other devices.
    pDirector->enableRetinaDisplay(true);
    
    
    TargetPlatform target = getTargetPlatform();//获取当前设备类型
    
    if (target == kTargetIpad){//如果是Ipad
        if (pDirector->enableRetinaDisplay(true)){ //如果开启高清视网膜
            CCFileUtils::sharedFileUtils()->setResourceDirectory("../ipadhd");
        }else {
            CCFileUtils::sharedFileUtils()->setResourceDirectory("../ipad");
        }
    }else if (target == kTargetIphone) {//如果是iphone
        if (pDirector->enableRetinaDisplay(true))
        {
            CCFileUtils::sharedFileUtils()->setResourceDirectory("../hd");
        }
    }
    // turn on display FPS
    pDirector->setDisplayStats(true);

    // set FPS. the default value is 1.0/60 if you don't call this
    pDirector->setAnimationInterval(1.0 / 60);

    // create a scene. it's an autorelease object
    CCScene *pScene = HelloWorld::scene();

    // run
    pDirector->runWithScene(pScene);

    return true;
}

// This function will be called when the app is inactive. When comes a phone call,it's be invoked too
void AppDelegate::applicationDidEnterBackground()
{
    CCDirector::sharedDirector()->pause();

    // if you use SimpleAudioEngine, it must be pause
    // SimpleAudioEngine::sharedEngine()->pauseBackgroundMusic();
}

// this function will be called when the app is active again
void AppDelegate::applicationWillEnterForeground()
{
    CCDirector::sharedDirector()->resume();
    
    // if you use SimpleAudioEngine, it must resume here
    // SimpleAudioEngine::sharedEngine()->resumeBackgroundMusic();
}
