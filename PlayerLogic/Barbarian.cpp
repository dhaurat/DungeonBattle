//
// Created on 20/11/2017.
//

#include "Barbarian.h"
#include "PlayerLogicConstants.h"
#include "Races.h"

Barbarian::Barbarian(const char * name, Class * characterClass) : Race(barbarian, name, characterClass)
{
    _attack = Skill(getAttack()->getValue() + ATTACK_VALUE+ATTACK_BONUS, getAttack()->getMaxValue() + ATTACK_MAX_VALUE+ATTACK_MAX_BONUS);
    _defense = Skill(getDefense()->getValue() + DEFENSE_VALUE,  getDefense()->getMaxValue() +  DEFENSE_MAX_VALUE);
    _agility = Skill(getAgility()->getValue() + AGILITY_VALUE, getAgility()->getMaxValue() + AGILITY_MAX_VALUE);
    _life = Skill(getLife()->getValue() + LIFE_VALUE, getLife()->getMaxValue()+  LIFE_MAX_VALUE);
}
