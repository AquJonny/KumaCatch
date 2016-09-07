#include "AppDelegate.h"
//#include "HelloWorldScene.h"
#include "MainScene.h"

USING_NS_CC;

//Landscape
static cocos2d::Size designResolutionSizeL = cocos2d::Size(480, 320);
static cocos2d::Size smallResolutionSizeL = cocos2d::Size(480, 320);
static cocos2d::Size mediumResolutionSizeL = cocos2d::Size(1024, 768);
static cocos2d::Size largeResolutionSizeL = cocos2d::Size(2048, 1536);

//Portait
static cocos2d::Size designResolutionSizeP = cocos2d::Size(320, 480);
static cocos2d::Size smallResolutionSizeP = cocos2d::Size(320, 480);
static cocos2d::Size mediumResolutionSizeP = cocos2d::Size(768, 1024);
static cocos2d::Size largeResolutionSizeP = cocos2d::Size(1536, 2048);



AppDelegate::AppDelegate()
{
}

AppDelegate::~AppDelegate() 
{
}

// if you want a different context, modify the value of glContextAttrs
// it will affect all platforms
void AppDelegate::initGLContextAttrs()
{
    // set OpenGL context attributes: red,green,blue,alpha,depth,stencil
    GLContextAttrs glContextAttrs = {8, 8, 8, 8, 24, 8};

    GLView::setGLContextAttrs(glContextAttrs);
}

// if you want to use the package manager to install more packages,  
// don't modify or remove this function
static int register_all_packages()
{
    return 0; //flag for packages manager
}

bool AppDelegate::applicationDidFinishLaunching() {
    // initialize director
    auto director = Director::getInstance();

    auto glview = director->getOpenGLView();

    if(!glview) {
#if (CC_TARGET_PLATFORM == CC_PLATFORM_WIN32) || (CC_TARGET_PLATFORM == CC_PLATFORM_MAC) || (CC_TARGET_PLATFORM == CC_PLATFORM_LINUX)
        glview = GLViewImpl::createWithRect("MyCppGame", cocos2d::Rect(0, 0, designResolutionSizeP.width, designResolutionSizeP.height));
#else
        glview = GLViewImpl::create("MyCppGame");
#endif
        director->setOpenGLView(glview);
    }

    //添加搜索用文件夹路径
    FileUtils::getInstance()->addSearchPath("fonts");
    FileUtils::getInstance()->addSearchPath("images");
    FileUtils::getInstance()->addSearchPath("bgm");
    FileUtils::getInstance()->addSearchPath("se");
    
    // turn on display FPS
    // 开关帧数显示等Debug信息
    director->setDisplayStats(true);
    //director->setDisplayStats(false);
    
    // set FPS. the default value is 1.0/60 if you don't call this
    director->setAnimationInterval(1.0f / 60);

    // Set the design resolution
    glview->setDesignResolutionSize(designResolutionSizeP.width, designResolutionSizeP.height, ResolutionPolicy::SHOW_ALL);
    //1）EXACT_FIT 整个游戏内容都会在屏幕内可见，并且不用提供比例系数。x,y会被拉伸，使内容铺满屏幕，所以可能会出现形变，所有的应用程序看起来可能会是拉伸或者压缩的。
    //2）NO_BORDER 一个方向铺满屏幕，另外一个方向超出屏幕，不会变形，但是可能有一些裁剪。
    //3）SHOW_ALL 该模式会尽可能按原始宽高比放大游戏世界，同时使得游戏内容全部可见。内容不会形变，不过可能会出现两条黑边，即屏幕中会有留白。
    //4）IXED_WIDTH 该模式会横向放大游戏世界内的内容以适应屏幕的宽度，纵向按原始宽高比放大。
    //5）FIXED_HEIGHT 与上一中模式相反。
    
/*
    auto frameSize = glview->getFrameSize();
    // if the frame's height is larger than the height of medium size.
    if (frameSize.height > mediumResolutionSize.height)
    {        
        director->setContentScaleFactor(MIN(largeResolutionSize.height/designResolutionSize.height, largeResolutionSize.width/designResolutionSize.width));
    }
    // if the frame's height is larger than the height of small size.
    else if (frameSize.height > smallResolutionSize.height)
    {        
        director->setContentScaleFactor(MIN(mediumResolutionSize.height/designResolutionSize.height, mediumResolutionSize.width/designResolutionSize.width));
    }
    // if the frame's height is smaller than the height of medium size.
    else
    {        
        director->setContentScaleFactor(MIN(smallResolutionSize.height/designResolutionSize.height, smallResolutionSize.width/designResolutionSize.width));
    }

    register_all_packages();
*/
    // create a scene. it's an autorelease object
    // 创建一个主画面并加载
    //auto scene = HelloWorld::createScene();
    auto scene = Mainscene::creatScene();
    
    // run
    director->runWithScene(scene);

    return true;
}

// This function will be called when the app is inactive. Note, when receiving a phone call it is invoked.
void AppDelegate::applicationDidEnterBackground() {
    Director::getInstance()->stopAnimation();

    // if you use SimpleAudioEngine, it must be paused
    // SimpleAudioEngine::getInstance()->pauseBackgroundMusic();
}

// this function will be called when the app is active again
void AppDelegate::applicationWillEnterForeground() {
    Director::getInstance()->startAnimation();

    // if you use SimpleAudioEngine, it must resume here
    // SimpleAudioEngine::getInstance()->resumeBackgroundMusic();
}
