#pragma once

namespace Clovicorn
{

    enum class ItemType
    {
        FOOD,
        WEAPON,
        HEAD,
        NECK,
        SHOULDERS,
        CHEST,
        BACK,
        LEGS,
        FEET,
        RING,
        TRINKET,
        REPAIR,
        MONEY,
        QUEST,

    };

    enum class Race
    {
        HUMAN,
        HALFHUMAN,
        ELVARIAN,
        BORK,
        DWARVIUS,
    };

    enum class PlayerClass
    {
        RANGER,
        WIZARD,
        COMMANDER,
        SPECIALIST,
    };

    struct Stats
    {
        int strength;
        int dexterity;
        int constitution;
        int wisdom;
        int intelligence;
        int charisma;
    };

    struct Speed
    {
        int maxSpeed;
        int currentSpeed;
    };

    struct Health
    {
        int maxHealth;
        int currentHealth;
    };

    struct Mana
    {
        int maxMana;
        int currentMana;
    };

    struct Stamina
    {
        int maxStamina;
        int currentStamina;
    };

    struct Level
    {
        int level;
        int currentXP;
        int xpToNextLevel;
    };
}