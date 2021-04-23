#include <iomanip>

#include "DiscountCard.h"

DiscountCard::DiscountCard():
    cardHolder_(),
    cardNumber_(0),
    organization_(),
    totalAmount_(0),
    issueDate_({}) {};

DiscountCard::DiscountCard(
    const std::string &cardHolder,
    int cardNumber,
    const std::string &organization,
    double totalAmount,
    Date date):

    cardHolder_(cardHolder),
    cardNumber_(cardNumber),
    organization_(organization),
    totalAmount_(totalAmount),
    issueDate_(date) {};

DiscountCard::DiscountCard(const DiscountCard & discountCard):
    cardHolder_(discountCard.cardHolder_),
    cardNumber_(discountCard.cardNumber_),
    organization_(discountCard.organization_),
    totalAmount_(discountCard.totalAmount_),
    issueDate_(discountCard.issueDate_) {};

DiscountCard::~DiscountCard() = default;

DiscountCard DiscountCard::operator+(int sum)
{
    totalAmount_ += sum;
    return *this;
}

DiscountCard operator-(DiscountCard &discountCard, int sum)
{
    discountCard.totalAmount_ -= sum;
    return discountCard;
}

bool DiscountCard::operator>=(const DiscountCard &discountCard)
{
    if (this->issueDate_.year < discountCard.issueDate_.year)
    {
        return false;
    }
    if (this->issueDate_.year == discountCard.issueDate_.year)
    {
        if (this->issueDate_.month < discountCard.issueDate_.month)
        {
            return false;
        }
        if (this->issueDate_.month == discountCard.issueDate_.month)
        {
            if (this->issueDate_.day < discountCard.issueDate_.day)
            {
                return false;
            }
            return true;
        }
        return true;
    }
    return true;
}

bool operator<=(const DiscountCard &card_one, DiscountCard &card_two)
{
    if (card_one.issueDate_.year > card_two.issueDate_.year)
    {
        return false;
    }
    if (card_one.issueDate_.year == card_two.issueDate_.year)
    {
        if (card_one.issueDate_.month > card_two.issueDate_.month)
        {
            return false;
        }
        if (card_one.issueDate_.month == card_two.issueDate_.month)
        {
            if (card_one.issueDate_.day > card_two.issueDate_.day)
            {
                return false;
            }
            return true;
        }
        return true;
    }
    return true;
}

bool DiscountCard::operator>(const DiscountCard &discountCard)
{
    if (this->totalAmount_ > discountCard.totalAmount_)
    {
        return true;
    }
    return false;
}

bool operator<(const DiscountCard &cardOne, DiscountCard &cardTwo)
{
    if (cardOne.totalAmount_ < cardTwo.totalAmount_)
    {
        return true;
    }
    return false;
}

bool DiscountCard::operator==(const DiscountCard &discountCard)
{
    return (cardNumber_ == discountCard.cardNumber_ && organization_ == discountCard.organization_);
}

DiscountCard DiscountCard::operator=(const DiscountCard &discountCard)
{
    if (this == &discountCard)
    {
        return *this;
    }
    cardHolder_ = discountCard.cardHolder_;
    cardNumber_ = discountCard.cardNumber_;
    organization_ = discountCard.organization_;
    totalAmount_ = discountCard.totalAmount_;
    issueDate_ = discountCard.issueDate_;
    return *this;
}

DiscountCard DiscountCard::operator++()
{
    cardNumber_ += 1;
    return *this;
}

DiscountCard operator++(DiscountCard &discountCard, int notused)
{
    DiscountCard currState = discountCard;
    discountCard.cardNumber_ += 1;
    return currState;
}

std::istream &operator>>(std::istream &in, DiscountCard &discountCard)
{
    in >> discountCard.cardHolder_ >> discountCard.cardNumber_
       >> discountCard.organization_ >> discountCard.totalAmount_;
    if(!in)
    {
        throw INCORRECT_DATA;
    }
    in >> discountCard.issueDate_.day >> discountCard.issueDate_.month
       >> discountCard.issueDate_.year;
    if(!in || discountCard.cardNumber_ < 0 || discountCard.totalAmount_ < 0 || \
    discountCard.issueDate_.day * discountCard.issueDate_.month * discountCard.issueDate_.year <= 0)
    {
        throw INCORRECT_DATA;
    }

    return in;
}

std::ostream &operator<<(std::ostream &out, DiscountCard &discountCard)
{
    out << std::setw(15) << std::left << discountCard.cardHolder_ << std::setw(5) << " "
        << std::setw(10) << std::left << discountCard.cardNumber_ << std::setw(5) << " "
        << std::setw(15) << std::left << discountCard.organization_ << std::setw(10) << " "
        << std::setw(10) << std::left << discountCard.totalAmount_ << std::setw(7) << " "
        << discountCard.issueDate_.day  << "."
        << discountCard.issueDate_.month << "."
        << discountCard.issueDate_.year << '\n' << std::endl;

    return out;
}

int DiscountCard::getAmount()
{
    return totalAmount_;
}

int DiscountCard::getCardNumber()
{
    return cardNumber_;
}

std::string &DiscountCard::getOrganizationName()
{
    return organization_;
}
