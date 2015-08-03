#include "NewScene.h"
#include "HelloWorldScene.h"


USING_NS_CC;

Scene* NewScene::createScene()
{
    // 'scene' is an autorelease object
    auto scene = Scene::create();
    
    // 'layer' is an autorelease object
    auto layer = NewScene::create();

    // add layer as a child to scene
    scene->addChild(layer);

    // return the scene
    return scene;
}

// on "init" you need to initialize your instance
bool NewScene::init()
{
    //////////////////////////////
    // 1. super init first
    if ( !Layer::init() )
    {
        return false;
    }
    
    Size visibleSize = Director::getInstance()->getVisibleSize();
    Vec2 origin = Director::getInstance()->getVisibleOrigin();

   




	

	auto lname = Label::create("Nombre : ","Verdana", 20);

	lname->setColor(Color3B(108,169,121));

	lname->setPosition(Point(lname->getContentSize().width/ 2 + origin.y + 10, visibleSize.height / 2 + origin.y + 30));

	this->addChild(lname,2);



	auto lapellido = Label::create("Apellido : ", "Verdana", 20);


	lapellido->setColor(Color3B(108,169,121));

	lapellido->setPosition(Point(lname->getContentSize().width / 2 + origin.y + 10, lname->getPositionY() - (lname->getContentSize().height + 40)));

	this->addChild(lapellido,2);



	
	ReadWriteFile *read = new ReadWriteFile;

	
	__String* valueName = read->getStringData(__String::create("key1"), __String::create("info.plist"));
	__String *valueApell = read->getStringData(__String::create("key2"), __String::create("info.plist"));



	auto name = Label::create(valueName->getCString(), "Verdana", 30);
	name->setColor(Color3B::BLACK);
	name->setPosition(Point(visibleSize.width / 2, lname->getPositionY()));
	this->addChild(name,2);


	auto apell = Label::create(valueApell->getCString(), "Verdana", 30);
	apell->setColor(Color3B::BLACK);
	apell->setPosition(Point(visibleSize.width / 2, lapellido->getPositionY()));
	this->addChild(apell,2);


    // add a "close" icon to exit the progress. it's an autorelease object
    auto btn = MenuItemImage::create(
                                           "btnv1.jpg",
                                           "btnv2.jpg",
										   CC_CALLBACK_1(NewScene::Volver, this));
    


	btn->setPosition(Vec2(btn->getContentSize().height + origin.y + 30, btn->getContentSize().height + origin.y));

    // create menu, it's an autorelease object
	auto menu = Menu::create(btn, NULL);
    menu->setPosition(Vec2::ZERO);
    this->addChild(menu, 1);

    /////////////////////////////
    // 3. add your codes below...

    // add a label shows "Hello World"
    // create and initialize a label
    
   
 
    // add "HelloWorld" splash screen"
    auto sprite = Sprite::create("capa2.jpg");

    // position the sprite on the center of the screen
    sprite->setPosition(Vec2(visibleSize.width/2 + origin.x, visibleSize.height/2 + origin.y));
    // add the sprite as a child to this layer
    this->addChild(sprite, 0);
    





    return true;
}


void NewScene::Volver(Ref* pSender)
{

	Director::getInstance()->replaceScene(TransitionFade::create(2,HelloWorld::createScene()));


}
