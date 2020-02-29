
#include "sequential.h"

Sequential::Sequential(Graph g) : graph(g) {}

std::set<Vertex> Sequential::findMIS() 
{
	while (!graph.isEmpty())
	{
		Vertex vertex = graph.peek();
		independent.insert(vertex);

		for (const auto& neighbor : vertex.getNeighbors())
		{
			graph.remove(neighbor);
		}

		graph.remove(vertex);
	}

	return independent;
}
