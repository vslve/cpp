#ifndef COUNT_UNIQUE_LETTERS_H
#define COUNT_UNIQUE_LETTERS_H

namespace cpp
{
    extern const std::string VALUE_ERROR;
    extern const std::string EOF_MASSAGE;
    extern const std::string FILE_NOT_OPEN;

    extern int STRING_NUMBER;

    void startCountUniqueLetter(std::ifstream &inFile, bool print=true);
    void openFile(std::ifstream &inFile, const std::string &fileName);
}

namespace c
{
    extern const char *FILE_NOT_OPEN;
    extern const char *VALUE_ERROR;
    extern const char *EOF_MASSAGE;

    extern int STRING_NUMBER;

    void startCountUniqueLetter(std::ifstream &inFile, bool print=true);
    void openFile(std::ifstream &inFile, const char *fileName);
}

#endif //COUNT_UNIQUE_LETTERS_H
