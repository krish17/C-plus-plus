#include "Graph.h"


Graph::Graph()
{
	for (int i = 0; i < 200; i++)
	{
		for (int j = 0; j < 200; j++)
		{
			matrix[i][j] = 0;
		}
	}
}

void Graph::setData(int i, int j)
{
	matrix[i][j] = 1;
}

int Graph::getData(int i, int j)
{
	return matrix[i][j];
}

Graph::~Graph()
{
}
