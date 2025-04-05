
#include <iostream>
#include "Point2D.h"
#include "Math.h"
Point2D::Point2D() : m_x{0}, m_y{0} {}
Point2D::Point2D(double x, double y) : m_x{x}, m_y{y} {}

void Point2D::affiche()
{

    std::cout << "Point2D ( " << m_x << " , " << m_y << " ) " << std::endl;
}

double Point2D::distance(Point2D p)
{

    return sqrt((p.m_x - m_x) * (p.m_x - m_x) + (p.m_y - m_y) * (p.m_y - m_y));
}

double distanceEntre(Point2D p1, Point2D p2)
{

    return sqrt((p2.m_x - p1.m_x) * (p2.m_x - p1.m_x) + (p2.m_y - p1.m_y) * (p2.m_y - p1.m_y));
}