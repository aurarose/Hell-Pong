#pragma once
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include "hitbox.h"

using namespace std;

class hitbox;

class actor
{
public:
	actor(string,float,float,float,float);

	float xpos;
	float ypos;
	float width;
	float height;
	int id;
	vector<hitbox> colliders;

	void draw();

	// moves x units right and y units down
	void move(float, float);
	// moves to point (x,y)
	void moveTo(float, float);

	void setHitbox(float, float, float, float);
	void addHitbox(float,float,float,float);
	virtual void update(){}
	float distanceToActor(actor);
	bool collidesWithActor(actor);

	void add();
	void cull();

protected:
	sf::Sprite sprite;
};

