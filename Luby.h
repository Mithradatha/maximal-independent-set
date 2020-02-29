
#include "graph.h"
#include <set>

#ifndef __LUBY_H__
#define __LUBY_H__

class Luby
{
private:
	
	Graph graph;
	std::set<Vertex> independent;

	template <class T>
	void removeFromSet(std::set<T>& set, const T& value);

public:

	Luby(Graph g);

	std::set<Vertex> findMIS();
};

#endif // !__LUBY_H__
