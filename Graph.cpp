
#include "graph.h"

Rng Graph::rng;

Graph::Graph(int nodes, double density)
{
	for (int id = 0; id < nodes; id++)
	{
		Vertex v(id);
		vertices.push_back(v);
	}

	for (int i = 0; i < nodes; i++)
	{
		for (int j = i; j < nodes; j++)
		{
			if (i != j && rng.probability() < density)
			{
				vertices[i].addNeighbor(vertices[j]);
				vertices[j].addNeighbor(vertices[i]);
			}
		}
	}
}

Graph::Graph(std::vector<Vertex> v)
{
	vertices = std::vector<Vertex>(v);
}

Graph::Graph(const Graph& o)
{
	vertices = o.vertices;
}

bool Graph::isEmpty()
{
	return vertices.empty();
}

Vertex Graph::peek() 
{
	return vertices[0];
}

Vertex Graph::pop()
{
	Vertex v = vertices[0];
	vertices.erase(vertices.begin());
	return v;
}

/* Favor vertices with fewer neighbors */
std::set<Vertex> Graph::select()
{
	std::set<Vertex> random;
	for (const auto& vertex : vertices)
	{
		if (rng.probability() < 1.0 / (2 * vertex.degree()))
		{
			random.insert(vertex);
		}
	}

	return random;
}

void Graph::remove(Vertex v)
{
	vertices.erase(std::remove(vertices.begin(), vertices.end(), v), vertices.end());
}

/* Remove isolated vertices */
void Graph::trim()
{
	vertices.erase(std::remove_if(vertices.begin(), vertices.end(), [&](Vertex vertex)
	{
		return vertex.degree() < 1;
	}), vertices.end());
}

void Graph::print()
{
	for (const auto& vertex : vertices)
	{
		std::cout << vertex.toString() << std::endl;
	}
}
