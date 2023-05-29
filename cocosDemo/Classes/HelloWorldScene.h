#ifndef __HELLOWORLD_SCENE_H__
#define __HELLOWORLD_SCENE_H__

#include "cocos2d.h"
#include "SceneManager.hpp"
#include <extensions/cocos-ext.h>
#include "ui/CocosGUI.h"

USING_NS_CC;
class HelloWorld : public cocos2d::Scene, public cocos2d::extension::TableViewDataSource, public cocos2d::extension::TableViewDelegate
{
public:
    static cocos2d::Scene* createScene();

    virtual bool init();
    
    virtual void tableCellTouched(cocos2d::extension::TableView* table, cocos2d::extension::TableViewCell* cell)override;
    virtual cocos2d::Size tableCellSizeForIndex(cocos2d::extension::TableView *table, ssize_t idx)override;
    virtual cocos2d::extension::TableViewCell* tableCellAtIndex(cocos2d::extension::TableView *table, ssize_t idx)override;
    virtual ssize_t numberOfCellsInTableView(cocos2d::extension::TableView *table)override;

    // implement the "static create()" method manually
    CREATE_FUNC(HelloWorld);
    
public:
};

#endif // __HELLOWORLD_SCENE_H__
