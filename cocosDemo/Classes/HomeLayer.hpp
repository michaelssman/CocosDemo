//
//  HomeLayer.hpp
//  cocosDemo-mobile
//
//  Created by apple on 2017/11/10.
//

#ifndef HomeLayer_hpp
#define HomeLayer_hpp

#include <stdio.h>
#include <cocos2d.h>
#include "SceneManager.hpp"

USING_NS_CC;

class HomeLayer:public Layer {
public:
    CREATE_FUNC(HomeLayer);
    virtual bool init();
    void onButtonClicked(Ref* sender);
public:
    SceneManager * tsm;
};
#endif /* HomeLayer_hpp */
