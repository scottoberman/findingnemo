/*
 * FileManager.cpp
 *
 *  Created on: Apr 25, 2015
 *      Author: Talon
 */

#include "FileManagerHeader.h"

/*COMMENT ABOUT THE FILE INFO: I couldn't think of a much better way than to
 * simply include a boolean stating if the team is a national or American
 * league team, as well as a boolean to state if the stadium has astroturf or
 * if the feild is real grass. (NOTE: the astroturn boolean is not yet
 * implemented).
 */

/*this default constructor will get all the data from the file and add it to a
 * map of stadiums
 */
FileManager::FileManager() {
	std::ifstream inFile;
	inFile.open("baseballStadiumInformation.txt");

	while(!inFile.eof()) {
		stadiumInfo newStadium;
		std::string newTeamName;

		std::getline(inFile, newStadium.stadiumName);
		std::getline(inFile, newTeamName);
		std::getline(inFile, newStadium.streetAddress);
		std::getline(inFile, newStadium.cityStateZip);
		std::getline(inFile, newStadium.phoneNumber);
		std::getline(inFile, newStadium.dateOpened);
		std::getline(inFile, newStadium.seatingCapacity);

		//checking for national, American and astroturf booleans
		for(int i = 0; i < 3; i++) {
			std::string yesOrNo;
			inFile >> yesOrNo >> yesOrNo >> yesOrNo;
			inFile.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

				switch(i) {
				case 0:		newStadium.nationalLeague = (yesOrNo == "YES");
					break;
				case 1:		newStadium.americanLeague = (yesOrNo == "YES");
					break;
				case 2:		newStadium.astroturf	  = (yesOrNo == "YES");
					break;
			}//end - if
		}//end - for

		//resetting for the next stadium
		inFile.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

		//adding all the data to the FileManager
		listOfStadiums[newTeamName] = newStadium;

	}//end - while !inFile.eof()
}// end - FileManager - default constructor

FileManager::~FileManager() {}//end - default destructor

/*printAll is a debug and admin method that will print the contents of all the
 * stadiums for testing
 */
std::string FileManager::printAll() {
	std::string stadiumOutput;

	std::map<std::string, stadiumInfo>::iterator it = listOfStadiums.begin();
	for(; it != listOfStadiums.end(); it++) {
		stadiumOutput += it->first + " -> " + it->second.stadiumName + "\n";
	}//end - for

	return stadiumOutput;
}//end - printAll

/*getAmericanLeagueStadiums will return a queue of an alphabetized list of all
 * the American league stadiums currently in the list
 */
std::queue<std::string> FileManager::getAmericanLeagueStadiums() {
	std::queue<std::string> returnQueue;

	std::map<std::string, stadiumInfo>::iterator it = listOfStadiums.begin();
	for(; it != listOfStadiums.end(); it++) {
		if(it->second.americanLeague) {
			returnQueue.push(it->first);
		}
	}//end - for

	return returnQueue;
}//end - getAmericanLeagueStadiums

/*getNationalLeagueStadiums will return a queue of an alphabetized list of all
 * the American league stadiums currently in the list
 */
std::queue<std::string> FileManager::getNationalLeagueStadiums() {
	std::queue<std::string> returnQueue;

	std::map<std::string, stadiumInfo>::iterator it = listOfStadiums.begin();
	for(; it != listOfStadiums.end(); it++) {
		if(it->second.nationalLeague) {
			returnQueue.push(it->first);
		}
	}//end - for

	return returnQueue;
}//end - getAmericanLeagueStadiums

/*getAllStadiums will return a queue of an alphabetized list of all
 * the stadiums currently in the list
 */
std::queue<std::string> FileManager::getAllStadiums() {
	std::queue<std::string> returnQueue;

	std::map<std::string, stadiumInfo>::iterator it = listOfStadiums.begin();
	for(; it != listOfStadiums.end(); it++) {
		returnQueue.push(it->first);
	}//end - for

	return returnQueue;
}//end - getAllStadiums





















