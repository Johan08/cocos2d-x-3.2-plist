#ifndef __HELLOWORLD_SCENE_H__
#define __HELLOWORLD_SCENE_H__

#include "cocos2d.h"


#include "ui\UIButton.h"
#include "ui\UIText.h"
//#include "ui\UITextField.h"
#include "ui\UIWidget.h"
#include "ui\CocosGUI.h"

#include "ReadWriteFile.h"


//#include "cocos2d\extensions\cocos-ext.h";

using namespace std;
using namespace cocos2d;
using namespace ui;


//USING_NS_CC_EXT;



class HelloWorld : public cocos2d::Layer
{
public:
    // there's no 'id' in cpp, so we recommend returning the class instance pointer
    static cocos2d::Scene* createScene();

    // Here's a difference. Method 'init' in cocos2d-x returns bool, instead of returning 'id' in cocos2d-iphone
    virtual bool init();  

	TextField *name;
	TextField *apell;


    
    // a selector callback
    void Registro(cocos2d::Ref* pSender);
    
	void Close(Ref* pSender);

    // implement the "static create()" method manually
    CREATE_FUNC(HelloWorld);
};

#endif // __HELLOWORLD_SCENE_H__
