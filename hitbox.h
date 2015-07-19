#pragma once

class hitbox
{
public:
	hitbox(float x, float y, float width, float height);
	float height;
	float width;
	float x_offset;
	float y_offset;
	float xpos;
	float ypos;

	bool collides(hitbox);
	void updatePosition(float,float);
private:
	
};

