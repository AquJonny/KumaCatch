#include "HelloWorldScene.h"
#include "SimpleAudioEngine.h"

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
    //开启多触点监听务必调用此函数
    setTouchEnabled(true);
    
    CCSprite * sp1 = CCSprite::create("Icon.png");
    sp1->setColor(ccc3(255, 255, 0));//便于区分
    CCSprite * sp2 = CCSprite::create("Icon.png"); 
    sp1->setPosition(ccp(150,100));
    sp2->setPosition(ccp(150,200)); 
    addChild(sp1,0,91);
    addChild(sp2,0,92);
    
    return true;
}

//注册多触点的委托监听
void HelloWorld::registerWithTouchDispatcher(void){
    CCDirector::sharedDirector()->getTouchDispatcher()->addStandardDelegate(this, 0);
}

//用户手指第一次触碰
void HelloWorld::ccTouchesBegan(CCSet *pTouches, CCEvent *pEvent){
    CCSetIterator iter = pTouches->begin();
    for (; iter != pTouches->end(); iter++)
    {
        CCTouch* pTouch = (CCTouch*)(*iter);
        CCPoint location = pTouch->getLocation();
        if(pTouch->getID()==0){//第一个触点
            CCSprite * sp1 = (CCSprite*)this->getChildByTag(91);
            sp1->setPosition(location);            
        }else if(pTouch->getID()==1){//第二个触点
            CCSprite * sp2= (CCSprite*)this->getChildByTag(92);
            sp2->setPosition(location);
        }
    }
}
//用户手指进行移动或者拖拽
void HelloWorld::ccTouchesMoved(CCSet *pTouches, CCEvent *pEvent){
    CCSetIterator iter = pTouches->begin();
    for (; iter != pTouches->end(); iter++)
    {
        CCTouch* pTouch = (CCTouch*)(*iter);
        CCPoint location = pTouch->getLocation();
        if(pTouch->getID()==0){//第一个触点
            CCSprite * sp1 = (CCSprite*)this->getChildByTag(91);
            sp1->setPosition(location);
        }else if(pTouch->getID()==1){//第二个触点
            CCSprite * sp2= (CCSprite*)this->getChildByTag(92);
            sp2->setPosition(location);
        }
    }
}
//用户手指抬起
void HelloWorld::ccTouchesEnded(CCSet *pTouches, CCEvent *pEvent){
    CCSetIterator iter = pTouches->begin();
    for (; iter != pTouches->end(); iter++)
    {
        CCTouch* pTouch = (CCTouch*)(*iter);
        CCPoint location = pTouch->getLocation();
         CCLOG("pTouch  触摸点 %i 的坐标: x:%f,y:%f",pTouch->getID(),location.x,location.y);
    }
}

//删除多触点的委托监听
void HelloWorld::onExit(){
    CCDirector::sharedDirector()->getTouchDispatcher()->removeDelegate(this);
    CCLayer::onExit();
}







































