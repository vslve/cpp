#ifndef DISCOUNTCARD_H
#define DISCOUNTCARD_H

#include <string>
#include <iostream>

const std::string INCORRECT_DATA = "Ошибка входных данных.";

struct Date
{
    int day;
    int month;
    int year;
};

class DiscountCard
{
    public:

        DiscountCard();
        DiscountCard(
                const std::string &cardHolder,
                int cardNumber,
                const std::string &organization,
                double totalAmount,
                Date date);
        DiscountCard(const DiscountCard &discountCard);
        ~DiscountCard();

        int getCardNumber();
        int getAmount();
        std::string &getOrganizationName();

        DiscountCard operator+(int sum);
        friend DiscountCard operator-(DiscountCard &discountCard, int sum);
        bool operator>=(const DiscountCard &discountCard);
        friend bool operator<=(const DiscountCard &card_one, DiscountCard &card_two);
        bool operator>(const DiscountCard &discountCard);
        friend bool operator<(const DiscountCard &card_one, DiscountCard &card_two);
        bool operator==(const DiscountCard &discountCard);
        DiscountCard operator=(const DiscountCard &discountCard);
        DiscountCard operator++();
        friend DiscountCard operator++(DiscountCard &discountCard, int notused);
        friend std::istream &operator>>(std::istream &in, DiscountCard &discountCard);
        friend std::ostream &operator<<(std::ostream &out, DiscountCard &discountCard);


    private:
        std::string cardHolder_;
        int cardNumber_;
        std::string organization_;
        double totalAmount_;
        Date issueDate_;
};

#endif // DISCOUNTCARD_H
