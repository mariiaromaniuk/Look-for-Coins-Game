//
//  world.cpp
//  look-for
//  Created by Mariia Romaniuk
//

// definition of World class
#include "world.hpp"
#include <fstream>

// set founded coins to zero
int World::coinsFound = 0;

// default constructor
World::World(){
}

// destructor
World::~World(){
}

// this function prints out the locations of three coins
void World::print() const{
  ofstream outfile;
  outfile.open ("output.txt", ios::out | ios::app);
    
  if (!outfile){
      throw "Error opening ioutput file";
  }
    else {
    cout << "\nPosition of coin No.1 ";
    coins[0].print();
    cout << "\nPosition of coin No.2 ";
    coins[1].print();
    cout << "\nPosition of coin No.3 ";
    coins[2].print();
    outfile << endl;
    cout << endl;
    outfile.close();
  }
} //end of print()


// this function sets the location of the i-th coin in the data member array to (x, y)
void World::setCoin(int i, int x, int y){
    coins[i].set(x, y);
} // end of setCoin()


// this function generates random locations of the coins
void World::randomlySetCoins(){
    for (int i = 0; i < 3; i++){
        int x = rand() % n;
        int y = rand() % m;
        setCoin(i, x, y);
    }
} // end of randomlySetCoins()


// this functions sets the coins location using validated user input
void World::userSetCoins(){
    for (int i = 0; i < 3; i++){
        int x, y;
        cout << "Please set X coordinate for coin No." << i+1 << " (from 0 to 9): \n";
        cin >> x;
        while (cin.fail() || x < 0 || x > 9){
            cin.clear();
            cin.ignore(10, '\n');
            cout << "Invalid input. Please re-enter: " << endl;
            cin >> x;
        }
        cout << "Please set Y coordinate for coin No." << i+1 << " (from 0 to 9): \n";
        cin >> y;
        while (cin.fail() || y < 0 || y > 9){
            cin.clear();
            cin.ignore(10, '\n');
            cout << "Invalid input. Please re-enter: " << endl;
            cin >> y;
        }
        setCoin(i, x, y);
    }
} // end of userSetCoin()


// this function returns the number of coins found
int World::getCoinsFound(){
    return coinsFound;
} // end of getCoinsFound()


// this function initializes the world
void World::initWorld(){
    for (int b = 0; b < m; b++){
        for (int a = 0; a < n; a++){
            world[b][a] = '.';
        }
    }
    for (int i = 0; i < 3; i++)
        world[coins[i].getY()][coins[i].getX()] = 'C';
} // end of initWorld()


// this function displays the world
void World::displayWorld(){
    cout << endl;
    for (int b = 0; b < m; b++){
        for (int a = 0; a < n; a++){
            cout << " ";
            cout << world[b][a];
        }
        cout << endl;
    }
} // end of displayWorld()


// this function resets robot's previous location in the world
void World::resetWorld(Robot R){
    world[R.getLocation().getY()][R.getLocation().getX()] = '.';
} // end of resetWorld()


// this function updates robot's new location in the world,
// determines and inform the user if coins are found
// and keeps track of how many coins have been found
void World::updateWorld(Robot R){
    if (coinsFound < 3 && world[R.getLocation().getY()][R.getLocation().getX()] == 'C'){
        coinsFound++;
        cout << "I found the coin No." << coinsFound << "! Yippee!" << endl;
    }
    world[R.getLocation().getY()][R.getLocation().getX()] = 'R';
} // end of updateWorld()


// this function reads and validates user commands to move the robot in the world
void World::controller(Robot R){
    // char variable to store user input
    char input;
    
    // prompt menu for user to execute the command
    cout << "\nReading the next robot's move from the file: \n";
    cout << "-----------------------------------\n";
    cout << "t - visit every cell until all coins are found\n";
    cout << "f - move the robot forward one step\n";
    cout << "c - rotate the robot clockwise\n";
    cout << "a - rotate the robot anti-clockwise\n";
    cout << "q - quit the program\n";
    
    ifstream infile;
    int i = 0;
    
    infile.open("input.txt", ios::in);
    if (!infile) {
        throw "Error opening input file";
    }
    
    while (!infile.eof()) {
        infile >> input;
        
        while (tolower(input) != 'q'){
            
            if (tolower(input) == 't'){
                // let the robot visit every cell until all the coins are found
                while (getCoinsFound() < 3){
                    resetWorld(R);
                    R.forward();
                    R.print();
                    updateWorld(R);
                    displayWorld();
                }
                R.result();
                break;
                
            } else if (tolower(input) == 'f'){
                // move the robot forward one step
                resetWorld(R);
                R.forward();
                R.print();
                updateWorld(R);
                displayWorld();
                
            } else if (tolower(input) == 'c'){
                // rotate the robot clockwise
                resetWorld(R);
                R.turnCW();
                R.print();
                updateWorld(R);
                displayWorld();
                
            } else if (tolower(input) == 'a'){
                // rotate the robot anti-clockwise
                resetWorld(R);
                R.turnAntiCW();
                R.print();
                updateWorld(R);
                displayWorld();
                
            } else if (tolower(input) == 'q'){
                // quit the program if user enter q
                break;
                
            } else {
                // user input validation
                cout << "\nInvalid option. You have to select from the menu.\n";
            }
            
            if (getCoinsFound() == 3){
                // print the results and quit the program if all the coins are found
                R.result();
                break;
            }
            cout << "\nReading the next robot's move from the file. \n";
            infile >> input;
        }
    i++;
  }
    infile.close();
    
} // end of controller()
