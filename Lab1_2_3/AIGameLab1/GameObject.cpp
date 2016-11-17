#include "stdafx.h"
#define _USE_MATH_DEFINES
#include "GameObject.h"
#include "MathsUtil.h"
#include "GameConstants.h"

GameObject::GameObject()
{
	_isLoaded = false;
}

GameObject::GameObject(std::string txFilename)
{
	load(txFilename);
	getSprite().setOrigin(getSprite().getTextureRect().width / 2, getSprite().getTextureRect().height / 2);

	int randomAngle = rand() % 360;
	_angle = randomAngle;
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
		_texture.setSmooth(true);
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
	move(elapsedTime);
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

Vector2f GameObject::getVelocity() const
{
	return _velocity;
}

void GameObject::getOrientation()
{
	float length = sqrt((_velocity.x * _velocity.x) + (_velocity.y * _velocity.y));
	if (length > 0)
		getSprite().setRotation(std::atan2(-_velocity.x, _velocity.y) * (180 / M_PI));

}

void GameObject::setTargetPosition(Vector2f targetPosition)
{
	_targetPosition = targetPosition;
}
sf::Sprite& GameObject::getSprite()
{
	return _sprite;
}

bool GameObject::isLoaded() const
{
	return _isLoaded;
}
void GameObject::checkWrapAround()
{
	float mDynamicHeight = getSprite().getGlobalBounds().height;
	float mDynamicWidth = getSprite().getGlobalBounds().width;
	//WrapAround movement
	//Check position Y of the ship isn't out of bounds
	if (getPosition().y + mDynamicHeight < 0)
	{
		setPosition(getPosition().x, GameConstants::SCREEN_HEIGHT + mDynamicHeight);
	}
	else if (getPosition().y - mDynamicHeight > GameConstants::SCREEN_HEIGHT)
	{
		setPosition(getPosition().x, -mDynamicHeight);
	}
	//Check position X of the ship isn't out of bounds
	if (getPosition().x - mDynamicWidth > GameConstants::SCREEN_WIDTH)
	{
		setPosition(-mDynamicWidth, getPosition().y);
	}
	else if (getPosition().x + mDynamicWidth < 0)
	{
		setPosition(GameConstants::SCREEN_WIDTH + mDynamicWidth, getPosition().y);
	}
}

void GameObject::move(float elapsedTime)
{
	getOrientation();
	Vector2f dv = getPosition() + (_velocity * elapsedTime);
	setPosition(dv.x, dv.y);
	checkWrapAround();
}
