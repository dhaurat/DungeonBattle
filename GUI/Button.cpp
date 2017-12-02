//
// Created on 18/10/2017.
//

#include "Button.h"

Button::Button(const char * path, int x, int y, int w, int h) : Tile(path, x, y, w, h)
{
    _pressed = false;
}

bool Button::pressed() const
{
    return _pressed;
}

void Button::init()
{
    Tile::init();
}

void Button::handleEvent(SDL_Event * event)
{
    if (event->type == SDL_MOUSEBUTTONDOWN)
    {
        // Get mouse position
        int x, y;
        x = event->button.x;
        y = event->button.y;

        if ((x >= _tileRect.x) && (x <= (_tileRect.x + _tileRect.w)) && (y >= _tileRect.y) &&
                (y <= (_tileRect.y + _tileRect.h)))
        {
            _pressed = true;
        }
    }
}

void Button::render()
{
    SDL_RenderCopy(GameEngine::getGameRenderer(), _texture, nullptr, &_tileRect);
}

void Button::cleanup()
{
    Tile::cleanup();
}

void Button::unpress()
{
    _pressed = false;
}