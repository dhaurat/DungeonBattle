//
// Created on 03/11/2017.
//

#include <cstdio>
#include "Race.h"
#include "Races.h"
#include "Classes.h"

class Class;

Race::Race(int race, const char * name, Class * characterClass) : _race(race), _name(name)
{
    _class = characterClass;

    _attack.setMaxValue(_class->getAttack().getMaxValue());
    _attack.setValue(_class->getAttack().getValue());

    _defense.setMaxValue(_class->getDefense().getMaxValue());
    _defense.setValue(_class->getDefense().getValue());

    _agility.setMaxValue(_class->getAgility().getMaxValue());
    _agility.setValue(_class->getAgility().getValue());

    _life.setMaxValue(_class->getLife().getMaxValue());
    _life.setValue(_class->getLife().getValue());
}

int Race::getRace() const
{
    return _race;
}

int Race::getClass() const
{
    return _class->getClass();
}

const char * Race::getName() const
{
    return _name;
}

Skill * Race::getAttack()
{
    return & _attack;
}

Skill * Race::getDefense()
{
    return & _defense;
}

Skill * Race::getAgility()
{
    return & _agility;
}

Skill * Race::getLife()
{
    return & _life;
}

const char * Race::RaceToString() const
{
    switch (_race)
    {
        case barbarian:
            return "Nordique";
        case dwarf:
            return "Nain";
        case elf:
            return "Elf";
        case human:
            return "Humain";
        default:
            return "OVNI";
    }
}

const char * Race::ClassToString() const
{
    switch (_class->getClass())
    {
        case assassin:
            return "Assassin";
        case paladin:
            return "Paladin";
        case priest:
            return "Pretre";
        case thief:
            return "Voleur";
        default:
            return "OVNI";
    }
}

Race::~Race() = default;