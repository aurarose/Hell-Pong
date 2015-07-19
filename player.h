#pragma once
#include "paddle.h"

class player :public paddle
{
public:
	player(string imgpath, float x, float y,float width,float height) :paddle(imgpath,x, y,width,height){
		this->shot_delay = 15;
	};
	//~player();
	void update() override;
protected:
	void processMovement();
	void shoot();
private:
	float last_y=-1;

};

