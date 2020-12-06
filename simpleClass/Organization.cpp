#include <iomanip>

#include "Organization.h"

Organization::Organization():
    name_(""),
    size_(0),
    cards_(Container<DiscountCard>{}) {};

Organization::Organization(std::string name, const Container<DiscountCard> &cards):
    name_(name),
    size_(0),
    cards_(Container<DiscountCard>{}){};

Organization::Organization(const Organization &organization):
    name_(organization.name_)
{
    cards_.create(organization.cards_.size());
    for (DiscountCard &card : organization.cards_)
    {
        cards_.add(card);
    }
}

Organization::~Organization() = default;

void Organization::addCard(DiscountCard &card)
{
    cards_.add(card);
    ++size_;
}

DiscountCard &Organization::getCard(int cardNumber)
{
    return cards_.take(cardNumber);
}

Organization Organization::operator=(const Organization &organization)
{
    if (this == &organization)
    {
        return *this;
    }
    name_ = organization.name_;
    size_ = organization.size_;
    cards_.create(organization.cards_.size());
    for (DiscountCard &card : organization.cards_)
    {
        cards_.add(card);
    }
    return *this;
}

bool Organization::operator==(const Organization &organization)
{
    return (name_ == organization.name_);
}

std::string Organization::getName()
{
    return name_;
}

std::ostream &operator<<(std::ostream &out, Organization &organization)
{
    out << std::setw(25) << std::left << organization.name_ << std::setw(5) <<  " ";
    for (DiscountCard &card : organization.cards_)
    {
        int cardNumber = card.getCardNumber();
        if (&card == organization.cards_.end() - 1)
        {
            out << cardNumber;
        }
        else
        {
            out << cardNumber << ", ";
        }
    }
    out << '\n' << std::endl;

    return out;
}