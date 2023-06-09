#pragma once

#include <memory>
#include <string>
#include <SFML/Graphics.hpp>

#include "definitions.hpp"
#include "enumsStructs.hpp"

#include "stateMachine.hpp"
#include "assetManager.hpp"
#include "inputManager.hpp"
#include "characters/player.hpp"

using namespace sf;

namespace Clovicorn
{
    struct gameData
    {
        StateMachine machine;
        RenderWindow window;
        AssetManager assets;
        InputManager inputs;
        Player player;
        float fps = FPS;
    };
    typedef std::shared_ptr<gameData> gameDataRef;
    class Game
    {
    public:
        Game(int width, int height, std::string title);
        void setDt(int fps);
        ~Game();

    private:
        int origWidth;
        int origHeight;
        float dt = 1.0f / FPS;
        Clock _clock;
        gameDataRef _data = std::make_shared<gameData>();

        void run();
    };
}