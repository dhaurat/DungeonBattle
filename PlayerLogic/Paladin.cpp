//
// Created on 03/11/2017.
//

#include "Paladin.h"
#include "Classes.h"
#include "PlayerLogicConstants.h"

Paladin::Paladin() : Class(paladin)
{
    _attack = Skill(0, 0);
    _defense = Skill(DEFENSE_BONUS, DEFENSE_MAX_BONUS);
    _agility = Skill(0, 0);
    _life = Skill(0, 0);
}