#include "stdafx.h"
#include "Enemy.h"

Enemy::Enemy(float Speed): Ship(Speed)
{
	Ship::mShipTx.loadFromFile("Textures/enemy.png");
	mSprite.setTexture(mShipTx);
}

Enemy::~Enemy()
{
}

void Enemy::update(Vector2f targetPos)
{
}
