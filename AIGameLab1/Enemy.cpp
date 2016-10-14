#include "stdafx.h"
#define _USE_MATH_DEFINES
#include "Enemy.h"

Enemy::Enemy(float Speed): Ship(Speed)
{
	Ship::mShipTx.loadFromFile("Textures/enemy.png");
	mSprite.setTexture(mShipTx);
	mSprite.setOrigin(mSprite.getTextureRect().width / 2, mSprite.getTextureRect().height / 2);
}

Enemy::~Enemy()
{
}

void Enemy::update(Vector2f targetPos, float gameTime)
{
	seek(targetPos);
	Ship::moveSprite(gameTime);
}

Vector2f Enemy::seek(Vector2f targetPos)
{
	float maxSpeed = 0.8f;
	sf::Vector2f vel = targetPos - Ship::mPosition;
	float distance = sqrt((vel.x * vel.x) + (vel.y * vel.y));
	vel = normalize(vel);
	return vel;
}
