//
// Created on 07/11/2017.
//

#include "Tile.h"

Tile::Tile(const char * path, int x, int y, int w, int h) : Element(path)
{
    _tileRect.w = w;
    _tileRect.h = h;
    _tileRect.x = x;
    _tileRect.y = y;
}

void Tile::init()
{
    loadImage();

    loadTexture();
}

void Tile::render()
{
    SDL_RenderCopy(GameEngine::getGameRenderer(), _texture, nullptr, &_tileRect);
}

void Tile::cleanup()
{
    Element::cleanup();
}

int Tile::getX() const
{
    return _tileRect.x;
}

int Tile::getY() const
{
    return _tileRect.y;
}

int Tile::getW() const
{
    return _tileRect.w;
}

int Tile::getH() const
{
    return _tileRect.h;
}
