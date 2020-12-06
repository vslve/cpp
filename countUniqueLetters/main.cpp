#include <iostream>
#include <fstream>

#include "count_unique_letters.hpp"

int main()
{
    std::ifstream inFile;
    try {
        c::openFile(inFile, "stringsToRead.txt");
        c::startCountUniqueLetter(inFile);
    }
    catch (const char *error)
    {
        if (error == c::FILE_NOT_OPEN)
        {
            std::cerr << error << std::endl;
        }
        else {
            std::cerr << "Строка " << c::STRING_NUMBER << ": " << error << std::endl;
        }
    }
    inFile.close();
    std::cout << std::endl << std::endl;
    try {
        cpp::openFile(inFile, "stringsToRead.txt");
        cpp::startCountUniqueLetter(inFile);
    }
    catch (const std::string &error) {
        if (error == cpp::FILE_NOT_OPEN) {
            std::cerr << error << std::endl;
        }
        else {
            std::cerr << "Строка " << cpp::STRING_NUMBER << ": " << error << std::endl;
        }
    }
    inFile.close();
    std::cout << std::endl << std::endl;

    return 0;
}
