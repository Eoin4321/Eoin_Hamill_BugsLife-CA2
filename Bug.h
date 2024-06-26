#ifndef EOIN_HAMILL_BUGSLIFE_CA2_BUG_H
#define EOIN_HAMILL_BUGSLIFE_CA2_BUG_H
#include <utility>
#include <list>
#include <ostream>
#include<stdio.h>   // Standard Input Output
#include<iostream>  // Input Output Stream
#include<string>    // string library
#include<sstream>   // String Stream library
#include <cmath>
//This is for the time
#include <chrono>
#include <thread>
//This is for the graphics
#include <SFML/Graphics.hpp>

using namespace std;

class Bug {
protected:
    int id;
    std::pair<int, int> position;
    int direction;
    int size;
    bool alive;
    std::list<std::pair<int,int>> path;
    bool isWayBlocked();
    int eatenBy;

public:

    int getEatenBy() const;

    void setEatenBy(int eatenBy);

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

    const string &getBugType() const;

    void setBugType(const string &bugType);

    string bugType;

    virtual void move()=0;


};


#endif //EOIN_HAMILL_BUGSLIFE_CA2_BUG_H
