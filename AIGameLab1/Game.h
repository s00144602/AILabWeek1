#pragma once
#include "SFML/Window.hpp"
#include "SFML/Graphics.hpp"
#include "GameObjectManager.h"
#include "MovingObject.h"

class Game
{
public:
	static void Start();
	static sf::RenderWindow& getWindow();
	const static bool isKeyPress(sf::Keyboard::Key key);
	const static int SCREEN_WIDTH = 1024;
	const static int SCREEN_HEIGHT = 768;

private:
	static void renderingThread(sf::RenderWindow* window);
	static bool IsExiting();
	static void GameLoop();
	//TODO: revise. will use this later ... not needed as of yet
	enum GameState {
		Uninitialized, ShowingSplash, Paused,
		ShowingMenu, Playing, Exiting
	};

	static GameState _gameState;
	static sf::RenderWindow _mainWindow;
	static GameObjectManager _gameObjectManager;
};
