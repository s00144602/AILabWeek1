#include "stdafx.h"
#include "SimpleSprite.h"

SimpleSprite::SimpleSprite(const sf::Texture &texture, sf::Vector2f position, float speed)
{
	Sprite.setTexture(texture);
	Speed = speed;
	Position = position;
	Sprite.setPosition(position);
	//Random directions for the sprites
	Direction.x = rand() % 5 + 1;
	Direction.y = -rand() % 5 + 1;
}

SimpleSprite::~SimpleSprite(){}

void SimpleSprite::Update(sf::Event Event)
{
	if ((Event.type == sf::Event::KeyPressed) && (Event.key.code == sf::Keyboard::Up))
		Speed < 0.1f ? Speed += 0.001f : Speed = 0.1f;

	if ((Event.type == sf::Event::KeyPressed) && (Event.key.code == sf::Keyboard::Down))
		Speed > 0.002f ? Speed -= 0.001f : Speed = 0.002f;

}

void SimpleSprite::Draw(sf::RenderWindow window)
{
	window.draw(Sprite);
}

void SimpleSprite::draw(sf::RenderTarget& target, sf::RenderStates states) const {
	target.draw(Sprite, states);
}

void SimpleSprite::MoveSprite(int ViewportWidth, int ViewportHeight) {
	//Ireland Sprite Movement
	Sprite.move(Direction*Speed);
	if (Sprite.getPosition().y <= 0 - Sprite.getTextureRect().height)
		Sprite.setPosition(Sprite.getPosition().x, ViewportHeight - Sprite.getTextureRect().height);
	if (Direction.x > 0) {
		if (Sprite.getPosition().x >= ViewportWidth + Sprite.getTextureRect().width)
			Sprite.setPosition(0 - Sprite.getTextureRect().width, Sprite.getPosition().y);
	}
	else {
		if (Sprite.getPosition().x <= 0 - Sprite.getTextureRect().width)
			Sprite.setPosition(ViewportWidth + Sprite.getTextureRect().width, Sprite.getPosition().y);
	}
}