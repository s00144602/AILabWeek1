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
#include "SimpleSprite.h"


////////////////////////////////////////////////////////////
///Entrypoint of application 
//////////////////////////////////////////////////////////// 

int main()
{
	//initialise random seed
	srand(time(NULL));

	int ViewportWidth = 2000;
	int ViewportHeight = 1000;
	// Create the main window 
	sf::RenderWindow window(sf::VideoMode(ViewportWidth, ViewportHeight, 32), "Randomly starting, infinitely moving Sprites and Circles");

	//Ireland circle sprite moves in the same direction and reappears at eh bottom of the screen where it exited
	sf::Texture spaceShipTx;
	spaceShipTx.loadFromFile("ireland.png");
	int offsetForXY = 50;
	int randomX = rand() % ViewportWidth + offsetForXY;
	int randomY = rand() % ViewportHeight + offsetForXY;
	sf::Vector2f position(randomX, randomY);
	SimpleSprite spaceShip(spaceShipTx, position , 0.01);

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
				spaceShip.Update(Event);
			}

			spaceShip.MoveSprite(ViewportWidth,ViewportHeight);

			//prepare frame
			window.clear();
			//draw frame items
			window.draw(spaceShip);
			// Finally, display rendered frame on screen 
			window.display();
			//loop back for next frame
		}

	return EXIT_SUCCESS;

}

