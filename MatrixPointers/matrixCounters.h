#ifndef MATRIXCOUNTERS_H
#define MATRIXCOUNTERS_H

#include <vector>

namespace matrix
{
    struct Matrix
    {
        const int rows;
        const int columns;
        int *matrix = nullptr;
    };

    struct SquareMatrix
    {
        const int size;
        int **matrix = nullptr;
    };
}

extern const std::vector<matrix::Matrix> matrixVector;

void evaluateInsertMatrix(int *matrix, int rows, int columns);

void evaluateDynamicMatrix();

#endif //MATRIXCOUNTERS_H
