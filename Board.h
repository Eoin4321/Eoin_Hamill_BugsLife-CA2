#ifndef EOIN_HAMILL_BUGSLIFE_CA2_BOARD_H
#define EOIN_HAMILL_BUGSLIFE_CA2_BOARD_H


#include "Bug.h"
#include <iostream>

class Board {

private:
    //A 2d character array. We can go in x and y
    char board[10][10];

protected:
    //Making a list of bugs
    std::list <Bug*> Buglist;

public:
    Board() {
        //Loop which repeats ten times going through each coloum. It creates a 10x10 board
        for (int row = 0; row < 10; row++) {
            //This loop goes through the row
            for (int column = 0; column < 10; column++)
                board[row][column] = '=';
        }
    }
    void display();

    void importBugs(std::string fileName);
};


#endif //EOIN_HAMILL_BUGSLIFE_CA2_BOARD_H
