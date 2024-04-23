//
// Created by kay on 23/04/2024.
//

#ifndef EOIN_HAMILL_BUGSLIFE_CA2_HOPPER_H
#define EOIN_HAMILL_BUGSLIFE_CA2_HOPPER_H


#include "Bug.h"

class Hopper : public Bug {
    protected:
        int hopLength;
        virtual void move();
};


#endif //EOIN_HAMILL_BUGSLIFE_CA2_HOPPER_H