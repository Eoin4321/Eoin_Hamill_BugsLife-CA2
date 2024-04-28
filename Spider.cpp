#include "Spider.h"
//Spiders travel along the corners of the board. I thought this would be a good idea as the game usually goes on to long with to many crawlers around the edge.
Spider::Spider(int id, const pair<int, int> &position, int direction, int size) : Bug(id, position, direction,
                                                                                        size) {
    this->bugType="Spider";
}

void Spider::move() {
    if(alive) {
        path.push_back(position);
        //While loop will return true if way is blocked.
        while (isWayBlocked()) {
            //If bug is facing a wall it will face a random direction while loop will run again to make sure its not facing same direction.
            srand(time(NULL));
            direction = 1 + (rand() % 4);
        }
        //North
        if (direction == 1) {
            position.second = 0;
        }
        //East
        if (direction == 2)
            position.first = 9;
        //South
        if (direction == 3)
            position.second = 9;
        //West
        if (direction == 4)
            position.first = 0;
    }
}