//
// Created on 11/11/2017.
//

#ifndef NUMKINCH_DUNGEON_H
#define NUMKINCH_DUNGEON_H

#include <vector>
#include <memory>
#include "../GUI/Button.h"
#include "../GUI/Background.h"
#include "Room.h"
#include "Card.h"

using namespace std;

class Dungeon : public IHandleable, IDisplayable {

private:
    vector<unique_ptr<Card>> _playedDeck; /*!< Contains the card displayed on screen, selectable by the player. */

    vector<unique_ptr<Room>> _allRooms; /*!< Contains the entire set of 100 rooms. */

    bool _activated;

    Card * _lastVisitedCard;

    unsigned int _returnedCardsCount;

public:

    /**
     * Sets up all the rooms.
     */
    Dungeon();

    /**
     * Generates randomly a set of 30 cards to be displayed on screen from the entire set of 100 rooms.
     */
    void generate();

    /**
     * Re-generates randomly a set of 30 cards to be displayed on screen from the entire set of 100 rooms.
     * PRECONDITION: all the cards must have been taken by the players.
     * POSTCONDITION: a new set of cards to be taken by the players is displayed.
     */
    void regenerate();

    /**
     * Dungeon graphical elements initialization.
     */
    void init() override;

    /**
     * If the cards are selectable (the dungeon is "activated"), checks if the player clicked on a card and passes the
     * event to the found card.
     * If the dungeon is not activated because a BigCard is displayed, passes the event to the displayed BigCard.
     * @param event the mouse event of the current player.
     */
    void handleEvent(SDL_Event * event) override;

    /**
     * Updates dungeon cards and for each, checks if the player had an interaction with the card. If so, updates the
     * player stats in regard to the card he/she interacted with.
     */
    void update();

    /**
     * Renders the dungeon cards. If no BigCard is displayed, dungeon gets (re)activated.
     */
    void render() override;

    /**
     * Cleans up the dungeon cards.
     */
    void cleanup() override;

private:
    /**
     * Given the mouse button last position, checks if the click occurred on a dungeon card.
     *
     * @param positionX x position of the mouse button event.
     * @param positionY y position of th mouse button event.
     * @return the card corresponding to the position if found, nullptr otherwise.
     */
    Card * findCard(int positionX, int positionY);
};

#endif //NUMKINCH_DUNGEON_H