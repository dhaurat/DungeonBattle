//
// Created on 11/11/2017.
//

#ifndef NUMKINCH_HANDLEABLE_H
#define NUMKINCH_HANDLEABLE_H

#include <SDL_events.h>

class IHandleable {

public:
    virtual void handleEvent(SDL_Event * event) = 0;
};

#endif //NUMKINCH_HANDLEABLE_H
