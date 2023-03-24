#include "inputManager.hpp"

namespace Clovicorn
{
    bool InputManager::isSpriteClicked(Sprite object, Mouse::Button button, RenderWindow &window)
    {
        if (Mouse::isButtonPressed(button))
        {
            IntRect tempRect(object.getPosition().x, object.getPosition().y, object.getGlobalBounds().width, object.getGlobalBounds().height);

            if (tempRect.contains(Mouse::getPosition(window)))
            {
                return true;
            }
        }
        return false;
    }
    Vector2i InputManager::getMousePosition(RenderWindow &window)
    {
        return Mouse::getPosition(window);
    }
}