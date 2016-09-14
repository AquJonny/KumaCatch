//
//  HRocker.cpp
//  GameRockerTest
//
//  Created by Himi on 12-9-24.
//
//

#include "HRocker.h"

HRocker* HRocker::createHRocker(const char* rockerImageName,const char* rockerBGImageName,CCPoint position){
    HRocker *layer = HRocker::create();
    if(layer){
        layer->rockerInit(rockerImageName, rockerBGImageName,position);
        return layer;
    }
    CC_SAFE_DELETE(layer);
    return NULL;
}

void HRocker::rockerInit(const char* rockerImageName,const char* rockerBGImageName,CCPoint position){
    
    CCSprite * spRockerBG = CCSprite::create(rockerBGImageName);
    spRockerBG->setPosition(position);
    spRockerBG->setVisible(false);
    addChild(spRockerBG,0,tag_rockerBG);
    
    CCSprite * spRocker = CCSprite::create(rockerImageName);
    spRocker->setPosition(position);
    spRocker->setVisible(false);
    addChild(spRocker,1,tag_rocker);
    
    rockerBGPosition = position;
    
    rockerBGR= spRockerBG->getContentSize().width*0.5;
}

//启动对摇杆的操作
void HRocker::startRocker(bool _isStopOther){
    CCSprite * rocker = (CCSprite*)this->getChildByTag(tag_rocker);
    rocker->setVisible(true);
    
    CCSprite * rockerBG = (CCSprite*)this->getChildByTag(tag_rockerBG);
    rockerBG->setVisible(true);
    
    CCDirector::sharedDirector()->getTouchDispatcher()->addTargetedDelegate(this, -1, _isStopOther);
}

//停止对摇杆的操作
void HRocker::stopRocker(){
    CCSprite * rocker = (CCSprite*)this->getChildByTag(tag_rocker);
    rocker->setVisible(false);
    
    CCSprite * rockerBG = (CCSprite*)this->getChildByTag(tag_rockerBG);
    rockerBG->setVisible(false);
    
    CCDirector::sharedDirector()->getTouchDispatcher()->removeDelegate(this);
}

//得到摇杆与触屏点所形成的角度
float HRocker::getRad(CCPoint pos1,CCPoint pos2) {
    float px1 = pos1.x;
    float py1 = pos1.y;
    float px2 = pos2.x;
    float py2 = pos2.y;
    
    //得到两点X的距离
    float x = px2 - px1;
    //得到两点Y的距离
    float y = py1 - py2;
    //算出斜边长
    float xie =  sqrt(pow(x, 2) + pow(y, 2));
    //得到这个角度的余弦值（通过三角函数中的定理 ：邻边/斜边=角度余弦值）
    float cosAngle = x / xie;
    //通过反余弦定理获取到其角度的弧度
    float rad = acos(cosAngle);
    //注意：当触屏的位置Y坐标<摇杆的Y坐标我们要取反值-0~-180
    if (py2 < py1) {
        rad = -rad;
    }
    return rad;
}

//得到半径为r的圆周运动上一个角度应对应的x、y坐标
CCPoint getAnglePosition(float r,float angle){ 
    return  ccp(r*cos(angle),r*sin(angle)); 
}

//抬起事件
bool HRocker::ccTouchBegan(CCTouch *pTouch, CCEvent *pEvent){
    
    CCPoint point = pTouch->getLocation();
    CCSprite * rocker = (CCSprite*)this->getChildByTag(tag_rocker);
    if(rocker->boundingBox().containsPoint(point)){
        isCanMove=true;
    }
    
    return true;
}

//移动事件
void HRocker::ccTouchMoved(CCTouch *pTouch, CCEvent *pEvent){
    if(!isCanMove){
        return;
    }
    CCPoint point  = pTouch->getLocation();
    
    CCSprite * rocker = (CCSprite*)this->getChildByTag(tag_rocker);
    
    //判断两个圆的圆心距是否大于摇杆背景的半径
    if (sqrt(pow((rockerBGPosition.x - point.x), 2) +pow((rockerBGPosition.y - point.y), 2)) >= rockerBGR) {
        //得到摇杆与触屏点所形成的角度
        float angle = getRad(rockerBGPosition, point);
        
        //保证内部小圆运动的长度限制
        rocker->setPosition(ccpAdd(getAnglePosition(rockerBGR, angle),ccp(rockerBGPosition.x,rockerBGPosition.y)));
    }else{
        //当没有超过，让摇杆跟随用户触屏点移动即可
        rocker->setPosition(point);
    }
}

//离开事件
void HRocker::ccTouchEnded(CCTouch *pTouch, CCEvent *pEvent){
    if(!isCanMove){
        return;
    }
    CCSprite * rockerBG = (CCSprite*)this->getChildByTag(tag_rockerBG);
    CCSprite * rocker = (CCSprite*)this->getChildByTag(tag_rocker);
    rocker->stopAllActions();
    rocker->runAction(CCMoveTo::create(0.08, rockerBG->getPosition()));
    isCanMove=false;
}

