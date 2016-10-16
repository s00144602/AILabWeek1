#include "stdafx.h"
#include "ArrivingObject.h"
#include "MathsUtil.h"
#include "GameConstants.h"

ArrivingObject::ArrivingObject(std::string txFilename) : GameObject(txFilename)
{
	//randomly set the position of the ship within the Viewport
	int offsetForXY = 50;
	int randomX = rand() % GameConstants::SCREEN_WIDTH - offsetForXY;
	int randomY = rand() % GameConstants::SCREEN_HEIGHT - offsetForXY;
	setPosition(randomX, randomY);
}


ArrivingObject::~ArrivingObject()
{
}

void ArrivingObject::update(float elapseTime)
{
	getTargetVelocity();
	GameObject::update(elapseTime);
}

void ArrivingObject::getTargetVelocity()
{
	Vector2f desiredVel = _targetPosition - getPosition();
	float distance = MathsUtil::lengthOfVector(desiredVel);
	if (distance < _arrivalRadius) 
	{
		_speed = 0;
	}
	else if (distance > _slowRadius)
	{
		_speed = MAX_SPEED;
	}
	else 
	{
		_speed = MAX_SPEED * (distance / _slowRadius);
	}

	_velocity = MathsUtil::normaliseVector(desiredVel) * _speed;

	//_velocity = MathsUtil::truncate(_velocity, MAX_SPEED);
}

