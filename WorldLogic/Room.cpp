//
// Created on 11/11/2017.
//

#include "Room.h"
#include "../GUI/GUIConstants.h"
#include "Entities.h"
#include "../PlayerLogic/Skills.h"

Room::Room(int type, const char * name, const char * description) :
        _type(type), _name(name), _description(description), _visited(false),
        _targetSkill(NONE)
{
    _inDeck = false;
    _bigCard = nullptr;
}

int Room::getType() const
{
    return _type;
}

bool Room::visited() const
{
    return _visited;
}

void Room::setVisited(bool visited)
{
    _visited = visited;
}

unsigned int Room::getTargetSkill() const
{
    return _targetSkill;
}

BigCard * Room::getBigCard()
{
    return _bigCard;
}

bool Room::inDeck() const
{
    return _inDeck;
}

void Room::setInDeck(bool inDeck)
{
    _inDeck = inDeck;
}

Room::~Room()
{
    _name = nullptr;
    _description = nullptr;
    delete _bigCard;
    _bigCard = nullptr;
}