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
        if(currentBug->getBugType()=="Hopper"&&currentBug->isAlive())
        {
            boardGrid[y][x]='H';
        }
        else if(currentBug->getBugType()=="Crawler"&&currentBug->isAlive())
        {
            boardGrid[y][x]='C';
        }
        else if(currentBug->getBugType()=="Spider"&&currentBug->isAlive())
        {
            boardGrid[y][x]='S';
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
            // now, instantiate a Crawler and adding them to list

            buglist.push_back(tempCrawler);
        }
            else if (bug_type == "S") { // if it is Spider, then read the Spider fields
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

                auto *tempSpider = new Spider(id, position, direction, size);
                // now, instantiate a Crawler and adding them to list

                buglist.push_back(tempSpider);

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
            // now, instantiate a Hopper and adding them to list

            buglist.push_back(tempHopper);
        }
    }


    catch (std::invalid_argument const &e) {
        cout;

    }
}
//Code based on code we did in class.
void Board::DemoOutputFileStream(string data)
{
    // making an output file stream
    ofstream outFileStream("bugs_life_history_date_time.out");  // default write mode (overwrites existing data)
    //checking if im able to open file if it returns true and I can run the if statement
    if ( outFileStream.good() )
    {
        //Adding in the data inputed to the file
        outFileStream << data;

        outFileStream.close(); //  close file
        cout << "Bugs Path has been added to the file..\n Shutting down..." << endl;
    }
    else
        cout << "Can't Open File. Please try again.";
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
    string bug;
    for (Bug* currentBug: buglist)
    {
        if(currentBug->getId()==input)
         return currentBug->toString();
    }
    return "Bug not found";
}

void Board::tapBoard(){
    for (Bug* currentBug: buglist)
    {
        currentBug->move();
    }

}

string Board::displaypath(){
    string bugslife="";
    for (Bug* currentBug: buglist){
        bugslife=bugslife+to_string(currentBug->getId())+" "+currentBug->getBugType()+" "+"Path: ";
        for(std::pair<int,int> path : currentBug->getPath())
        {
            bugslife=bugslife+"("+to_string(path.first)+","+to_string(path.second)+") ";
        }
        if(currentBug->isAlive()) {
            bugslife = bugslife + "Alive!";
        }
        else if(!currentBug->isAlive())
        {
            bugslife = bugslife + "Eaten by "+to_string(currentBug->getEatenBy());
        }
        bugslife=bugslife+"\n";
    }
    return bugslife;
}

string Board:: displaycells() {
    string celldata;
    bool cellempty=true;
    //going through each row
     for (int row = 0; row < 10; row++) {
         //This loop goes through the column
         for (int column = 0; column < 10; column++){
             celldata=celldata+"("+ to_string(row)+","+ to_string(column)+": ";
         for (Bug *currentBug: buglist) {
             int x = currentBug->getPosition().first;
             int y = currentBug->getPosition().second;
             if(row==x&&column==y)
             {
                 celldata=celldata+" ,"+currentBug->getBugType()+" "+ to_string(currentBug->getId());
                 cellempty=false;
             }
            }
            if(cellempty==false)
            {
                celldata=celldata+" Empty";
                cellempty=true;
            }
            celldata=celldata+"\n";
         }
     }
     return celldata;
 }
int Board:: eat() {
    int bugsEaten=0;
    std::list <Bug*> bugsOnCell;
    //going through each row
    for (int row = 0; row < 10; row++) {
        //This loop goes through the column
        for (int column = 0; column < 10; column++){
            for (Bug *currentBug: buglist) {
                int x = currentBug->getPosition().first;
                int y = currentBug->getPosition().second;
                if(row==x&&column==y&&currentBug->isAlive())
                {
                    bugsOnCell.push_back(currentBug);
                }
            }
            int biggestbug=0;
            int biggestBugId=0;
            for(Bug *bugFight :bugsOnCell)
            {
                if(biggestbug==0) {
                    biggestBugId=bugFight->getId();
                    biggestbug = bugFight->getSize();
                    bugsEaten++;
                }
                else if(biggestbug>bugFight->getSize())
                {
                    bugFight->setAlive(false);
                    bugFight->setEatenBy(biggestBugId);
                    bugsEaten++;
                }
                else if(biggestbug<bugFight->getSize())
                {
                    biggestbug=bugFight->getSize();
                    biggestBugId=bugFight->getId();
                    bugsEaten++;
                }
                //Handling if there is a tie.
                else if(biggestbug==bugFight->getSize())
                {
                    srand(time(NULL));
                    int winner= 1+(rand() % 2);
                    //The new bug wins the random fight
                    if(winner==1)
                    {
                        biggestbug=bugFight->getSize();
                        biggestBugId=bugFight->getId();
                        bugsEaten++;
                    }
                    //The old bug wins the fight
                    else if(winner==2)
                    {
                        bugFight->setAlive(false);
                        bugFight->setEatenBy(biggestBugId);
                        bugsEaten++;
                    }
                }
            }
            bugsOnCell.clear();
        }
    }
    return bugsEaten;
}

void Board::runSimulation(){
    //Learned the sleep for from https://www.youtube.com/watch?v=QYaQStudgnE
    int bugsRemaining=buglist.size();
    cout << "Starting Simulation:\n";
    while(bugsRemaining!=1) {
        cout << "Shaking Board:\n";
        tapBoard();
        bugsRemaining=bugsRemaining-eat();
        display();
        std::this_thread::sleep_for(std::chrono::seconds(1));
    }
    for (Bug *currentBug: buglist)
    {
        if(currentBug->isAlive())
        {
            cout << "The winner is: "+currentBug->getId();
        }
    }
}
//Code based on code from Moodle
void Board::sfmlDisplay(){
    srand(time(NULL));
    //Making the player
    pair<int, int> position;
    position.first = 2;
    position.second = 2;
    auto *PlayerCrawler = new Crawler(1, position, 1, 1000);
    //Opening a window for the SFML
    sf::RenderWindow window(sf::VideoMode(800, 800), "SFML works!");
    //Making visuals.
    sf::CircleShape character(40);
    character.setPosition(0,0);
    character.setFillColor(sf::Color::Red);
    vector<sf::RectangleShape> squares;
    //Ten by ten loop to make the grid
    for(int x = 0; x < 10;x ++)
    {
        for(int y=0; y<10;y++)
        {
            sf::RectangleShape cell(sf::Vector2f(80,80));
            cell.setPosition(x*80, y*80);
            //Making the grid
            cell.setOutlineThickness(1);
            cell.setOutlineColor(sf::Color::Black);
            squares.push_back(cell);
        }
    }

    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
            if(event.type == sf::Event::KeyReleased)
            {
                int x = character.getPosition().x;
                int y = character.getPosition().y;
                if(event.key.code == sf::Keyboard::Up)
                {
                    if(y> 0)
                        character.setPosition(x, y-80);
                }
                if(event.key.code == sf::Keyboard::Down)
                {
                    if(y<700)
                        character.setPosition(x, y+80);
                }
                if(event.key.code == sf::Keyboard::Left)
                {
                    if(x> 0)
                        character.setPosition(x-80, y);
                }
                if(event.key.code == sf::Keyboard::Right)
                {
                    if(x<700)
                        character.setPosition(x+80, y);
                }
                if(event.key.code == sf::Keyboard::Space)
                {
                    for(sf::RectangleShape &sh:squares)
                    {
                        if(x == sh.getPosition().x
                           && y ==sh.getPosition().y )
                        {
                            sh.setFillColor(sf::Color::Green);
                        }
                    }
                }
            }
            if(event.type == sf::Event::MouseButtonReleased)
            {
                int x = event.mouseButton.x;
                int y = event.mouseButton.y;

                for(sf::RectangleShape &sh:squares)
                {
                    if(x >= sh.getPosition().x&&x < sh.getPosition().x+10
                       && y >=sh.getPosition().y&&y < sh.getPosition().y+10 )
                    {
                        sh.setFillColor(sf::Color::Green);
                    }
                }
            }
        }
        window.clear(sf::Color::White);
        for(sf::RectangleShape sh:squares)
        {
            window.draw(sh);
        }
        window.draw(character);
        window.display();
    }
}