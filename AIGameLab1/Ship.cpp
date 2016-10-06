#include "stdafx.h"
#define _USE_MATH_DEFINES
#include "Ship.h"

extern const int ViewportWidth;
extern const int ViewportHeight;

Ship::Ship(float speed)
{
	Speed = speed;
	shipTx.loadFromFile("Textures/ship.png");
	int offsetForXY = 50;
	int randomX = rand() % ViewportWidth + offsetForXY;
	int randomY = rand() % ViewportHeight + offsetForXY;
	sf::Vector2f position(randomX, randomY);
	Sprite.setTexture(shipTx);

	Position = position;
	Sprite.setPosition(position);
	angle = std::atan2(position.x, position.y) * (180 / M_PI);

	Sprite.setRotation(angle);



}

Ship::~Ship() {}

void Ship::Update(sf::Event Event)
{
	if ((Event.type == sf::Event::KeyPressed) && (Event.key.code == sf::Keyboard::Up))
	{
		Speed < 0.5f ? Speed += 0.01f : Speed = 0.5f;
	}

	if ((Event.type == sf::Event::KeyPressed) && (Event.key.code == sf::Keyboard::Down))
	{
		Speed > 0.01f ? Speed -= 0.01f : Speed = 0.01f;
	}

	if ((Event.type == sf::Event::KeyPressed) && (Event.key.code == sf::Keyboard::Left))
	{
		Sprite.setRotation(Sprite.getRotation() - 3);
	}

	if ((Event.type == sf::Event::KeyPressed) && (Event.key.code == sf::Keyboard::Right))
	{
		Sprite.setRotation(Sprite.getRotation() + 3);
	}

}

void Ship::Draw(sf::RenderWindow window)
{
	window.draw(Sprite);
}

void Ship::draw(sf::RenderTarget& target, sf::RenderStates states) const {
	target.draw(Sprite, states);
}

void Ship::MoveSprite() {
	Direction.x = Speed *  cos(Sprite.getRotation() * (M_PI / 180.f));
	Direction.y = Speed *  sin(Sprite.getRotation() * (M_PI / 180.f));
	Sprite.move(Direction);
	//WrapAround movement
	//TODO : use the angle and setDirection to indicate  
	//what height and width to use for the buffer of the wrap around effect
	if (Sprite.getPosition().y < 0)
		Sprite.setPosition(Sprite.getPosition().x, ViewportHeight);
	else if (Sprite.getPosition().y > ViewportHeight)
		Sprite.setPosition(Sprite.getPosition().x, 0);
	//Check the direction the ship is moving in the x and reset accordingly
	if (Sprite.getPosition().x > ViewportWidth)
		Sprite.setPosition(0, Sprite.getPosition().y);
	else if (Sprite.getPosition().x < 0)
		Sprite.setPosition(ViewportWidth, Sprite.getPosition().y);

}
