#pragma once

#include <SFML/Graphics.hpp>
#include <string>
#include "../definitions.hpp"
#include "../enumsStructs.hpp"

using namespace sf;
namespace Clovicorn
{
    class Character
    {
    public:
        Character();
        void init();
        virtual Sprite getSprite();
        virtual bool getIsWaiting();
        virtual bool getIsAttacking();
        virtual bool getIsMoving();

        virtual void setIsWaiting(bool state);
        virtual void setIsAttacking(bool state);
        virtual void setIsMoving(bool state);

        virtual void setSprite(Texture &texture);
        virtual void setPosition(Vector2f position);

    protected:
        bool _isWaiting = true;
        bool _isAttacking = false;
        bool _isMoving = false;
        Sprite _sprite;
        std::string name;
    };
}