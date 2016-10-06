#include "stdafx.h"
#define _USE_MATH_DEFINES
#include "Ship.h"

extern const int ViewportWidth;
extern const int ViewportHeight;

Ship::Ship(float speed)
{
	Speed = speed;
	shipTx.loadFromFile("Textures/ship.png");
	Sprite.setTexture(shipTx);
	//randomly set the position of the ship within the Viewport
	int offsetForXY = 50;
	int randomX = rand() % ViewportWidth + offsetForXY;
	int randomY = rand() % ViewportHeight + offsetForXY;
	sf::Vector2f position(randomX, randomY);
	Position = position;
	Sprite.setPosition(position);
	//determine the angle the ship is moving
	angle = std::atan2(position.x, position.y) * (180 / M_PI);
	Sprite.setRotation(angle);
}

//TODO:review if i need this (check I'm getting the correct height and width..
//i may use this for different movement later.
void Ship::SpriteOrientation() {
	angle = Sprite.getRotation();
	if ((135 > angle && angle > 45)
		|| (225 < angle && angle < 315)) {
		spriteOrientaion = Vertical;
	}
	else {
		spriteOrientaion = Horizontal;
	}
	//i could determine when it's exactly diagonal - but don't see a need as of yet
	getHeightWidth();
}

void Ship::getHeightWidth() {
	//set the height and width of the ship depending on the way the ship is facing
	//using this because the ship is rectangular 
	//change in orientation affects wrap around world calculation
	if (spriteOrientaion == Horizontal) {
		dynamicHeight = Sprite.getGlobalBounds().height;
		dynamicWidth = Sprite.getGlobalBounds().width;
	}
	else
	{
		dynamicHeight = Sprite.getGlobalBounds().width;
		dynamicWidth = Sprite.getGlobalBounds().height;
	}
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


void Ship::draw(sf::RenderTarget& target, sf::RenderStates states) const {
	target.draw(Sprite, states);
}

void Ship::MoveSprite() {
	SpriteOrientation();//checks which way the sprite is facing
	Direction.x = Speed *  cos(Sprite.getRotation() * (M_PI / 180.f));
	Direction.y = Speed *  sin(Sprite.getRotation() * (M_PI / 180.f));
	Sprite.move(Direction);
	Position = Sprite.getPosition();
	CheckWrapAround();

}

void Ship::CheckWrapAround() {
	//WrapAround movement
	//Check position Y of the ship isn't out of bounds
	if (Position.y + dynamicHeight < 0)
		Position.y = ViewportHeight + dynamicHeight;
	else if (Position.y - dynamicHeight > ViewportHeight)
		Position.y = -dynamicHeight;
	//Check position X of the ship isn't out of bounds
	 if (Position.x - dynamicWidth > ViewportWidth)
		Position.x = -dynamicWidth;
	 else if (Position.x + dynamicWidth < 0)
		 Position.x = ViewportWidth + dynamicWidth;

	Sprite.setPosition(Position);
}
