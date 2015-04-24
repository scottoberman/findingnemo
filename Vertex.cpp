/************************************************************************
* AUTHOR		: Scott Oberman
* STUDENT ID	: 271984
* Assignment #12:
* CLASS			: CS1D
* SECTION		: TTh 5:30p - 7:20p
* DUE DATE		: 4/14/15
*************************************************************************/

#include "Vertex.h"

Vertex::Vertex()
{
	dijkstraWeight = 9999;
	dijkstraPrevVertex = NULL;
}

Vertex::Vertex(const string STADIUM_NAME, const string TEAM_NAME, const string ADDRESS, const string CITY_STATE_ZIP, const string PHONE_NUMBER, const string DATE_OPENED, const int CAPACITY)
{
	info.stadiumName = STADIUM_NAME;
	info.teamName = TEAM_NAME;
	info.address = ADDRESS;
	info.cityStateZip = CITY_STATE_ZIP;
	info.phoneNumber = PHONE_NUMBER;
	info.dateOpened = DATE_OPENED;
	info.capacity = CAPACITY;
	dijkstraWeight = 9999;
	dijkstraPrevVertex = NULL;
}

// Connects an edge to a vertex (somewhat useless at this point)
void Vertex::AddConnection(Edge* connection)
{
	connections.push_back(connection);
}

// Outputs every edge associated with a vertex
void Vertex::OutputAllConnections()
{
	vector<Edge*>::const_iterator connectionsIterator = connections.begin();
	int currentConnection = 0;

	cout << info.stadiumName << " is connected to: " << endl;

	while (connectionsIterator != connections.end())
	{
		cout << (*connectionsIterator)->GetOtherVertex(this)->info.stadiumName
			<< " Distance between vertices is " << (*connectionsIterator)->weight << endl;
		connectionsIterator++;

	}
	cout << endl;

}

// Gets the vertex at the other side of this edge
Vertex* Vertex::GetOtherVertex(Edge* connection)
{
	if (this == connection->vertices[0])
	{
		return connection->vertices[1];
	}
	else // if (this == connection->vertices[1])
	{
		return connection->vertices[0];
	}
}

// Checks whether a vertex has been found in a set of visited vertices
bool Vertex::HasBeenVisited(vector<Vertex*> visitedVertices)
{
	vector<Vertex*>::const_iterator visitedVerticesIterator = visitedVertices.begin();
	bool hasBeenVisited = false;

	while (!hasBeenVisited && visitedVerticesIterator != visitedVertices.end())
	{
		if (info.stadiumName == (*visitedVerticesIterator)->info.stadiumName)
		{
			hasBeenVisited = true;
		}

		visitedVerticesIterator++;
	}

	return hasBeenVisited;
}