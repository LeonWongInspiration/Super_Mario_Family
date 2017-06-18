#ifndef GameOver_hpp
#define GameOver_hpp
#include "HelloWorldScene.h"

using namespace cocos2d;

class GameOver : public Layer
{
public:

	static Scene * createScene();

	virtual bool init();

	void menuCallBack(cocos2d::Ref * pSender);

	CREATE_FUNC(GameOver);
};

#endif 