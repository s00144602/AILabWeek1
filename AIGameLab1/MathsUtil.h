#pragma once
#include "stdafx.h"
#include "SFML/Graphics.hpp" 

class MathsUtil
{
public:
	MathsUtil();
	~MathsUtil();

	static sf::Vector2f normaliseVector(sf::Vector2f vector);
};

