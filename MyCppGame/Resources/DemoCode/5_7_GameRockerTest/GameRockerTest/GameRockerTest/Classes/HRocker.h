//
//  HRocker.h
//  GameRockerTest
//
//  Created by Himi on 12-9-24.
//
//

#ifndef __GameRockerTest__HRocker__
#define __GameRockerTest__HRocker__

#include "cocos2d.h"
using namespace cocos2d;

//用于标识摇杆与摇杆的背景
typedef enum{
    tag_rocker,
    tag_rockerBG,

}tagForHRocker;

class HRocker:public CCLayer{
    
public:
    //创建摇杆（摇杆的操作体图片资源名，摇杆背景图片资源名，起始坐标）
    static HRocker* createHRocker(const char* rockerImageName,const char* rockerBGImageName,CCPoint position);
    //启动摇杆（显示摇杆、监听摇杆触屏事件）
    void startRocker(bool _isStopOther);
    //停止摇杆(隐藏摇杆，取消摇杆的触屏监听)
    void stopRocker();
    
    CREATE_FUNC(HRocker);
private:
    //自定义初始化函数
    void rockerInit(const char* rockerImageName,const char* rockerBGImageName,CCPoint position);
    //是否可操作摇杆
    bool isCanMove;
    //获取当前摇杆与用户触屏点的角度
    float getRad(CCPoint pos1,CCPoint pos2);
    //摇杆背景的坐标
    CCPoint rockerBGPosition;
    //摇杆背景的半径
    float rockerBGR;
    //触屏事件
    virtual bool ccTouchBegan(CCTouch *pTouch, CCEvent *pEvent);
    virtual void ccTouchMoved(CCTouch *pTouch, CCEvent *pEvent);
    virtual void ccTouchEnded(CCTouch *pTouch, CCEvent *pEvent);
    
};


#endif
