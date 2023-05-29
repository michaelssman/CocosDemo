//
//  LoadLayer.cpp
//  cocosDemo-mobile
//
//  Created by apple on 2017/11/9.
//

#include "LoadLayer.hpp"

bool LoadLayer::init(){
    Size visivleSize = Director::getInstance()->getVisibleSize();
    Vec2 origin = Director::getInstance()->getVisibleOrigin();
    
    Label * label = Label::createWithTTF("Loading...", "fonts/Marker Felt.ttf", 80);
    label->setPosition(Vec2(origin.x + visivleSize.width / 2, origin.y + visivleSize.height / 2));
    
    this->addChild(label);
    
    scheduleOnce(CC_SCHEDULE_SELECTOR(LoadLayer::onScheduleOnce), 3.5);
    
    return true;
}

void LoadLayer::onScheduleOnce(float dt){
    tsm->goHomeScene();
}
