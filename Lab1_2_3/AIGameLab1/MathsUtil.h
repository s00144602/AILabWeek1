#pragma once
#include "stdafx.h"
#include "SFML/Graphics.hpp" 

class MathsUtil
{
public:
	MathsUtil();
	~MathsUtil();

	static sf::Vector2f normaliseVector(sf::Vector2f vector);
	static float lengthOfVector(sf::Vector2f vector);
	static float distanceBetweenVectors(sf::Vector2f v1, sf::Vector2f v2);
	static sf::Vector2f truncate(sf::Vector2f vector, int maxNumber);
};

