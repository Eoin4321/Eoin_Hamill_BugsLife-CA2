#ifndef EOIN_HAMILL_BUGSLIFE_CA2_SPIDER_H
#define EOIN_HAMILL_BUGSLIFE_CA2_SPIDER_H

#include <ostream>
#include "Bug.h"

class Spider : public Bug {
protected:
public:
    //Constructor
    Spider(int id, const pair<int, int> &position, int direction, int size);



protected:
    virtual void move();

public:
    const string &getBugType() const;

    void setBugType(const string &bugType);
};

#endif //EOIN_HAMILL_BUGSLIFE_CA2_SPIDER_H
