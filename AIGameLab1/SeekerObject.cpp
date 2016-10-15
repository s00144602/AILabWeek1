#include "stdafx.h"
#define  _USE_MATH_DEFINES
#include "SeekerObject.h"
#include "MathsUtil.h"


SeekerObject::SeekerObject(std::string txFileName): GameObject(txFileName)
{
}

SeekerObject::~SeekerObject()
{
}

void SeekerObject::seek()
{
	sf::Vector2f vel = _targetPosition - getPosition();
	vel = MathsUtil::normaliseVector(vel);
	float distance = sqrt((vel.x * vel.x) + (vel.y * vel.y));
	_velocity = vel * _speed;
}

void SeekerObject::update(float elapsedTime)
{
	seek();
	GameObject::update(elapsedTime);
}


