#ifndef FILEMANAGERHEADER_H_
#define FILEMANAGERHEADER_H_

#include <iostream>
#include <fstream>
#include <limits>
#include <ios>
#include <map>
#include <queue>

struct stadiumInfo {
	//setting all values to default NULL values in construction of struct
	std::string stadiumName      = "";
	std::string streetAddress    = "";
	std::string cityStateZip     = "";
	std::string phoneNumber		 = "";;
	std::string dateOpened       = "";;
	std::string seatingCapacity  = "";;
	bool        nationalLeague   = false;
	bool        americanLeague   = false;
	bool        astroturf        = false;
};

class FileManager {
public:
	FileManager();
	virtual ~FileManager();

//ACCESSORS////////////////////////////////////////////////////////////////////
	std::string printAll();
	std::queue<std::string> getAmericanLeagueStadiums();
	std::queue<std::string> getNationalLeagueStadiums();
	std::queue<std::string> getAllStadiums();
	std::queue<std::string> getAstroturfStadiums();//not implemented yet

//MUTATORS/////////////////////////////////////////////////////////////////////


private:
	std::map<std::string, stadiumInfo> listOfStadiums;

};

#endif /* FILEMANAGERHEADER_H_ */
