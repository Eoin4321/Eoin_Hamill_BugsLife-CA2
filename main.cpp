#include "main.h"

int main() {
    Board* board = new Board();
    board->DemoInputFileStream();
    board->displayAllBugs();
    board -> display();

    cout<< "Menu\n";
    cout<< "--------------------------------------------\n";
    cout<< "1.Initialize Bug Board (load data from file)\n";
    cout<< "2.Display all Bugs\n";
    cout<< "3.Find a Bug (given an id)\n";
    cout<< "4.Tap the Bug Board (causes move all, then fight/eat)\n";
    cout<< "5.Display Life History of all Bugs (path taken)\n";
    cout<< "6.Display all Cells listing their Bugs\n";
    cout<< "7.Run simulation (generates a Tap every second)\n";
    cout<< "8.Exit (write Life History of all Bugs to file)\n";
    cout<< "--------------------------------------------\n";

    return 0;
}
