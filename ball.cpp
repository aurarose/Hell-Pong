
#include <math.h>

#include "ball.h"
#include "globals.h"

#define PI 3.14159265
#define DEG_TO_RAD PI/180

void ball::update(){
	
	// Move
	this->move(this->speed*cos(DEG_TO_RAD*this->direction),
		this->speed*sin(DEG_TO_RAD*this->direction));
	this->speed -= this->friction;
	if (this->speed < this->min_speed) this->speed = this->min_speed;
	else if (this->speed > this->max_speed) this->speed = this->max_speed;
	if (this->collide_timer > 0) this->collide_timer--;
	// Collide with paddles
	
	if (this->collidesWithActor(*player_ptr)&&(this->collide_timer<1||this->collided_id!=player_ptr->id)) {

		this->direction = -45 + 90 * (this->ypos - player_ptr->ypos) / player_ptr->height;
		this->speed += this->collision_speed;
		this->collide_timer = 60;
		this->collided_id = player_ptr->id;
		r_manager.playSound("sound/bounce_orig.wav");

	}
	if (this->collidesWithActor(*enemy_ptr) && (this->collide_timer<1 || this->collided_id != enemy_ptr->id)){
		this->direction = -225 + 90 * (this->ypos - enemy_ptr->ypos) / enemy_ptr->height;
		this->speed += this->collision_speed;
		this->collide_timer = 60;
		this->collided_id = enemy_ptr->id;
		r_manager.playSound("sound/bounce_orig.wav");
	}
	
	// If out of y bounds bounce
	if (this->ypos+this->height > 480 || this->ypos < 0){
		this->direction = -1*this->direction;
		this->speed += this->collision_speed;
		this->collide_timer = 60;
		this->collided_id = -1;
		r_manager.playSound("sound/ricochet.wav");
	}
	// If out of x bounds reset and score
	if (this->xpos > 640){
		g_player_score++;
		r_manager.playSound("sound/hit.wav");
		this->cull();
	}
	else if (this->xpos < 0){
		g_ai_score++;
		r_manager.playSound("sound/hit.wav");
		this->cull();
	}
	if (this->direction > 360)
		this->direction -= 360;
	else if (this->direction < -360){
		this->direction += 360;
	}
}

void ball::reset(){
	this->moveTo(320, 240);
	this->direction = rand()%360*1.f;
	this->speed = this->max_speed/2;
}