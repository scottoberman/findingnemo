/************************************************************************
* AUTHOR		: Scott Oberman
* STUDENT ID	: 271984
* Assignment #12:
* CLASS			: CS1D
* SECTION		: TTh 5:30p - 7:20p
* DUE DATE		: 4/14/15
*************************************************************************/

#include "Graph.h"

void Graph::SetVertex(const string NAME)
{
    vertices.push_back(new Vertex(NAME));
}

void Graph::ChangeVertexName(const string OG_NAME, const string NEW_NAME)
{
    vector<Vertex*>::iterator vertexIterator = vertices.begin();

    while ((*vertexIterator)->name != OG_NAME)
    {
        vertexIterator++;
    }

    (*vertexIterator)->name = NEW_NAME;
}

// Sets up two vertices and an edge between them with just the names of each vertex and the weight of their edge.
void Graph::SetVertices(const string VERTEX_1_NAME, const string VERTEX_2_NAME, const int WEIGHT)
{
    vector<Vertex*>::const_iterator verticesIterator = vertices.begin();

    Vertex* vertex1 = NULL;
    Vertex* vertex2 = NULL;

    bool vertex1Found = false;
    bool vertex2Found = false;

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
        vertex1 = new Vertex(VERTEX_1_NAME);
    }

    if (!vertex2Found)
    {
        vertex2 = new Vertex(VERTEX_2_NAME);
    }

    SetVertices(vertex1, vertex2, WEIGHT);
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
    Edge* edgeToBeAdded = new Edge(vertex1, vertex2, WEIGHT);

    vertex1->connections.push_back(edgeToBeAdded);
    vertex2->connections.push_back(edgeToBeAdded);
    edges.push_back(edgeToBeAdded);

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

stack<string> Graph::DijkstrasAlgorithm(const string START_VERTEX_NAME, const string END_VERTEX_NAME, int& weightOfTrip)
{
    vector<Vertex*>::const_iterator vertexIterator = vertices.begin();

    Vertex* startVertex = NULL;
    Vertex* endVertex = NULL;

    bool foundStart = false;
    bool foundEnd = false;

    while ((!foundStart || !foundEnd) && vertexIterator != vertices.end())
    {
        if ((*vertexIterator)->name == START_VERTEX_NAME)
        {
            foundStart = true;
            startVertex = (*vertexIterator);
        }
        else if ((*vertexIterator)->name == END_VERTEX_NAME)
        {
            foundEnd = true;
            endVertex = (*vertexIterator);
        }

        vertexIterator++;

    }

    return DijkstrasAlgorithm(startVertex, endVertex, weightOfTrip);
}

stack<string> Graph::DijkstrasAlgorithm(Vertex* startVertex, Vertex* endVertex, int& weightOfTrip)
{
    weightOfTrip = 0;

    vector<Vertex*> notVisitedVertices = vertices;
    vector<Vertex*> visitedVertices;
    vector<Edge*> visitedConnections;

    Vertex* activeVertex = startVertex;
    vector<Edge*>::iterator	activeConnection = activeVertex->connections.begin();
    vector<Vertex*>::const_iterator nextVertex;
    vector<Edge*>::const_iterator nextEdge;

    stack<string> verticesToVisit;

    startVertex->dijkstraWeight = 0; // CHECK THIS LATER K

    // While the end vertex has not yet been visited, keep checking for shortest distance to end vertex.
    while (visitedVertices.size() != vertices.size())
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
        if (visitedVertices.size() != vertices.size())
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

    // Set the names of which vertices should be visited in the order they appear.
    while (outputVertex != startVertex)
    {
        verticesToVisit.push(outputVertex->name);
        outputVertex = outputVertex->dijkstraPrevVertex;
    }
    cout << outputVertex->name << endl;

    weightOfTrip = endVertex->dijkstraWeight;

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
    cout << "Outputting MST: " << endl;
    while (connectionsIterator != connectionsToTake.end())
    {
        cout << (*connectionsIterator)->vertices[0]->name << " connected to " << (*connectionsIterator)->vertices[1]->name << endl;
        connectionsIterator++;

        MST.push((*connectionsIterator)->vertices[0]->name + " connected to " + (*connectionsIterator)->vertices[1]->name);
    }
    cout << "Distance traveled is: " << totalDistance << endl;

    weight = totalDistance;

    return MST;

}
