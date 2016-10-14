#include "stdafx.h"
#include "MovingObject.h"


MovingObject::MovingObject()
{
}

MovingObject::MovingObject(std::string txFileName) : GameObject(txFileName)
{
	
}

MovingObject::~MovingObject()
{

}

void MovingObject::update(float elapsedTime)
{
}

//void MovingObject::draw(sf::RenderWindow & rw) : GameObject(rw);
//{
//}

float MovingObject::getVelocity() const
{
	return _velocity;
}
