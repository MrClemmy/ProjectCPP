#ifndef POINT_H
#define POINT_H

#include <iostream>
#include <cmath>

using namespace std;

class Point {
private:
    int x;
    int y;
    
public:
    // Constructor with default values
Point(int xVal = 0, int yVal = 0);

// The accessors
int getX() const;
int getY() const;

// The mutators
void setX(int xVal);
void setY(int yVal);

// Print method
 void Print() const;
 
// DistanceTo method
double DistanceTo(const Point& other)const;
};

#endif