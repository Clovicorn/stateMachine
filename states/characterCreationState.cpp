#include "characterCreationState.hpp"

namespace Clovicorn
{
    CharacterCreationState::CharacterCreationState(gameDataRef data) : _data(data) {}

    void CharacterCreationState::init()
    {
        std::cout << "Entered into Character creation screen!\n";
    }

    void CharacterCreationState::handleInput()
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
                    // TODO change to pop up pause menu!
                    _data->window.close();
                }
            }
        }
    }

    void CharacterCreationState::update(float dt)
    {
    }

    void CharacterCreationState::draw(float dt)
    {
        _data->window.clear();

        _data->window.display();
    }
}