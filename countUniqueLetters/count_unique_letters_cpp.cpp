#include <iostream>
#include <fstream>
#include <string>

#include "count_unique_letters.hpp"


namespace cpp {
    const std::string VALUE_ERROR = "-----CPP::ERROR-----неврное значение длины.";
    const std::string EOF_MASSAGE = "-----CPP::OK-----достигнут конец файла.";
    const std::string FILE_NOT_OPEN = "Не удалось открыть файл";

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

    void printString(const std::string &string) {
        std::cout << string;
    }

    void printInfo(const std::string &string, int letterCount) {
        std::cout << "Различных букв в строке \"";
        printString(string);
        std::cout << "\": " << letterCount << '\n';
    }

    void checkStringLength(std::string &string, int &stringLength) {
        int trueLength = string.length();
        if (trueLength > stringLength) {
            for (int i = 0; i < trueLength - stringLength; ++i) {
                string.pop_back();
            }
        }
        else if (trueLength < stringLength)
        {
            stringLength = trueLength;
        }

    }

    std::string getStringFromFile(std::ifstream &inFile) {
        std::string string;
        getline(inFile, string);
        return string;
    }

    bool isUniqueLetter(std::string string, int letterIndex) {
        if (letterIndex == 0 && string[0] == ' ') {
            return false;
        }
        for (int i = 0; i < letterIndex; ++i) {
            if (string[i] == string[letterIndex]) {
                return false;
            }
        }
        return true;
    }

    int countUniqueLetter(const std::string &string, int stringLength) {
        int nUnique = 0;

        for (int i = 0; i < stringLength; ++i) {
            if (isUniqueLetter(string, i)) {
                nUnique += 1;
            }
        }
        return nUnique;
    }

    void openFile(std::ifstream &inFile, const std::string &fileName) {
        inFile.open(fileName);
        if (!inFile) {
            throw FILE_NOT_OPEN;
        }
    }

    void startCountUniqueLetter(std::ifstream &inFile, bool print) {

        while (inFile) {
            static int stringNumber = 1;
            int length = 0;
            std::string string;
            length = getStringLengthFromFile(inFile);
            string = getStringFromFile(inFile);
            checkStringLength(string, length);
            int nUniqueLetters = countUniqueLetter(string, length);

            if (!print) {
                continue;
            }
            printInfo(string, nUniqueLetters);
            stringNumber++;
            STRING_NUMBER = stringNumber;
        }
    }
}
