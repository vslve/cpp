#include <iostream>

#include "point.h"
#include "userinterface.h"
#include "distance.h"


int main()
{
    while(true)
    {
        showMenu();
        int choice = userChoice();
        if (choice == 1)
        {
            Point point = getPointFromUserInput();
            Point anotherPoint = getPointFromUserInput();
            printDistance(point, anotherPoint);
        }
        else if (choice == 2)
        {
            PointZ point = getPointZFromUserInput();
            PointZ anotherPoint = getPointZFromUserInput();
            printDistance(point, anotherPoint);
        }
        else if (choice == 3)
        {
            break;
        }
    }
}
