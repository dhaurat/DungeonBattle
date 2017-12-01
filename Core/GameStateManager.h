//
// Created on 18/10/2017.
//

#ifndef NUMKINCH_GAMESTATEMANAGER_H
#define NUMKINCH_GAMESTATEMANAGER_H

#include <stack>
#include <memory>
#include "GameState.h"

using namespace std;

/**
 * In charge of pushing/popping GameStates on a stack.
 */
class GameStateManager {

private:
    static GameStateManager _gameStateManager; //!< Singleton pattern.

    stack<unique_ptr<GameState>> _gameStates;

public:
    static GameStateManager & get();

    GameStateManager(const GameStateManager &) = delete; // avoid copy

    GameStateManager & operator=(const GameStateManager&) = delete; // avoid copy

public:
    GameState * getCurrentGameState() const;

    /**
     * Adds a new game state onto the stack and activates it.
     *
     * @param newState the new current GameState to be
     */
    void pushGameState(GameState * newState);

    /**
     * Cleans up the current state and removes it from the stack.
     */
    void popGameState();

private:
    GameStateManager(); // avoid instancing

    /**
     * Removes all GameStates from the stack.
     */
    ~GameStateManager();
};

#endif //NUMKINCH_GAMESTATEMANAGER_H
