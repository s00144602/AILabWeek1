#pragma once
#include "SFML/Window.hpp"
#include "SFML/Graphics.hpp"
#include "GameObjectManager.h"

class Game
{
public:
	static void Start();

private:
	static void renderingThread(sf::RenderWindow* window);
	static bool IsExiting();
	static void GameLoop();

	enum GameState {
		Uninitialized, ShowingSplash, Paused,
		ShowingMenu, Playing, Exiting
	};

	static GameState _gameState;
	static sf::RenderWindow _mainWindow;

	static GameObjectManager _gameObjectManager;
};
