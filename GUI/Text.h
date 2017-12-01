//
// Created on 20/11/2017.
//

#ifndef NUMKINCH_TEXT_H
#define NUMKINCH_TEXT_H

#include <SDL_ttf.h>
#include <string>
#include "IDisplayable.h"

#define FONT_PATH "./res/fonts/VeraSe.ttf"

using namespace std;

class Text : IDisplayable {

private:
    TTF_Font * _font;

    SDL_Color _textColor;

    SDL_Surface * _surface;

    SDL_Texture * _texture;

    int _textWidth;

    int _textHeight;

    SDL_Rect _distanceRect;

public:
    Text(TTF_Font * font, Uint8 colorR, Uint8 colorG, Uint8 colorB, const char * text, int rectX, int rectY);

    Text(TTF_Font * font, Uint8 colorR, Uint8 colorG, Uint8 colorB, const char * text, int rectX, int rectY, unsigned int width);

    void init() override;

    void update(string text);

    void render() override;

    void cleanup() override;

    ~Text();
};

#endif //NUMKINCH_TEXT_H
