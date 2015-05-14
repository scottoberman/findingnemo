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


#include <iostream>
#include <iomanip>
#include <sstream>
#include <stack>
#include <queue>
#include <string>
#include <vector>
#include "Edge.h"
#include "Vertex.h"

using namespace std;


class Graph
{
public:
        vector<Edge*>	edges;
        vector<Vertex*> vertices;

        void SetVertex(string name);

        void ChangeVertexName(const string OG_NAME, const string NEW_NAME);

        void SetVertices(const string VERTEX1, const string VERTEX2, const int WEIGHT);
        void SetVertices(Vertex* vertex1, Vertex* vertex2, const int WEIGHT);

		string OutputAllConnections();

        stack<string> DijkstrasAlgorithm(const string START_VERTEX_NAME, const string END_VERTEX_NAME, int& weightOfTrip);
        stack<string> DijkstrasAlgorithm(Vertex* startVertex, Vertex* endVertex, int& weightOfTrip);

        queue<string> PrimsAlgorithm(const string START_VERTEX_NAME, int& weight);
        queue<string> PrimsAlgorithm(Vertex* startVertex, int& weight);

		Vertex* GetSmallestUnvisitedVertex(vector <Vertex*> vertices, vector<Vertex*> visitedVertices);
};
extern Graph graph;
#endif
