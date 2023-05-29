#include "HelloWorldScene.h"
#include "SimpleAudioEngine.h"
#include "CustomTableViewCell.h"

USING_NS_CC_EXT;

Scene* HelloWorld::createScene()
{
    return HelloWorld::create();
}

// Print useful error message instead of segfaulting when files are not there.
static void problemLoading(const char* filename)
{
    printf("Error while loading: %s\n", filename);
    printf("Depending on how you compiled you might have to add 'Resources/' in front of filenames in HelloWorldScene.cpp\n");
}

// on "init" you need to initialize your instance
bool HelloWorld::init()
{
    //////////////////////////////
    // 1. super init first
    if ( !Scene::init() )
    {
        return false;
    }

    Size winSize = Director::getInstance()->getWinSize();
    
    //加载背景图片
    Sprite* bg = Sprite::create("bg.png");
    bg->setPosition(winSize.width/2,winSize.height/2);
    bg->setScale(winSize.width/bg->getContentSize().width, winSize.height/bg->getContentSize().height);
    this->addChild(bg);
    
    
    //tableView
    TableView* tableView = TableView::create(this, Size(250, 60));
    tableView->setDirection(TableView::Direction::HORIZONTAL);
    tableView->setPosition(winSize.width/2 - 125,winSize.height/2 - 55);
    tableView->setDelegate(this);
    this->addChild(tableView);
    tableView->reloadData();
    
    
//    auto visibleSize = Director::getInstance()->getVisibleSize();
//    Vec2 origin = Director::getInstance()->getVisibleOrigin();
//
//    /////////////////////////////
//    // 2. add a menu item with "X" image, which is clicked to quit the program
//    //    you may modify it.
//
//    // add a "close" icon to exit the progress. it's an autorelease object
//    auto closeItem = MenuItemImage::create(
//                                           "game_btn.png",
//                                           "game_btn_sel.png",
//                                           CC_CALLBACK_1(HelloWorld::onButtonClicked, this));
//
//    if (closeItem == nullptr ||
//        closeItem->getContentSize().width <= 0 ||
//        closeItem->getContentSize().height <= 0)
//    {
//        problemLoading("'CloseNormal.png' and 'CloseSelected.png'");
//    }
//    else
//    {
////        float x = origin.x + visibleSize.width - closeItem->getContentSize().width/2;
////        float y = origin.y + closeItem->getContentSize().height/2;
//        closeItem->setPosition(Vec2(visibleSize.width/2 + origin.x, visibleSize.height/2 + origin.y));;
//    }
//
//    // create menu, it's an autorelease object
//    auto menu = Menu::create(closeItem, NULL);
//    menu->setPosition(Vec2::ZERO);
//    this->addChild(menu, 1);
//
//    /////////////////////////////
//    // 3. add your codes below...
//
//    // add a label shows "Hello World"
//    // create and initialize a label
//
//    auto label = Label::createWithTTF("Hello World", "fonts/Marker Felt.ttf", 24);
//    if (label == nullptr)
//    {
//        problemLoading("'fonts/Marker Felt.ttf'");
//    }
//    else
//    {
//        // position the label on the center of the screen
//        label->setPosition(Vec2(origin.x + visibleSize.width/2,
//                                origin.y + visibleSize.height - label->getContentSize().height));
//
//        // add the label as a child to this layer
//        this->addChild(label, 1);
//    }

//    // add "HelloWorld" splash screen"
//    auto sprite = Sprite::create("HelloWorld.png");
//    if (sprite == nullptr)
//    {
//        problemLoading("'HelloWorld.png'");
//    }
//    else
//    {
//        // position the sprite on the center of the screen
//        sprite->setPosition(Vec2(visibleSize.width/2 + origin.x, visibleSize.height/2 + origin.y));
//
//        // add the sprite as a child to this layer
//        this->addChild(sprite, 0);
//    }
    return true;
}


//void HelloWorld::menuCloseCallback(Ref* pSender)
//{
//    //Close the cocos2d-x game scene and quit the application
//    Director::getInstance()->end();
//
//    #if (CC_TARGET_PLATFORM == CC_PLATFORM_IOS)
//    exit(0);
//#endif
//
//    /*To navigate back to native iOS screen(if present) without quitting the application  ,do not use Director::getInstance()->end() and exit(0) as given above,instead trigger a custom event created in RootViewController.mm as below*/
//
//    //EventCustom customEndEvent("game_scene_close_event");
//    //_eventDispatcher->dispatchEvent(&customEndEvent);
//
//
//}

//void HelloWorld::onButtonClicked(Ref* sender){
//    tsm->goTestScene();
//}
#pragma mark  tableView
void HelloWorld::tableCellTouched(TableView* table, TableViewCell* cell)
{
    CCLOG("cell touched at index: %ld", static_cast<long>(cell->getIdx()));
}

Size HelloWorld::tableCellSizeForIndex(TableView *table, ssize_t idx)
{
    if (idx == 2) {
        return Size(100, 100);
    }
    return Size(60, 60);
}

TableViewCell* HelloWorld::tableCellAtIndex(TableView *table, ssize_t idx)
{
    auto string = StringUtils::format("%ld", static_cast<long>(idx));
    TableViewCell *cell = table->dequeueCell();
    if (!cell) {
        cell = new (std::nothrow) CustomTableViewCell();
        cell->autorelease();
        auto sprite = Sprite::create("right_tip.png");
        sprite->setAnchorPoint(Vec2::ZERO);
        sprite->setPosition(Vec2(0, 0));
        cell->addChild(sprite);
        
        auto label = Label::createWithSystemFont(string, "Helvetica", 20.0);
        label->setPosition(Vec2::ZERO);
        label->setAnchorPoint(Vec2::ZERO);
        label->setTag(123);
        cell->addChild(label);
    }
    else
    {
        auto label = (Label*)cell->getChildByTag(123);
        label->setString(string);
    }
    
    
    return cell;
}

ssize_t HelloWorld::numberOfCellsInTableView(TableView *table)
{
    return 20;
}
