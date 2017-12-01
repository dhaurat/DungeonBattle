//
// Created on 18/10/2017.
//

#ifndef NUMKINCH_MAINMENUSTATE_H
#define NUMKINCH_MAINMENUSTATE_H

#include "GameState.h"
#include "../GUI/Background.h"
#include "../GUI/Button.h"
#include "../GUI/Text.h"

#define MENU_BG_PATH        "./res/menu_bg.png"
#define PLAY_BUTTON_PATH    "./res/play_btn.png"
#define QUIT_BUTTON_PATH    "./res/quit_btn.png"

/**
 * Displays the main menu, the first window showing up when the program is executed.
 */
class MainMenuState : public GameState {

private:
    Background _menuBg;

    Button _menuNewPlayBtn;

    Button _menuQuitBtn;

public:
    MainMenuState();

    /**
     * MainMenuState initialization: graphical elements are initialized.
     */
    void onEnter() override;

    /**
     * Watches user's mouse inputs:
     * - closing the window,
     * - pressing the "menuNewPlay" Button. If the button is pressed, then launches the next GameState,
     * - pressing the "menuQuit" Button. If the button is pressed, the program exits.
     */
    void handleEvents() override;

    //! NOT USED.
    void update() override;

    /**
     * Renders MainMenuState graphical elements.
     */
    void render() override;

    /**
     * Cleans up MainMenuState graphical elements.
     */
    void onExit() override;
};

#endif //NUMKINCH_MAINMENUSTATE_H
