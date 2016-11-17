#include "stdafx.h"
#define  _USE_MATH_DEFINES
#include "SeekerObject.h"
#include "MathsUtil.h"
#include "GameConstants.h"

SeekerObject::SeekerObject(std::string txFileName): GameObject(txFileName)
{
	//randomly set the position of the ship within the Viewport
	int offsetForXY = 50;
	int randomX = rand() % GameConstants::SCREEN_WIDTH - offsetForXY;
	int randomY = rand() % GameConstants::SCREEN_HEIGHT - offsetForXY;
	setPosition(randomX, randomY);
}

SeekerObject::~SeekerObject()
{
}

void SeekerObject::seek()
{
	sf::Vector2f vel = _targetPosition - getPosition();
	_velocity = MathsUtil::normaliseVector(vel) * MAX_SPEED;
}

void SeekerObject::update(float elapsedTime)
{
	seek();
	GameObject::update(elapsedTime);
}


