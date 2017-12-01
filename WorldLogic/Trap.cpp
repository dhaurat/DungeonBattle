//
// Created on 19/11/2017.
//

#include <sstream>
#include "Trap.h"
#include "../PlayerLogic/Skills.h"

Trap::Trap(int type, const char * name, const char * description, const char* imagePath,
           const unsigned int targetSkill, const unsigned int damage) :
        Room(type, name, description), _damage(damage)
{
    _targetSkill = targetSkill;
    _bigCard = new BigCard(false, OK_BTN_PATH, imagePath, getDamageString(), name, description);
}

unsigned int Trap::getDamage() const
{
    return _damage;
}

string Trap::getDamageString()
{
    ostringstream damageString;
    switch (_targetSkill)
    {
        case (ATTACK):
            damageString << "MALUS: ATTACK -" << _damage;
            break;
        case (DEFENSE):
            damageString << "MALUS: DEFENSE -" << _damage;
            break;
        case (AGILITY):
            damageString << "MALUS: AGILITY -" << _damage;
            break;
        case (LIFE):
            damageString << "MALUS: LIFE -" << _damage;
            break;
        default:
            break;
    }
    return damageString.str();
}
