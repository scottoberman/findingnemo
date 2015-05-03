/************************************************************************
* AUTHOR		: Scott Oberman
* STUDENT ID	: 271984
* Assignment #12:
* CLASS			: CS1D
* SECTION		: TTh 5:30p - 7:20p
* DUE DATE		: 4/14/15
*************************************************************************/

#include "Edge.h"

Edge::Edge()
{
    weight = 0;
    vertices[0] = NULL;
    vertices[1] = NULL;
}

Edge::Edge(Vertex* vertex1, Vertex* vertex2, const int WEIGHT)
{
    vertices[0] = vertex1;
    vertices[1] = vertex2;
    weight = WEIGHT;
}

// Attaches two vertices to an edge as well as set the weight of the edge between them
void Edge::AddEdge(Vertex* vertex1, Vertex* vertex2, const int WEIGHT)
{
    vertices[0] = vertex1;
    vertices[1] = vertex2;
    weight = WEIGHT;

    vertices[0]->AddConnection(this);
    vertices[1]->AddConnection(this);
}

// Gets the vertex that is on the opposite end of this edge compared to another vertex
Vertex* Edge::GetOtherVertex(Vertex* vertex)
{
    Vertex* otherVertex;
    if (vertex == vertices[0])
    {
        otherVertex = vertices[1];
    }
    else // if (vertex == vertices[1])
    {
        otherVertex = vertices[0];
    }

    return otherVertex;
}
