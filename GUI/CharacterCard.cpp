//
// Created on 20/11/2017.
//

#include "CharacterCard.h"

CharacterCard::CharacterCard(const char * path, int x, int y, int w, int h, const char * race,
                             const char * characterClass, const char * name, const char * headTilePath,
                             const char * bodyTilePath) : Tile(path, x, y, w, h),
                                                           _race(TTF_OpenFont(FONT_PATH, 23), 0, 0,
                                                                  0, race, x + 20, y + 60),
                                                           _class(TTF_OpenFont(FONT_PATH, 23), 0, 0,
                                                                  0, characterClass, x + 20, y + 90),
                                                           _name(TTF_OpenFont(FONT_PATH, 22), 0, 0,
                                                                 0, name, x + 20, y + 20),
                                                           _headTile(headTilePath, x+40, y+115, w-90, h-235),
                                                           _bodyTile(bodyTilePath, x+38, y+177, w-80, h-200)
{
}

void CharacterCard::init()
{
    Tile::init();
    _bodyTile.init();
    _headTile.init();
}

void CharacterCard::render()
{
    Tile::render();
    _race.render();
    _class.render();
    _name.render();
    _bodyTile.render();
    _headTile.render();
}

void CharacterCard::cleanup()
{
    Tile::cleanup();
    _name.cleanup();
    _class.cleanup();
    _race.cleanup();
    _bodyTile.cleanup();
    _headTile.cleanup();
}


