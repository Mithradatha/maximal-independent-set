
#include "luby.h"

Luby::Luby(Graph g) : graph(g) {}

std::set<Vertex> Luby::findMIS()
{
	while (!graph.isEmpty())
	{
		std::set<Vertex> vertices = graph.select();

		for (const auto& vertex : vertices)
		{
			for (const auto& neighbor : vertex.getNeighbors())
			{
				if (vertices.find(neighbor) != vertices.end())
				{
					removeFromSet(vertices, (vertex.degree() < neighbor.degree()) ? vertex : neighbor);
				}
			}
		}

		independent.insert(vertices.begin(), vertices.end());
		for (const auto& vertex : vertices)
		{
			for (const auto& neighbor : vertex.getNeighbors())
			{
				graph.remove(neighbor);
			}
			
			graph.remove(vertex);
		}
	}

	return independent;
}

template <class T>
void Luby::removeFromSet(std::set<T>& set, const T& value)
{
	for (auto iterator = set.begin(); iterator != set.end();)
	{
		if (*iterator == value)
		{
			iterator = set.erase(iterator);
			break; // sets have unique values
		}
		else
		{
			++iterator;
		}
	}
}
