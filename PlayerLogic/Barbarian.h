//
// Created on 20/11/2017.
//

#ifndef NUMKINCH_BARBARIAN_H
#define NUMKINCH_BARBARIAN_H


#include "Race.h"

class Barbarian : public Race {

public:
    Barbarian(const char * name, Class * characterClass);

    //void cheerPlayerUp(unique_ptr<Race> player);
};


#endif //NUMKINCH_BARBARIAN_H
