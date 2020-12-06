#ifndef SIMPLECLASSUTILLS_H
#define SIMPLECLASSUTILLS_H

#include "Organization.h"
#include "fstream"

const std::string FILE_ERROR = "Не удалось открыть файл.";

int findMaxTotalAmountCard(Container<DiscountCard> &cards);
std::string askInputFileName();
void openFile(std::ifstream &inFile, std::string &fileName);
void outputItemsTable(Container<DiscountCard> &cards);
void outputItemsTable(std::ofstream &outFile, Container<DiscountCard> &cards);
void outputItemsTable(Container<Organization> &organizations);
void outputItemsTable(std::ofstream &outFile, Container<Organization> &organizations);
Container<Organization> createOrganizationsList(Container<DiscountCard> &cards);


template <class Type>
void sortItems (Type &items)
{
    int size = items.size();
    for (int i = 0; i < size; ++i)
    {
        int j = i;
        while (j > 0)
        {
            int cardNumberOne = items.take(j + 1).getCardNumber();
            int cardNumberTwo = items.take(j).getCardNumber();
            if (cardNumberOne < cardNumberTwo)
            {
                auto item = items.take(j);
                items.take(j) = items.take(j + 1);
                items.take(j + 1) = item;
            }
            --j;
        }
    }
}

template<typename Type>
void readFromFileTo(std::ifstream &inFile, Container<Type> &container, int &counter)
{
    while (!inFile.eof())
    {
        Type item;
        inFile >> item;
        container.add(item);
        ++counter;
    }
}

#endif //SIMPLECLASSUTILLS_H
