#pragma once
#include "GameObject.h"

class MovingObject : public GameObject
{
public:
	MovingObject();
	MovingObject(std::string asset);
	~MovingObject();

	virtual void update(float elapsedTime);
	Vector2f getVelocity() const;
	void getOrientation();
	void setVelocity();
	float getSpeed() const;

protected:
	const float MAX_SPEED = 1;
	float _speed = 0.3f;
	void checkWrapAround();
	float _angle;

private:
	void move(float elapsedTime);
	Vector2f _velocity; 

};

