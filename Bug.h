#ifndef EOIN_HAMILL_BUGSLIFE_CA2_BUG_H
#define EOIN_HAMILL_BUGSLIFE_CA2_BUG_H


#include <utility>
#include <list>

class Bug {
protected:
    int id;
    std::pair<int, int> position;
    int direction;
    int size;
    bool alive;
    std::list<std::pair<int,int>> path;
    virtual void move()=0;
    bool isWayBlocked();

public:
    Bug(int id, const std::pair<int, int> &position, int direction, int size);
};


#endif //EOIN_HAMILL_BUGSLIFE_CA2_BUG_H
