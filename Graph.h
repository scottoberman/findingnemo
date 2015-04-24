/************************************************************************
* AUTHOR		: Scott Oberman
* STUDENT ID	: 271984
* Assignment #12:
* CLASS			: CS1D
* SECTION		: TTh 5:30p - 7:20p
* DUE DATE		: 4/14/15
*************************************************************************/

#ifndef GRAPH_H_
#define GRAPH_H_


#include "header.h"
#include "Edge.h"
#include "Vertex.h"


class Graph
{
public:
	vector<Edge*> edges;
	vector<Vertex*> vertices;

	void SetEdge(Vertex* vertex1, Vertex* vertex2, const int WEIGHT);
	void SetEdge(const string VERTEX1, const string VERTEX2, const int WEIGHT);
	void OutputAllConnections();
	void SetVertex(const string STADIUM_NAME, const string TEAM_NAME, const string ADDRESS, const string CITY_STATE_ZIP, const string PHONE_NUMBER, const string DATE_OPENED, const int CAPACITY);
	void DepthFirstSearch(Vertex* startVertex);
	void DepthFirstSearch(const string START_VERTEX_NAME);
	bool IsDiscoveryEdge(vector<Vertex*> visitedVertices, Vertex* vertex);
	void DijkstrasAlgorithm(Vertex* startVertex, Vertex* endVertex);
	void DijkstrasAlgorithm(const string START_VERTEX_NAME, const string END_VERTEX_NAME);
	void PrimsAlgorithm(const string START_VERTEX_NAME);
	void PrimsAlgorithm(Vertex* startVertex);
};

#endif