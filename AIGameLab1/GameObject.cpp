#include "stdafx.h"
#include "GameObject.h"

extern const int ViewportWidth;
extern const int ViewportHeight;

GameObject::GameObject()
{
	_isLoaded = false;
}

GameObject::GameObject(std::string txFilename)
{
	load(txFilename);
	getSprite().setOrigin(getSprite().getTextureRect().width / 2, getSprite().getTextureRect().height / 2);
}

GameObject::~GameObject()
{
}

void GameObject::load(std::string txFilename)
{
	if (_texture.loadFromFile(txFilename) == false)
	{
		_txFilename = "";
		_isLoaded = false;
	}
	else
	{
		_txFilename = txFilename;
		_sprite.setTexture(_texture);
		_isLoaded = true;
	}
}

void GameObject::draw(sf::RenderWindow & renderWindow)
{
	if (_isLoaded)
	{
		renderWindow.draw(_sprite);
	}
}

void GameObject::update(float elapsedTime)
{

}

void GameObject::setPosition(float x, float y)
{
	if (_isLoaded)
	{
		_sprite.setPosition(x, y);
	}
}

sf::Vector2f GameObject::getPosition() const
{
	if (_isLoaded)
	{
		return _sprite.getPosition();
	}
	return sf::Vector2f();
}

float GameObject::getWidth() const
{
	return _sprite.getTextureRect().width;
}

float GameObject::getHeight() const
{
	return _sprite.getTextureRect().height;
}

sf::IntRect GameObject::getBoundingRect() const
{
	return _sprite.getTextureRect();
}


sf::Sprite& GameObject::getSprite()
{
	return _sprite;
}

bool GameObject::isLoaded() const
{
	return _isLoaded;
}
