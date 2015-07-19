#include "player.h"
#include "globals.h"
#include <iostream>

void player::processMovement(){
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up)){
		this->move(0.f, -15.f);
		this->last_y = -1;
	}
		
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down)){
		this->move(0.f, 15.f);
		this->last_y = -1;
	}
	if (this->last_y == -1) this->last_y = sf::Mouse::getPosition().y;
	float y = sf::Mouse::getPosition().y;
	float delta_y = y-this->last_y;

	if (delta_y != 0){
		this->moveTo(this->xpos, y);
	}

	if (sf::Mouse::isButtonPressed(sf::Mouse::Left) || sf::Keyboard::isKeyPressed(sf::Keyboard::Space)){
		player::shoot();
	}
}

void player::shoot(){
	
	if (this->shot_timer < 1){
		actor_ptr b = actor_ptr(new ball("images/ball.png", xpos, ypos, 64, 0));
		actors_add_list.push_back(b);
		this->shot_timer = this->shot_delay;

	}
		
}

void player::update(){
	this->processMovement();
	if (this->ypos > 335) this->ypos = 335;
	else if (this->ypos < 0) this->ypos = 0;
	if (shot_timer>0)shot_timer--;
}

