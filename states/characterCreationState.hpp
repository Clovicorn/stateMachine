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
        bool _buttonLeftPressed = false;
        bool _buttonRightPressed = false;
        float _screenWidth;
        float _screenHeight;
        float _currentWidthPercent;
        float _currentHeightPercent;
        gameDataRef _data;
        Sprite _addSubSprites[12];
        Sprite _bgSprite;
        Sprite _classBGSprite;
        Text stregthText;

        View _hudView;
        View _bgView;
    };
}