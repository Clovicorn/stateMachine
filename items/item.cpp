#include "item.hpp"

namespace Clovicorn
{
    Item::Item() {}
    void Item::init() {}
    int Item::getType()
    {
        return 0;
    }
    void Item::setType(int type) {}
    bool Item::getCanEquip()
    {
        return _canEquip;
    }
    void Item::setCanEquip() {}
}