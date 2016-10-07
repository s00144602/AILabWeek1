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
#include "Player.h"
#include "Enemy.h"



////////////////////////////////////////////////////////////
///Entrypoint of application 
//////////////////////////////////////////////////////////// 
//Global variables should be prepended with a 'g'.
//Global constants should be all caps with '_' separators. .. 
//I'll know for again :)
extern const int ViewportWidth = 2000;
extern const int ViewportHeight = 1000;


int main()
{
	sf::Clock clock;
	float gameTime = 0;
	//initialise random seed
	srand(time(NULL));

	sf::ContextSettings settings;
	settings.antialiasingLevel= 4;

	// Create the main window 
	sf::RenderWindow window(sf::VideoMode(ViewportWidth, ViewportHeight, 32), "Randomly starting, infinitely moving Sprites and Circles", sf::Style::Default, settings);
	window.setVerticalSyncEnabled(true);
	window.setFramerateLimit(0);

	Player spaceShip(400);
	Enemy enemyShip(300);
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

			spaceShip.update(Event);
		}
		spaceShip.moveSprite(gameTime);
		enemyShip.moveSprite(gameTime);
		// Get elapsed time since last loop
		//f you don't take in account the time factor, 
		//your simulation won't produce the same results 
		//whether the application runs at 60 frames per seconds or at 1000 frames per seconds.
		sf::Time time = clock.getElapsedTime();
		gameTime = time.asSeconds();
		clock.restart();

		//prepare frame
		window.clear(sf::Color(31, 68, 127));
		//draw frame items
		window.draw(spaceShip);
		
		window.draw(enemyShip);
	
		// Finally, display rendered frame on screen 
		window.display();
		//loop back for next frame
	}

	return EXIT_SUCCESS;

}

