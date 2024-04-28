#ifndef EOIN_HAMILL_BUGSLIFE_CA2_BOARD_H
#define EOIN_HAMILL_BUGSLIFE_CA2_BOARD_H

#include "Crawler.h"
#include "Hopper.h"
#include <iostream>
#include <sstream>
#include <fstream>

class Board {

private:
    //A 2d character array. We can go in x and y
    char boardGrid[10][10];

protected:
    //Making a list of bugs
    std::list <Bug*> buglist;



public:
    void displayAllBugs();
    Board();
    void display();
    void DemoOutputFileStream(string);
    void parseLine(const std::string& strLine);
    void DemoInputFileStream();
    string searchBugBasedOnID(int);
    void tapBoard();
    string displaypath();
    string displaycells();
    int eat();
    void runSimulation();
};


#endif //EOIN_HAMILL_BUGSLIFE_CA2_BOARD_H
