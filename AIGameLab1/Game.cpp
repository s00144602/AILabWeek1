#include "stdafx.h"
#include "Game.h"
#include "Player.h"
#include "Enemy.h"
#include "MovingObject.h"
#include "GameObject.h"
#include "GameObjectManager.h"

//Global variables should be prepended with a 'g'.
//Global constants should be all caps with '_' separators. .. 
//I'll know for again :)
extern const int ViewportWidth = 1500;
extern const int ViewportHeight = 750;
Game::GameState Game::_gameState = Uninitialized;
sf::RenderWindow Game::_mainWindow;
GameObjectManager Game::_gameObjectManager;
GameObject* test;

Player spaceShip(0.5f);
Enemy enemyShip(0.2f);
float currentTime = 0;
//GameObjectManager* _gameObjectManager;
void Game::renderingThread(sf::RenderWindow* window)
{
	float timer = 0;
	sf::Clock clock;
	// the rendering loop
	while (window->isOpen())
	{
		currentTime = clock.getElapsedTime().asSeconds();
		clock.restart();

		//Display fps in window title
		timer++;
		float fps = 1 / (currentTime);
		if (timer == 50) {
			timer = 0;
			std::string s = std::to_string(fps) + "Player 1 x: " + std::to_string(round(spaceShip.mPosition.x))
				+ " y: " + std::to_string(round(spaceShip.mPosition.y))
				+ "  .. E x: " + std::to_string(round(enemyShip.mPosition.x))
				+ " y: " + std::to_string(round(enemyShip.mPosition.y));

			window->setTitle(s);
		}
		// draw...
		window->clear(sf::Color(31, 68, 127));
		
		 _gameObjectManager.GameObjectManager::DrawAll(*window);
		window->draw(spaceShip);

		window->draw(enemyShip);

		// Finally, display rendered frame on screen 
		window->display();
	}
}


void Game::Start(void)
{
	
	if (_gameState != Uninitialized)
		return;

	test = new MovingObject("Textures/ship.png");
	test->setPosition(300, 300);
	_gameObjectManager.Add("testShip", test);
	
	// Create the main window 
	sf::ContextSettings settings;
	settings.antialiasingLevel = 8;
	_mainWindow.create(sf::VideoMode(ViewportWidth, ViewportHeight, 32), "AI labs week 1-3", sf::Style::Default, settings);
	_mainWindow.setVerticalSyncEnabled(true);
	// deactivate its OpenGL context
	_mainWindow.setActive(false);
	// launch the rendering thread
	sf::Thread thread(&renderingThread, &_mainWindow);
	thread.launch();

	_gameState = Game::Playing;

	while (!IsExiting())
	{
		GameLoop();
	}

	_mainWindow.close();
}

sf::RenderWindow & Game::getWindow()
{
	return _mainWindow;
}

const bool Game::isKeyPress(sf::Keyboard::Key key)
{
	if (sf::Keyboard::isKeyPressed(key))
		return true;
	return false;

}

bool Game::IsExiting()
{
	if (_gameState == Game::Exiting)
		return true;
	else
		return false;
}

void Game::GameLoop()
{
	sf::Event currentEvent;
	spaceShip.update(currentTime);
	enemyShip.update(spaceShip.mPosition, currentTime);
	while (_mainWindow.pollEvent(currentEvent))
	{
		//TODO: revise switch statement for game states
		if (currentEvent.type == sf::Event::Closed)
		{
			_gameState = Game::Exiting;
		}

		// Escape key : exit 
		if ((currentEvent.type == sf::Event::KeyPressed) && (currentEvent.key.code == sf::Keyboard::Escape))
			_mainWindow.close();
		else if (currentEvent.type == sf::Event::KeyPressed)
		{
			spaceShip.inputEvent(currentEvent.key.code);
		}

		break;
	}
}


