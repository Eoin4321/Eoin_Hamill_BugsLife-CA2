#ifndef EOIN_HAMILL_BUGSLIFE_CA2_HOPPER_H
#define EOIN_HAMILL_BUGSLIFE_CA2_HOPPER_H

#include "Bug.h"

class Hopper : public Bug {
    protected:
        int hopLength;
public:
    Hopper(int id, const std::pair<int, int> &position, int direction, int size, int hopLength);

protected:
    virtual void move();
};


#endif //EOIN_HAMILL_BUGSLIFE_CA2_HOPPER_H