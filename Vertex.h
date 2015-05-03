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

#include <iostream>
#include <iomanip>
#include <sstream>
#include <stack>
#include <string>
#include <vector>
#include "Edge.h"

using namespace std;

class Edge;

class Vertex
{
public:
    string name;
    vector<Edge*> connections;
    int dijkstraWeight;
    Vertex* dijkstraPrevVertex;

    Vertex();
    Vertex(const string NAME);

    void AddConnection(Edge* connection);
    Vertex* GetOtherVertex(Edge* connection);
    void OutputAllConnections();
    bool HasBeenVisited(vector<Vertex*> visitedVertices);
};

#endif
