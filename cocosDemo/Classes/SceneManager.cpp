//
//  SceneManager.cpp
//  cocosDemo-mobile
//
//  Created by apple on 2017/11/9.
//

#include "SceneManager.hpp"
#include "LoadLayer.hpp"
#include "HomeLayer.hpp"
#include "TestLayer.hpp"

void SceneManager::createLoadScene(){
    loadScene = Scene::create();
    LoadLayer *layer = LoadLayer::create();
    layer->tsm = this;
    loadScene->addChild(layer);
}

void SceneManager::goHomeScene(){
    homeScene = Scene::create();
    HomeLayer *layer = HomeLayer::create();
    layer->tsm = this;
    homeScene->addChild(layer);
    Director::getInstance()->pushScene(homeScene);
}

void SceneManager::goTestScene(){
    testScene = Scene::create();
    TestLayer *layer = TestLayer::create();
    testScene->addChild(layer);
    
    Director::getInstance()->pushScene(testScene);
    
}
