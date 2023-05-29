//
//  HomeLayer.cpp
//  cocosDemo-mobile
//
//  Created by apple on 2017/11/10.
//

#include "HomeLayer.hpp"
#include "HelloWorldScene.h"
bool HomeLayer::init(){
    Size winSize = Director::getInstance()->getWinSize();
    
    //加载背景图片
    Sprite* bg = Sprite::create("bg.png");
    bg->setPosition(winSize.width/2,winSize.height/2);
    bg->setScale(winSize.width/bg->getContentSize().width, winSize.height/bg->getContentSize().height);
    this->addChild(bg);
    
    auto visibleSize = Director::getInstance()->getVisibleSize();
    Vec2 origin = Director::getInstance()->getVisibleOrigin();
    
    /////////////////////////////
    // 2. add a menu item with "X" image, which is clicked to quit the program
    //    you may modify it.
    
    // add a "close" icon to exit the progress. it's an autorelease object
    auto closeItem = MenuItemImage::create(
                                           "game_btn.png",
                                           "game_btn_sel.png",
                                           CC_CALLBACK_1(HomeLayer::onButtonClicked, this));
    

        closeItem->setPosition(Vec2(visibleSize.width/2 + origin.x, visibleSize.height/2 + origin.y));;
    
    // create menu, it's an autorelease object
    auto menu = Menu::create(closeItem, NULL);
    menu->setPosition(Vec2::ZERO);
    this->addChild(menu, 1);
    
    
    return true;
}

void HomeLayer::onButtonClicked(Ref* sender){
    tsm->goTestScene();
    
//    auto scene = HelloWorld::createScene();
//    Director::getInstance()->replaceScene(scene);
}
