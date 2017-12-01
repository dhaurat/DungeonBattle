//
// Created on 07/11/2017.
//

#ifndef NUMKINCH_SPRITE_H
#define NUMKINCH_SPRITE_H

#include "Element.h"

class Tile : public Element {

protected:
    SDL_Rect _tileRect;

public:
    Tile(const char * path, int x, int y, int w, int h);

    void init() override;

    void render() override;

    void cleanup() override;

    virtual int getX() const;

    virtual int getY() const;

    virtual int getW() const;

    virtual int getH() const;
};

#endif //NUMKINCH_SPRITE_H
