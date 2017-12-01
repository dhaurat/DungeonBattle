//
// Created on 20/11/2017.
//

#include "Priest.h"
#include "PlayerLogicConstants.h"
#include "Classes.h"

Priest::Priest() : Class(priest)
{
    _attack = Skill(0, 0);
    _defense = Skill(0, 0);
    _agility = Skill(0, 0);
    _life = Skill(LIFE_BONUS, LIFE_MAX_BONUS);
}
