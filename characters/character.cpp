#include "character.hpp"

namespace Clovicorn
{

    Character::Character() {}

    void Character::init()
    {
    }

    void Character::setSprite(Texture &texture)
    {

        _sprite.setTexture(texture);
    }

    Sprite Character::getSprite()
    {
        return this->_sprite;
    }

    bool Character::getIsWaiting()
    {
        return _isWaiting;
    }

    bool Character::getIsAttacking()
    {
        return _isAttacking;
    }

    bool Character::getIsMoving()
    {
        return _isMoving;
    }

    void Character::setIsWaiting(bool state)
    {
        _isWaiting = state;
    }

    void Character::setIsAttacking(bool state)
    {
        _isAttacking = state;
    }

    void Character::setIsMoving(bool state)
    {
        _isMoving = state;
    }

    void Character::setPosition(Vector2f position)
    {
        _sprite.setPosition(position);
    }
}