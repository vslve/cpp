#include <iostream>

#include "point.h"
#include "userinterface.h"

Point getPointFromUserInput()
{
    std::cout << "Введите координаты точки на плоскости \"x y\"" << '\n';
    int x = 0;
    int y = 0;
    std::cin >> x >> y;
    while (!std::cin)
    {
        std::cin.clear();
        std::cin.ignore(10000,'\n');
        std::cout << "Некорректный ввод. Введите координаты точки на плоскости \"x y\" - целые десятичные числа:\n";
        std::cin >> x >> y;
    }
    std::cin.ignore(10000,'\n');
    return Point(x, y);
}

PointZ getPointZFromUserInput()
{
    std::cout << "Введите координаты точки на плоскости \"x y z\"" << '\n';
    int x = 0;
    int y = 0;
    int z = 0;
    std::cin >> x >> y >> z;
    while (!std::cin)
    {
        std::cin.clear();
        std::cin.ignore(10000,'\n');
        std::cout << "Некорректный ввод. Введите координаты точки на плоскости \"x y\" - целые десятичные числа:\n";
        std::cin >> x >> y >> z;
    }
    std::cin.ignore(10000,'\n');
    return PointZ(x, y, z);
}

void showMenu()
{
    std::cout << "Найти расстояние между точками\n\n \
1. на плоскости\n \
2. в пространстве\n \
3. завершить программу\n\n"
                 << "Введите номер пункта меню для продожения: ";
}

int userChoice()
{
        int choice = 0;
        std::cin >> choice;
        while (!std::cin || choice < 1 || choice > 3)
        {
            std::cin.clear();
            std::cin.ignore(10000, '\n');
            std::cout << "\nНекорректный ввод.\nВведите номер подходящего пункта меню для продожения: ";
            std::cin >> choice;
        }
        std::cout << std::endl;
        return choice;
}
