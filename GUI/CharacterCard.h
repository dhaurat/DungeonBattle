//
// Created on 20/11/2017.
//

#ifndef NUMKINCH_TEXTTILE_H
#define NUMKINCH_TEXTTILE_H

#include "Tile.h"
#include "Text.h"

/**
 * Used in ChooseCharacterState to display the information of a character.
 */
class CharacterCard : public Tile {

private:
    Text _race;

    Text _class;

    Text _name;

    Tile _headTile;

    Tile _bodyTile;

public:
    CharacterCard(const char * path, int x, int y, int w, int h, const char * race, const char * characterClass,
    const char * name, const char * headTilePath, const char * bodyTilePath);

    void init() override;

    void render() override;

    void cleanup() override;
};

#endif //NUMKINCH_TEXTTILE_H
