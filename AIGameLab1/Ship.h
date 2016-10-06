#pragma once
#include "SFML/Graphics.hpp" 
using namespace sf;
enum Orientation {
	Vertical, Horizontal, Diagonal
};

class Ship : public sf::Drawable
{

public:
	Ship(float Speed);
	void SpriteOrientation();
	~Ship();

	void Update(sf::Event Event);
	void MoveSprite();
	virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const;
	float Speed;

private:
	sf::Sprite Sprite;
	sf::Vector2f Position;
	sf::Vector2f Direction;
	double angle;
	Texture shipTx;
	float dynamicHeight, dynamicWidth;
	Orientation spriteOrientaion = Horizontal;
	void CheckWrapAround();
	void getHeightWidth();
};




