/*
 Mariia Romaniuk, ID 23846860
 Fall 2019, CSC 211
 Thursday, November 14, 2019 (5:00 pm)
 Instructor: Dr. Azhar
 
 main.cpp
 look-for
 
 This program demonstrates simulates a robot moving around in a 2-dimensional world,
 looking for coins. The robot’s current location is represented by an (x, y) point in space.
 The robot has a controller that receives commands one at a time. Each command will tell it
 to move forward or turn 90 degrees, either clockwise or anti-clockwise. The program will
 have a broad control loop, and for each iteration of the loop, the robot must decide what
 to do (i.e., which command to execute). The goal is for the robot to locate all the coins
 hidden in its world. The robot’s world is 10 × 10 units in size, and the x and y coordinates
 are in the range [0, 9] (from 0 to 9, inclusive).
 */

#include <iostream>
#include <string>
#include "point.hpp"
#include "robot.hpp"
#include "world.hpp"
using namespace std;


// main method
int main(){
    
    // creating the World object
    World W;
    
    // opt.1: initialize coins location randomly
    // W.randomlySetCoins(); // uncomment to use this option
    
    // opt.2: initialize coins location using validated user input
    W.userSetCoins(); // comment it out to use option 1

    // print the coins location
    W.print();
    
    // create and initialize Robot object
    Robot R;
    R.init();
    
    // display Robot object in the world
    W.initWorld();
    W.updateWorld(R);
    W.displayWorld();
    R.print();
    W.controller(R);
    
    return 0;
} // end of main method