//
// Created on 03/11/2017.
//

#ifndef NUMKINCH_CHARACTERFACTORY_H
#define NUMKINCH_CHARACTERFACTORY_H

#include "Race.h"

/**
 * Builds characters (race + class) with the Factory pattern.
 */
class CharacterFactory {

private:
    CharacterFactory() = default; // avoid instancing

    static CharacterFactory _characterFactory;

public:
    static CharacterFactory & get();

    CharacterFactory(const CharacterFactory &) = delete; // avoid copy

    CharacterFactory & operator=(const CharacterFactory &) = delete; // avoid copy

    /**
     * Builds a randomly generated character (race + class + name).
     *
     * @return a pointer to a Race object.
     */
    Race * createCharacter();

    /**
     * Builds a character with chosen Race, Class and name.
     *
     * @param race the identifier of the Race (from Races.h).
     * @param className the identifier of the Class (from Classes.h).
     * @param name the name of the character.
     * @return a pointer to a Race object.
     */
    Race * createCharacter(int race, int className, const char * name);

    const char * NameToString(int name) const;

};


#endif //NUMKINCH_CHARACTERFACTORY_H
