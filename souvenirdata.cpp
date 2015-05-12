#include "SouvenirData.h"
#include <iomanip>
#include <fstream>
#include <sstream>
#include <limits>
#include <ios>

//creates a souvenir class based on the text file souvenirInfoList.txt
SouvenirData::SouvenirData() {
    std::ifstream inFile;
    inFile.open("C:/Users/gdfgdf/Documents/findingnemo/souvenirInfoList.txt");

    while(!inFile.eof()) {

        std::vector<souvenirInfo> newSouvenirs;
        std::string  teamName;
        souvenirInfo newSouvenir;
        std::string  souvenirName;
        float        souvenirPrice;

        //getting the stadium name that will hold the list of souvenirs
        std::getline(inFile, teamName);

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

            //pushing the new souvenir info into the vector
            newSouvenirs.push_back(newSouvenir);

            //getting the stadium's souvenir name
            std::getline(inFile, souvenirName);
        }//end - while

        listOfSouvenirs[teamName] =  newSouvenirs;
    }//end - while

    inFile.close();

}//end - default constructor

SouvenirData::~SouvenirData() { }//end - default constructor

//this method will make the soucenir list presistant between runs depending on
//the changes that were made to it.
void SouvenirData::updateSouvenirList() {
    std::map< std::string, std::vector<souvenirInfo> >::iterator
                                    it = listOfSouvenirs.begin();
    std::map< std::string, std::vector<souvenirInfo> >::iterator
                                    endFileCheck = listOfSouvenirs.begin();
    endFileCheck++;



    //opening file for update
    std::ofstream outFile;
    outFile.open("C:/Users/gdfgdf/Documents/findingnemo/souvenirInfoList.txt");
    int sizeOfSouvs = listOfSouvenirs.size();
    int i = 0;
    for(; it != listOfSouvenirs.end(); it++) {
        i++;
        outFile << it->first << std::endl;

        std::vector<souvenirInfo>::iterator it2 = it->second.begin();

        for(; it2 != it->second.end(); it2++) {
            outFile << it2->item << std::endl;
            outFile << it2->price << std::endl;
        }//end - for
        outFile << "~";

        if(sizeOfSouvs != i) outFile << std::endl;
    }//end - for

    outFile.close();

}//end - updateSouvenirList


//this method will print the data for all the stadiums
std::string SouvenirData::printAll() {
    std::map< std::string, std::vector<souvenirInfo> >::iterator
                                    it = listOfSouvenirs.begin();
    std::map< std::string, std::vector<souvenirInfo> >::iterator
                                    endFileCheck = listOfSouvenirs.begin();
    endFileCheck++;

    std::stringstream returnStr;
    returnStr << std::setprecision(2) << std::fixed;

    for(; it != listOfSouvenirs.end(); it++, endFileCheck++) {
        returnStr << it->first << "\n";

        std::vector<souvenirInfo>::iterator it2 = it->second.begin();

        for(; it2 != it->second.end(); it2++) {
            returnStr << it2->item << "\n";
            returnStr << it2->price << "\n";
        }//end - for
        if(endFileCheck != listOfSouvenirs.end()) returnStr << "\n";
    }//end - for

    return returnStr.str();
}//end - printAll

//adding a souvenir to the passed in stadium. returns true if item was
//added successfully
bool SouvenirData::addSouvenir(std::string stadiumName,
                 std::string itemName,
                 float itemPrice) {
    //the .count() method will return a bool if the key is in the map.
    //if stadium is not in the map, return false.
    if(!listOfSouvenirs.count(stadiumName)) return false;

    souvenirInfo newSouvenir;
    newSouvenir.item  = itemName;
    newSouvenir.price = itemPrice;
    listOfSouvenirs.at(stadiumName).push_back(newSouvenir);
    return true;
}//end - addSouvenir

//updates the price of an item. returns true if the item's price was
//updated successfully
bool SouvenirData::updatePrice(std::string stadiumName,
                               std::string itemName, float newPrice) {
    //the .count() method will return a bool if the key is in the map.
    //if stadium is not in the map, return false.
    if(!listOfSouvenirs.count(stadiumName)) return false;

    bool notUpdated = true;

    std::vector<souvenirInfo>::iterator it = listOfSouvenirs.at(stadiumName).begin();
    while(it != listOfSouvenirs.at(stadiumName).end() && notUpdated) {
        //if true, the item was found and the price was updated
        if(it->item == itemName) {
            it->price = newPrice;
            notUpdated = false;
            return true;
        }
        it++;
    }//end - while

    //if this false is reached, this means there IS a stadium in the list, but
    //no passed in souvenir in that sradium's shop.
    return false;
}//end - updatePrice

//removes a souvenir from a stadium. returns true if removal was
//successful
bool SouvenirData::removeSouvenir(std::string stadiumName, std::string itemName) {
    //the .count() method will return a bool if the key is in the map.
    //if stadium is not in the map, return false.
    if(!listOfSouvenirs.count(stadiumName)) return false;

    std::vector<souvenirInfo>::iterator it = listOfSouvenirs.at(stadiumName).begin();
    while(it != listOfSouvenirs.at(stadiumName).end()) {
        //if true, the item was found and the price was updated
        if(it->item == itemName) {
            listOfSouvenirs.at(stadiumName).erase(it);
            return true;
        }
        it++;
    }//end - while

    //if this false is reached, this means there IS a stadium in the list, but
    //no passed in souvenir in that sradium's shop.
    return false;
}//end - removeSouvenir

//returns the price of the souvenir at the stadium. returns -1 if not found
float SouvenirData::getPrice(std::string stadiumName, std::string souvenirName) {
    //the .count() method will return a bool if the key is in the map.
    //if stadium is not in the map, return false.
    if(!listOfSouvenirs.count(stadiumName)) return -1.0;

    std::vector<souvenirInfo>::iterator it = listOfSouvenirs.at(stadiumName).begin();
    while(it != listOfSouvenirs.at(stadiumName).end()) {
        //if true, the item was found and the price was updated
        if(it->item == souvenirName) {
            return it->price;
        }
        it++;
    }//end - while

    //if this return, item was not found
    return -1.0;

}//end - getPrice

//returns a string all the souvenir's information at the passed in stadium
//returns an error message if the stadium is not found
std::map< std::string, std::vector<souvenirInfo> > SouvenirData::getAllInfoAt(std::string stadiumName) {
    //the .count() method will return a bool if the key is in the map.
    //if stadium is not in the map, return false.
   // if(!listOfSouvenirs.count(stadiumName)) return "::ERROR:: Stadium Not Found\n";



    return listOfSouvenirs;
}//end - getAllInfoAt

