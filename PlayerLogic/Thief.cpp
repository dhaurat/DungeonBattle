//
// Created on 20/11/2017.
//

#include "Thief.h"
#include "Classes.h"
#include "PlayerLogicConstants.h"

Thief::Thief() : Class(thief)
{
    _attack = Skill(0, 0);
    _defense = Skill(0, 0);
    _agility = Skill(AGILITY_BONUS, AGILITY_MAX_BONUS);
    _life = Skill(0, 0);
}
