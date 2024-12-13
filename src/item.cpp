#include <iostream>
#include "item.h"

using namespace std;




item::item(string name, string description, int quantity, float price)
{
    itemName = name;
    itemDescription = description;
    itemQuantity = quantity;
    itemPrice = price;
}

item::~item()
{
}

string item::getName()
{
    cout << "Name: ";
    return this->itemName;
}

string item::getDescription()
{
    cout << "Details: ";
    return this->itemDescription;
}

int item::addQuantity(int q)
{
    itemQuantity = q++;

    return itemQuantity;
}

int item::getQuantity()
{
    cout << "Quantity: ";
    return this->itemQuantity;
}

float item::getPrice()
{
    cout << "Price: ";
    return this->itemPrice;
}
