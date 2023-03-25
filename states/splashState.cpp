#include "splashState.hpp"
#include "mainMenuState.hpp"

namespace Clovicorn
{
    SplashState::SplashState(gameDataRef data) : _data(data)
    {
    }

    void SplashState::init()
    {
        _data->assets.loadTexture("splashBackground", SPLASH_BACKGROUND_FILEPATH);
        _data->assets.loadFont("aliceFont", "resources/fonts/AliceInWonderland.ttf");
        _backgroundSprite.setTexture(_data->assets.getTexture("splashBackground"));
        _splashText.setFont(_data->assets.getFont("aliceFont"));
        _splashText.setCharacterSize(0);
        _splashText.setFillColor(Color::Black);
        _splashText.setString("Clovicorn\nPresents!");
        _splashText.setOrigin(Vector2f(_splashText.getLocalBounds().width / 2, _splashText.getLocalBounds().height / 2));
        _splashText.setPosition(_data->window.getSize().x / 2, _data->window.getSize().y / 2);
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
            if (event.type == Event::KeyPressed)
            {
                if (event.key.code == Keyboard::Escape)
                {
                    _data->machine.addState(stateRef(new MainMenuState(this->_data)));
                }
            }
        }
    }

    void SplashState::update(float dt)
    {

        if (_splashText.getCharacterSize() < 100)
        {
            currentFontSize += dt * 30.0f;
            if ((int)currentFontSize % 2 == 0)
            {
                _splashText.setCharacterSize((currentFontSize));
                _splashText.setOrigin(Vector2f(_splashText.getLocalBounds().width / 2, _splashText.getLocalBounds().height / 2));
                _splashText.setPosition(_data->window.getSize().x / 2, _data->window.getSize().y / 2);
            }
        }
        else if (_clock.getElapsedTime().asSeconds() > SPLASH_SHOW_TIME)
        {
            _data->machine.addState(stateRef(new MainMenuState(this->_data)));
        }
    }

    void SplashState::draw(float dt)
    {
        _data->window.clear();
        _data->window.draw(_backgroundSprite);
        _data->window.draw(_splashText);
        _data->window.display();
    }
}