#pragma once
#include "actor.h"


class ball : public actor
{
public:
	ball(string imgpath,float x,float y, float speed, float direction) : actor(imgpath, x, y, 64,64){
		this->speed = speed;
		this->direction = direction;
		//this->reset();
	}
	float direction;
	float speed;
	virtual void update();
	void reset();
private:
	int collide_timer = 0;
	int collided_id = -1;

	float max_speed = 19.f;
	float min_speed = 7.f;
	float friction = 0.0845f;
	float collision_speed = 10.f;
};

