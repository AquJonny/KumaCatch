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
//    //----------------------通过地编文件创建生成地图
//    CCTMXTiledMap* map = CCTMXTiledMap::create("map1.tmx");
//    addChild(map);
//    CCSize tileSize  = map->getTileSize();
//    CCSize mapSize = map->getMapSize();
//    CCLOG("tileSize:%f_%f,   mapSize:%f_%f",tileSize.width,tileSize.height,mapSize.width,mapSize.height);
//    
//    //遍历每个图块并设置抗锯齿
//    CCArray * pChildrenArray = map->getChildren();
//    CCSpriteBatchNode* child = NULL;
//    CCObject* pObject = NULL;
//    CCARRAY_FOREACH(pChildrenArray, pObject)
//    {
//        child = (CCSpriteBatchNode*)pObject;
//        
//        if(!child)
//            break;
//        
//        child->getTexture()->setAntiAliasTexParameters();
//    }
//    
//    //取出地图层中的最后一个图块进行操作
//    CCTMXLayer* layer = map->layerNamed("layer1");
//    CCSprite* sprite= layer->tileAt(ccp(9,9));
//    sprite->setScale(2);
//    sprite->setRotation(-90);

    
    
    //----------------------对象层
    CCTMXTiledMap* map = CCTMXTiledMap::create("map1.tmx");
    addChild(map);
    
    CCTMXObjectGroup* group = map->objectGroupNamed("objLayer1");
    CCArray* objects = group->getObjects();
    
    CCDictionary* dict = NULL;
    CCObject* pObj = NULL;
    CCARRAY_FOREACH(objects, pObj)
    {
        dict = (CCDictionary*)pObj;
        
        if(!dict)
            break;
        const char* key = "x";
        int x = ((CCString*)dict->objectForKey(key))->intValue();
        key = "y";
        int y = ((CCString*)dict->objectForKey(key))->intValue();
        key = "width";
        int width = ((CCString*)dict->objectForKey(key))->intValue();
        key = "height";
        int height = ((CCString*)dict->objectForKey(key))->intValue();
        CCLog("对象图块的坐标与尺寸~ x:%i_y:%i_width:%i_height:%i",x,y,width,height);
        
        
        int objUDID = ((CCString*)dict->objectForKey("UDID"))->intValue();
        int objSCALE = ((CCString*)dict->objectForKey("SCALE"))->intValue();
        int objROTATE = ((CCString*)dict->objectForKey("ROTATE"))->intValue();
        CCLog("对象图块的属性值~objUDID:%i_objSCALE:%i_objROTATE:%i",objUDID,objSCALE,objROTATE);
        
        CCSprite* sprite = CCSprite::create("Icon.png");
        sprite->setRotation(objROTATE);
        sprite->setScale(objSCALE);
        sprite->setPosition(ccp(x,y));
        addChild(sprite);
    }
    
    
    return true;
}
