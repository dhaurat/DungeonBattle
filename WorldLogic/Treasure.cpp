//
// Created on 19/11/2017.
//

#include <sstream>
#include "Treasure.h"
#include "../PlayerLogic/Skills.h"

Treasure::Treasure(int type, const char * name, const char * description,const char* imagePath,
                   unsigned int targetSkill, unsigned int bonus) :
        Room(type, name, description), _bonus(bonus)
{
    _targetSkill = targetSkill;
    _bigCard = new BigCard(false, TAKE_BTN_PATH, imagePath, getBonusString(), name, description);
}

unsigned int Treasure::getBonus() const
{
    return _bonus;
}

string Treasure::getBonusString()
{
    ostringstream bonusString;
    switch (_targetSkill)
    {
        case (ATTACK):
            bonusString << "BONUS: ATTACK +" << _bonus;
            break;
        case (DEFENSE):
            bonusString << "BONUS: DEFENSE +" << _bonus;
            break;
        case (AGILITY):
            bonusString << "BONUS: AGILITY +" << _bonus;
            break;
        case (LIFE):
            bonusString << "BONUS: LIFE +" << _bonus;
            break;
        default:
            break;
    }
    return bonusString.str();
}