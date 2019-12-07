//
//  point.hpp
//  look-for
//  Created by Mariia Romaniuk
//

#ifndef point_hpp
#define point_hpp

#include <stdio.h>
#include <iostream>
using namespace std;


// declaration of Point class
class Point{
    
    // private class member fields
private:
    
    // x and y coordinates of the Point object
    int x, y;
    
    // public class member functions declaration
public:
    // default constructor
    Point();
    
    // constructor with arguments
    Point(int x, int y);
    
    // destructor
    ~Point();
    
    // this function prints out the values of the data members x and y
    void print() const;
    
    // this function sets the values of the data members x and y
    void set(int x, int y);
    
    // this function returns the value of the x data member
    int getX();
    
    // this function returns the value of the y data member
    int getY();
    
    // this function increments X value by one
    void incX();
    
    // this function decrements X value by one
    void decX();
    
    // this function increments Y value by one
    void incY();
    
    // this function decrements Y value by one
    void decY();
    
}; // end of Point class

#endif /* point_hpp */

