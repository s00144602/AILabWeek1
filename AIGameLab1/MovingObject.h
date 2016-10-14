#pragma once
#include "GameObject.h"

class MovingObject : public GameObject
{
public:
	MovingObject();
	MovingObject(std::string asset);
	~MovingObject();

	void update(float elapsedTime);
//	void draw(sf::RenderWindow& rw);

	float getVelocity() const;

private:
	float _velocity;  // -- left ++ right
	float _maxVelocity;
};

