#include <iostream>
#include <vector>
#include <cstdlib>
#include <ctime>
#include "point.h"
using namespace std;

// Part III - Print all points
void PrintPoints(const vector<Point>& points) {
    cout << "[";
    for (size_t i = 0; i < points.size(); ++i) {
        points[i].Print();
        if (i < points.size() - 1) cout << ", ";
    }
    cout << "]" << endl;
}

// Part IV - Graphical grid display
void PrintGrid(const vector<Point>& points) {
    const int size = 10;
    char grid[size][size];

    // Initialize grid with '.'
    for (int i = 0; i < size; ++i)
        for (int j = 0; j < size; ++j)
            grid[i][j] = '.';

    // Mark points on grid with 'X'
    for (const Point& p : points) {
        int x = p.getX();
        int y = p.getY();
        if (x >= 0 && x < size && y >= 0 && y < size)
            grid[y][x] = 'X'; // y = row, x = column
    }

    // Print grid from top to bottom
    for (int i = 0; i < size; ++i) {
        for (int j = 0; j < size; ++j)
            cout << grid[i][j] << " ";
        cout << endl;
    }
}

int main() {
    srand(time(0));

    // Part II test
    Point a(5, 6), b(-2, 3);
    a.Print(); cout << endl;
    b.Print(); cout << endl;
    cout << a.DistanceTo(b) << endl;

    // Part III - Generate random points
    vector<Point> points(5);
    for (auto& pt : points) {
        pt.setX(rand() % 10);
        pt.setY(rand() % 10);
    }

    PrintPoints(points);  // Fancy output

    cout << "\nGraphical Grid:\n";
    PrintGrid(points);

    return 0;
}
