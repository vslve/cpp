#include <iostream>
#include <clocale>


#include "utils.h"


int main()
{
    setlocale(LC_ALL, "ru-RU.UTF-8");
    std::string fileName = askInputFileName();

    std::ifstream inFile;
    try
    {
        openFile(inFile, fileName);
    }
    catch (std::string &error)
    {
        std::cerr << error << std::endl;
    }


    Container<DiscountCard> cards;
    int counter = 0;
    try
    {
        readFromFileTo(inFile, cards, counter);
    }
    catch (std::string &error)
    {
        std::cerr << error << " Считано карт: " << counter << '\n' << std::endl;
        if (counter == 0)
        {
            return -1;
        }
    }

    std::cout << "\nНомер карты с максимальной общей суммой: " << findMaxTotalAmountCard(cards) << "\n\n";

    sortItems(cards);

    std::ofstream outFile;
    outputItemsTable( outFile, cards);

    Container<Organization> organizations = createOrganizationsList(cards);
    outputItemsTable( outFile,organizations);

    return 0;
}

