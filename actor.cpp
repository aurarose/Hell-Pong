#include "actor.h"
#include "globals.h"

#include <iostream>

using namespace std;

actor::actor(string imgpath,float x,float y,float width,float height){
	this->xpos = x;
	this->ypos = y;
	this->width = width;
	this->height = height;
	this->id = g_cur_id++;

	this->colliders.push_back(hitbox(0,0,width,height));
	this->colliders[0].updatePosition(x, y);

	this->sprite.setTexture(r_manager.lookUp(imgpath));
	this->sprite.setPosition(x, y);

	/*
	sf::Texture texture;
	sf::Sprite sprite;

	if (texture.loadFromFile(imgpath))
		sprite.setTexture(texture);
	this->texture = texture;

	sprite.setPosition(x, y);

	this->sprite = sprite;*/
}

void actor::move(float x, float y){
	this->xpos += x;
	this->ypos += y;
	this->sprite.setPosition(this->xpos, this->ypos);
	for (auto it = this->colliders.begin(); it != this->colliders.end(); it++){
		it->updatePosition(this->xpos, this->ypos);
	}
}

void actor::moveTo(float x, float y){
	if (x >= 0 && x + this->colliders[0].width < 640)
		this->xpos = x;
	else if (x < 0) this->xpos = 0;
	else
		this->xpos = 640 - this->colliders[0].width;
	if (y >= 0 && y < 350)
		this->ypos = y;
	else if (y < 0) this->ypos = 0;
	else
		this->ypos = 480 - 130;
	this->sprite.setPosition(this->xpos, this->ypos);
	for (auto it = this->colliders.begin(); it != this->colliders.end(); it++){
		it->updatePosition(this->xpos, this->ypos);
	}
}

float actor::distanceToActor(actor other){
	float x_dist = this->xpos - other.xpos;
	float y_dist = this->ypos - other.ypos;
	return sqrt(x_dist*x_dist + y_dist*y_dist);
}

bool actor::collidesWithActor(actor other){
	for (auto this_it = this->colliders.begin(); this_it != this->colliders.end(); this_it++){
		for (auto o_it = other.colliders.begin(); o_it != other.colliders.end(); o_it++){
			if (this_it->collides(*o_it)) return true;
		}
	}
	return false;
}

void actor::add(){
}

void actor::cull(){
	actors_cull_list.push_back(this->id);
}

void actor::setHitbox(float x, float y, float width, float height){
	this->colliders.erase(this->colliders.begin(),this->colliders.end());
	this->colliders.push_back(hitbox(x,y,width,height));
}

void actor::addHitbox(float x, float y, float width, float height){
	this->colliders.push_back(hitbox(x, y, width, height));
}
void actor::draw(){
	window.draw(this->sprite);
}
