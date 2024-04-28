#include "Crawler.h"

Crawler::Crawler(int id, const pair<int, int> &position, int direction, int size) : Bug(id, position, direction,
                                                                                        size) {
    this->bugType="Crawler";
}

void Crawler::move() {
    if (alive) {
        path.push_back(position);
        //While loop will return true if way is blocked.
        while (isWayBlocked()) {
            //If bug is facing a wall it will face a random direction while loop will run again to make sure its not facing same direction.
            srand(time(NULL));
            direction = 1 + (rand() % 4);
        }
        //North
        if (direction == 1) {
            position.second--;
        }
        //East
        if (direction == 2)
            position.first++;
        //South
        if (direction == 3)
            position.second++;
        //West
        if (direction == 4)
            position.first--;

    }
}
