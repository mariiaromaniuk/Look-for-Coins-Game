//
//  world.hpp
//  look-for
//  Created by Mariia Romaniuk
//

#ifndef world_hpp
#define world_hpp

#include <stdio.h>
#include "point.hpp"
#include "robot.hpp"
using namespace std;


// declaration of constants
const int n = 10;
const int m = 10;

// declaration of World class
class World{
    
    // private class member fields
private:
    
    // an array of three point objects, each object storing the
    // location of one of the three coins the robot is looking for
    Point coins[3];
    
    // ann array that stores information about robot's moves
    char world[m][n];
    
    // variable that indicates founded coins
    static int coinsFound;
    
    // public class member functions declaration
public:
    
    // default constructor
    World();
    
    // destructor
    ~World();
    
    // this function prints out the locations of three coins
    void print() const;
    
    // this function sets the location of the i-th coin in the data member array to (x, y)
    void setCoin(int i, int x, int y);
    
    // this function generates random locations of the coins
    void randomlySetCoins();
    
    // this functions sets the coins location using validated user input
    void userSetCoins();
    
    // this function returns how many coins were found
    int getCoinsFound();
    
    // this function initializes the world
    void initWorld();
    
    // this function displays the world
    void displayWorld();
    
    // this function resets robot's previous location in the world
    void resetWorld(Robot R);
    
    // this function updates robot's new location in the world,
    // determines and inform the user if coins are found
    // and keeps track of how many coins have been found
    void updateWorld(Robot R);
    
    // this function reads and validates user commands to move the robot in the world
    void controller(Robot R);
    
}; // end of World class

#endif /* world_hpp */
