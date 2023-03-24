#include "splashState.hpp"

namespace Clovicorn
{
    SplashState::SplashState(gameDataRef data) : _data(data)
    {
    }

    void SplashState::init()
    {
        _data->assets.loadTexture("SplashBackground", SPLASH_BACKGROUND_FILEPATH);
        _backgroundSprite.setTexture(_data->assets.getTexture("SplashBackground"));
    }

    void SplashState::handleInput()
    {
        Event event;
        while (_data->window.pollEvent(event))
        {
            if (event.type == Event::Closed)
            {
                _data->window.close();
            }
        }
    }

    void SplashState::update(float dt)
    {
        if (_clock.getElapsedTime().asSeconds() > SPLASH_SHOW_TIME)
        {
            std::cout << "go to main menu!\n";
        }
    }

    void SplashState::draw(float dt)
    {
        _data->window.clear();
        _data->window.draw(_backgroundSprite);
        _data->window.display();
    }
}