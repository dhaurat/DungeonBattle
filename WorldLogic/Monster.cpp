//
// Created on 19/11/2017.
//

#include <sstream>
#include "Monster.h"

#define FIGHT_BTN_PATH "./res/FightBtn.png"

Monster::Monster(int type, bool isBoss, const char * name, const char * description, const char * imagePath,
                 unsigned int attack, unsigned int defense, int life, unsigned int level) :
        Room(type, name, description), _attack(attack), _defense(defense), _life(life), _level(level)
{
    _isBoss = isBoss;
    _bigCard = new BigCard(true, FIGHT_BTN_PATH, imagePath, getSkillsString(), name, description);
}

bool Monster::isBoss() const
{
    return _isBoss;
}

unsigned int Monster::getAttack() const
{
    return _attack;
}

unsigned int Monster::getDefense() const
{
    return _defense;
}

int Monster::getLife() const
{
    return _life;
}

unsigned int Monster::getLevel() const
{
    return _level;
}


void Monster::alterLife(int value)
{
    _life += value;
}

string Monster::getSkillsString()
{
    ostringstream stringStream;
    stringStream << "ATT: " << _attack << " / DEF: " << _defense << "\nPV: " << _life << " / NIV: " << _level;
    return stringStream.str();
}
