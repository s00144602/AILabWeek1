#include "stdafx.h"
#include "SFML/Graphics.hpp" 
#include "MathsUtil.h"


MathsUtil::MathsUtil()
{
}


MathsUtil::~MathsUtil()
{
}

sf::Vector2f MathsUtil::normaliseVector(sf::Vector2f source)
{
	float length = sqrt((source.x * source.x) + (source.y * source.y));
	if (length != 0)
		return sf::Vector2f(source.x / length, source.y / length);
	else
		return source;
}

float MathsUtil::lengthOfVector(sf::Vector2f vector)
{
	return sqrt(pow(vector.x,2) + pow(vector.y,2));
}

float MathsUtil::distanceBetweenVectors(sf::Vector2f v1, sf::Vector2f v2)
{
	return sqrt(pow(v1.x - v2.x,2) + pow(v1.y- v2.y,2));
}

sf::Vector2f MathsUtil::truncate(sf::Vector2f vector, int maxNumber)
{
	int i;
	i = maxNumber / lengthOfVector(vector);
	i = i < 1.0 ? i : 1.0;
	vector.x *= i;
	vector.y *= i;
	return vector;
}
