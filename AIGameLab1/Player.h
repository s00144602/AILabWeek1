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
	
	void update(sf::Event Event);
	
private:

	const float MaxSpeed = 1500;
	const float MinSpeed = 250;
	const float AngleToRotate = 3;
};

