#include "stdafx.h"
#define _USE_MATH_DEFINES
#include "Player.h"
#include "GameConstants.h"
#include "MathsUtil.h"

Player::Player(std::string asset) : GameObject(asset)
{
	//randomly set the position of the ship within the Viewport
	int offsetForXY = 50;
	int randomX = rand() % GameConstants::SCREEN_WIDTH - offsetForXY;
	int randomY = rand() % GameConstants::SCREEN_HEIGHT - offsetForXY;
	setPosition(randomX, randomY);
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
		_speed > 0.001f ? _speed -= SPEED_CHANGER : _speed = MIN_SPEED;
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

void Player::setVelocity()
{
	float x = cos(_angle  * (M_PI / 180.f));
	float y = sin(_angle  * (M_PI / 180.f));
	Vector2f dir(x, y);
	dir = MathsUtil::normaliseVector(dir);
	_velocity = _speed * dir;
}

void Player::update(float elapsedTime)
{
	setVelocity();

	speedInput(elapsedTime);

	turnInput(elapsedTime);

	GameObject::update(elapsedTime);
}

