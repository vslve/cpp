#include <iostream>

#include "point.h"
#include "distance.h"


double findDistance(Point &point, Point &anotherPoint)
{
    return point.getDistance(anotherPoint);
}

double findDistance(PointZ &point, PointZ &anotherPoint)
{
    return point.getDistance(anotherPoint);
}


void printDistance(Point &point, Point &anotherPoint)
{
    std::cout << "\nРасстояние на плоскости между точками (" << point.getX() << "," << point.getY() << ") и ("
              << anotherPoint.getX() << "," << anotherPoint.getY() << "): "
              << findDistance(point, anotherPoint) << '\n' << std::endl;
}

void printDistance(PointZ &point, PointZ &anotherPoint)
{
    std::cout << "\nРасстояние в пространстве между точками (" << point.getX() << "," << point.getY() << "," << point.getZ() << ") и ("
              << anotherPoint.getX() << "," << anotherPoint.getY() << "," << point.getZ() << "): "
              << findDistance(point, anotherPoint) << '\n' << std::endl;
}
