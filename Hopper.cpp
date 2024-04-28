#include "Hopper.h"

Hopper::Hopper(int id, const std::pair<int, int> &position, int direction, int size, int hopLength) :
Bug(id, position, direction, size) {
    this->hopLength=hopLength;
    this->bugType="Hopper";
}

void Hopper::move() {
    path.push_back(position);
    //While loop will return true if way is blocked.
    while(isWayBlocked())
    {
        //If bug is facing a wall it will face a random direction while loop will run again to make sure its not facing same direction.
        srand(time(NULL));
        direction= 1+ (rand() % 4);
    }
    //North
    if (direction == 1) {
        position.second=position.second-hopLength;
        if(position.second<0)
        {
            position.second=0;
        }
    }
    //East
    if (direction == 2)
        position.first=position.first+hopLength;
        if(position.first>9)
        {
            position.first=9;
        }
    //South
    if (direction == 3)
        position.second=position.second+hopLength;
        if(position.second>9)
        {
            position.second=9;
        }
    //West
    if (direction == 4)
        position.first=position.first-hopLength;
        if(position.first<0)
        {
            position.first=0;
        }
}

int Hopper::getHopLength() const {
    return hopLength;
}

void Hopper::setHopLength(int hopLength) {
    Hopper::hopLength = hopLength;
}



