#include "player.hpp"

namespace Clovicorn
{
    Player::Player()
    {
    }

    int Player::getStatStrength()
    {
        return stats.strength;
    }
    int Player::getStatDexterity()
    {
        return stats.dexterity;
    }
    int Player::getStatConstitution()
    {
        return stats.constitution;
    }
    int Player::getStatWisdom()
    {
        return stats.wisdom;
    }
    int Player::getStatIntelligence()
    {
        return stats.intelligence;
    }
    int Player::getStatCharisma()
    {
        return stats.charisma;
    }

    void Player::setStatStrength(int amount)
    {
        stats.strength += amount;
    }
    void Player::setStatDexterity(int amount)
    {
        stats.dexterity += amount;
    }
    void Player::setStatConstitution(int amount)
    {
        stats.constitution += amount;
    }
    void Player::setStatWisdom(int amount)
    {
        stats.wisdom += amount;
    }
    void Player::setStatIntelligence(int amount)
    {
        stats.intelligence += amount;
    }
    void Player::setStatCharisma(int amount)
    {
        stats.charisma += amount;
    }

    void Player::update(float dt)
    {
    }
}