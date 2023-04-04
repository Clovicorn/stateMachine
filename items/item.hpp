#pragma once
#include <SFML/Graphics.hpp>
#include <memory>
#include "../enumsStructs.hpp"

using namespace sf;
namespace Clovicorn
{

    class Item
    {
    public:
        Item();
        void init();
        int getType();
        void setType(int type);
        bool getCanEquip();
        void setCanEquip();

    private:
        int _type = 0;
        bool _canEquip = false;
    };
}