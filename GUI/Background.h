//
// Created on 22/10/2017.
//

#ifndef NUMKINCH_MENUBACKGROUND_H
#define NUMKINCH_MENUBACKGROUND_H

#include "Element.h"

/**
 * Used to render image with no coordinates which fits the entire window.
 */
class Background : public Element {

public:
    explicit Background(const char * path);

    void init() override;

    void render() override;

    void cleanup() override;
};

#endif //NUMKINCH_MENUBACKGROUND_H
