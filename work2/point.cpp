#include "point.h"


 Point::Point(int xVal, int yVal) {
    x = xVal;
    y = yVal;
}

int Point::getX() const { return x; }
int Point::getY() const { return y; }

void Point:: setX(int xVal) { x = xVal;}
void Point:: setY(int yVal) { y = yVal;}

void Point::Print() const {
    cout << "(" << x << "," << y << ")" << endl;
}
    
double Point:: DistanceTo(const Point& other) const {
    int dx = x - other.x;
    int dy = y - other.y;
return sqrt(dx * dx + dy * dy);
}