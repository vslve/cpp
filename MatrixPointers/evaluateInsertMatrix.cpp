#include <iostream>
#include <vector>
#include <iomanip>

#include "matrixCounters.h"

int firstMatrix[][7] = {
        {1, 2, 3, 4, 5, 0, 7},
        {1, 2, 3, 4, 5, 6, 7},
        {0, 2, 3, 4, 5, 6, 7},
        {1, 2, 3, 4, 5, 6, 7},
        {0, 0, 0, 0, 0, 0, 0}
};

int secondMatrix[][5] = {
        {0, 1, 2, 3, 4},
        {1, 2, 3, 4, 5},
};

matrix::Matrix one{5, 7, *firstMatrix};
matrix::Matrix two{2, 5, *secondMatrix};

const std::vector<matrix::Matrix> matrixVector {one, two};


int countStingsWithZero(const int *matrix, int rows, int columns)
{
    int count = 0;
    for (int row = 0; row < rows; ++row)
    {
        for (int column = 0; column < columns; ++column)
        {
            if (*(matrix + row * columns + column) == 0)
            {
                count++;
                break;
            }
        }
    }
    return count;
}

void printMatrix(int *matrix, int rows, int columns)
{
    std::cout << '\n';
    for (int row = 0; row < rows; ++row)
    {
        for (int column = 0; column < columns; ++column)
        {
            std::cout << std::setw(4) << *(matrix + row * columns + column) << ' ';
        }
        std::cout << '\n';
    }
    std::cout << '\n';
}

void printStringsWithZeroNumber(int count)
{
    std::cout << "Количество строк, содержащих хотя бы один нулевой эдемент: "
              << count
              << "\n\n";
}

void evaluateInsertMatrix(int *matrix, int rows, int columns)
{
    std::cout << "Встроенная матрица:\n";
    printMatrix(matrix, rows, columns);
    printStringsWithZeroNumber(countStingsWithZero(matrix, rows, columns));
}
