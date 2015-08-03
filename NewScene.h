#ifndef __NEW_SCENE_H__
#define __NEW_SCENE_H__

#include "cocos2d.h"
#include "ReadWriteFile.h"

using namespace std;
using namespace cocos2d;
using namespace ui;




class NewScene : public cocos2d::Layer
{
public:
    // there's no 'id' in cpp, so we recommend returning the class instance pointer
    static cocos2d::Scene* createScene();

    // Here's a difference. Method 'init' in cocos2d-x returns bool, instead of returning 'id' in cocos2d-iphone
    virtual bool init();  
  
    // a selector callback
    void Volver(cocos2d::Ref* pSender);
    


    // implement the "static create()" method manually
    CREATE_FUNC(NewScene);
};

#endif // __HELLOWORLD_SCENE_H__
