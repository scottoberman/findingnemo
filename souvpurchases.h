#ifndef SOUVPURCHASES_H_
#define SOUVPURCHASES_H_
#include <iostream>
#include <vector>
#include <map>
#include <fstream>
//this struct will hold the item name and the item price
struct souvenirPurchase {
    std::string item;
    float	    price;
    int        quantity;
};

class souvPurchases {
public:
    souvPurchases();
    virtual ~souvPurchases();

//////MUTATORS/////////////////////////
    void updateSouvenirPurchases();
    //adding a souvenir purchase to the passed in stadium. returns true if item was
    //added successfully
    bool addSouvenirPurchase(std::string stadiumName,
                             std::string itemName,
                             float itemPrice,
                             int quantity);

////ACCESSORS///////////////////////////////
    std::map< std::string, std::vector<souvenirPurchase> > getAllInfoAt(std::string stadiumName);



private:
    //a map with the key being the stadium name and the data being a list of
    //the souvenirs they offer.
    std::map< std::string, std::vector<souvenirPurchase> > listOfPurchases;
};

#endif /* SOUVPURCHASES_H_ */
