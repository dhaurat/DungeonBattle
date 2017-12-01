//
// Created on 03/11/2017.
//

#include "Elf.h"
#include "Races.h"
#include "PlayerLogicConstants.h"

Elf::Elf(const char * name, Class * characterClass) : Race(elf, name, characterClass)
{
    _attack = Skill(getAttack()->getValue() + ATTACK_VALUE,  getAttack()->getMaxValue() + ATTACK_MAX_VALUE);
    _defense = Skill(getDefense()->getValue() +DEFENSE_VALUE,getDefense()->getMaxValue() +   DEFENSE_MAX_VALUE);
    _agility = Skill(getAgility()->getValue() + AGILITY_VALUE+ AGILITY_BONUS, getAgility()->getMaxValue() + AGILITY_MAX_VALUE+AGILITY_MAX_BONUS);
    _life = Skill(getLife()->getValue() + LIFE_VALUE,getLife()->getMaxValue()+  LIFE_MAX_VALUE);
}