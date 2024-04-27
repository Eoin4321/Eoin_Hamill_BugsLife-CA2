#include "main.h"

int main() {
    Board* board = new Board();
    board->display();
    //Menu while loop
    while(true) {
        cout << "Menu\n";
        cout << "--------------------------------------------\n";
        cout << "1.Initialize Bug Board (load data from file)\n";
        cout << "2.Display all Bugs\n";
        cout << "3.Find a Bug (given an id)\n";
        cout << "4.Tap the Bug Board (causes move all, then fight/eat)\n";
        cout << "5.Display Life History of all Bugs (path taken)\n";
        cout << "6.Display all Cells listing their Bugs\n";
        cout << "7.Run simulation (generates a Tap every second)\n";
        cout << "8.Exit (write Life History of all Bugs to file)\n";
        cout << "--------------------------------------------\n";
        //Taking in input
        cout << "Enter your Command:";
        string command;    // note lowercase "s" for string type (unlike Java)
        cin >> command;

        if (command == "1") {
            board->DemoInputFileStream();
            cout << "Bugs have been updated based on file\n";
            board->display();
        }
        if (command == "2") {
            board->displayAllBugs();
        }
        if(command == "3") {
            cout << "Enter the ID you want to search for:";
            int input;    // note lowercase "s" for string type (unlike Java)
            cin >> command;
            board->searchBugBasedOnID(input);
        }
        if(command == "4"){
            cout << "Shaking Board:\n";
            board->tapBoard();
            board->display();
        }
    }
    return 0;
}
