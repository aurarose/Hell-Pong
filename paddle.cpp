#include "paddle.h"
#include "globals.h"
#include <iostream>

void paddle::processMovement(){
	// Move toward closest ball
	actor_ptr target = actors.begin()->second;
	for (auto it = actors.begin(); it!=actors.end(); it++){
		if (it->first<2){
			continue;
		}
		actor_ptr cur = it->second;
		if (this->distanceToActor(*cur) < this->distanceToActor(*target)){
			target = it->second;
		}
	}
	
	if (this->ypos + this->move_speed < target->ypos) this->move(0, this->move_speed );
	else if (this->ypos - this->move_speed>target->ypos) this->move(0, -this->move_speed);

	// Shoot
	this->shoot();
}	

void paddle::shoot(){
	if (this->shot_timer < 1){
		actor_ptr b = actor_ptr(new ball("images/ball.png", xpos, ypos, 64, 180));
		actors_add_list.push_back(b);
		this->shot_timer = this->shot_delay;
	}

}

void paddle::update(){
	this->processMovement();
	//boundPosition();
	if (this->ypos + this->height > 480) this->ypos = 480 - this->height;
	else if (this->ypos < 0) this->ypos = 0;
	if (shot_timer>0)shot_timer--;
}
