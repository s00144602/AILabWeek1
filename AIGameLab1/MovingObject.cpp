#include "stdafx.h"
#define _USE_MATH_DEFINES
#include "GameConstants.h"
#include "Game.h"
#include "MovingObject.h"

MovingObject::MovingObject()
{
}

MovingObject::MovingObject(std::string txFileName) : GameObject(txFileName)
{
	/* initialize random seed: */
	srand(time(NULL));
	//randomly set the position of the ship within the Viewport
	int offsetForXY = 50;
	int randomX = rand() % GameConstants::SCREEN_WIDTH - offsetForXY;
	int randomY = rand() % GameConstants::SCREEN_HEIGHT - offsetForXY;
	setPosition(randomX, randomY);
	int randomAngle = rand() % 360;
	_angle = randomAngle;
}

MovingObject::~MovingObject()
{

}

void MovingObject::update(float elapsedTime)
{
	move(elapsedTime);
}

Vector2f MovingObject::getVelocity() const
{
	return _velocity;
}

void MovingObject::getOrientation()
{
	float length = sqrt((_velocity.x * _velocity.x) + (_velocity.y * _velocity.y));
	if (length > 0)
		getSprite().setRotation(std::atan2(-_velocity.x, _velocity.y) * (180 / M_PI));
	
}

void MovingObject::setVelocity()
{
	float x = cos(_angle  * (M_PI / 180.f));
	float y = sin(_angle  * (M_PI / 180.f));
	Vector2f dir(x, y);
	_velocity = _speed * dir;
}

float MovingObject::getSpeed() const
{
	return _speed;
}

void MovingObject::checkWrapAround()
{
		float mDynamicHeight = getSprite().getGlobalBounds().height;
		float mDynamicWidth = getSprite().getGlobalBounds().width;
		//WrapAround movement
		//Check position Y of the ship isn't out of bounds
		if (getPosition().y + mDynamicHeight < 0)
		{
			setPosition(getPosition().x, GameConstants::SCREEN_HEIGHT + mDynamicHeight);
		}
		else if (getPosition().y - mDynamicHeight > GameConstants::SCREEN_HEIGHT)
		{
			setPosition(getPosition().x, -mDynamicHeight);
		}
		//Check position X of the ship isn't out of bounds
		if (getPosition().x - mDynamicWidth > GameConstants::SCREEN_WIDTH)
		{
			setPosition(-mDynamicWidth, getPosition().y);
		}
		else if (getPosition().x + mDynamicWidth < 0)
		{
			setPosition(GameConstants::SCREEN_WIDTH + mDynamicWidth, getPosition().y);
		}
}

void MovingObject::move(float elapsedTime)
{
	setVelocity();
	getOrientation();
	Vector2f dv = getPosition() + (_velocity * elapsedTime);
	setPosition(dv.x, dv.y);
	checkWrapAround();
}
