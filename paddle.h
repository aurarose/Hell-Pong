#pragma once
#include "actor.h"

class paddle :public actor
{
public:
	paddle(string imgpath,float x, float y, float width,float height) :actor(imgpath,x, y,width,height){}
	//~paddle();
	virtual void update();
protected:
	void processMovement();
	void shoot();
	float move_speed = 15;
	int shot_timer = 0;
	int shot_delay = 75;
};

