#include "stdafx.h"
#include "VisibleGameObject.h"

VisibleGameObject::VisibleGameObject()
{
	_isLoaded = false;
}

VisibleGameObject::VisibleGameObject(std::string txFilename, Vector2f pos)
{
	load(txFilename);
	setPosition(pos.x, pos.y);
	getSprite().setOrigin(getSprite().getScale().x / 2, getSprite().getScale().y / 2);
}

VisibleGameObject::~VisibleGameObject()
{
}

void VisibleGameObject::load(std::string txFilename)
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

void VisibleGameObject::draw(sf::RenderWindow & renderWindow)
{
	if (_isLoaded)
	{
		renderWindow.draw(_sprite);
	}
}

void VisibleGameObject::update(float elapsedTime)
{
}

void VisibleGameObject::setPosition(float x, float y)
{
	if (_isLoaded)
	{
		_sprite.setPosition(x, y);
	}
}

sf::Vector2f VisibleGameObject::getPosition() const
{
	if (_isLoaded)
	{
		return _sprite.getPosition();
	}
	return sf::Vector2f();
}

sf::Sprite& VisibleGameObject::getSprite()
{
	return _sprite;
}

bool VisibleGameObject::isLoaded() const
{
	return _isLoaded;
}
