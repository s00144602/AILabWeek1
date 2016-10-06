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

	void update(sf::Event Event);
	void moveSprite();
	void spriteOrientation();
	virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const;
	

private:
	//Prepending 'm' prevents any conflict with method names. 
	//Often your methods and attribute names will be similar, especially for accessors.
	sf::Sprite mSprite;
	sf::Vector2f mPosition;
	sf::Vector2f mDirection;
	double mAngle;
	float mSpeed;
	const float MaxSpeed = 0.45f;
	const float MinSpeed = 0.01f;
	const float AngleToRotate = 3;
	Texture mShipTx;
	float mDynamicHeight, mDynamicWidth;
	Orientation Orientaion = HORIZONTAL;
	void checkWrapAround();
	void getHeightWidth();
};




