/************************************************************************
* AUTHOR		: Scott Oberman
* STUDENT ID	: 271984
* Assignment #12:
* CLASS			: CS1D
* SECTION		: TTh 5:30p - 7:20p
* DUE DATE		: 4/14/15
*************************************************************************/

#ifndef EDGE_H_
#define EDGE_H_

#include <iostream>
#include <iomanip>
#include <sstream>
#include <stack>
#include <string>
#include <vector>
#include "Vertex.h"

using namespace std;

class Vertex;

class Edge
{
public:
	int weight;
	Vertex* vertices[2];

	Edge();
	Edge(Vertex* vertex1, Vertex* vertex2, int weight);

	void AddEdge(Vertex* vertex1, Vertex* vertex2, int weight);
	Vertex* GetOtherVertex(Vertex* thisVertex);
};

#endif