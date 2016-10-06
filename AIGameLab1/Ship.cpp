#include "stdafx.h"
#define _USE_MATH_DEFINES
#include "Ship.h"

extern const int ViewportWidth;
extern const int ViewportHeight;

Ship::Ship(float speed)
{
	mSpeed = speed;
	mShipTx.loadFromFile("Textures/ship.png");
	mSprite.setTexture(mShipTx);
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

//TODO:review if i need this (check I'm getting the correct height and width..
//i may use this for different movement later.
void Ship::spriteOrientation() {
	mAngle = mSprite.getRotation();
	if ((135 > mAngle && mAngle > 45)
		|| (225 < mAngle && mAngle < 315)) {
		Orientaion = VERTICAL;
	}
	else {
		Orientaion = HORIZONTAL;
	}
	//i could determine when it's exactly diagonal - but don't see a need as of yet
	getHeightWidth();
}

void Ship::getHeightWidth()
{
	//set the height and width of the ship depending on the way the ship is facing
	//using this because the ship is rectangular 
	//change in orientation affects wrap around world calculation
	if (Orientaion == HORIZONTAL)
	{
		mDynamicHeight = mSprite.getGlobalBounds().height;
		mDynamicWidth = mSprite.getGlobalBounds().width;
	}
	else
	{
		mDynamicHeight = mSprite.getGlobalBounds().width;
		mDynamicWidth = mSprite.getGlobalBounds().height;
	}
}

Ship::~Ship() {}

void Ship::update(sf::Event Event)
{

	if ((Event.type == sf::Event::KeyPressed) && (Event.key.code == sf::Keyboard::Up))
	{
		mSpeed < MaxSpeed ? mSpeed += MinSpeed : mSpeed = MaxSpeed;
	}

	if ((Event.type == sf::Event::KeyPressed) && (Event.key.code == sf::Keyboard::Down))
	{
		mSpeed > MinSpeed ? mSpeed -= MinSpeed : mSpeed = MinSpeed;
	}

	if ((Event.type == sf::Event::KeyPressed) && (Event.key.code == sf::Keyboard::Left))
	{
		mSprite.rotate(-AngleToRotate);
	}

	if ((Event.type == sf::Event::KeyPressed) && (Event.key.code == sf::Keyboard::Right))
	{
		mSprite.rotate(AngleToRotate);
	}

}

void Ship::draw(sf::RenderTarget& target, sf::RenderStates states) const
{
	target.draw(mSprite, states);
}

void Ship::moveSprite()
{
	spriteOrientation();//checks which way the sprite is facing
	mDirection.x = mSpeed *  cos(mSprite.getRotation() * (M_PI / 180.f));
	mDirection.y = mSpeed *  sin(mSprite.getRotation() * (M_PI / 180.f));
	mSprite.move(mDirection);
	mPosition = mSprite.getPosition();
	checkWrapAround();

}

void Ship::checkWrapAround()
{
	//WrapAround movement
	//Check position Y of the ship isn't out of bounds
	if (mPosition.y + mDynamicHeight < 0)
		mPosition.y = ViewportHeight + mDynamicHeight;
	else if (mPosition.y - mDynamicHeight > ViewportHeight)
		mPosition.y = -mDynamicHeight;
	//Check position X of the ship isn't out of bounds
	if (mPosition.x - mDynamicWidth > ViewportWidth)
		mPosition.x = -mDynamicWidth;
	else if (mPosition.x + mDynamicWidth < 0)
		mPosition.x = ViewportWidth + mDynamicWidth;

	mSprite.setPosition(mPosition);
}
