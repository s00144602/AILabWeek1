#include "stdafx.h"
#include "Player.h"


Player::Player(float speed) : Ship(speed)
{
	Ship::mShipTx.loadFromFile("Textures/1.png");
	mSprite.setTexture(mShipTx);
	mSprite.setOrigin(mSprite.getTextureRect().width / 2, mSprite.getTextureRect().height / 2);
}

Player::Player() : Ship(8)
{
	Ship::mShipTx.loadFromFile("Textures/ship.png");
	mSprite.setTexture(mShipTx);
}

void Player::update(float gameTime)
{
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
	{
		mSprite.setRotation(mSprite.getRotation()-(AngleToRotate*gameTime));
	}

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
	{
		mSprite.setRotation(mSprite.getRotation()+(AngleToRotate*gameTime));
	}

	moveSprite(gameTime);
}

void Player::inputEvent(sf::Keyboard::Key key)
{
	float diff = 0.1f;
	if (key == (sf::Keyboard::Up))
	{
			mSpeed <= MaxSpeed ? mSpeed += diff : mSpeed = MaxSpeed;
	}

	if (key == (sf::Keyboard::Down))
	{
		mSpeed >= MinSpeed ? mSpeed -= diff : mSpeed = MinSpeed;

	}
}

Player::~Player()
{
}
