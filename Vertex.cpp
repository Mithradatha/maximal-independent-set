
#include "vertex.h"

Vertex::Vertex(int id) : id(id) {}

int Vertex::getId() const
{
	return id;
}

int Vertex::degree() const
{
	return neighbors.size();
}

bool Vertex::operator ==(const Vertex& other) const
{
	return id == other.id;
}

bool Vertex::operator <(const Vertex& other) const
{
	return id < other.id;
}

void Vertex::addNeighbor(Vertex neighbor)
{
	neighbors.push_back(neighbor);
}

std::vector<Vertex> Vertex::getNeighbors() const
{
	return neighbors;
}

std::string Vertex::toString() const
{
	std::stringstream ss;

	ss << id << ": [";

	const int last = neighbors.size() - 1;
	if (last > -1)
	{
		for (int i = 0; i < last; i++) {

			ss << neighbors[i].id << ", ";
		}

		ss << neighbors[last].id;
	}

	ss << "]";
	return ss.str();
}
