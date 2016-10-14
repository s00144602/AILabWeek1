#include "stdafx.h"
#define _USE_MATH_DEFINES
#include "Ship.h"

extern const int ViewportWidth;
extern const int ViewportHeight;

void Ship::setOrientaion(Vector2f velocity)
{
	float length = sqrt((velocity.x * velocity.x) + (velocity.y * velocity.y));
	if(length > 0)
		mSprite.setRotation(std::atan2(-velocity.x, velocity.y) * (180 / M_PI));
}

Ship::Ship(float speed)
{
	mSpeed = speed;
	//randomly set the position of the ship within the Viewport
	int offsetForXY = 50;
	int randomX = rand() % ViewportWidth + offsetForXY;
	int randomY = rand() % ViewportHeight + offsetForXY;
	sf::Vector2f position(randomX, randomY);
	mPosition = position;
	mSprite.setPosition(position);
	//determine the angle the ship is moving
	setOrientaion(normalize(position));
}

Ship::~Ship() {}

void Ship::draw(sf::RenderTarget& target, sf::RenderStates states) const
{
	target.draw(mSprite, states);
}

void Ship::moveSprite(float gameTime)
{
	mVelocity.x = mSpeed *  cos(mSprite.getRotation() * (M_PI / 180.f))* gameTime;
	mVelocity.y = mSpeed *  sin(mSprite.getRotation() * (M_PI / 180.f))* gameTime;
	mSprite.setPosition(mPosition +(mVelocity));
	mPosition = mSprite.getPosition();
	checkWrapAround();
}

void Ship::checkWrapAround()
{
	mDynamicHeight = mSprite.getGlobalBounds().height;
	mDynamicWidth = mSprite.getGlobalBounds().width;
	//WrapAround movement
	//Check position Y of the ship isn't out of bounds
	if (mPosition.y + mDynamicHeight < 0)
	{
		mPosition.y = ViewportHeight + mDynamicHeight;
	}
	else if (mPosition.y - mDynamicHeight > ViewportHeight)
	{
		mPosition.y = -mDynamicHeight;
	}
	//Check position X of the ship isn't out of bounds
	if (mPosition.x - mDynamicWidth > ViewportWidth)
	{
		mPosition.x = -mDynamicWidth;
	}
	else if (mPosition.x + mDynamicWidth < 0)
	{
		mPosition.x = ViewportWidth + mDynamicWidth;
	}
	mSprite.setPosition(mPosition);
}

Vector2f Ship::normalize(Vector2f source)
{
	float length = sqrt((source.x * source.x) + (source.y * source.y));
	if (length != 0)
		return Vector2f(source.x / length, source.y / length);
	else
		return source;
}
