#include "utils.h"
#include <iomanip>

int findMaxTotalAmountCard(Container<DiscountCard> &cards)
{
    int cardNumber = 0;
    int maxAmount = -1;
    for (DiscountCard &card : cards)
    {
        int amount = card.getAmount();
        if (amount > maxAmount)
        {
            maxAmount = amount;
            cardNumber = card.getCardNumber();
        }
    }
    return cardNumber;
}

Container<Organization> createOrganizationsList(Container<DiscountCard> &cards)
{
    Container<Organization> organizations;
    for (DiscountCard &card : cards)
    {
        std::string organizationName = card.getOrganizationName();
        Organization organization(organizationName);
        if (!organizations.is_member(organization))
        {
            organizations.add(organization);
        }
        int position = organizations.getPosition(organizationName);
        organizations.take(position).addCard(card);
    }

    return organizations;
}

std::string askInputFileName()
{
    std::cout << "Введите имя файла для чтения данных о картах: ";
    std::string fileName;
    std::cin >> fileName;

    return fileName;
}

void openFile(std::ifstream &inFile, std::string &fileName)
{
    inFile.open(fileName);

    if (!inFile)
    {
        throw FILE_ERROR;
    }
}

void outputItemsTable(Container<DiscountCard> &cards)
{
    std::cout << "-----------------------------------------------------------------------------------------------" << '\n';
    std::cout << std::setw(25) << std::left << "Владелец карты" << std::setw(5) << " "
              << std::setw(15) << std::left << "Номер карты" << std::setw(5) << " "
              << std::setw(25) << std::left << "Название организации" << std::setw(5) << " "
              << std::setw(15) << std::left << "Общаая сумма" << std::setw(5) << " "
              << std::setw(15) << std::left << "Дата выдачи карты" << std::setw(5) << " "
              << "\n";
    std::cout << "-----------------------------------------------------------------------------------------------" << "\n\n";
    for (DiscountCard &card : cards)
    {
        std::cout << card;
    }
    std::cout << "-----------------------------------------------------------------------------------------------" << '\n';
}

void outputItemsTable(std::ofstream &outFile, Container<DiscountCard> &cards)
{
    outFile.open("cardsTable.txt");
    outFile << std::setw(25) << std::left << "Владелец карты" << std::setw(5) << " "
            << std::setw(15) << std::left << "Номер карты" << std::setw(5) << " "
            << std::setw(25) << std::left << "Название организации" << std::setw(5) << " "
            << std::setw(15) << std::left << "Общаая сумма" << std::setw(5) << " "
            << std::setw(15) << std::left << "Дата выдачи карты" << std::setw(5) << " "
            << "\n\n";

    for (DiscountCard &card : cards)
    {
        outFile << card;
    }

    outFile.close();
    std::cout << "Таблица отсортированных по номеру карт записана в файл \"cardsTable.txt\"" << std::endl;
}

void outputItemsTable(Container<Organization> &organizations)
{
    std::cout << "-----------------------------------------------------------------------" << '\n';
    std::cout << std::setw(25) << std::left << "Название организации" << std::setw(10) << " "
            << std::setw(25) << std::left << "Номера выданных организацией карт" << std::setw(5) << " "
            << "\n";
    std::cout << "-----------------------------------------------------------------------" << "\n\n";
    for (Organization organization : organizations)
    {
        std::cout << organization;
    }
    std::cout << "-----------------------------------------------------------------------" << '\n';
}

void outputItemsTable(std::ofstream &outFile, Container<Organization> &organizations)
{
    outFile.open("organizationsTable.txt");
    outFile << std::setw(25) << std::left << "Название организации" << std::setw(10) << " "
            << std::setw(25) << std::left << "Номера выданных организацией карт" << std::setw(5) << " "
            << "\n\n";
    for (Organization organization : organizations)
    {
        outFile << organization;
    }

    outFile.close();
    std::cout << "Таблица организаций и выданных карт записана в файл \"organizationsTable.txt\"" << std::endl;
}