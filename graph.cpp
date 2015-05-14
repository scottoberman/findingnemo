/************************************************************************
* AUTHOR		: Scott Oberman
* STUDENT ID	: 271984
* Assignment #12:
* CLASS			: CS1D
* SECTION		: TTh 5:30p - 7:20p
* DUE DATE		: 4/14/15
*************************************************************************/

#include "Graph.h"
#include <QString>
#include <QDebug>

void Graph::SetVertex(string name)
{
	vector<Vertex*>::iterator alreadyExistsIterator = vertices.begin();
	string message;
	bool nameFound = false;

	// Fix for question mark appearing in first instance of name from input file
	if (name[0] < 65 || name[0] > 122)
	{
		name.erase(0, 3);
	}

	while (!nameFound && alreadyExistsIterator != vertices.end())
	{
		if ((*alreadyExistsIterator)->name == name)
		{
			nameFound = true;
		}
		else
		{
			alreadyExistsIterator++;
		}
		
	}	

	if (!nameFound)
	{
		vertices.push_back(new Vertex(name));

		message = "SUCCESS: Placing Vertex: " + vertices.back()->name + " into graph";
		qDebug() << QString::fromStdString(message);
	}
	else
	{
		message = "WARNING: Vertex: " + name + " already inserted into graph";
		qDebug() << QString::fromStdString(message);
	}



}

void Graph::ChangeVertexName(const string OG_NAME, const string NEW_NAME)
{
    vector<Vertex*>::iterator vertexIterator = vertices.begin();
	string message;

    while ((*vertexIterator)->name != OG_NAME)
    {
        vertexIterator++;
    }
	if (vertexIterator == vertices.end())
	{
		message = "ERROR: Vertex not found; cannot rename " + OG_NAME + " to " + NEW_NAME;
		qDebug() << QString::fromStdString(message);
	}
	else
	{
		message = "SUCCESS: Vertex not found; cannot rename " + (*vertexIterator)->name + " to " + NEW_NAME;
		qDebug() << QString::fromStdString(message);
		(*vertexIterator)->name = NEW_NAME;
		message = "Checking rename: " + (*vertexIterator)->name;
		qDebug() << QString::fromStdString(message);
	}
    
}

// Sets up two vertices and an edge between them with just the names of each vertex and the weight of their edge.
void Graph::SetVertices(const string VERTEX_1_NAME, const string VERTEX_2_NAME, const int WEIGHT)
{
    vector<Vertex*>::const_iterator verticesIterator = vertices.begin();

    Vertex* vertex1 = NULL;
    Vertex* vertex2 = NULL;

    bool vertex1Found = false;
    bool vertex2Found = false;

	string message;

    while ((!vertex1Found || !vertex2Found) && verticesIterator != vertices.end())
    {
        if ((*verticesIterator)->name == VERTEX_1_NAME)
        {
            vertex1 = *verticesIterator;
            vertex1Found = true;
        }
        else if ((*verticesIterator)->name == VERTEX_2_NAME)
        {
            vertex2 = *verticesIterator;
            vertex2Found = true;
        }
        verticesIterator++;
    }

	

    if (!vertex1Found)
    {
		message = "ERROR: Vertex 1 not found; cannot place edge between " + VERTEX_1_NAME + " and " + VERTEX_2_NAME;
		qDebug() << QString::fromStdString(message);
        //vertex1 = new Vertex(VERTEX_1_NAME);
    }

    if (!vertex2Found)
    {
		message = "ERROR: Vertex 2 not found; cannot place edge between " + VERTEX_1_NAME + " and " + VERTEX_2_NAME;
		qDebug() << QString::fromStdString(message);
        //vertex2 = new Vertex(VERTEX_2_NAME);
    }

	if (vertex1Found && vertex2Found)
	{
		message = "SUCCESS: " + VERTEX_1_NAME + " and " + VERTEX_2_NAME + " found (DOES NOT CONFIRM THAT THESE ARE IN THE GRAPH YET)";
		qDebug() << QString::fromStdString(message);
		SetVertices(vertex1, vertex2, WEIGHT);
	}
    
}

// Sets up two vertices and an edge between them then adds them to the graph.
void Graph::SetVertices(Vertex* vertex1, Vertex* vertex2, const int WEIGHT)
{
    bool vertexFound = false;
    bool otherVertexFound = false;

    vector<Vertex*>::iterator searchIterator = vertices.begin();
    Vertex* vertexStillBeingSought;

    // First thing is to check if any of the vertices already exist in the graph
    while (!vertexFound && searchIterator != vertices.end())
    {
        // If any vertex already exists in the graph, store it temporarily for later.
        if ((*searchIterator)->name == vertex1->name || (*searchIterator)->name == vertex2->name)
        {
            vertexFound = true;

            if ((*searchIterator)->name == vertex1->name)
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
                if ((*searchIterator)->name == vertexStillBeingSought->name || (*searchIterator)->name == vertexStillBeingSought->name)
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
                if (vertexStillBeingSought->name == vertex1->name)
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

    // If the vertices being added don't yet exist, add an isolated edge.
    if (!vertexFound)
    {
        vertices.push_back(vertex1);
        vertices.push_back(vertex2);
    }

	// Check if an edge already exists between the two locations
	vector<Edge*>::iterator edgeAlreadyExistsIterator = vertex1->connections.begin();
	bool edgeFound = false;
	while (!edgeFound && edgeAlreadyExistsIterator != vertex1->connections.end())
	{
		if (vertex1->GetOtherVertex(*edgeAlreadyExistsIterator) == vertex2)
		{
			edgeFound = true;
		}
		else
		{
			edgeAlreadyExistsIterator++;
		}
	}

	if (!edgeFound)
	{
		Edge* edgeToBeAdded = new Edge(vertex1, vertex2, WEIGHT);

		vertex1->connections.push_back(edgeToBeAdded);
		vertex2->connections.push_back(edgeToBeAdded);
		edges.push_back(edgeToBeAdded);
		qDebug() << "SUCCESS: " + QString::fromStdString(vertex1->name) + " and " + QString::fromStdString(vertex2->name) + " connected";
	}
	else
	{
		qDebug() << "WARNING: Edge already exists between " + QString::fromStdString(vertex1->name) + " and " + QString::fromStdString(vertex2->name);
	}


}

// Outputs the edges belonging to every vertex of the graph.
string Graph::OutputAllConnections()
{
	string connectionsStr;
    vector<Vertex*>::const_iterator verticesIterator = vertices.begin();
    while (verticesIterator != vertices.end())
    {
        connectionsStr.append((*verticesIterator)->OutputAllConnections());
        verticesIterator++;
    }

	return connectionsStr;
}

stack<string> Graph::DijkstrasAlgorithm(const string START_VERTEX_NAME, const string END_VERTEX_NAME, int& weightOfTrip)
{
    vector<Vertex*>::const_iterator vertexIterator = vertices.begin();

    Vertex* startVertex = NULL;
    Vertex* endVertex = NULL;

    bool foundStart = false;
    bool foundEnd = false;

	string message = "Attempting dijkstras algorithm from " + START_VERTEX_NAME + " to " + END_VERTEX_NAME;

	qDebug() << QString::fromStdString(message);

    while ((!foundStart || !foundEnd) && vertexIterator != vertices.end())
    {
        if ((*vertexIterator)->name == START_VERTEX_NAME)
        {
            foundStart = true;
            startVertex = (*vertexIterator);
        }
        
		if ((*vertexIterator)->name == END_VERTEX_NAME)
        {
            foundEnd = true;
            endVertex = (*vertexIterator);
        }

        vertexIterator++;

    }

	if (!foundStart && !foundEnd)
	{
		message = "ERROR: Neither of the intended dijkstra vertices " + START_VERTEX_NAME + " nor " + END_VERTEX_NAME + " are connected/exist";
	}
	else if (!foundStart)
	{
		message = "ERROR: Start vertex for dijkstras " + START_VERTEX_NAME + " not found";
	}
	else if (!foundEnd)
	{
		message = "ERROR: End vertex for dijkstras " + END_VERTEX_NAME + " not found";
	}
	else
	{
		message = "SUCCESS: BOTH of the intended dijkstra vertices " + START_VERTEX_NAME + " and " + END_VERTEX_NAME + " are connected";
	}

	qDebug() << QString::fromStdString(message);

    return DijkstrasAlgorithm(startVertex, endVertex, weightOfTrip);
}

stack<string> Graph::DijkstrasAlgorithm(Vertex* startVertex, Vertex* endVertex, int& weightOfTrip)
{
    weightOfTrip = 0;

    vector<Vertex*> visitedVertices;

    Vertex* activeVertex = startVertex;
    vector<Edge*>::iterator	activeConnection = activeVertex->connections.begin();

    stack<string> verticesToVisit;

    startVertex->dijkstraWeight = 0;

	if (startVertex == endVertex)
	{
		verticesToVisit.push(startVertex->name);
		return verticesToVisit;
	}

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

		if (!endVertex->HasBeenVisited(visitedVertices))
		{
			activeVertex = GetSmallestUnvisitedVertex(vertices, visitedVertices);
		}
		
        activeConnection = activeVertex->connections.begin();

    }

    Vertex* outputVertex = endVertex;

    // Set the names of which vertices should be visited in the order they appear.
    while (outputVertex != startVertex)
    {
        verticesToVisit.push(outputVertex->name);
        outputVertex = outputVertex->dijkstraPrevVertex;
		qDebug() << QString::fromStdString(outputVertex->name);
    }

	verticesToVisit.push(outputVertex->name);
    cout << outputVertex->name << endl;
    weightOfTrip = endVertex->dijkstraWeight;

	vector<Vertex*>::iterator resetIterator = vertices.begin();
	while (resetIterator != vertices.end())
	{
		(*resetIterator)->dijkstraWeight = 9999;
		resetIterator++;
	}

    return verticesToVisit;
}

queue<string> Graph::PrimsAlgorithm(const string START_VERTEX_NAME, int& weight)
{
    vector<Vertex*>::const_iterator vertexIterator = vertices.begin();

    Vertex* startVertex = NULL;

    bool foundStart = false;

    while (!foundStart && vertexIterator != vertices.end())
    {
if ((*vertexIterator)->name == START_VERTEX_NAME)
{
	foundStart = true;
	startVertex = (*vertexIterator);
}
vertexIterator++;

	}

	return PrimsAlgorithm(startVertex, weight);
}

queue<string> Graph::PrimsAlgorithm(Vertex* startVertex, int& weight)
{
	vector<Vertex*> visitedVertices;
    vector<Edge*> connectionsToTake;
    vector<Edge*>::const_iterator connectionsIterator;
	vector<Vertex*>::const_iterator vertexIterator;
	Vertex* activeVertex = startVertex;
	Edge* connectionToMoveAcross = NULL;
    int totalDistance = 0;

	queue<string> MST;

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
	qDebug() << "Outputting MST: ";
	while (connectionsIterator != connectionsToTake.end())
	{
		cout << (*connectionsIterator)->vertices[0]->name << " connected to " << (*connectionsIterator)->vertices[1]->name << endl;
		connectionsIterator++;

		MST.push((*connectionsIterator)->vertices[0]->name + " connected to " + (*connectionsIterator)->vertices[1]->name);
	}
	qDebug() << "Distance traveled is: " + totalDistance;

	weight = totalDistance;

	return MST;

}

Vertex* Graph::GetSmallestUnvisitedVertex(vector <Vertex*> vertices, vector<Vertex*> visitedVertices)
{
	int tempWeight = 999999;
	Vertex* tempSmallestVertex = NULL;
	vector<Vertex*>::iterator vertexIterator = vertices.begin();
	while (vertexIterator != vertices.end())
	{
		qDebug() << "PROCESS: Examining dijkstra weight of " + QString::fromStdString((*vertexIterator)->name) + " of weight " + QString::fromStdString(to_string((*vertexIterator)->dijkstraWeight));
		if (!(*vertexIterator)->HasBeenVisited(visitedVertices) && (*vertexIterator)->dijkstraWeight < tempWeight)
		{
			qDebug() << "SUCESS: Vertex " + QString::fromStdString((*vertexIterator)->name) + " of weight " + QString::fromStdString(to_string((*vertexIterator)->dijkstraWeight)) + " is current smallest vertex";
			tempSmallestVertex = (*vertexIterator);
			tempWeight = tempSmallestVertex->dijkstraWeight;
		}
		else
		{
			if ((*vertexIterator)->HasBeenVisited(visitedVertices))
			{
				qDebug() << "PROCESS: Vertex " + QString::fromStdString((*vertexIterator)->name) + " of weight " + QString::fromStdString(to_string((*vertexIterator)->dijkstraWeight)) + " has been visited";
			}
			else if ((*vertexIterator)->dijkstraWeight >= tempWeight)
			{
				qDebug() << "PROCESS: Vertex " + QString::fromStdString((*vertexIterator)->name) + " of weight " + QString::fromStdString(to_string((*vertexIterator)->dijkstraWeight)) + " has larger dijkstra weight than" + QString::fromStdString(tempSmallestVertex->name) + " of weight " + QString::fromStdString(to_string(tempSmallestVertex->dijkstraWeight));
			}
			vertexIterator++;
		}
	}

	if (tempSmallestVertex == NULL)
	{
		qDebug() << "ERROR: SMALLEST UNVISITED VERTEX INVALID";
	}

	qDebug() << "Smallest unvisited verex for this iteration is " + QString::fromStdString(tempSmallestVertex->name);
	return tempSmallestVertex;
}
