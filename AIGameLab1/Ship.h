#pragma once
#include "SFML/Graphics.hpp" 
using namespace sf;
enum Orientation {
	VERTICAL, HORIZONTAL, DIAGONAL
};

class Ship : public sf::Drawable
{

public:
	Ship(float Speed);

	~Ship();
	Vector2f mPosition;
	Sprite mSprite;
	Texture mShipTx;
	float mSpeed;
	void moveSprite(float gameTime);
	virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const;
	

private:
	//Prepending 'm' prevents any conflict with method names. 
	//Often your methods and attribute names will be similar, especially for accessors.
	Vector2f mDirection;
	double mAngle;
	float mDynamicHeight, mDynamicWidth;
	Orientation Orientaion = HORIZONTAL;
	void checkWrapAround();
};




