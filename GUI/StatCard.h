//
// Created on 21/11/2017.
//

#ifndef NUMKINCH_STATCARD_H
#define NUMKINCH_STATCARD_H

#include <string>
#include "Tile.h"
#include "Text.h"

using namespace std;

/**
 *
 */
class StatCard : public Tile {

private:
    Text _playerIdentity;

    Text _attack;

    Text _defense;

    Text _agility;

    Text _life;

    Tile _headTile;

    Tile _bodyTile;

public:
    StatCard(const char * path, int x, int y, int w, int h, string playerIdentity, string attack, string defense,
             string agility, string life, const char * headTilePath, const char * bodyTilePath);

    void init() override;

    void update(string attack, string defense, string agility, string life);

    void render() override;

    void cleanup() override;

    void setTile(const char* path);
};

#endif //NUMKINCH_STATCARD_H
