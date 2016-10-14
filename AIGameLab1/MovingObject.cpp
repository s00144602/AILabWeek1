#include "stdafx.h"
#include "MovingObject.h"


MovingObject::MovingObject()
{
}

MovingObject::MovingObject(std::string txFileName, Vector2f position) : VisibleGameObject(txFileName, position)
{
	
}

MovingObject::~MovingObject()
{

}

void MovingObject::update(float elapsedTime)
{
}

//void MovingObject::draw(sf::RenderWindow & rw) : VisibleGameObject(rw);
//{
//}

float MovingObject::getVelocity() const
{
	return 0.0f;
}
