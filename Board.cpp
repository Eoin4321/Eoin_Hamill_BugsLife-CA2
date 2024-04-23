//
// Created by kay on 23/04/2024.
//

#include "Board.h"

void Board::display() {
    //Iterate through the columns.
    for (int row = 0; row < 10; row++) {
        //Iterate through the row
        for (int column = 0; column < 10; column++) {
            std::cout << board[row][column] << "  ";
        }
        std::cout << std::endl;
    }
};

