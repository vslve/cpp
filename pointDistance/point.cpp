#include <iostream>
#include <cmath>

#include "point.h"


Point::Point(): x_(0), y_(0) {};
Point::Point(int x, int y): x_(x), y_(y) {};
void Point::setXY(int x, int y)
{
    x_ = x;
    y_ = y;
}
int Point::getX()
{
    return x_;
}
int Point::getY()
{
    return y_;
}
double Point::getDistance(Point &point)
{
    return std::sqrt(std::pow(this->x_ - point.getX(), 2) + std::pow(this->y_ - point.getY(), 2));
}


PointZ::PointZ(): Point(), z_(0) {};
PointZ::PointZ(int x, int y, int z): Point(x, y), z_(z) {};
void PointZ::setXYZ(int x, int y, int z)
{
    Point::setXY(x, y);
    z_ = z;
}
int PointZ::getZ()
{
    return z_;
}
double PointZ::getDistance(PointZ &point)
{

    return std::sqrt(std::pow(Point::getDistance(point), 2) + std::pow(this->z_ - point.getZ(), 2));
}

