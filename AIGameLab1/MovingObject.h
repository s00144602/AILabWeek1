#pragma once
#include "VisibleGameObject.h"

class MovingObject : public VisibleGameObject
{
public:
	MovingObject();
	MovingObject(std::string asset, Vector2f position);
	~MovingObject();

	void update(float elapsedTime);
//	void draw(sf::RenderWindow& rw);

	float getVelocity() const;

private:
	float _velocity;  // -- left ++ right
	float _maxVelocity;
};

