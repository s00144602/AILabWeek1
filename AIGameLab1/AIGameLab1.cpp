//////////////////////////////////////////////////////////// 
// Headers 
//////////////////////////////////////////////////////////// 
#include "stdafx.h" 
#ifdef _DEBUG 
#pragma comment(lib,"sfml-graphics-d.lib") 
#pragma comment(lib,"sfml-audio-d.lib") 
#pragma comment(lib,"sfml-system-d.lib") 
#pragma comment(lib,"sfml-window-d.lib") 
#pragma comment(lib,"sfml-network-d.lib") 
#else 
#pragma comment(lib,"sfml-graphics.lib") 
#pragma comment(lib,"sfml-audio.lib") 
#pragma comment(lib,"sfml-system.lib") 
#pragma comment(lib,"sfml-window.lib") 
#pragma comment(lib,"sfml-network.lib") 
#endif 
#pragma comment(lib,"opengl32.lib") 
#pragma comment(lib,"glu32.lib") 

#include "SFML/Graphics.hpp" 
#include "SFML/OpenGL.hpp" 
#include <iostream> 
#define _USE_MATH_DEFINES
#include <math.h>



////////////////////////////////////////////////////////////
///Entrypoint of application 
//////////////////////////////////////////////////////////// 

int main()
{
	//initialise random seed
	srand(time(NULL));

	// Create the main window 
	sf::RenderWindow window(sf::VideoMode(2000,1000,32),"Randomly starting, infinitely moving Sprites and Circles");

	//load a font
	sf::Font font;
	font.loadFromFile("C:\\Windows\\Fonts\\GARA.TTF");

	//create a formatted text string
	sf::Text text;
	text.setFont(font);
	text.setString("");
	text.setStyle(sf::Text::Underlined | sf::Text::Italic | sf::Text::Bold);
	text.setPosition(0, 0);
	text.setCharacterSize(40);

	//Speed of objects
	float speed = 0.05f;

	//Random X and Ys for starting positons of White Circle and Ireland Sprite
	int offsetForXY = 50;
	int randomX = rand() % window.getViewport(window.getDefaultView()).width + offsetForXY;
	int randomY = rand() % window.getViewport(window.getDefaultView()).height + offsetForXY;
	
	//Random directions for the sprites
	int randomdirectionX = rand() % 5 + 1;
	int randomdirectionY = rand() % 5 + 1;

	//blue circle- moves straight down and reappears at a random x at the top of the screen
	sf::CircleShape circle2(20);
	circle2.setPosition(200, 400);
	circle2.setFillColor(sf::Color::Blue);

	//White Circle that will move randomly but appears back where is started once it leaves the viewport
	sf::CircleShape circle(30); 
	sf::Vector2f direction1(randomdirectionX, randomdirectionY); //has a random direction
	sf::Vector2f circleStartPos(randomX, randomY); // random start position set --- used later to determine where to re-enter on the screen
	circle.setPosition(circleStartPos);
	sf::Vector2f circleEndPos = circleStartPos; //default endPos with startPos to determine correct re-entry pos using direction
	while (circleEndPos.x > 0 && circleEndPos.y > 0)
	{
		circleEndPos.x -= direction1.x;
		circleEndPos.y -= direction1.y;
	}
	circleEndPos.x = circleEndPos.x - circle.getRadius() * 2;
	circleEndPos.y = circleEndPos.y - circle.getRadius() * 2;

	//Ireland circle sprite moves in the same direction and reappears at eh bottom of the screen where it exited
	sf::Texture texture;
	if (!texture.loadFromFile("ireland.png"))
	{
		circle2.setFillColor(sf::Color::Red); //indicate not loading image
	}
	sf::Sprite sprite;
	sprite.setTexture(texture);
	//reset random directions
	randomdirectionX = rand() % 5;
	randomdirectionY = rand() % 5;
	//direction for second
	sf::Vector2f direction2(-randomdirectionX, -randomdirectionY);
	//rest random postitions
	randomX = rand() % window.getViewport(window.getDefaultView()).width + offsetForXY;
	randomY = rand() % window.getViewport(window.getDefaultView()).height + offsetForXY;
	sf::Vector2f spriteStartPos(randomX, randomY); // random start position set --- used later to determine where to re-enter on the screen
	sprite.setPosition(spriteStartPos);

	// Start game loop 
	while (window.isOpen())
	{
		// Process events 
		sf::Event Event;
		while (window.pollEvent(Event))
		{
			// Close window : exit 
			if (Event.type == sf::Event::Closed)
				window.close();

			// Escape key : exit 
			if ((Event.type == sf::Event::KeyPressed) && (Event.key.code == sf::Keyboard::Escape))
				window.close();

			if ((Event.type == sf::Event::KeyPressed) && (Event.key.code == sf::Keyboard::Up))
				speed < 0.1f ? speed += 0.001f : speed = 0.1f;

			if ((Event.type == sf::Event::KeyPressed) && (Event.key.code == sf::Keyboard::Down))
				speed > 0.001f ?  speed -= 0.001f :  speed = 0.05f;
		}

		//White Circle movement
		circle.move(direction1*speed);
		if (circle.getPosition().x >= window.getViewport(window.getDefaultView()).width) 
			circle.setPosition(circleEndPos.x, circleEndPos.y);

		//Blue circle moves straight down and appears on the top at random postions 
		circle2.move(0, speed);
		if (circle2.getPosition().y + circle2.getRadius() * 2 >= window.getViewport(window.getDefaultView()).height)
		{
			circle2.setPosition(randomX, -circle2.getRadius() * 2);
			randomX = rand() % window.getViewport(window.getDefaultView()).width;
		}
	
		//Ireland Sprite Movement
		sprite.move(direction2*speed);
		if (sprite.getPosition().y <= 0 - sprite.getTextureRect().height)
			sprite.setPosition(sprite.getPosition().x, window.getViewport(window.getDefaultView()).height - sprite.getTextureRect().height);	
		if(sprite.getPosition().x <= 0 - sprite.getTextureRect().width)
			sprite.setPosition(window.getViewport(window.getDefaultView()).width - sprite.getTextureRect().width, window.getViewport(window.getDefaultView()).height - sprite.getTextureRect().height);

		//prepare frame
		window.clear();

		//draw frame items
		window.draw(text);

		window.draw(circle);

		window.draw(circle2);

		window.draw(sprite);

		// Finally, display rendered frame on screen 
		window.display();
	} //loop back for next frame

	return EXIT_SUCCESS;
}
void loadContent() {

}