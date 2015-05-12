/*
 * SouvenirData.h
 *
 *  Created on: May 10, 2015
 *      Author: Talon
 */

#ifndef SOUVENIRDATA_H_
#define SOUVENIRDATA_H_
#include <iostream>
#include <vector>
#include <map>

//this struct will hold the item name and the item price
struct souvenirInfo {
    std::string item;
    float	    price;
};

class SouvenirData {
public:
    SouvenirData();
    virtual ~SouvenirData();

//////MUTATORS/////////////////////////

    //run this method to save all changes made to the souvenir list
    //(AKA: file persistence)
    void updateSouvenirList();
    //adding a souvenir to the passed in stadium. returns true if item was
    //added successfully
    bool addSouvenir(std::string stadiumName,
                     std::string itemName,
                     float itemPrice);
    //updates the price of an item. returns true if the item's price was
    //updated successfully
    bool updatePrice(std::string stadiumName, std::string itemName, float newPrice);
    //removes a souvenir from a stadium. returns true if removal was
    //successful
    bool removeSouvenir(std::string stadiumName, std::string itemName);

////ACCESSORS///////////////////////////////

    //printing all the stadium's souvenir data
    std::string printAll();
    //returns the price of the souvenir at the stadium. returns -1 if not found
    float getPrice(std::string stadiumName, std::string souvenirName);
    //returns a string all the souvenir's information at the passed in stadium
    //returns an error message if the stadium is not found
    std::map< std::string, std::vector<souvenirInfo> > getAllInfoAt(std::string stadiumName);



private:
    //a map with the key being the stadium name and the data being a list of
    //the souvenirs they offer.
    std::map< std::string, std::vector<souvenirInfo> > listOfSouvenirs;
};

#endif /* SOUVENIRDATA_H_ */
