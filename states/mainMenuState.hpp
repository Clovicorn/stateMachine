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

    const int menuTextAmount = 3;
    class MainMenuState : public State
    {
    public:
        MainMenuState(gameDataRef data);
        void init();
        void handleInput();
        void update(float dt);
        void draw(float dt);

    private:
        float currentFontSize;
        gameDataRef _data;
        Clock _clock;
        Texture _backgroundTex;
        Sprite _backgroundSprite;
        std::vector<Text> _menuOptions;
        bool _buttonLeftPressed = false;
        bool _buttonRightPressed = false;
    };
}