//
// Created on 21/11/2017.
//

#include "StatCard.h"

StatCard::StatCard(const char * path, int x, int y, int w, int h, string playerIdentity, string attack,
                   string defense, string agility, string life, const char * headTilePath,
                   const char * bodyTilePath) :
        Tile(path, x, y, w, h),
        _playerIdentity(TTF_OpenFont(FONT_PATH, 17), 0, 0, 0, playerIdentity.c_str(), x + 20, y + 10),
        _attack(TTF_OpenFont(FONT_PATH, 20), 0, 0, 0, attack.c_str(), x + 20, y + 36),
        _defense(TTF_OpenFont(FONT_PATH, 20), 0, 0, 0, defense.c_str(), x + 20, y + 64),
        _agility(TTF_OpenFont(FONT_PATH, 20), 0, 0, 0, agility.c_str(), x + 20, y + 92),
        _life(TTF_OpenFont(FONT_PATH, 20), 0, 0, 0, life.c_str(), x + 20, y + 120),
        _headTile(headTilePath, x+182, y+32, w-200, h-100),
        _bodyTile(bodyTilePath, x+185, y+80, w-200, h-90)
{}

void StatCard::init()
{
    Tile::init();
    _bodyTile.init();
    _headTile.init();
}

void StatCard::update(string attack, string defense, string agility, string life)
{
    _attack.update(move(attack));
    _defense.update(move(defense));
    _agility.update(move(agility));
    _life.update(move(life));
}

void StatCard::render()
{
    Tile::render();
    _playerIdentity.render();
    _attack.render();
    _defense.render();
    _agility.render();
    _life.render();
    _bodyTile.render();
    _headTile.render();
}

void StatCard::cleanup()
{
    Tile::cleanup();
    _playerIdentity.cleanup();
    _attack.cleanup();
    _defense.cleanup();
    _agility.cleanup();
    _life.cleanup();
    _bodyTile.cleanup();
    _headTile.cleanup();
}

void StatCard::setTile(const char * path)
{
    Tile::cleanup();
    Tile::setImagePath(path);
    Tile::init();
    Tile::render();
}