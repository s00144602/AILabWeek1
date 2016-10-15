#pragma once
#include "GameObject.h"

class Player : public GameObject
{
public:
	Player(std::string asset);
	~Player();
	void update(float elapsedTime);
private:
	void speedInput(float elapsedTime);
	void turnInput(float elapsedTime);
	const float ROTATION_ANGLE = 0.1f;
	const float SPEED_CHANGER = 0.1f;
	const float MIN_SPEED = 0.1f;
};

