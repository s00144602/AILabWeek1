#include "stdafx.h"
#include "Player.h"


Player::Player(float speed) : Ship(speed)
{
	Ship::mShipTx.loadFromFile("Textures/ship.png");
	mSprite.setTexture(mShipTx);
}

Player::Player() : Ship(8)
{
	Ship::mShipTx.loadFromFile("Textures/ship.png");
	mSprite.setTexture(mShipTx);
}


void Player::update(sf::Event Event)
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

Player::~Player()
{
}
