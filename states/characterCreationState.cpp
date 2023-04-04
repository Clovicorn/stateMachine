#include "characterCreationState.hpp"
#include "mainMenuState.hpp"

namespace Clovicorn
{
    CharacterCreationState::CharacterCreationState(gameDataRef data) : _data(data) {}

    void CharacterCreationState::init()
    {
        _screenWidth = _data->window.getSize().x;
        _screenHeight = _data->window.getSize().y;
        _currentWidthPercent = _screenWidth / STANDARD_WIDTH;
        _currentHeightPercent = _screenHeight / STANDARD_HEIGHT;

        _hudView.setSize(Vector2f(_screenWidth, _screenHeight));
        _hudView.setCenter(_screenWidth / 2, _screenHeight / 2);

        //_data->assets.loadFont("ccMenu", CCMENU_FONT_FILEPATH);
        std::cout << "start of loading textures\n";
        _data->assets.loadTexture("ccMenuBG", CCMENU_BACKGROUND_FILEPATH);
        _data->assets.loadTexture("player", TEST_PLAYER);

        _data->assets.loadTexture("minusDown", MINUS_DOWN_FILEPATH);
        _data->assets.loadTexture("minusOver", MINUS_OVER_FILEPATH);
        _data->assets.loadTexture("minusUp", MINUS_UP_FILEPATH);

        _data->assets.loadTexture("plusDown", PLUS_DOWN_FILEPATH);
        _data->assets.loadTexture("plusOver", PLUS_OVER_FILEPATH);
        _data->assets.loadTexture("plusUp", PLUS_UP_FILEPATH);

        _data->player.setSprite(_data->assets.getTexture("player"));
        _data->player.setPosition(Vector2f(_data->window.getSize().x / 2, _data->window.getSize().y / 2));

        for (int x = 0; x < 12; x += 2)
        {
            _addSubSprites[x].setTexture(_data->assets.getTexture("plusUp"));
            _addSubSprites[x + 1].setTexture(_data->assets.getTexture("minusUp"));
            _addSubSprites[x].setPosition(150, (42 + (x * 42)));
            _addSubSprites[x + 1].setPosition(150, 42 + 28 + (x * 42));
        }
        _bgSprite.setTexture(_data->assets.getTexture("ccMenuBG"));
        _bgSprite.setScale(Vector2f(_currentWidthPercent, _currentHeightPercent));
        _bgSprite.setPosition(Vector2f(0, 0));
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
                    _data->machine.addState(stateRef(new MainMenuState(this->_data)));
                }
            }
            if (event.type == Event::MouseButtonPressed)
            {
                if (event.mouseButton.button == Mouse::Left)
                {
                    _buttonLeftPressed = true;
                }
            }
            if (event.type == Event::MouseButtonReleased)
            {
                if (event.mouseButton.button == Mouse::Left)
                {
                    _buttonLeftPressed = false;
                    Vector2i curMousePosition = Mouse::getPosition();
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
        _data->window.setView(_hudView);
        _data->window.draw(_bgSprite);
        for (int x = 0; x < 12; x++)
        {
            _data->window.draw(_addSubSprites[x]);
        }
        _data->window.draw(_data->player.getSprite());
        _data->window.display();
    }
}