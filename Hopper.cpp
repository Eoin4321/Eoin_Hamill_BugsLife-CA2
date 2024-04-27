#include "Hopper.h"

Hopper::Hopper(int id, const std::pair<int, int> &position, int direction, int size, int hopLength) :
Bug(id, position, direction, size) {
    this->hopLength=hopLength;
}

void Hopper::move() {

}
