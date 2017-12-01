//
// Created on 21/11/2017.
//

#include <zconf.h>
#include "Card.h"
#include "../GUI/GUIConstants.h"
#include "../Core/PlayState.h"

#define BACK_CARD_PATH "./res/BackCard.png"
#define FRONT_CARD_PATH "./res/FrontCard.png"

Card::Card(Room * room, int column, int line) : _room(room),
                                                _backCardBtn(BACK_CARD_PATH, column * CARD_WIDTH + CARD_MARGIN_SIDE,
                                                             line * CARD_HEIGHT + CARD_MARGIN_TOP, CARD_WIDTH,
                                                             CARD_HEIGHT),
                                                _frontCardTile(FRONT_CARD_PATH,
                                                               column * CARD_WIDTH + CARD_MARGIN_SIDE,
                                                               line * CARD_HEIGHT + CARD_MARGIN_TOP, CARD_WIDTH,
                                                               CARD_HEIGHT)
{
    _positionX = column * CARD_WIDTH + CARD_MARGIN_SIDE;
    _positionY = line * CARD_HEIGHT + CARD_MARGIN_TOP;
    _updatePlayer = false;
}

Room * Card::getRoom()
{
    return _room;
}

int Card::getX() const
{
    return _positionX;
}

int Card::getY() const
{
    return _positionY;
}

void Card::init()
{
    _backCardBtn.init();
    _frontCardTile.init();
    _room->getBigCard()->init();
}

void Card::handleEvent(SDL_Event * event)
{
    if (event->type == SDL_MOUSEBUTTONDOWN)
    {
        if (!_room->visited())
        {
            _backCardBtn.handleEvent(event);
            if (_backCardBtn.pressed())
            {
                _room->setVisited(true);
                _room->getBigCard()->setDisplay(true);
            }
        }
    }
}

void Card::setUpdate(bool update)
{
    _updatePlayer = update;
}

bool Card::updatePlayer() const
{
    return _updatePlayer;
}

void Card::update()
{
    if (_room->getBigCard()->accept() || _room->getBigCard()->refuse())
    {
        setUpdate(true);
    }
}

void Card::render()
{
    _backCardBtn.render();
    if (_room->visited())
    {
        _frontCardTile.render();
        if (_room->getBigCard()->displayed())
        {
            _room->getBigCard()->render();
        }
    }
}

void Card::cleanup()
{
    if (!_room->visited())
    {
        _backCardBtn.cleanup();
    }
    else if (_room->visited())
    {
        _frontCardTile.cleanup();
    }
}

Card::~Card()
{
    _room = nullptr;
}
