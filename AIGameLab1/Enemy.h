#pragma once
#include "SFML/Graphics.hpp" 
using namespace sf;
#include "Ship.h"
#include "Player.h"

class Enemy : public Ship
{
	enum MovementState {
		SEEKING, FLEEING, 
	};

public:
	Enemy(float Speed);
	~Enemy();

	void update(Vector2f targetPos, float gameTime);

private:
	Vector2f seek(Vector2f targetPos);
};

