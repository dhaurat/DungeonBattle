//
// Created on 07/11/2017.
//

#ifndef NUMKINCH_PLAYSTATE_H
#define NUMKINCH_PLAYSTATE_H

#include <vector>
#include "../PlayerLogic/Race.h"
#include "GameState.h"
#include "../GUI/Background.h"
#include "../GUI/StatCard.h"
#include "../WorldLogic/Dungeon.h"
#include "../WorldLogic/Monster.h"
#include "../WorldLogic/Trap.h"
#include "../WorldLogic/Treasure.h"

#define IN_GAME_DEFAULT_BG_PATH "./res/choose_bg.png"
#define IN_GAME_BG_1_PATH "./res/play_bg_1.png"
#define IN_GAME_BG_2_PATH "./res/play_bg_2.png"
#define IN_GAME_BG_3_PATH "./res/play_bg_3.png"
#define IN_GAME_BG_4_PATH "./res/play_bg_4.png"

using namespace std;

/**
 * Runs the game itself.
 */
class PlayState : public GameState {

private:
    Background _inGameBg;

    Dungeon _dungeon; /*!< Handles the main interaction between the game and the players. */

    vector<StatCard *> _playerStats;

    vector<unique_ptr<Race>> _players; /*!< Contains the characters obtained from ChooseCharactersState. */

    unsigned int _currentPlayer;

public:
    /**
     * Takes ownership of the set of players in parameter and randomly sets the background.
     * @param players
     */
    explicit PlayState(vector<unique_ptr<Race>> players);

    /**
     * PlayState setup:
     * - graphical elements are initialized,
     * - cards of the dungeon are generated.
     */
    void onEnter() override;

    /**
     * Watches user's mouse inputs:
     * - closing the window,
     * - clicking somewhere on screen. The event is then passed to the dungeon for handling it.
     */
    void handleEvents() override;

    /**
     * Computes the points gained/lost during a fight against a monster.
     * Return true if a boss is killed
     * @param monster the monster card taken from the deck.
     */
    bool fightMonster(Monster * monster);

    /**
     * The player has one in four chance of loosing half of his/her life points when fleeing a monster.
     */
    void fleeMonster();

    /**
     * Computes the damage taken by the player from the trap card.
     *
     * @param trap the trap card taken from the deck.
     */
    void takeTrap(Trap * trap);

    /**
     * Computes the bonus taken by the player from the treasure card.
     *
     * @param treasure the treasure card taken from the deck.
     */
    void takeTreasure(Treasure * treasure);

    /**
     * CALLED BY DUNGEON.
     * Updates the current player's stats depending on the card taken from the deck and the action chosen.
     *
     * @param room the monster, trap or treasure card taken from the deck.
     * @param accept the action chosen by the player: fight/take or flee a Monster.
     */
    void updateCurrentPlayer(Room * room, bool accept);

    /**
     * Updates the dungeon.
     */
    void update() override;

    /**
     * Renders PlayState graphical elements.
     */
    void render() override;

    /**
     * Cleans up PlayState graphical elements.
     */
    void onExit() override;

    ~PlayState() override;
};

#endif //NUMKINCH_PLAYSTATE_H
