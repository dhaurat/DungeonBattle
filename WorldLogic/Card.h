//
// Created on 21/11/2017.
//

#ifndef NUMKINCH_CARD_H
#define NUMKINCH_CARD_H

#include "Room.h"
#include "BigCard.h"

/**
 * One of the selectable rooms displayed on screen. Contains a Room, i.e. the value/information given by the card.
 */
class Card : public IHandleable, IDisplayable {

private:
    Room * _room; // don't delete it in the destructor since it comes from a unique_ptr

    Button _backCardBtn;

    Tile _frontCardTile;

    int _positionX;

    int _positionY;

    bool _updatePlayer;

public:
    Card(Room * room, int column, int line);

    Room * getRoom();

    int getX() const;

    int getY() const;

    void setUpdate(bool update);

    bool updatePlayer() const;

    void init() override;

    void handleEvent(SDL_Event * event) override;

    void update();

    void render() override;

    void cleanup() override;

    ~Card();
};


#endif //NUMKINCH_CARD_H
