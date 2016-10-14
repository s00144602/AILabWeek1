#pragma once
#include "SFML/Graphics.hpp" 
#include "Ship.h"
using namespace sf;

class Player : public Ship
{
public:
	Player(float Speed);
	~Player();

	Player();
	
	void update(float gameTime);
	void inputEvent(sf::Keyboard::Key key);
	
private:

	const float MaxSpeed = 2;
	const float MinSpeed = 0.01f;
	const float AngleToRotate = 0.1f;
};

