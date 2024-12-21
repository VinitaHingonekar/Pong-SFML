#include <iostream>
#include <SFML/Graphics.hpp>
#include "Header/Core/GameWindowManager.h"
#include "Header/Event/EventManager.h"

using namespace Event;

int main()
{
    Core::GameWindowManager gameWindowManager;
    EventManager event_manager;

    gameWindowManager.initialize();

    while(gameWindowManager.isGameRunning())
    {
        event_manager.pollEvents(gameWindowManager.getGameWindow());
        gameWindowManager.render();
    }
}