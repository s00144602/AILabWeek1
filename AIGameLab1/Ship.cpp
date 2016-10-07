#include "stdafx.h"
#define _USE_MATH_DEFINES
#include "Ship.h"

extern const int ViewportWidth;
extern const int ViewportHeight;

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
	mAngle = std::atan2(position.x, position.y) * (180 / M_PI);
	mSprite.setRotation(mAngle);
}

Ship::~Ship() {}

void Ship::draw(sf::RenderTarget& target, sf::RenderStates states) const
{
	target.draw(mSprite, states);
}

void Ship::moveSprite(float gameTime)
{
	mDirection.x = mSpeed *  cos(mSprite.getRotation() * (M_PI / 180.f));
	mDirection.y = mSpeed *  sin(mSprite.getRotation() * (M_PI / 180.f));
	mSprite.move(mDirection * gameTime);
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
