#pragma once
#ifndef item_h
#define item_h

using namespace std;

class item
{
private:


public:
    item(string name, string description, int quantity, float price);
    ~item();

    string itemName;
    string itemDescription;
    int itemQuantity;
    float itemPrice;
    
    string getName();
    string getDescription();
    int addQuantity(int q);
    int getQuantity();
    float getPrice();
};

class potion : public item
{
    public:
    void prova()
    {
        cout << "potion prova\n";
    }
};




#endif