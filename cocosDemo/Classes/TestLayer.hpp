//
//  TestLayer.hpp
//  cocosDemo-mobile
//
//  Created by apple on 2017/11/10.
//

#ifndef TestLayer_hpp
#define TestLayer_hpp

#include <stdio.h>
#include <cocos2d.h>
#include <extensions/cocos-ext.h>
#include "ui/CocosGUI.h"

USING_NS_CC;
using namespace cocos2d::ui;

class TestLayer:public Layer, public cocos2d::extension::TableViewDataSource, public cocos2d::extension::TableViewDelegate{
public:
    CREATE_FUNC(TestLayer);
    virtual bool init();
    void onButtonClicked(Ref* sender, Widget::TouchEventType type);

    virtual void tableCellTouched(cocos2d::extension::TableView* table, cocos2d::extension::TableViewCell* cell)override;
    virtual cocos2d::Size tableCellSizeForIndex(cocos2d::extension::TableView *table, ssize_t idx)override;
    virtual cocos2d::extension::TableViewCell* tableCellAtIndex(cocos2d::extension::TableView *table, ssize_t idx)override;
    virtual ssize_t numberOfCellsInTableView(cocos2d::extension::TableView *table)override;
private:
    Text* mathLabel;
    ValueVector vec;
    int i;
    Button *voiceSprite;
};
#endif /* TestLayer_hpp */
