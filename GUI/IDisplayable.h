//
// Created on 24/11/2017.
//

#ifndef NUMKINCH_IDISPLAYABLE_H
#define NUMKINCH_IDISPLAYABLE_H

class IDisplayable {

public:
    virtual void init() = 0;

    virtual void render() = 0;

    virtual void cleanup() = 0;
};

#endif //NUMKINCH_IDISPLAYABLE_H
