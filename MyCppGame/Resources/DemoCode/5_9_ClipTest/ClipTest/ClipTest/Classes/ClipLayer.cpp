//
//  ClipLayer.cpp
//  ClipTest
//
//  Created by Himi on 12-10-19.
//
//

#include "ClipLayer.h"
ClipLayer* ClipLayer::create(CCSize size){
    ClipLayer * nCLayer = new  ClipLayer();
    if(nCLayer && nCLayer->init()){
        nCLayer->autorelease();
        nCLayer->clipLayerInit(size);
        return nCLayer;
    }
    CC_SAFE_DELETE(nCLayer);
    return NULL;
}

void ClipLayer::clipLayerInit(CCSize size){
    mSize=size;
}


void ClipLayer::visit()
{
    
	kmGLPushMatrix();
	
    if (m_pGrid && m_pGrid->isActive())
    {
        m_pGrid->beforeDraw();
        this->transformAncestors();
    }
    
	this->transform();
    
    //默认情况下,剪裁是禁用的
    glEnable(GL_SCISSOR_TEST);//启用剪裁测试
    
    float s = this->getScale();//当前layer缩放的倍数
    s *= CCDirector::sharedDirector()->getContentScaleFactor();//获取缩放倍率
    CCPoint screenPos = this->convertToWorldSpace(this->getParent()->getPosition());
    //默认不设置Scissor的大小是整个视图的大小
    glScissor((GLint)screenPos.x, (GLint)screenPos.y, (GLsizei)(mSize.width*s), (GLsizei)(mSize.height*s));
    
    //子节点处理
	if(m_pChildren)
    {
		ccArray *arrayData = m_pChildren->data;
		unsigned int i=0;
		
		for( ; i < arrayData->num; i++ )
        {
			CCNode *child =  (CCNode*)arrayData->arr[i];
			if ( child->getZOrder() < 0 )
            {
				child->visit();
			}
            else
            {
				break;
            }
		}
		this->draw();
		for( ; i < arrayData->num; i++ )
        {
			CCNode* child = (CCNode*)arrayData->arr[i];
			child->visit();
		}
        
	} else
    {
		this->draw();
    }
    
    glDisable(GL_SCISSOR_TEST);//禁用剪裁测试
    
	if ( m_pGrid && m_pGrid->isActive())
    {
		m_pGrid->afterDraw(this);
    }
    
	kmGLPopMatrix();
}


