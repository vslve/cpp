#include <iostream>
#include <fstream>
#include <cstring>

#include "count_unique_letters.hpp"


namespace c {
    const char *FILE_NOT_OPEN = "Не удалось открыть файл";
    const char *VALUE_ERROR = "-----C::ERROR-----неврное значение длины.";
    const char *EOF_MASSAGE = "-----C::OK-----достигнут конец файла.";

    int STRING_NUMBER = 0;

    int getStringLengthFromFile(std::ifstream &inFile) {
        int stringLength = 0;
        inFile >> stringLength;
        if (inFile.eof()) {
            throw EOF_MASSAGE;
        }
        if (!inFile) {
            throw VALUE_ERROR;
        }
        inFile.ignore(10000, '\n');
        return stringLength;
    }

    void printString(char *string) {
        std::cout << string;
    }


    void printInfo(char *string, int letterCount) {
        std::cout << "Различных букв в строке \"";
        printString(string);
        std::cout << "\": " << letterCount << '\n';
    }

    void checkStringLength(char *string, int &stringLength) {
        int trueLength = strlen(string);
        if (trueLength != stringLength) {
            stringLength = trueLength;
        }
    }

    char *getStringFromFile(std::ifstream &inFile, int &stringLength) {
        char *string = new char[stringLength + 1];
        inFile.get(string, stringLength + 1);
        inFile.ignore(1000, '\n');
        return string;
    }

    bool isUniqueLetter(const char *string, int letterIndex) {
        if (letterIndex == 0 && *string == ' ') {
            return false;
        }
        for (int i = 0; i < letterIndex; ++i) {
            if (*(string + i) == *(string + letterIndex)) {
                return false;
            }
        }
        return true;
    }

    int countUniqueLetter(char *string, int stringLength) {
        int nUnique = 0;

        for (int i = 0; i < stringLength; ++i) {
            if (isUniqueLetter(string, i)) {
                nUnique += 1;
            }
        }
        return nUnique;
    }

    void openFile(std::ifstream &inFile, const char *fileName) {

        inFile.open(fileName);
        if (!inFile) {
            throw FILE_NOT_OPEN;
        }
    }

    void deleteString(char *&string) {
        delete[] string;
        string = nullptr;
    }

    void startCountUniqueLetter(std::ifstream &inFile, bool print) {

        while (true) {
            static int stringNumber = 1;
            int length = 0;
            char *string;
            length = getStringLengthFromFile(inFile);
            string = getStringFromFile(inFile, length);
            checkStringLength(string, length);
            int nUniqueLetters = countUniqueLetter(string, length);
            if (!print) {
                continue;
            }
            printInfo(string, nUniqueLetters);
            deleteString(string);
            stringNumber++;
            if (!inFile) {
                STRING_NUMBER = stringNumber;
                throw EOF_MASSAGE;
            }
        }
    }
}


