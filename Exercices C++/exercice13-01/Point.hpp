#ifndef POINT_HPP
#define POINT_HPP

#include <iostream>

class Point {
private:
    int m_x;
    int m_y;
    int m_z;

public:
    Point(int x, int y, int z);

    friend std::ostream& operator<<(std::ostream& out, const Point& p);
};

#endif
