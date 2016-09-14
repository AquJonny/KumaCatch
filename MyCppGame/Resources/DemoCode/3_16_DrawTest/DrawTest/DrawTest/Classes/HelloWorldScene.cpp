#include "HelloWorldScene.h"
#include "SimpleAudioEngine.h"

using namespace cocos2d;
using namespace CocosDenshion;

CCScene* HelloWorld::scene()
{ 
    CCScene *scene = CCScene::create();
     
    HelloWorld *layer = HelloWorld::create();
 
    scene->addChild(layer); 
    return scene;
}
 
bool HelloWorld::init()
{
    if ( !CCLayer::init() )
    {
        return false;
    }
    
    return true;
}

void HelloWorld::draw(){
    CCSize s = CCDirector::sharedDirector()->getWinSize();
    //设置颜色
    ccDrawColor4B(255,0,0,255);
    //设置线的宽度
    glLineWidth(2);
    //绘制一条直线
    ccDrawLine( ccp(0, 0), ccp(s.width*0.5, s.height*0.5) );
    
    ccDrawColor4B(255,255,0,0);
    //设置像素尺寸
    ccPointSize(30);
    //绘制一个点
    ccDrawPoint( ccp(s.width*0.5, s.height *0.5) );
    
    ccDrawColor4B(0,0,255,0);
    //绘制圆形
    ccDrawCircle( ccp(s.width/2, s.height/2), 50, CC_DEGREES_TO_RADIANS(90), 50, false);
    ccDrawCircle( ccp(s.width/2, s.height/2), 50, CC_DEGREES_TO_RADIANS(45), 6, false);
    
    ccDrawColor4B(0, 255, 255, 255);
    glLineWidth(5);
    //绘制多边形
    CCPoint vertices[] = { ccp(70,150), ccp(150,150), ccp(150,200),ccp(190,300)  };
    ccDrawPoly( vertices, 4, true);
    
    ccDrawColor4B(255, 0, 255, 255);
    //绘制填充的多边形
    CCPoint filledVertices[] = { ccp(0,120), ccp(50,120), ccp(50,170), ccp(25,200), ccp(0,170) };
	ccDrawSolidPoly(filledVertices, 5, ccc4f(0.5f, 0.5f, 1, 1 ) );
//    ccDrawPoly(<#const cocos2d::CCPoint *vertices#>, <#unsigned int numOfVertices#>, <#bool closePolygon#>)
    
    //绘制贝塞尔曲线
    ccDrawQuadBezier(ccp(0,s.height), ccp(s.width/2,s.height/2), ccp(s.width,s.height), 50);
    
    //绘制立体的贝塞尔曲线
    // draw cubic bezier path
    ccDrawCubicBezier(ccp(s.width/2, s.height/2), ccp(s.width/2+30,s.height/2+50), ccp(s.width/2+60,s.height/2-50),ccp(s.width, s.height/2),100);
    
    //绘制填充举行
    ccDrawSolidRect(ccp(240,50), ccp(300,10), ccc4f(255, 177, 177, 255));
    //绘制空心矩形
//    ccDrawRect(<#cocos2d::CCPoint origin#>, <#cocos2d::CCPoint destination#>)
    
}
