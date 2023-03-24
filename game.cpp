#include "game.hpp"
#include "states/splashState.hpp"
namespace Clovicorn
{
    Game::Game(int width, int height, std::string title)
    {
        _data->window.create(VideoMode(width, height), title, Style::Fullscreen);
        _data->machine.addState(stateRef(new SplashState(this->_data)));

        this->run();
    }

    void Game::run()
    {
        float newTime;
        float frameTime;
        float interpolation;
        float currentTime = this->_clock.getElapsedTime().asSeconds();
        float accumulator = 0.0f;

        while (this->_data->window.isOpen())
        {
            this->_data->machine.processStateChanges();

            newTime = this->_clock.getElapsedTime().asSeconds();
            frameTime = newTime - currentTime;

            if (frameTime > 0.25f)
            {
                frameTime = 0.25f;
            }
            currentTime = newTime;
            accumulator += frameTime;

            while (accumulator >= dt)
            {
                this->_data->machine.getActiveState()->handleInput();
                this->_data->machine.getActiveState()->update(dt);

                accumulator -= dt;
            }
            interpolation = accumulator / dt;
            this->_data->machine.getActiveState()->draw(interpolation);
        }
    }
}