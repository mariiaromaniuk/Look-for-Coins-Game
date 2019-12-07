//
//  point.cpp
//  look-for
//  Created by Mariia Romaniuk
//

// definition of Point class
#include "point.hpp"
#include <fstream>

// default constructor
Point::Point(){
    x=0;
    y=0;
}

// constructor with arguments
Point::Point(int x, int y){
    this->x=x;
    this->y=y;
}

// destructor
Point::~Point(){
}

// this function prints out the values of the data members x and y
void Point::print() const{
  ofstream outfile;
  outfile.open ("output.txt", ios::out | ios::app);
    
  if (!outfile){
      throw "Error opening ioutput file";
  }
    else {
    outfile << "(x, y): ";
    cout << "(x, y): ";
    outfile << "(" << x << "," << y << ")";
    cout << "(" << x << "," << y << ")";
  }
} // end of print()


// this function sets the values of the data members x and y
void Point::set(int x, int y){
    this->x = x;
    this->y = y;
} // end of set()


// this function returns the value of the x data member
int Point::getX(){
    return x;
} // end of getX()


// this function returns the value of the y data member
int Point::getY(){
    return y;
} // end of getY()


// this function increments X value by one
void Point::incX(){
    x++;
} // end of incX()


// this function decrements X value by one
void Point::decX(){
    x--;
} // end of decX()


// this function increments Y value by one
void Point::incY(){
    y++;
} // end of incY()


// this function decrements Y value by one
void Point::decY(){
    y--;
} // end of decY()
