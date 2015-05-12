#include "souvpurchases.h"
#include <iomanip>
#include <fstream>
#include <sstream>
#include <limits>
#include <ios>
#include <qdebug.h>
//creates a souvenir class based on the text file souvenirInfoList.txt
souvPurchases::souvPurchases() {
    std::ifstream inFile;
    inFile.open("C:/Users/gdfgdf/Documents/findingnemo/souvenirpurchase.txt");

    while(!inFile.eof()) {

        std::vector<souvenirPurchase> newSouvenirs;
        std::string  teamName;
        souvenirPurchase newSouvenir;
        std::string  souvenirName;
        float        souvenirPrice;
        int          souvenirQuantity;

        //getting the stadium name that will hold the list of souvenirs
        std::getline(inFile, teamName);
        if (inFile.eof())
        {
            return;
        }
        //getting the stadium's souvenir name
        std::getline(inFile, souvenirName);

        //taking in all the souvenirs the stadium has to offer
        while(souvenirName != "~") {

            //getting the souvenir's price
            inFile >> souvenirPrice;
            inFile.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

            //setting the name and price to the struct
            newSouvenir.item  = souvenirName;
            newSouvenir.price = souvenirPrice;
            newSouvenir.quantity = souvenirQuantity;
            //pushing the new souvenir info into the vector
            newSouvenirs.push_back(newSouvenir);

            //getting the stadium's souvenir name
            std::getline(inFile, souvenirName);
        }//end - while

        listOfPurchases[teamName] =  newSouvenirs;
    }//end - while

    inFile.close();

}//end - default constructor

souvPurchases::~souvPurchases() { }//end - default constructor

//this method will make the soucenir list presistant between runs depending on
//the changes that were made to it.
void souvPurchases::updateSouvenirPurchases() {
    std::map< std::string, std::vector<souvenirPurchase> >::iterator
                                    it = listOfPurchases.begin();

    //opening file for update
    std::ofstream outFile;
    outFile.open("C:/Users/gdfgdf/Documents/findingnemo/souvenirpurchases.txt");
    int sizeOfSouvs = listOfPurchases.size();
    int i = 0;
    for(; it != listOfPurchases.end(); it++) {
        i++;
        outFile << it->first << std::endl;

        std::vector<souvenirPurchase>::iterator it2 = it->second.begin();

        for(; it2 != it->second.end(); it2++) {
            outFile << it2->item << std::endl;
            outFile << it2->price << std::endl;
            outFile << it2->quantity << std::endl;
        }//end - for
        outFile << "~";

        if(sizeOfSouvs != i) outFile << std::endl;
    }//end - for

    outFile.close();

}//end - updateSouvenirList


//adding a souvenir to the passed in stadium. returns true if item was
//added successfully
bool souvPurchases::addSouvenirPurchase(std::string stadiumName,
                 std::string itemName,
                 float itemPrice,
                 int quantity) {
    //the .count() method will return a bool if the key is in the map.
    //if stadium is not in the map, return false.
    if(!listOfPurchases.count(stadiumName)) return false;

    souvenirPurchase newSouvenir;
    newSouvenir.item  = itemName;
    newSouvenir.price = itemPrice;
    newSouvenir.quantity = quantity;
    listOfPurchases.at(stadiumName).push_back(newSouvenir);
    return true;
}//end - addSouvenir

//returns a string all the souvenir's information at the passed in stadium
//returns an error message if the stadium is not found
std::map< std::string, std::vector<souvenirPurchase> > souvPurchases::getAllInfoAt(std::string stadiumName) {
    //the .count() method will return a bool if the key is in the map.
    //if stadium is not in the map, return false.
   // if(!listOfSouvenirs.count(stadiumName)) return "::ERROR:: Stadium Not Found\n";



    return listOfPurchases;
}//end - getAllInfoAt

