#pragma once

#include <SFML/Graphics.hpp>
#include <string>
#include <memory>
#include <vector>
#include <map>

#include "../items/item.hpp"
#include "character.hpp"
#include "../definitions.hpp"
#include "../enumsStructs.hpp"

using namespace sf;
namespace Clovicorn
{
    class Player : public Character
    {
    public:
        Player();
        void init();
        void update(float dt);

        int getStatStrength();
        int getStatDexterity();
        int getStatConstitution();
        int getStatWisdom();
        int getStatIntelligence();
        int getStatCharisma();

        void setStatStrength(int amount);
        void setStatDexterity(int amount);
        void setStatConstitution(int amount);
        void setStatWisdom(int amount);
        void setStatIntelligence(int amount);
        void setStatCharisma(int amount);

        // TODO figure out names of functions
        // For attacking, taking damage, etc
    private:
        bool _isInit = false;

        struct Stats stats;
        struct Health _health;
        struct Mana _mana;
        struct Stamina _stamina;
        struct Level _levelInfo;

        // std::map<std::string, Item> _equipedItems;
    };
}