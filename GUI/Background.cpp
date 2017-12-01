//
// Created on 22/10/2017.
//

#include "Background.h"

Background::Background(const char * path) : Element(path)
{}

void Background::init()
{
    Element::init();
}

void Background::render()
{
    SDL_RenderCopy(GameEngine::getGameRenderer(), _texture, nullptr, nullptr);
}

void Background::cleanup()
{
   Element::cleanup();
}