//
//  TestLayer.cpp
//  cocosDemo-mobile
//
//  Created by apple on 2017/11/10.
//

#include "TestLayer.hpp"
#include "CustomTableViewCell.h"
USING_NS_CC_EXT;

bool TestLayer::init(){
    Size winSize = Director::getInstance()->getWinSize();
    
    //加载背景图片
    Sprite* bg = Sprite::create("bg.png");
    bg->setPosition(winSize.width/2,winSize.height/2);
    bg->setScale(winSize.width/bg->getContentSize().width, winSize.height/bg->getContentSize().height);
    this->addChild(bg);
    
    //加载面板层
    Sprite* panel = Sprite::create("Panel.png");
    panel->setPosition(winSize.width/2,winSize.height/2);
    panel->setScale(winSize.width*0.8/panel->getContentSize().width, winSize.height*0.7/panel->getContentSize().height);
    this->addChild(panel);
    
    Size panelSize = panel->getContentSize();

    //设置向左翻页按钮
    Button* leftArrow = Button::create("left_Arrow_inactive.png");
    leftArrow->addTouchEventListener( CC_CALLBACK_2(TestLayer::onButtonClicked, this));
    leftArrow->setName("leftArrow");
    leftArrow->setScale(1);
    leftArrow->setPosition(Vec2(15,winSize.height - 55));
    this->addChild(leftArrow);

    //设置音频
    voiceSprite = Button::create("left_Arrow_inactive.png");
    voiceSprite->addTouchEventListener( CC_CALLBACK_2(TestLayer::onButtonClicked, this));
    voiceSprite->setName("leftArrow");
    voiceSprite->setScale(1);
    voiceSprite->setPosition(Vec2(winSize.width - 25, 55));
    this->addChild(voiceSprite);
    //加载题目
    mathLabel = Text::create("Please wait a moment","Arial",23);
    mathLabel->setPosition(Vec2(winSize.width*0.5, winSize.height*0.6));
    this->addChild(mathLabel);
    
    //读取.plist文件
    // ValueVector & ValueMap
    vec = FileUtils::getInstance()->getValueVectorFromFile("TestList.plist");
    
    //    for (int i = 0; i < vec.size(); i ++) {
    //
    //    }
    i = 0;
    ValueMap vec_map_0 = vec.at(i).asValueMap();
    std::string vec_0 = vec_map_0.at("name").asString();
    mathLabel->setString(vec_0);
    
    //tableView
    TableView* tableView = TableView::create(this, Size(250, 60));
    tableView->setDirection(TableView::Direction::HORIZONTAL);
    tableView->setPosition(winSize.width/2 - 75,winSize.height/2 - 55);
    tableView->setDelegate(this);
    this->addChild(tableView);
    tableView->reloadData();
    
    auto testNode = Node::create();
    testNode->setName("testNode");
    tableView->addChild(testNode);
    tableView->removeChild(testNode, true);
    CCAssert(nullptr == tableView->getChildByName("testNode"), "The added child has been removed!");
    
    return true;
}
void TestLayer::onButtonClicked(Ref* sender, Widget::TouchEventType type)
{
    Director::getInstance()->popScene();
}

#pragma mark  tableView
void TestLayer::tableCellTouched(TableView* table, TableViewCell* cell)
{
    CCLOG("cell touched at index: %ld", static_cast<long>(cell->getIdx()));
    if (i == (vec.size() - 1)) {
        return;
    }
    i++;
    ValueMap vec_map_0 = vec.at(i).asValueMap();
    std::string vec_0 = vec_map_0.at("name").asString();
    mathLabel->setString(vec_0);
}

Size TestLayer::tableCellSizeForIndex(TableView *table, ssize_t idx)
{
    return Size(100, 100);
}

TableViewCell* TestLayer::tableCellAtIndex(TableView *table, ssize_t idx)
{
    log("cell at index");
//    auto string = StringUtils::format("%ld", static_cast<long>(idx));
//    TableViewCell *cell = table->dequeueCell();

    CustomTableViewCell *cell = dynamic_cast<CustomTableViewCell *>(table->dequeueCell());
    if (!cell) {
        cell = CustomTableViewCell::create(idx);
    }
    ValueMap vec_map_0 = vec.at(i).asValueMap();
    ValueVector vec_1 = vec_map_0.at("content").asValueVector();
    cell->reset(idx, vec_1);
    return cell;
}

ssize_t TestLayer::numberOfCellsInTableView(TableView *table)
{
    ValueMap vec_map_0 = vec.at(i).asValueMap();
    ValueVector vec_1 = vec_map_0.at("content").asValueVector();
    return vec_1.size();;
}

