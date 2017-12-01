//
// Created on 17/10/2017.
//

#ifndef NUMKINCH_GAMEENGINE_H
#define NUMKINCH_GAMEENGINE_H

#include <SDL.h>

class GameEngine {

private:
    static GameEngine _gameEngine; //!< Singleton pattern.

    static SDL_Window * _gameWindow;

    static SDL_Renderer * _gameRenderer;

    bool _running;


public:
    static GameEngine & get();

    static SDL_Window * getGameWindow();

    static SDL_Renderer * getGameRenderer();

    GameEngine(const GameEngine &) = delete; // avoid copy

    GameEngine & operator=(const GameEngine&) = delete; // avoid copy

private:
    GameEngine(); // avoid instancing

    /**
     * Shutdowns the SDL API.
     */
    ~GameEngine();

public:
    /**
     * Creates the game window.
     *
     * @return true if window creation succeeded.
     */
    bool onInit();

    /**
     * Calls the current GameState handleEvents method.
     */
    void handleEvents();

    /**
     * Calls the current GameState update method.
     */
    void update();

    /**
     * Calls the current GameState render method.
     */
    void render();

    /**
     * Initializes SDL API, pushes the first GameState on the GameStateManager stack and launches the main game loop.
     *
     * @return 0 (EXIT_SUCCESS) if the game excited successfully.
     */
    int onExecute();

    /**
     * Causes the GameEngine to break from the main game loop.
     */
    void Quit();

    /**
     * Calls SDL cleaning functions.
     */
    void onCleanup();
};


#endif //NUMKINCH_GAMEENGINE_H
