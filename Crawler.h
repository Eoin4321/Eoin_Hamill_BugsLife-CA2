#ifndef EOIN_HAMILL_BUGSLIFE_CA2_CRAWLER_H
#define EOIN_HAMILL_BUGSLIFE_CA2_CRAWLER_H

#include "Bug.h"

class Crawler : public Bug {
protected:
public:
    Crawler(int id, const pair<int, int> &position, int direction, int size);

protected:
    virtual void move();

};


#endif //EOIN_HAMILL_BUGSLIFE_CA2_CRAWLER_H
