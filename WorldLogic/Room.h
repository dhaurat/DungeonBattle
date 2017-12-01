//
// Created on 11/11/2017.
//

#ifndef NUMKINCH_ROOM_H
#define NUMKINCH_ROOM_H

#include "../GUI/Button.h"
#include "../GUI/CharacterCard.h"
#include "BigCard.h"


/**
 * Defines the content of a dungeon card (what is inside a dungeon "room").
 */
class Room {

protected:
    int _type;

    bool _visited;

    bool _inDeck;

    const char * _name;

    const char * _description;

    unsigned int _targetSkill;

    BigCard * _bigCard; /*!< Big representation of the card, displaying all the information of the room on screen. */


public:
    Room(int type, const char * name, const char * description);

    int getType() const;

    bool inDeck() const;

    bool visited() const;

    void setVisited(bool visited);

    BigCard * getBigCard();

    unsigned int getTargetSkill() const;

    virtual ~Room();

    void setInDeck(bool inDeck);
};


#endif //NUMKINCH_ROOM_H
