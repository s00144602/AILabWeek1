#pragma once
#include "SFML/Graphics.hpp" 

class SimpleSprite : public sf::Drawable
{
	enum Direction {
		Down, Left, Right, Up
	};

public:
	SimpleSprite(const sf::Texture& texture, sf::Vector2f position, float Speed);
	~SimpleSprite();

	void Update(sf::Event Event);
	void Draw(sf::RenderWindow window);
	void MoveSprite(int ViewportWidth, int ViewportHeight);
	virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const;
	float Speed;

private:
	sf::Sprite Sprite;
	sf::Vector2f Position;
	sf::Vector2f Direction;
};




