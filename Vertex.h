/************************************************************************
* AUTHOR		: Scott Oberman
* STUDENT ID	: 271984
* Assignment #12:
* CLASS			: CS1D
* SECTION		: TTh 5:30p - 7:20p
* DUE DATE		: 4/14/15
*************************************************************************/

#ifndef VERTEX_H_
#define VERTEX_H_

#include "header.h"
#include "Edge.h"

struct Info
{
	string stadiumName;
	string teamName;
	string address;
	string cityStateZip;
	string phoneNumber;
	string dateOpened;
	int capacity;
};

class Edge;

class Vertex
{
public:
	Info info;
	vector<Edge*> connections;
	int dijkstraWeight;
	Vertex* dijkstraPrevVertex;

	Vertex();
	Vertex(const string STADIUM_NAME, const string TEAM_NAME, const string ADDRESS, const string CITY_STATE_ZIP, const string PHONE_NUMBER, const string DATE_OPENED, const int CAPACITY);

	void AddConnection(Edge* connection);
	Vertex* GetOtherVertex(Edge* connection);
	void OutputAllConnections();
	bool HasBeenVisited(vector<Vertex*> visitedVertices);
};

#endif