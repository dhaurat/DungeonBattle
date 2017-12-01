//
// Created on 20/11/2017.
//

#include "Human.h"
#include "Races.h"
#include "PlayerLogicConstants.h"

Human::Human(const char * name, Class * characterClass) : Race(human, name, characterClass)
{
    _attack = Skill(getAttack()->getValue() + ATTACK_VALUE,  getAttack()->getMaxValue() + ATTACK_MAX_VALUE);
    _defense = Skill(getDefense()->getValue() +DEFENSE_VALUE, getDefense()->getMaxValue() +  DEFENSE_MAX_VALUE);
    _agility = Skill(getAgility()->getValue() + AGILITY_VALUE, getAgility()->getMaxValue() + AGILITY_MAX_VALUE);
    _life = Skill(getLife()->getValue() + LIFE_VALUE+LIFE_BONUS,getLife()->getMaxValue()+  LIFE_MAX_VALUE+LIFE_MAX_BONUS);
}
