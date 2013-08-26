#include "GameScene.h"

USING_NS_CC;

Scene* GameScene::scene()
{
    // 'scene' is an autorelease object
    Scene *scene = Scene::create();
    
    // 'layer' is an autorelease object
    GameScene *layer = GameScene::create();

    // add layer as a child to scene
    scene->addChild(layer);

    // return the scene
    return scene;
}

// on "init" you need to initialize your instance
bool GameScene::init()
{
    //////////////////////////////
    // 1. super init first
    if ( !Layer::init() )
    {
        return false;
    }
    
    Size visibleSize = Director::getInstance()->getVisibleSize();
    Point origin = Director::getInstance()->getVisibleOrigin();


	//Hey was geht denn ? :D

	Sprite * tmpSprite;

	//Para Layer 2 (Ganz Hinten)

	paralax2 = new Layer();
	tmpSprite = Sprite::create("Game/PARA11.PNG");
	tmpSprite->setPosition(Point(visibleSize.width/2,visibleSize.height/2));
	paralax2->addChild(tmpSprite);

	tmpSprite = Sprite::create("Game/PARA12.PNG");
	tmpSprite->setPosition(Point(visibleSize.width/2 + tmpSprite->getContentSize().width,visibleSize.height/2));
	paralax2->addChild(tmpSprite);

	this->addChild(paralax2, 0);

	//Para Layer 1 (Vor dem layer 2)

	paralax1 = new Layer();
	tmpSprite = Sprite::create("Game/PARA21.PNG");
	tmpSprite->setPosition(Point(visibleSize.width/2,visibleSize.height/2));
	paralax1->addChild(tmpSprite);

	tmpSprite = Sprite::create("Game/PARA22.PNG");
	tmpSprite->setPosition(Point(visibleSize.width/2 + tmpSprite->getContentSize().width,visibleSize.height/2));
	paralax1->addChild(tmpSprite);

	this->addChild(paralax1, 0);

	/*
	paralax1 = new Layer();
	paralax2 = new Layer();

	level = new Layer();

	this->addChild(paralax2, 0);
	Sprite* tmpS = Sprite::create("Game/PARA11.PNG");
	tmpS->setPosition(Point(tmpS->getContentSize().width/2,tmpS->getContentSize().height/2));
	paralax2->addChild(tmpS);
	tmpS = Sprite::create("Game/PARA12.PNG");
	tmpS->setPosition(Point(tmpS->getContentSize().width/2+tmpS->getContentSize().width,tmpS->getContentSize().height/2));
	paralax2->addChild(tmpS);

	this->addChild(paralax1, 1);
	tmpS = Sprite::create("Game/PARA21.PNG");
	tmpS->setPosition(Point(tmpS->getContentSize().width/2,tmpS->getContentSize().height/2));
	paralax1->addChild(tmpS);
	tmpS = Sprite::create("Game/PARA22.PNG");
	tmpS->setPosition(Point(tmpS->getContentSize().width/2+tmpS->getContentSize().width,tmpS->getContentSize().height/2));
	paralax1->addChild(tmpS);

	this->addChild(level, 2);

	player = Sprite::create("Mario/Standing.PNG");
	player->setPosition(Point(player->getContentSize().width/2,64+player->getContentSize().height/2));
	this->addChild(player, 1);

	blocks = new Sprite*[10];

	Sprite* obj;

	for(int i=0; i<10;i++){
		blocks[i] = Sprite::create("Game/Dirt.PNG");

		blocks[i]->setPosition(Point(blocks[i]->getContentSize().width/2 + i*blocks[i]->getContentSize().width,
									 blocks[i]->getContentSize().height/2));

		level->addChild(blocks[i],1);
	}

	*/

    /////////////////////////////
    // 2. add a menu item with "X" image, which is clicked to quit the program
    //    you may modify it.

    // add a "close" icon to exit the progress. it's an autorelease object
    MenuItemImage *closeItem = MenuItemImage::create(
                                        "CloseNormal.png",
                                        "CloseSelected.png",
                                        CC_CALLBACK_1(GameScene::menuCloseCallback, this));
    
	closeItem->setPosition(Point(origin.x + visibleSize.width - closeItem->getContentSize().width/2 ,
                                origin.y + closeItem->getContentSize().height/2));

    // create menu, it's an autorelease object
    Menu* menu = Menu::create(closeItem, NULL);
    menu->setPosition(Point::ZERO);
    this->addChild(menu, 1);

    /////////////////////////////
    // 3. add your codes below...

    // add a label shows "Hello World"
    // create and initialize a label
    
    LabelTTF* label = LabelTTF::create("Hello World", "Arial", 24);
    
    // position the label on the center of the screen
    label->setPosition(Point(origin.x + visibleSize.width/2,
                            origin.y + visibleSize.height - label->getContentSize().height));

    // add the label as a child to this layer
    this->addChild(label, 1);

	/*
    // add "HelloWorld" splash screen"
    Sprite* sprite = Sprite::create("HelloWorld.png");

    // position the sprite on the center of the screen
    sprite->setPosition(Point(visibleSize.width/2 + origin.x, visibleSize.height/2 + origin.y));

    // add the sprite as a child to this layer
    this->addChild(sprite, 0);
    */





	//this->schedule(schedule_selector(GameScene::update), 0.01F);

    return true;
}

void GameScene::update(float dt){
	if(GetAsyncKeyState(VK_RIGHT)){
		paralax1->setPositionX(paralax1->getPositionX()-dt*2.0F*speed);
		paralax2->setPositionX(paralax2->getPositionX()-dt*speed);

		level->setPositionX(level->getPositionX()-dt*3.0*speed);
	}
}

void GameScene::menuCloseCallback(Object* pSender)
{
    Director::getInstance()->end();

#if (CC_TARGET_PLATFORM == CC_PLATFORM_IOS)
    exit(0);
#endif
}
