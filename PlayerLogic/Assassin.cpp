//
// Created on 03/11/2017.
//

#include "Assassin.h"
#include "Classes.h"
#include "PlayerLogicConstants.h"

Assassin::Assassin() : Class(assassin)
{
    _attack = Skill(ATTACK_BONUS, ATTACK_MAX_BONUS);
    _defense = Skill(0, 0);
    _agility = Skill(0, 0);
    _life = Skill(0, 0);
}