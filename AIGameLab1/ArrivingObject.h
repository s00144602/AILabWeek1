#pragma once
#include "GameObject.h"

class ArrivingObject : public GameObject
{
public:
	ArrivingObject(std::string txFilename);
	~ArrivingObject();
	void update(float elapseTime);

private:
	void getTargetVelocity();
	float _speed = 0.2f;
	float _acceleration = 0.1f;
	const float MAX_SPEED = 1;
	const float _arrivalRadius = 10;
	const float _slowRadius= 100;
	float _maxAcceleration;
	float _timeToTarget;
};

