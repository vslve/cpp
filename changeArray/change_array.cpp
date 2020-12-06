#include <iostream>
#include <fstream>

#include "change_array.hpp"

int askArraySize()
{
    std::cout << "Введите размер массива: " << '\n';
    int size = 0;
    std::cin >> size;
    while (!std::cin)
    {
        std::cin.clear();
        std::cin.ignore(10000, '\n');
        std::cout << "Введите размер массива - целое число." << '\n';
        std::cin >> size;
    }
    std::cin.ignore(10000, '\n');

    return size;
}

int *createArray(int size)
{
    int *array = new int[size] {};
    for (int i = 0; i < size; ++i)
    {
        *(array + i) = std::rand() % 50;
    }
    return array;
}

int *askIndexes(int arraySize)
{
    const std::string INVALID_INDEXES = "Недопустимый диапозон.";

    int *indexes = new int[2];
    std::cout << "Введите Start-индекс и Stop-индекс через пробел: " << '\n';
    int start = 0;
    int stop = 0;
    std::cin >> start >> stop;
    while (!std::cin)
    {
        std::cin.clear();
        std::cin.ignore(10000, '\n');
        std::cout << "Введите Start-индекс и Stop-индекс через пробел. Start и Stop - натуральные числа: " << '\n';
        std::cin >> start >> stop;
    }
    std::cin.ignore(10000, '\n');
    if (start < 0 || start >= arraySize || stop < 0 || stop >= arraySize || start > stop)
    {
        throw INVALID_INDEXES;
    }
    indexes[0] = start;
    indexes[1] = stop;

    return indexes;
}

int *generateRange(int arraySize)
{
    int start = std::rand() % (arraySize / 2);
    int stop = start + 1 + std::rand() % (arraySize - start - 1);
    int *indexes = new int[2] {start, stop};
    return indexes;
}

void deleteArray(int *&array)
{
    delete[] array;
    array = nullptr;
}

void fillArray(int *array, int size)
{
    for (int i = 0; i < size; ++i)
    {
        *(array + i) = std::rand() % 50;
    }
}

void printArray(const int *array, int size)
{
    for (int i = 0; i < size; ++i)
    {
        std::cout << *(array + i) << ' ';
    }
    std::cout << std::endl;
}

void changeArray(int *array, int size, int startIndex, int stopIndex) {

    int firstPartSize = size - (stopIndex - startIndex + 1);
    int secondPartSize = size - firstPartSize;
    int *firstPart = new int[firstPartSize]{};
    int *secondPart = new int[secondPartSize]{};
    for (int i = 0; i < size; ++i)
    {
        if (i < startIndex)
        {
            *(firstPart + i) = *(array + i);
        }
        else if (i > stopIndex)
        {
            int firstPartIndex = i - secondPartSize;
            *(firstPart + firstPartIndex) = *(array + i);
        }
        else
        {
            int secondPartIndex = i - startIndex;
            *(secondPart + secondPartIndex) = *(array + i);
        }
    }
    for (int i = 0; i < firstPartSize; ++i)
    {
        *(array + i) = *(firstPart + i);
    }
    deleteArray(firstPart);
    for (int i = firstPartSize; i < size; ++i)
    {
        int secondPartIndex = i - firstPartSize;
        *(array + i) = *(secondPart + secondPartIndex);
    }
    deleteArray(secondPart);
}

void writeArrayToFile(const int *array, int size, bool &isEmpty)
{
    std::ofstream outFile;
    if (isEmpty)
    {
        outFile.open("arraysResult", std::ios_base::trunc);
        outFile.close();
        isEmpty = false;
    }
    outFile.open("arraysResult", std::ios_base::app);
    for (int i = 0; i < size; ++i)
    {
        outFile << *(array + i) << ' ';
    }
    outFile << '\n';
}

void printResult(int *array, int size, int start=-1, int stop=-1)
{
    std::cout << "Массив до: ";
    printArray(array, size);
    if(start == -1 && stop == -1)
    {
        int *indexes = generateRange(size);
        start = *indexes;
        stop = *(indexes + 1);
        deleteArray(indexes);
    }
    std::cout << "Массив после(" << "Start = " << start << ", Stop = " << stop << "): ";
    changeArray(array, size, start, stop);
    printArray(array, size);
}

void changeStaticArray(const int size)
{
    const std::string INVALID_VALUE = "Недопустимое значение размера массива.";

    if (size <= 0)
    {
        throw INVALID_VALUE;
    }
    int array[size];
    fillArray(array, size);
    printResult(array, size);
}

void changeUsersArray()
{
    int size = askArraySize();
    int *array = createArray(size);
    int *indexes = askIndexes(size);
    int start = *indexes;
    int stop = *(indexes + 1);
    deleteArray(indexes);
    printResult(array, size, start, stop);
    deleteArray(array);
}

void changeFileArray()
{
    bool isEmpty = true;

    const std::string INVALID_SIZE = "Недопустимое значение размера массива.";
    const std::string INVALID_VALUE = "Недопустимое значение элемента массива.";
    const std::string READ_FAIL = "Не удалось прочитать файл.";
    const std::string DATA_ERROR = "Несоответствие данных.";


    std::ifstream inFile;
    inFile.open("arraysToRead");

    if (!inFile)
    {
        throw READ_FAIL;
    }
    int * array = nullptr;
    int size = 0;
    bool firstRead = true;
    int **arrays = nullptr;
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
        array = new int[size];
        std::string numberString;
        getline(inFile, numberString);
        std::string number;
        int count = 0;
        for (char ch : numberString)
        {
            if (ch == ' ' && !number.empty())
            {
                if (count >= size)
                {
                    throw DATA_ERROR;
                }
                *(array + count) = std::stoi(number);
                number = "";
                ++count;
                continue;
            }
            if(ch != ' ')
            {
                if (ch < 48 || ch > 57)
                {
                    throw INVALID_VALUE;
                }
                number.push_back(ch);
            }
        }
        bool dataCorrect = !number.empty() && count == size - 1 || number.empty() && count == size;
        if (!dataCorrect)
        {
            throw DATA_ERROR;
        }
        if (!number.empty())
        {
            *(array + count) = std::stoi(number);
        }
        printResult(array, size);
        writeArrayToFile(array, size, isEmpty);
        std::cout << '\n';
        deleteArray(array);
        inFile >> size;
        inFile.ignore(10000, '\n');
    }
    inFile.close();
}
