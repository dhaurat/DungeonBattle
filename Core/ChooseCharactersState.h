//
// Created on 22/10/2017.
//

#ifndef NUMKINCH_CHOOSECHARACTERSSTATE_H
#define NUMKINCH_CHOOSECHARACTERSSTATE_H

#include <vector>
#include <memory>
#include "GameState.h"
#include "../GUI/Background.h"
#include "../GUI/Button.h"
#include "../PlayerLogic/Race.h"
#include "../GUI/Tile.h"
#include "../GUI/CharacterCard.h"

using namespace std;

/**
 * Displays the set of characters to be played by the users.
 */
class ChooseCharactersState : public GameState {

private:
    Background _chooseCharacterBg;

    Button _playGameBtn;

    vector<CharacterCard *> _characters;

    vector<unique_ptr<Race>> _randomPlayers; /*!< Contains randomly chosen characters to be passed to PlayState. */

    /**
     * Gives the filled _randomPlayers vector of game characters to the new PlayState and activates it.
     * PRECONDITION: _randomPlayers is filled with game characters randomly chosen.
     * POSTCONDITION: PlayState is the new current GameState.
     */
    void playStateHandler();


public:
    ChooseCharactersState();

    /**
     * ChooseCharactersState initialization:
     * - graphical elements are initialized,
     * - game characters to be played are randomly created and pushed into the _randomPlayers vector.
     */
    void onEnter() override;

    /**
     * Watches user's mouse inputs:
     * - closing the window,
     * - pressing the "playGame" Button. If the button is pressed, then launches the game session.
     */
    void handleEvents() override;

    //! NOT USED.
    void update() override;

    /**
     * Renders ChooseCharactersState graphical elements.
     */
    void render() override;

    /**
     * Cleans up ChooseCharactersState graphical elements.
     */
    void onExit() override;

    ~ChooseCharactersState() override;
};

#endif //NUMKINCH_CHOOSECHARACTERSSTATE_H
