#include "stdafx.h"
#include "Game.h"
#include "GameConstants.h"
#include "Player.h"
#include "SeekerObject.h"
#include "GameObjectManager.h"

Game::GameState Game::_gameState = Uninitialized;
sf::RenderWindow Game::_mainWindow;
GameObjectManager Game::_gameObjectManager;
GameObject* player;
GameObject* seeker;

float elapsedTime = 0;

//Thread for the drawing 
void Game::renderingThread(sf::RenderWindow* window)
{
	float timer = 0;
	sf::Clock clock;
	// the rendering loop
	while (window->isOpen())
	{
		elapsedTime = clock.getElapsedTime().asSeconds();
		clock.restart();
		//Display fps in window title
		timer++;
		float fps = 1 / (elapsedTime);
		if (timer == 50) {
			timer = 0;
			std::string s = std::to_string(fps);
			window->setTitle(s);
		}
		// draw...
		window->clear(sf::Color(31, 68, 127));

		 _gameObjectManager.GameObjectManager::DrawAll(*window);

		// Finally, display rendered frame on screen 
		window->display();
	}
}

//Loads all the game objects
void Game::loadGameObjects() 
{
	player = new Player("Textures/1.png");
	seeker = new SeekerObject("Textures/enemy.png");
	seeker->setTargetPosition(player->getPosition());
	_gameObjectManager.Add("Player1", player);
	_gameObjectManager.Add("Seeker", seeker);
}

//starts the game and loads the assets and begins the gameloop
void Game::start(void)
{	
	loadGameObjects();

	if (_gameState != Uninitialized)
		return;

	// Create the main window 
	sf::ContextSettings settings;
	settings.antialiasingLevel = 8;
	_mainWindow.create(sf::VideoMode(GameConstants::SCREEN_WIDTH, GameConstants::SCREEN_HEIGHT, 32), "AI labs week 1-3", sf::Style::Default, settings);
	_mainWindow.setVerticalSyncEnabled(true);
	
	// deactivate its OpenGL context
	_mainWindow.setActive(false);
	
	// launch the rendering thread
	sf::Thread thread(&renderingThread, &_mainWindow);
	thread.launch();

	_gameState = Game::Playing;

	while (!IsExiting())
	{
		seeker->setTargetPosition(player->getPosition());
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

	//Update gameObjects
	_gameObjectManager.updateAll(elapsedTime);

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

		break;
	}
}


