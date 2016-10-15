#include "stdafx.h"
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
