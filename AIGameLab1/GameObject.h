#pragma once
#include "SFML/Graphics.hpp" 

using namespace sf;

class GameObject
{
public:
	GameObject();
	GameObject(std::string txFilename);

	virtual ~GameObject();
	virtual void load(std::string txFilename);
	virtual void draw(sf::RenderWindow & window);
	virtual void update(float elapsedTime);

	virtual void setPosition(float x, float y);
	virtual sf::Vector2f getPosition() const;
	virtual float getWidth() const;
	virtual float getHeight() const;
	virtual sf::IntRect getBoundingRect() const;
	virtual bool isLoaded() const;

	//derived classes to get access to the inherited  private _sprite member.
protected:
	sf::Sprite& getSprite();

private:
	sf::Sprite  _sprite;
	sf::Texture _texture;
	std::string _txFilename;
	bool _isLoaded;

};
