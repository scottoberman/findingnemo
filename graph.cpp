/************************************************************************
* AUTHOR		: Scott Oberman
* STUDENT ID	: 271984
* Assignment #12:
* CLASS			: CS1D
* SECTION		: TTh 5:30p - 7:20p
* DUE DATE		: 4/14/15
*************************************************************************/

#include "Graph.h"

// Sets up an edge between two vertices.
void Graph::SetEdge(Vertex* vertex1, Vertex* vertex2, const int WEIGHT)
{
	bool vertexFound = false;
	bool otherVertexFound = false;

	vector<Vertex*>::iterator searchIterator = vertices.begin();
	Vertex* vertexStillBeingSought;

	// First thing is to check if any of the vertices already exist in the graph
	while (!vertexFound && searchIterator != vertices.end())
	{
		// If any vertex already exists in the graph, store it temporarily for later.
		if ((*searchIterator)->info.stadiumName == vertex1->info.stadiumName || (*searchIterator)->info.stadiumName == vertex2->info.stadiumName)
		{
			vertexFound = true;

			if ((*searchIterator)->info.stadiumName == vertex1->info.stadiumName)
			{
				vertexStillBeingSought = vertex2;
			}
			else // if ((*searchIterator)->name == vertex2->name)
			{
				vertexStillBeingSought = vertex1;
			}

			// Look for the other vertex to check if two already existing vertices will be connected
			while (!otherVertexFound && searchIterator != vertices.end())
			{
				if ((*searchIterator)->info.stadiumName == vertexStillBeingSought->info.stadiumName || (*searchIterator)->info.stadiumName == vertexStillBeingSought->info.stadiumName)
				{
					otherVertexFound = true;
				}
				else
				{
					searchIterator++;
				}
			}

			if (!otherVertexFound)
			{
				if (vertexStillBeingSought->info.stadiumName == vertex1->info.stadiumName)
				{
					vertices.push_back(vertex1);
				}
				else // if (vertexStillBeingSought->name == vertex1->name)
				{
					vertices.push_back(vertex2);
				}
			}
		}
		// Else (neither vertex is found thus far), move onto the next edge attached to this vertex
		else
		{
			searchIterator++;
		}

	}

	// If the vertices being added don't yet exist, add an isolated edge. SHOULDNT HAPPEN
	if (!vertexFound)
	{
		vertices.push_back(vertex1);
		vertices.push_back(vertex2);
	}
	Edge* edgeToBeAdded = new Edge(vertex1, vertex2, WEIGHT);

	vertex1->connections.push_back(edgeToBeAdded);
	vertex2->connections.push_back(edgeToBeAdded);
	edges.push_back(edgeToBeAdded);

}

// Sets up an edge between two vertices.
void Graph::SetEdge(const string VERTEX_1_NAME, const string VERTEX_2_NAME, const int WEIGHT)
{
	vector<Vertex*>::const_iterator verticesIterator = vertices.begin();

	Vertex* vertex1 = NULL;
	Vertex* vertex2 = NULL;

	bool vertex1Found = false;
	bool vertex2Found = false;

	while ((!vertex1Found || !vertex2Found) && verticesIterator != vertices.end())
	{
		if ((*verticesIterator)->info.stadiumName == VERTEX_1_NAME)
		{
			vertex1 = *verticesIterator;
			vertex1Found = true;
		}
		else if ((*verticesIterator)->info.stadiumName == VERTEX_2_NAME)
		{
			vertex2 = *verticesIterator;
			vertex2Found = true;
		}
		verticesIterator++;
	}

	// THESE TWO IFS ARE NOT NECESSARY
	//if (!vertex1Found)
	//{
	//	vertex1 = new Vertex(VERTEX_1_NAME);
	//}

	//if (!vertex2Found)
	//{
	//	vertex2 = new Vertex(VERTEX_2_NAME);
	//}

	SetEdge(vertex1, vertex2, WEIGHT);
}

// Outputs the edges belonging to every vertex of the graph.
void Graph::OutputAllConnections()
{
	vector<Vertex*>::const_iterator verticesIterator = vertices.begin();
	while (verticesIterator != vertices.end())
	{
		(*verticesIterator)->OutputAllConnections();
		verticesIterator++;
	}
}



void Graph::SetVertex(const string STADIUM_NAME, const string TEAM_NAME, const string ADDRESS, const string CITY_STATE_ZIP, const string PHONE_NUMBER, const string DATE_OPENED, const int CAPACITY)
{
	vertices.push_back(new Vertex(STADIUM_NAME, TEAM_NAME, ADDRESS, CITY_STATE_ZIP, PHONE_NUMBER, DATE_OPENED, CAPACITY));
}

void Graph::DepthFirstSearch(Vertex* startVertex)
{
	vector<Vertex*> visitedVertices;
	stack<Vertex*> parentVertices;
	vector<Edge*>::const_iterator connectionsIterator;
	Edge* shortestEdge;
	Vertex* activeVertex;
	Vertex* vertexToMoveTo = NULL;
	Vertex* vertexToMoveToMaybe = NULL;
	bool canMoveForward = false;

	visitedVertices.push_back(startVertex);
	parentVertices.push(startVertex);
	connectionsIterator = parentVertices.top()->connections.begin();
	shortestEdge = (*connectionsIterator);
	activeVertex = startVertex;



	vertexToMoveToMaybe = (*connectionsIterator)->GetOtherVertex(startVertex);
	visitedVertices.push_back(activeVertex);

	cout << "Beginning Depth-First-Search at " << startVertex->info.stadiumName << endl;

	// While there are parents to go back to incase of running out of never visited verices
	while (parentVertices.size() != 0)
	{
		// While we have not gone through all of the edges connected to this vertex
		while (connectionsIterator != parentVertices.top()->connections.end())
		{
			// If the current vertex has not yet been visited, consider going to this vertex
			if (!(activeVertex->GetOtherVertex(*connectionsIterator)->HasBeenVisited(visitedVertices)))
			{
				canMoveForward = true;
				// If this edge is the shortest edge so far attached to this vertex, allow the search to move through this vertex
				if (shortestEdge == NULL || (*connectionsIterator)->weight <= shortestEdge->weight)
				{
					vertexToMoveToMaybe = activeVertex->GetOtherVertex(*connectionsIterator);
					vertexToMoveTo = vertexToMoveToMaybe;
					shortestEdge = (*connectionsIterator);
				}

			}
			// Else, go onto the next vertex attached to the ACTIVE vertex and see if the DFS can move through that.
			else
			{
				vertexToMoveToMaybe = (*connectionsIterator)->GetOtherVertex(activeVertex);
			}
			connectionsIterator++;


		}

		// If the DFS can move through a never visited vertex, do so.
		if (canMoveForward)
		{
			cout << "Moving forwards  along DISCOVERY edge from " << activeVertex->info.stadiumName << " to " << vertexToMoveTo->info.stadiumName << endl;
			activeVertex = vertexToMoveTo;
			visitedVertices.push_back(activeVertex);
			parentVertices.push(activeVertex);
			connectionsIterator = parentVertices.top()->connections.begin();
			vertexToMoveToMaybe = activeVertex->GetOtherVertex(*connectionsIterator);

			shortestEdge = NULL;
		}
		// Else if there is no discovery edge to move through, move back to the most recent parent vertex.
		else if (parentVertices.size() > 1)
		{
			cout << "Moving backwards along DISCOVERY edge from " << activeVertex->info.stadiumName;
			parentVertices.pop();
			activeVertex = parentVertices.top();
			cout << " to " << activeVertex->info.stadiumName << endl;
			connectionsIterator = parentVertices.top()->connections.begin();
			vertexToMoveToMaybe = activeVertex->GetOtherVertex(*connectionsIterator);

			shortestEdge = NULL;

		}
		// Else, (if there are no discovery edges left and every vertex has been explored, end the search).
		else
		{
			parentVertices.pop();
			cout << "Breadth First Search Complete" << endl;
		}

		canMoveForward = false;
	}
}

// Allows a depth first search with just the name of the vertex.
void Graph::DepthFirstSearch(const string START_VERTEX_NAME)
{
	vector<Vertex*>::const_iterator vertexIterator = vertices.begin();

	bool found = false;

	while (!found && vertexIterator != vertices.end())
	{
		if ((*vertexIterator)->info.stadiumName == START_VERTEX_NAME)
		{
			found = true;
		}
		else
		{
			vertexIterator++;
		}
	}

	DepthFirstSearch(*vertexIterator);
}

// Determines if the edge connects to an already visited vertex.
bool Graph::IsDiscoveryEdge(vector<Vertex*> visitedVertices, Vertex* vertex)
{
	bool discoveryEdge = true;
	vector<Vertex*>::const_iterator vertexIterator = visitedVertices.begin();

	while (vertexIterator != visitedVertices.end() && discoveryEdge)
	{
		if (*vertexIterator == vertex)
		{
			discoveryEdge = false;
		}
	}

	return discoveryEdge;
}

void Graph::DijkstrasAlgorithm(Vertex* startVertex, Vertex* endVertex)
{
	vector<Vertex*> notVisitedVertices = vertices;
	vector<Vertex*> visitedVertices;
	vector<Edge*> visitedConnections;

	Vertex* activeVertex = startVertex;
	vector<Edge*>::iterator	activeConnection = activeVertex->connections.begin();
	vector<Vertex*>::const_iterator nextVertex;
	vector<Edge*>::const_iterator nextEdge;

	startVertex->dijkstraWeight = 0; // CHECK THIS LATER K

	// While the end vertex has not yet been visited, keep checking for shortest distance to end vertex.
	while (!endVertex->HasBeenVisited(visitedVertices))
	{
		// While not every single edge of this vertex has been assigned a dijkstra weight, keep checking weight of each edge
		while (activeConnection != activeVertex->connections.end())
		{

			// If the other vertex of the active edge has a longer dijkstra length than the
			// active vertex plus the length of the active edge, change the dijkstra weight to the shorter length.
			if (/*!(*activeConnection)->GetOtherVertex(activeVertex)->HasBeenVisited(visitedVertices) && */activeVertex->GetOtherVertex(*activeConnection)->dijkstraWeight > (*activeConnection)->weight + activeVertex->dijkstraWeight) // Removing the commened portion seems to fix some things
			{
				activeVertex->GetOtherVertex(*activeConnection)->dijkstraWeight = (*activeConnection)->weight + activeVertex->dijkstraWeight;
				activeVertex->GetOtherVertex(*activeConnection)->dijkstraPrevVertex = activeVertex;
			}
			activeConnection++;


		}

		visitedVertices.push_back(activeVertex);
		nextEdge = activeVertex->connections.begin();
		if (!endVertex->HasBeenVisited(visitedVertices))
		{
			while (nextEdge != activeVertex->connections.end() && (*nextEdge)->GetOtherVertex(activeVertex)->HasBeenVisited(visitedVertices))
			{
				nextEdge++;
			}
			activeVertex = (*nextEdge)->GetOtherVertex(activeVertex);
			activeConnection = activeVertex->connections.begin();
		}

	}

	Vertex* outputVertex = endVertex;

	cout << "Outputting shortest path from " << startVertex->info.stadiumName << " to " << endVertex->info.stadiumName << ":" << endl;
	while (outputVertex != startVertex)
	{
		cout << outputVertex->info.stadiumName << endl;
		outputVertex = outputVertex->dijkstraPrevVertex;
	}
	cout << outputVertex->info.stadiumName << endl;
	cout << "Distance traveled is: " << endVertex->dijkstraWeight << endl;

}

void Graph::DijkstrasAlgorithm(const string START_VERTEX_NAME, const string END_VERTEX_NAME)
{
	vector<Vertex*>::const_iterator vertexIterator = vertices.begin();

	Vertex* startVertex = NULL;
	Vertex* endVertex = NULL;

	bool foundStart = false;
	bool foundEnd = false;

	while ((!foundStart || !foundEnd) && vertexIterator != vertices.end())
	{
		if ((*vertexIterator)->info.stadiumName == START_VERTEX_NAME)
		{
			foundStart = true;
			startVertex = (*vertexIterator);
		}
		else if ((*vertexIterator)->info.stadiumName == END_VERTEX_NAME)
		{
			foundEnd = true;
			endVertex = (*vertexIterator);
		}

		vertexIterator++;

	}

	DijkstrasAlgorithm(startVertex, endVertex);
}

void Graph::PrimsAlgorithm(const string START_VERTEX_NAME)
{
	vector<Vertex*>::const_iterator vertexIterator = vertices.begin();

	Vertex* startVertex = NULL;

	bool foundStart = false;

	while (!foundStart && vertexIterator != vertices.end())
	{
		if ((*vertexIterator)->info.stadiumName == START_VERTEX_NAME)
		{
			foundStart = true;
			startVertex = (*vertexIterator);
		}
		vertexIterator++;

	}

	PrimsAlgorithm(startVertex);
}

void Graph::PrimsAlgorithm(Vertex* startVertex)
{
	vector<Vertex*> visitedVertices;
	vector<Edge*> connectionsToTake;
	vector<Edge*>::const_iterator connectionsIterator;
	vector<Vertex*>::const_iterator vertexIterator;
	Vertex* activeVertex = startVertex;
	Edge* connectionToMoveAcross = NULL;
	int totalDistance = 0;

	visitedVertices.push_back(startVertex);

	vertexIterator = visitedVertices.begin();
	connectionsIterator = (*visitedVertices.begin())->connections.begin();

	// While not every single vertex has been added to the MST, keep looking for a short edge.
	while (visitedVertices.size() != vertices.size())
	{
		// While we have not examined every vertex visited for a short edge, keep searching.
		while (vertexIterator != visitedVertices.end())
		{
			connectionsIterator = (*vertexIterator)->connections.begin();
			// While we have not examined every edge connected to the active vertex, keep checking.
			while (connectionsIterator != (*vertexIterator)->connections.end())
			{
				// If the vertex being checked has not been visited and the weight of the edge is shortest, mark it for being an edge of the MST
				if ((!(*connectionsIterator)->GetOtherVertex(*vertexIterator)->HasBeenVisited(visitedVertices)) && ((connectionToMoveAcross == NULL) || ((*connectionsIterator)->weight < connectionToMoveAcross->weight)))// ??CHECLK HERERERERER
				{
					connectionToMoveAcross = (*connectionsIterator);
					activeVertex = (*vertexIterator);
				}
				connectionsIterator++;
			}
			vertexIterator++;

		}

		visitedVertices.push_back(connectionToMoveAcross->GetOtherVertex(activeVertex));
		connectionsToTake.push_back(connectionToMoveAcross);
		totalDistance += connectionToMoveAcross->weight;

		connectionToMoveAcross = NULL;
		vertexIterator = visitedVertices.begin();
		connectionsIterator = (*visitedVertices.begin())->connections.begin();


	}

	connectionsIterator = connectionsToTake.begin();
	cout << "Outputting MST: " << endl;
	while (connectionsIterator != connectionsToTake.end())
	{
		cout << (*connectionsIterator)->vertices[0]->info.stadiumName << " connected to " << (*connectionsIterator)->vertices[1]->info.stadiumName << endl;
		connectionsIterator++;
	}
	cout << "Distance traveled is: " << totalDistance << endl;

}