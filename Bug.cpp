#include "Bug.h"
//Partial Constructor
Bug::Bug(int id, const std::pair<int, int> &position, int direction, int size) : id(id), position(position),
                                                                                 direction(direction), size(size),alive(true) {}
