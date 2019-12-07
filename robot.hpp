//
//  robot.hpp
//  look-for
//  Created by Mariia Romaniuk
//

#ifndef robot_hpp
#define robot_hpp

#include <stdio.h>
#include <iostream>
#include "point.hpp"
using namespace std;


// declaration of Robot class
class Robot{
    
    // private class member fields
private:
    
    // Point object that stores the robot’s current location in the world
    Point robot_location;
    
    // an enumerated data type that defines the four directions
    // that robot could be facing (north, south, east or west)
    enum orientation_type {North, South, East, West};
    
    // variable that stores robot’s current orientation
    orientation_type orientation;
    
    // variable that counts robot's moves
    static int moves;
    
    // public class member functions declaration
public:
    
    // default constructor
    Robot();
    
    // destructor
    ~Robot();
    
    // this function returns robot's location - Point object
    Point getLocation();
    
    // this function initializes robot’s current location to (0, 0)
    // and its current orientation to the east
    void init();
    
    // this function prints robot’s current location and orientation
    void print() const;
    
    // this function sets the value of the robot’s orientation data member
    void setOrientation(orientation_type orientation);
    
    // this function simulates the robot moving forward one step in the direction
    // that it is facing. It checks to make sure that the robot is not at the edge
    // of its world. It returns true if the robot moves forward successfully and
    // false if the robot is at the edge of its world and cannot move forward
    bool forward();
    
    // this function changes the robot’s orientation,
    // simulating a turn in the clockwise direction
    void turnCW();
    
    // this function changes the robot’s orientation,
    // simulating a turn in the anti-clockwise direction
    void turnAntiCW();
    
    // this function returns true if robot has reached the east edge of its world
    bool eastEnd();
    
    // this function returns true if robot has reached the west edge of its world
    bool westEnd();
    
    // this function returns true if robot has reached the north edge of its world
    bool northEnd();
    
    // this function returns true if robot has reached the south edge of its world
    bool southEnd();
    
    // this function is called when the robot has been moving east and has reached
    // the east edge of its world, in which case it should turn clockwise,
    // go forward one step south and turn clockwise again
    // (where it will be heading west for its next move)
    bool zag();
    
    // this function is called when the robot has been moving west and has reached
    // the west edge of its world, in which case it should turn anti-clockwise,
    // go forward one step south and turn anti-clockwise again
    // (where it will be heading east for its next move)
    bool zig();
    
    // this function reports the number of moves made by the robot
    // in order to find all the coins
    void result();
    
}; // end of Robot class

#endif /* robot_hpp */

