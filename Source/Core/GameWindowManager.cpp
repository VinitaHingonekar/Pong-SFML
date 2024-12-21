#include "../../Header/Core/GameWindowManager.h"

namespace Core
{
	void GameWindowManager::initialize()
	{
		game_window = new RenderWindow();
		createGameWindow();
	}

	void GameWindowManager::createGameWindow()
	{
		game_window->create(VideoMode(game_window_width, game_window_height),
							game_title);

		

			//game_window->create(
			//	sf::VideoMode::getDesktopMode(),
			//	game_title,	
			//	sf::Style::Fullscreen);
	}

	bool GameWindowManager::isGameRunning() 
	{
		return game_window->isOpen();
	}

	/*void GameWindowManager::render() 
	{
		game_window->clear(sf::Color(20, 150, 50, 255));

		game_window->display();
	}*/

	void GameWindowManager::clearGameWindow()
	{
		game_window->clear();
	}

	void GameWindowManager::displayGameWindow()
	{
		return game_window->display();
	}

	RenderWindow* GameWindowManager::getGameWindow() {
		return game_window;
	}
}