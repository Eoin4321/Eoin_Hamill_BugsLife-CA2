#include "Hopper.h"

Hopper::Hopper(int id, const std::pair<int, int> &position, int direction, int size, int hopLength) :
Bug(id, position, direction, size) {
    this->hopLength=hopLength;
    this->bugType="Hopper";
}

void Hopper::move() {

}

int Hopper::getHopLength() const {
    return hopLength;
}

void Hopper::setHopLength(int hopLength) {
    Hopper::hopLength = hopLength;
}



