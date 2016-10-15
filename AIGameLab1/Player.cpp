#include "stdafx.h"
#include "Player.h"


Player::Player(std::string asset) : GameObject(asset)
{

}

Player::~Player()
{
}

void Player::speedInput(float elapsedTime)
{
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up))
	{
		_speed <= MAX_SPEED ? _speed += SPEED_CHANGER : _speed = MAX_SPEED;
	}

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down))
	{
		_speed > MIN_SPEED ? _speed -= SPEED_CHANGER : _speed = MIN_SPEED;
	}
}

void Player::turnInput(float elapsedTime)
{
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
	{
		_angle -= ROTATION_ANGLE * elapsedTime;
	}

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
	{
		_angle += ROTATION_ANGLE * elapsedTime;
	}
}

void Player::update(float elapsedTime)
{
	setVelocity();

	speedInput(elapsedTime);

	turnInput(elapsedTime);

	GameObject::update(elapsedTime);
}

