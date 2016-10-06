#pragma once
#include "SFML/Graphics.hpp" 
using namespace sf;

class Ship : public sf::Drawable
{
	enum Direction {
		Down, Left, Right, Up
	};

	

public:
	Ship(float Speed);
	~Ship();

	void Update(sf::Event Event);
	void Draw(sf::RenderWindow window);
	void MoveSprite();
	virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const;
	float Speed;

private:
	sf::Sprite Sprite;
	sf::Vector2f Position;
	sf::Vector2f Direction;
	double angle;
	Texture shipTx;
};




