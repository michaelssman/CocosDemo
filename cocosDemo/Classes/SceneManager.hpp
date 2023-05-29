//
//  SceneManager.hpp
//  cocosDemo-mobile
//
//  Created by apple on 2017/11/9.
//

#ifndef SceneManager_hpp
#define SceneManager_hpp

#include <stdio.h>
#include <cocos2d.h>

USING_NS_CC;

class SceneManager {
public:
    Scene *loadScene;
    Scene *homeScene;
    Scene *testScene;
    
    void createLoadScene();
    void goHomeScene();
    void goTestScene();
};
#endif /* SceneManager_hpp */
