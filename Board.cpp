#include "Board.h"

void Board::display() {
    for (int row = 0; row < 10; row++) {
        //This loop goes through the row
        for (int column = 0; column < 10; column++)
            boardGrid[row][column] = '=';
    }
    for(Bug* currentBug: buglist)
    {
        int x =currentBug->getPosition().first;
        int y =currentBug->getPosition().second;
        if(currentBug->getBugType()=="Hopper")
        {
            boardGrid[y][x]='H';
        }
        else if(currentBug->getBugType()=="Crawler")
        {
            boardGrid[y][x]='C';
        }
        //Put third bug here later
        else if(!currentBug->isAlive())
        {
            boardGrid[y][x]='=';
        }
    }

    //Iterate through the columns.
    for (int row = 0; row < 10; row++) {
        //Iterate through the row
        for (int column = 0; column < 10; column++) {
            std::cout << boardGrid[row][column] << "  ";
        }
        std::cout << std::endl;
    }
};


void Board::DemoInputFileStream() {
    cout << "Attempting to read from a comma-delimited text file." << endl;

    ifstream inFileStream; // open file as input file stream (from working directory)
    inFileStream.open("bugs.txt");
    if ( inFileStream.good() )  // if file opened successfully, and not empty
    {
        string line;            // create a string object to store a line of text

        while ( !inFileStream.eof() )   // read a line until false returned , getline() from <string> library
        {
            getline(inFileStream, line);
            parseLine( line );  // pass the line of text to have it parsed
        }
        inFileStream.close();
    }
    else
        cout << "Unable to open file, or file is empty.";
}

void Board::parseLine(const string& strLine) {
    stringstream strStream(strLine);

    const char DELIMITER = ';'; // as this is specified in the specification

    string bug_type;
// extract the first token (the name) into the name variable
// - a comma delimits the strings -
    getline(strStream, bug_type, DELIMITER);
    string strTemp; // temporary string

    try {

        if (bug_type == "C") { // if it is Crawler, then read the Crawler fields
            getline(strStream, strTemp, DELIMITER); // read next field (id) as a string
            int id = stoi(strTemp); // convert string to int conversion (may throw exceptions)

            getline(strStream, strTemp, DELIMITER);
            pair<int, int> position;
            position.first = stoi(strTemp);
            getline(strStream, strTemp, DELIMITER);
            position.second = stoi(strTemp);

            getline(strStream, strTemp, DELIMITER); // read next field (id) as a string
            int direction = stoi(strTemp); // convert string to int conversion (may throw exceptions)

            getline(strStream, strTemp, DELIMITER); // read next field (id) as a string
            int size = stoi(strTemp); // convert string to int conversion (may throw exceptions)

            // and so on for all the expected crawler fields

            auto *tempCrawler = new Crawler(id, position, direction, size);
            // now, instantiate a Crawler and add to vector

            buglist.push_back(tempCrawler);

        } else if (bug_type == "H") { // if it is Hopper, then read the Hopper fields
            getline(strStream, strTemp, DELIMITER); // read next field (id) as a string
            int id = stoi(strTemp); // convert string to int conversion (may throw exceptions)

            getline(strStream, strTemp, DELIMITER);
            pair<int, int> position;
            position.first = stoi(strTemp);
            getline(strStream, strTemp, DELIMITER);
            position.second = stoi(strTemp);

            getline(strStream, strTemp, DELIMITER); // read next field (id) as a string
            int direction = stoi(strTemp); // convert string to int conversion (may throw exceptions)

            getline(strStream, strTemp, DELIMITER); // read next field (id) as a string
            int size = stoi(strTemp); // convert string to int conversion (may throw exceptions)

            getline(strStream, strTemp, DELIMITER); // read next field (id) as a string
            int hopLength = stoi(strTemp); // convert string to int conversion (may throw exceptions)

            // and so on for all the expected crawler fields

            auto *tempHopper = new Hopper(id, position, direction, size,hopLength);
            // now, instantiate a Crawler and add to vector

            buglist.push_back(tempHopper);

// and so on for all the expected fields

// and remember the extra field in hopper - hopping distance

// now, instantiate a Hopper and add to vector



        }

    }
    catch (std::invalid_argument const &e) {
        cout;

    }
}

//Setting everything to equal sign when its made
Board::Board(): boardGrid(), buglist() {


        //Loop which repeats ten times going through each coloum. It creates a 10x10 boardGrid
        for (int row = 0; row < 10; row++) {
            //This loop goes through the row
            for (int column = 0; column < 10; column++)
                boardGrid[row][column] = '=';
        }


}
void Board::displayAllBugs(){
    for (Bug* currentBug: buglist)
    {
        cout <<currentBug->toString() <<endl;
    }
}

string Board:: searchBugBasedOnID(int input)
{
    for (Bug* currentBug: buglist)
    {
        if(currentBug->getId()==input)
        return currentBug->toString();
    }
}

void Board::tapBoard(){
    for (Bug* currentBug: buglist)
    {
        currentBug->move();
    }
}
