//
// Created on 18/10/2017.
//

#include "GameStateManager.h"

/* ========== Singleton ========== */
GameStateManager GameStateManager::_gameStateManager;

GameStateManager & GameStateManager::get() {

    return _gameStateManager;
}

/* ========== Constructor / Destructor ========== */
GameStateManager::GameStateManager() = default;

GameStateManager::~GameStateManager()
{
    while (!_gameStates.empty())
    {
        popGameState();
    }
}
/* ============================================== */

GameState * GameStateManager::getCurrentGameState() const
{
    return _gameStates.top().get();
}

void GameStateManager::pushGameState(GameState * newState)
{
    _gameStates.push(unique_ptr<GameState>(newState));
    _gameStates.top()->onEnter();
}

void GameStateManager::popGameState()
{
    if (!_gameStates.empty())
    {
        _gameStates.top()->onExit();
        _gameStates.pop();
    }
}