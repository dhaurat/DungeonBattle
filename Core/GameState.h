//
// Created on 17/10/2017.
//

#ifndef NUMKINCH_GAMESTATE_H
#define NUMKINCH_GAMESTATE_H


#define HEAD_THIEF_PATH "./res/HeadThief.png"
#define HEAD_PRIEST_PATH "./res/HeadPriest.png"
#define HEAD_PALADIN_PATH "./res/HeadPaladin.png"
#define HEAD_ASSASSIN_PATH "./res/HeadAssassin.png"
#define BODY_BARBARIAN_PATH "./res/BodyBarbarian.png"
#define BODY_HUMAN_PATH "./res/BodyHuman.png"
#define BODY_ELF_PATH "./res/BodyElf.png"
#define BODY_DWARF_PATH "./res/BodyDwarf.png"

/**
 * Entity that defines a certain state of the program, and which is bound to handle SDL events (i.e. user mouse/keyboard
 * inputs), update data and render elements to screen during its lifecycle.
 */
class GameState {

public:
    virtual void onEnter() = 0;

    virtual void handleEvents() = 0;

    virtual void update() = 0;

    virtual void render() = 0;

    virtual void onExit() = 0;

    virtual ~GameState() = default;
};


#endif //NUMKINCH_GAMESTATE_H
