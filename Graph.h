
#include <vector>
#include <set>
#include "vertex.h"
#include "rng.h"

#ifndef __GRAPH_H__
#define __GRAPH_H__

class Graph
{

private:

	static Rng rng;
	
	std::vector<Vertex> vertices;

public:

	Graph(int nodes, double density);
	Graph(std::vector<Vertex> v);
	Graph(const Graph& o);
	
	bool isEmpty();
	
	Vertex peek();
	Vertex pop();
	
	std::set<Vertex> select();
	void remove(Vertex v);
	
	void trim();
	void print();
};

#endif // !__GRAPH_H__