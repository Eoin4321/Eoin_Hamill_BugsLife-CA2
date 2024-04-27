#include "Bug.h"
//Partial Constructor
Bug::Bug(int id, const std::pair<int, int> &position, int direction, int size) : id(id), position(position),
                                                                                 direction(direction), size(size),alive(true) {}
//getter
int Bug::getId() const {
    return id;
}

void Bug::setId(int id) {
    Bug::id = id;
}

const pair<int, int> &Bug::getPosition() const {
    return position;
}

void Bug::setPosition(const pair<int, int> &position) {
    Bug::position = position;
}

int Bug::getDirection() const {
    return direction;
}

void Bug::setDirection(int direction) {
    Bug::direction = direction;
}

int Bug::getSize() const {
    return size;
}

void Bug::setSize(int size) {
    Bug::size = size;
}

bool Bug::isAlive() const {
    return alive;
}

void Bug::setAlive(bool alive) {
    Bug::alive = alive;
}

const list<std::pair<int, int>> &Bug::getPath() const {
    return path;
}

void Bug::setPath(const list<std::pair<int, int>> &path) {
    Bug::path = path;
}

string Bug::toString() {
    string entireString="id: " + to_string(id) + " position: " + to_string(position.first) + to_string(position.second)+ " direction: " + to_string(direction) + " size: " + to_string(size)
       + " alive: " + to_string(alive) + " path: ";

    for(pair<int, int>pos: path){
        entireString+="<"+to_string(pos.first)+","+to_string(pos.second)+">,";
    }
    return entireString;
}

const string &Bug::getBugType() const {
    return bugType;
}

void Bug::setBugType(const string &bugType) {
    Bug::bugType = bugType;
}

bool Bug::isWayBlocked()
{
    cout << "1:\n";
    if(direction==1&&position.second==0) {
            return true;
        cout << "Winton1:\n";
    }
    else if(direction==2&&position.first==9) {
            return true;
    }
    else if(direction==3&&position.second==9) {
            return true;
    }
    else if(direction==4&&position.first==0) {
            return true;
    }
    else
    {
        cout << "YIPEEEEEE:\n";
        return false;
    }
    cout << "whileloopendo:\n";

}
