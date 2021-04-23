#ifndef ORGANIZATION_H
#define ORGANIZATION_H

#include "Container.h"
#include "DiscountCard.h"

class Organization
{
    public:
        Organization();
        Organization(std::string name, const Container<DiscountCard> &cards=Container<DiscountCard>{});
        Organization(const Organization &organization);
        ~Organization();

        void addCard(DiscountCard &card);
        DiscountCard &getCard(int cardNumber);
        std::string getName();

        friend std::ostream &operator<<(std::ostream &out, Organization &organization);

        bool operator==(const Organization &organization);
        Organization operator=(const Organization &organization);


    private:
        std::string name_;
        int size_;
        Container<DiscountCard> cards_;

};
#endif // ORGANIZATION_H
