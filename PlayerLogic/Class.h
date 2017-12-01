//
// Created on 03/11/2017.
//

#ifndef NUMKINCH_CLASS_H
#define NUMKINCH_CLASS_H

#include "Skill.h"

/**
 * Defines a set of points for three qualities: attack, defense, agility.
 */
class Class {

protected:
    const int _class;

    Skill _attack;

    Skill _defense;

    Skill _agility;

    Skill _life;

public:
    explicit Class(int characterClass);

    int getClass() const;

    const Skill & getAttack() const;

    const Skill & getDefense() const;

    const Skill & getAgility() const;

    const Skill & getLife() const;
};


#endif //NUMKINCH_CLASS_H
