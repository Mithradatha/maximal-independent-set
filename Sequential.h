

#include "graph.h"
#include <set>

#ifndef __SEQUENTIAL_H__
#define __SEQUENTIAL_H__

class Sequential
{

private:

	std::set<Vertex> independent;

	Graph graph;

public:

	Sequential(Graph g);

	std::set<Vertex> findMIS();
};

#endif // !__SEQUENTIAL_H__
