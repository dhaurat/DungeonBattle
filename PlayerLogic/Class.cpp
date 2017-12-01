//
// Created on 03/11/2017.
//

#include "Class.h"

Class::Class(int characterClass) : _class(characterClass)
{}

int Class::getClass() const
{
    return _class;
}

const Skill & Class::getAttack() const
{
    return _attack;
}

const Skill & Class::getDefense() const
{
    return _defense;
}

const Skill & Class::getAgility() const
{
    return _agility;
}

const Skill & Class::getLife() const
{
    return _life;
}
