#include <iostream>

#include "matrixCounters.h"

int main() {

    std::cout << "Функция вычисляет количество строк, содержащих нули во встроенном двумерном массиве." << "\n\n";
    for (matrix::Matrix m : matrixVector)
    {
        evaluateInsertMatrix(m.matrix, m.rows, m.columns);
    }
    std::cout << "-------------------------------------------------------------------------------------------------\n";
    std::cout << "Функция вычисляет количество локальных минимумов квадратной матрицы." << "\n\n";
    try
    {
        evaluateDynamicMatrix();
    }
    catch (const std::string &error) {
        std::cerr << error << std::endl;
    }
}
