#include "mainMenuState.hpp"

namespace Clovicorn
{

    MainMenuState::MainMenuState(gameDataRef data) : _data(data)
    {
    }

    void MainMenuState::init()
    {
    }

    void MainMenuState::handleInput()
    {
        Event event;

        while (_data->window.pollEvent(event))
        {
            if (event.type == Event::Closed)
            {
                _data->window.close();
            }
            if (event.type == Event::KeyPressed)
            {
                if (event.key.code == Keyboard::Escape)
                {
                    _data->window.close();
                }
            }
        }
    }

    void MainMenuState::update(float dt)
    {
        std::cout << "main menu\n";
    }

    void MainMenuState::draw(float dt)
    {
        _data->window.clear();

        _data->window.display();
    }
}