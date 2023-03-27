#pragma once

#include <SFML/Graphics.hpp>
#include <sstream>
#include <iostream>
#include <vector>

#include "state.hpp"
#include "../game.hpp"
#include "../definitions.hpp"

using namespace sf;
namespace Clovicorn
{
    class CharacterCreationState : public State
    {
    public:
        CharacterCreationState(gameDataRef data);
        void init();
        void handleInput();
        void update(float dt);
        void draw(float dt);

    private:
        gameDataRef _data;
    };
}