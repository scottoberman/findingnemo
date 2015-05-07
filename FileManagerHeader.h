#ifndef FILEMANAGERHEADER_H_
#define FILEMANAGERHEADER_H_

#include <iostream>
#include <fstream>
#include <limits>
#include <ios>
#include <map>
#include <queue>
#include <string>

struct stadiumInfo {
    //setting all values to default NULL values in construction of struct
    std::string teamName;
    std::string streetAddress;
    std::string cityStateZip;
    std::string phoneNumber;
    std::string dateOpened;
    std::string seatingCapacity;
    std::map<std::string,double> souvs;
    bool        nationalLeague;
    bool        americanLeague;
    bool        astroturf;
};

class FileManager {
public:
    FileManager();
    virtual ~FileManager();

//ACCESSORS////////////////////////////////////////////////////////////////////
    std::string printAll();
    std::queue<std::string> getAmericanLeagueStadiums();
    std::queue<std::string> getNationalLeagueStadiums();
    std::queue<std::string> getAstroturfStadiums();
    std::queue<std::string> getAllStadiums();
    void getAllStadiumsVector(std::vector<std::string> *returnVec);
    std::map<std::string, stadiumInfo> getListOfStadiums();
    void addNewTeam(std::string stadiumName, stadiumInfo stadium);
    void deleteStadium(std::string stadiumName);

//MUTATORS/////////////////////////////////////////////////////////////////////

    //modifies the file with the most current stadium information
    void updateList();
    //will change the team name of the stadium passed in

private:
    std::map<std::string, stadiumInfo> listOfStadiums;

};

#endif /* FILEMANAGERHEADER_H_ */
