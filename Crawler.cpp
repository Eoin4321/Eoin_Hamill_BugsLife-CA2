#include "Crawler.h"

Crawler::Crawler(int id, const pair<int, int> &position, int direction, int size) : Bug(id, position, direction,
                                                                                        size) {
    this->bugType="Crawler";
}

void Crawler::move() {
    path.push_back(position);
    //North
    if(direction==1) {
        position.second--;
    }
    //East
    if(direction==2)
        position.first++;
    //South
    if(direction==3)
        position.second++;
    //West
    if(direction==4)
        position.first--;

}



void toString()
{

}
