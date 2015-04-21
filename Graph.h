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

	// MAYBE WHEN PUSHING BACK ELEMENTS TO THE VERTICIES AT THE END OF THIS METHOD THE CHANGES ARE THROWN OUT SINCE vertex 1 and vertex 2 ARE BOTH DESTROYED ON CLOSURE OF THE METHOD MAYBE
	void SetVertices(Vertex* vertex1, Vertex* vertex2, const int WEIGHT);
	void SetVertices(const string VERTEX1, const string VERTEX2, const int WEIGHT);
	void OutputAllConnections();
	void AddVertex(Vertex* vertex);
	void DepthFirstSearch(Vertex* startVertex);
	void DepthFirstSearch(const string START_VERTEX_NAME);
	bool IsDiscoveryEdge(vector<Vertex*> visitedVertices, Vertex* vertex);
	void DijkstrasAlgorithm(Vertex* startVertex, Vertex* endVertex);
	void DijkstrasAlgorithm(const string START_VERTEX_NAME, const string END_VERTEX_NAME);
	void PrimsAlgorithm(const string START_VERTEX_NAME);
	void PrimsAlgorithm(Vertex* startVertex);
};

#endif