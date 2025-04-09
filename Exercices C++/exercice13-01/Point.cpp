#include "Point.hpp"

Point::Point(int x, int y, int z) : m_x{x}, m_y{y}, m_z{z} {}

std::ostream& operator<<(std::ostream& out, const Point& p) {
    return out << "Point(" << p.m_x << ", " << p.m_y << ", " << p.m_z << ")";
}
