#include "HelloWorldScene.h"
#include "NewScene.h"



USING_NS_CC;

Scene* HelloWorld::createScene()
{
    // 'scene' is an autorelease object
    auto scene = Scene::create();
    
    // 'layer' is an autorelease object
    auto layer = HelloWorld::create();

    // add layer as a child to scene
    scene->addChild(layer);

    // return the scene
    return scene;
}

// on "init" you need to initialize your instance
bool HelloWorld::init()
{
    //////////////////////////////
    // 1. super init first
    if ( !Layer::init() )
    {
        return false;
    }
    
    Size visibleSize = Director::getInstance()->getVisibleSize();
    Vec2 origin = Director::getInstance()->getVisibleOrigin();

    /////////////////////////////
    // 2. add a menu item with "X" image, which is clicked to quit the program
    //    you may modify it.


	//auto btn = Sprite::create("btn1.jpg");


	//btn->setPosition(Point(btn->getContentSize().height + origin.y + 30, btn->getContentSize().height + origin.y));

	//this->addChild(btn, 2);


	auto lname = Label::create("*Nombre","Verdana", 20);

	lname->setColor(Color3B(108,169,121));

	lname->setPosition(Point(lname->getContentSize().width/ 2 + origin.y + 10, visibleSize.height / 2 + origin.y + 30));

	this->addChild(lname,2);



	auto lapellido = Label::create("*Apellido", "Verdana", 20);


	lapellido->setColor(Color3B(108,169,121));

	lapellido->setPosition(Point(lname->getContentSize().width / 2 + origin.y + 10, lname->getPositionY() - (lname->getContentSize().height + 40)));

	this->addChild(lapellido,2);



	name = TextField::create("  ___________|", "Verdana", 30);
	name->setColor(Color3B::BLACK);
	name->setPosition(Point(name->getContentSize().width + 10, lname->getPositionY()));
	name->setMaxLengthEnabled(true);
	name->setMaxLength(10);

	this->addChild(name,2);




	apell = TextField::create("  ___________|", "Verdana", 30);
	apell->setColor(Color3B::BLACK);
	apell->setPosition(Point(name->getContentSize().width + 10, lapellido->getPositionY()));
	apell->setMaxLengthEnabled(true);
	apell->setMaxLength(10);
	this->addChild(apell,2);






    // add a "close" icon to exit the progress. it's an autorelease object
    auto btn = MenuItemImage::create(
                                           "btn1.jpg",
                                           "btn2.jpg",
                                           CC_CALLBACK_1(HelloWorld::Registro, this));
    
	btn->setPosition(Vec2(btn->getContentSize().height + origin.y + 30, btn->getContentSize().height + origin.y));

    // create menu, it's an autorelease object
    auto menu = Menu::create(btn, NULL);
    menu->setPosition(Vec2::ZERO);
    this->addChild(menu, 1);

    /////////////////////////////
    // 3. add your codes below...

    // add a label shows "Hello World"
    // create and initialize a label
    
	 auto closeItem = MenuItemImage::create(
                                           "x.png",
                                           "x.png",
										   CC_CALLBACK_1(HelloWorld::Close, this));
    
	closeItem->setPosition(Point(origin.x + visibleSize.width - closeItem->getContentSize().width/2 ,
                                origin.y + closeItem->getContentSize().height/2));

    // create menu, it's an autorelease object
    auto menu2 = Menu::create(closeItem, NULL);
    menu2->setPosition(Point::ZERO);
    this->addChild(menu2, 2);
   

	 // add "HelloWorld" splash screen"
    auto sprite = Sprite::create("capa.jpg");

 
   
    // position the sprite on the center of the screen

    sprite->setPosition(Vec2(visibleSize.width/2 + origin.x, visibleSize.height/2 + origin.y));
    // add the sprite as a child to this layer
    this->addChild(sprite, 0);
    
    return true;
}







void HelloWorld::Registro(Ref* pSender)
{

	ReadWriteFile *write = new ReadWriteFile;

	

	if(name->getStringValue() != "" && apell->getStringValue() != "")
	{

	write->setStringData(__String::create("key1"), __String::create(name->getStringValue()), __String::create("info.plist"));
	write->setStringData(__String::create("key2"), __String::create(apell->getStringValue()), __String::create("info.plist"));

	Director::getInstance()->replaceScene(TransitionFade::create(2,NewScene::createScene()));

	}


	//nada
}



void HelloWorld::Close(Ref *pSender)
{

	#if (CC_TARGET_PLATFORM == CC_PLATFORM_WP8) || (CC_TARGET_PLATFORM == CC_PLATFORM_WINRT)
	MessageBox("You pressed the close button. Windows Store Apps do not implement a close button.","Alert");
    return;
#endif

    Director::getInstance()->end();

#if (CC_TARGET_PLATFORM == CC_PLATFORM_IOS)
    exit(0);
#endif


}


