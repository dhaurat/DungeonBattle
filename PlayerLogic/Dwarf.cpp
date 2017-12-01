//
// Created on 03/11/2017.
//

#include "Dwarf.h"
#include "PlayerLogicConstants.h"
#include "Races.h"

Dwarf::Dwarf(const char * name, Class * characterClass) : Race(dwarf, name, characterClass)
{
    _attack = Skill(getAttack()->getValue() + ATTACK_VALUE,  getAttack()->getMaxValue() + ATTACK_MAX_VALUE);
    _defense = Skill(getDefense()->getValue() +DEFENSE_VALUE+DEFENSE_BONUS, getDefense()->getMaxValue() +  DEFENSE_MAX_VALUE+DEFENSE_MAX_BONUS);
    _agility = Skill(getAgility()->getValue() + AGILITY_VALUE, getAgility()->getMaxValue() + AGILITY_MAX_VALUE);
    _life = Skill(getLife()->getValue() + LIFE_VALUE, getLife()->getMaxValue()+ LIFE_MAX_VALUE);
}