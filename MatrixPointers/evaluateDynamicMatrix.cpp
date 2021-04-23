#include <iostream>
#include <fstream>
#include <iomanip>

#include "matrixCounters.h"

void deleteMatrix(int **&matrix, int size)
{
    for (int i = 0; i < size; ++i)
    {
        delete[] *(matrix + i);
    }
    delete[] matrix;
    matrix = nullptr;
}

int countMatrixLocalMin(int **matrix, int size) {
    int count = 0;
    // для матрицы размера n - 1 m - 1
    for (int i = 1; i < size - 1; ++i) {
        for (int j = 1; j < size - 1; ++j) {
            bool isRowMinimum = *(*(matrix + i) + j) < *(*(matrix + i) + j + 1) \
 && *(*(matrix + i) + j) < *(*(matrix + i) + j - 1);
            bool isColumnMinimum = *(*(matrix + i) + j) < *(*(matrix + i - 1) + j) \
 && *(*(matrix + i) + j) < *(*(matrix + i + 1) + j);
            bool isDiagonalMinimum = *(*(matrix + i) + j) < *(*(matrix + i + 1) + j + 1) \
 && *(*(matrix + i) + j) < *(*(matrix + i - 1) + j - 1) \
 && *(*(matrix + i) + j) < *(*(matrix + i + 1) + j - 1) \
 && *(*(matrix + i) + j) < *(*(matrix + i - 1) + j + 1);
            bool isLocalMinimum = isRowMinimum && isColumnMinimum && isDiagonalMinimum;
            if (isLocalMinimum) {
                count++;
            }
        }
    }
    // для первой строки от 1 до size - 1 элемента
    for (int i = 1; i < size - 1; ++i) {
        bool isRowMinimum = *(*(matrix) + i) < *(*(matrix) + i + 1) \
 && *(*(matrix) + i) < *(*(matrix) + i - 1);
        bool isColumnMinimum = *(*(matrix) + i) < *(*(matrix + 1) + i);
        bool isDiagonalMinimum = *(*(matrix) + i) < *(*(matrix + 1) + i + 1) \
 && *(*(matrix) + i) < *(*(matrix + 1) + i - 1);
        bool isLocalMinimum = isRowMinimum && isColumnMinimum && isDiagonalMinimum;
        if (isLocalMinimum) {
            count++;
        }
    }
    for (int i = 1; i < size - 1; ++i) {

        bool isRowMinimum = *(*(matrix + size - 2) + i) < *(*(matrix + size - 2) + i + 1) \
 && *(*(matrix) + i) < *(*(matrix) + i - 1);
        bool isColumnMinimum = *(*(matrix + size - 2) + i) < *(*(matrix + size - 3) + i);
        bool isDiagonalMinimum = *(*(matrix + size - 2) + i) < *(*(matrix + size - 3) + i + 1) \
 && *(*(matrix + size - 2) + i) < *(*(matrix + size - 3) + i - 1);
        bool isLocalMinimum = isRowMinimum && isColumnMinimum && isDiagonalMinimum;
        if (isLocalMinimum) {
            count++;
        }
    }
    // для первого столца от 1 до size - 1 элемента
    for (int i = 1; i < size - 1; ++i) {
        bool isRowMinimum = **(matrix + i) < *(*(matrix + i) + 1);
        bool isColumnMinimum = **(matrix + i) < **(matrix + i - 1) \
 && **(matrix + i) < **(matrix + i + 1);
        bool isDiagonalMinimum = **(matrix + i) < *(*(matrix + i - 1) + 1) \
 && **(matrix + i) < *(*(matrix + i + 1) + 1);
        bool isLocalMinimum = isRowMinimum && isColumnMinimum && isDiagonalMinimum;
        if (isLocalMinimum) {
            count++;
        }
    }
    for (int i = 1; i < size - 1; ++i) {
        int column = size - 1;
        bool isRowMinimum = *(*(matrix + i) + column) < *(*(matrix + i) + column - 1);
        bool isColumnMinimum = *(*(matrix + i) + column) < *(*(matrix + i + 1) + column) \
 && *(*(matrix + i) + column) < *(*(matrix + i - 1) + column);
        bool isDiagonalMinimum = *(*(matrix + i) + column) < *(*(matrix + i - 1) + column - 1) \
 && *(*(matrix + i) + column) < *(*(matrix + i + 1) + column - 1);
        bool isLocalMinimum = isRowMinimum && isColumnMinimum && isDiagonalMinimum;
        if (isLocalMinimum) {
            count++;
        }
    }
    bool isLeftUpCornerLocalMinimum = **matrix < *(*matrix + 1) && **matrix < *(*(matrix + 1)) \
 && **matrix < *(*(matrix + 1) + 1);
    bool isLeftDownCornerLocalMinimum = **(matrix + size - 1) < **(matrix + size - 2) \
 && **(matrix + size - 1) < *(*(matrix + size - 1) + 1) && **(matrix + size - 1) < *(*(matrix + size - 2) + 1);
    bool isRightUpCornerLocalMinimum = *(*matrix + size - 1) < *(*matrix + size - 2) \
 && *(*matrix + size - 1) < *(*(matrix + 1) + size - 1) && *(*matrix + size - 1) < *(*(matrix + 1) + size - 2);
    bool isRightDownCornerLocalMinimum = *(*(matrix + size - 1) + size - 1) < *(*(matrix + size - 1) + size - 2) \
 && *(*(matrix + size - 1) + size - 1) < *(*(matrix + size - 2) + size - 1) \
 && *(*(matrix + size - 1) + size - 1) < *(*(matrix + size - 2) + size - 2);
    bool isCornerLocalMinimum[4] = {isLeftUpCornerLocalMinimum, isRightUpCornerLocalMinimum, \
    isLeftDownCornerLocalMinimum, isRightDownCornerLocalMinimum};
    for (bool isLocalMinimum : isCornerLocalMinimum) {
        if (isLocalMinimum) {
            count++;
        }
    }
    return count;

}

void writeLocalMinimumNumber(int **matrix, int size, bool &isEmpty, const std::string &outFileName = "matrixResult.txt")
{
    std::ofstream outFile;
    if (isEmpty)
    {
        outFile.open(outFileName, std::ios_base::trunc);
        outFile.close();
        isEmpty = false;
    }
    outFile.open(outFileName, std::ios_base::app);
    outFile << "Квадратная матрица:" << '\n';
    outFile << '\n';
    for (int row = 0; row < size; ++row)
    {
        for (int column = 0; column < size; ++column)
        {
            outFile << std::setw(4) <<  *(*(matrix + row) + column) << ' ';
        }
        outFile << '\n';
    }
    outFile << '\n';
    outFile << "Количество локальных минимумов матрицы: " << countMatrixLocalMin(matrix, size) << "\n\n";
    outFile.close();
    std::cout << "Результат записан в файл " << outFileName << '\n';
}

void writeLocalMinimumNumber(int **matrix, int size)
{
    std::cout << "Квадратная матрица:" << '\n';
    std::cout << '\n';
    for (int row = 0; row < size; ++row)
    {
        for (int column = 0; column < size; ++column)
        {
            std::cout << std::setw(4) <<  *(*(matrix + row) + column) << ' ';
        }
        std::cout << '\n';
    }
    std::cout << '\n';
    std::cout << "Количество локальных минимумов матрицы: " << countMatrixLocalMin(matrix, size) << '\n';

}


int **allocateSquadMatrix(int size)
{
    int **matrix = new int*[size];
    for (int i = 0; i < size; ++i)
    {
        *(matrix + i) = new int[size];
    }
    return matrix;
}



void evaluateDynamicMatrix()
{
    bool isEmpty = true;

    const std::string INVALID_SIZE = "Недопустимое значение размера массива.";
    const std::string INVALID_VALUE = "Недопустимое значение элемента массива.";
    const std::string READ_FAIL = "Не удалось прочитать файл.";
    const std::string DATA_ERROR = "Несоответствие данных.";


    std::ifstream inFile;
    inFile.open("matrixToRead.txt");

    if (!inFile)
    {
        throw READ_FAIL;
    }
    int **matrix = nullptr;
    int size = 0;
    bool firstRead = true;
    while(inFile) {
        if (firstRead)
        {
            inFile >> size;
            inFile.ignore(10000, '\n');
            firstRead = false;
        }
        if (size <= 0 || !inFile)
        {
            throw INVALID_SIZE;
        }
        matrix = allocateSquadMatrix(size);
        std::string numberString;
        getline(inFile, numberString);
        std::string number;
        int count = 0;
        for (char ch : numberString)
        {
            if (ch == ' ' && !number.empty())
            {
                if (count >= size * size)
                {
                    deleteMatrix(matrix, size);
                    throw DATA_ERROR;
                }
                *(*(matrix + count / size) + count % size) = std::stoi(number);
                number = "";
                ++count;
                continue;
            }
            if(ch != ' ')
            {
                if (ch < 48 || ch > 57)
                {
                    deleteMatrix(matrix, size);
                    throw INVALID_VALUE;
                }
                number.push_back(ch);
            }
        }
        bool dataCorrect = !number.empty() && count == size * size - 1 || number.empty() && count == size * size;
        if (!dataCorrect)
        {
            deleteMatrix(matrix, size);
            throw DATA_ERROR;
        }
        if (!number.empty())
        {
            *(*(matrix + count / size) + count % size) = std::stoi(number);
        }
        writeLocalMinimumNumber(matrix, size);
        writeLocalMinimumNumber(matrix, size, isEmpty);
        std::cout << '\n';
        deleteMatrix(matrix, size);
        inFile >> size;
        inFile.ignore(10000, '\n');
    }
    inFile.close();
}



