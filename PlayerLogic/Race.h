//
// Created on 03/11/2017.
//

#ifndef NUMKINCH_RACE_H
#define NUMKINCH_RACE_H

#include "Skill.h"
#include "Class.h"

/**
 * Defines a set of points for three qualities: attack, defense, agility. The addition of these points plus the points
 * given by the class of the character gives the total amount of points of the character in each quality.
 */
class Race {

protected:
    const int _race;

    const char * _name;

    Skill _attack;

    Skill _defense;

    Skill _agility;

    Skill _life;

    Class * _class; /*!< The pointer to the class object defining the character. */

public:
    Race(int race, const char * name, Class * characterClass);

    int getRace() const;

    int getClass() const;

    const char * getName() const;

    Skill * getAttack();

    Skill * getDefense();

    Skill * getAgility();

    Skill * getLife();

    const char * RaceToString() const;

    const char * ClassToString() const;

    virtual ~Race();
};


#endif //NUMKINCH_RACE_H
