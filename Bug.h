#ifndef EOIN_HAMILL_BUGSLIFE_CA2_BUG_H
#define EOIN_HAMILL_BUGSLIFE_CA2_BUG_H
#include <utility>
#include <list>
#include <ostream>

using namespace std;

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

    string toString();

    Bug(int id, const std::pair<int, int> &position, int direction, int size);

    int getId() const;

    void setId(int id);

    const pair<int, int> &getPosition() const;

    void setPosition(const pair<int, int> &position);

    int getDirection() const;

    void setDirection(int direction);

    int getSize() const;

    void setSize(int size);

    bool isAlive() const;

    void setAlive(bool alive);

    const list<std::pair<int, int>> &getPath() const;

    void setPath(const list<std::pair<int, int>> &path);
};


#endif //EOIN_HAMILL_BUGSLIFE_CA2_BUG_H
