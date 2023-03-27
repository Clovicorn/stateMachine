#include "mainMenuState.hpp"
#include "characterCreationState.hpp"

namespace Clovicorn
{

    MainMenuState::MainMenuState(gameDataRef data) : _data(data)
    {
    }

    void MainMenuState::init()
    {
        std::string menuOptionText[] = {"Start", "Options", "Exit"};
        Text curText;
        for (int i = 0; i < 3; i++)
        {
            curText.setFont(_data->assets.getFont("aliceFont"));
            curText.setFillColor(Color::Red);
            curText.setCharacterSize(75);
            curText.setString(menuOptionText[i]);
            curText.setOrigin(curText.getLocalBounds().width / 2, curText.getLocalBounds().height / 2);
            if (i != 0)
            {
                int lastY = _menuOptions[i - 1].getPosition().y;
                curText.setPosition(Vector2f(_data->window.getSize().x / 2, (lastY + curText.getLocalBounds().height) + 25));
            }
            else
            {
                curText.setPosition(Vector2f(_data->window.getSize().x / 2, _data->window.getSize().y / 2));
            }
            _menuOptions.push_back(curText);
        }
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
                    for (int i = 0; i < menuTextAmount; i++)
                    {
                        if (_menuOptions[i].getGlobalBounds().contains((Vector2f)curMousePosition))
                        {
                            switch (i)
                            {
                            case 0:
                                _data->machine.addState(stateRef(new CharacterCreationState(this->_data)));
                                break;
                            case 1:
                                std::cout << "Clicked options state"
                                          << "\n";
                                break;
                            case 2:
                                _data->window.close();
                                break;
                            }
                        }
                    }
                }
            }
        }
    }

    void MainMenuState::update(float dt)
    {
        Vector2i curMousePosition = Mouse::getPosition();
        for (int i = 0; i < menuTextAmount; i++)
        {
            if (_menuOptions[i].getGlobalBounds().contains((Vector2f)curMousePosition))
            {
                if (_buttonLeftPressed)
                {
                    _menuOptions[i].setFillColor(Color::Green);
                }
                else
                {
                    _menuOptions[i].setFillColor(Color::White);
                }
            }
            else
            {
                if (_menuOptions[i].getFillColor() == Color::White || _menuOptions[i].getFillColor() == Color::Green)
                {
                    _menuOptions[i].setFillColor(Color::Red);
                }
            }
        }
    }

    void MainMenuState::draw(float dt)
    {
        _data->window.clear();
        for (int i = 0; i < _menuOptions.size(); i++)
        {
            _data->window.draw(_menuOptions[i]);
        }
        _data->window.display();
    }
}