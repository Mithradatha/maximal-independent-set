
#include "graph.h"
#include "sequential.h"
#include "luby.h"

#define NEW_LINE std::cout << std::endl

void printResults(const std::set<Vertex> &mis)
{
	for (const auto& v : mis)
	{
		std::cout << v.toString() << std::endl;
	}
}

int main()
{
	// generate graph
	Graph s(12, 0.2);
	std::cout << "Graph [original]:" << std::endl;
	s.print();
	NEW_LINE;

	// trim isolated vertices
	s.trim();
	std::cout << "Graph [trimmed]:" << std::endl;
	s.print();
	NEW_LINE;

	// copy constructor
	Graph l(s);
	std::set<Vertex> mis;

	// sequential mis
	Sequential seq(s);
	mis = seq.findMIS();
	std::cout << "MIS [sequential]:" << std::endl;
	printResults(mis);
	NEW_LINE;

	// luby mis
	Luby luby(l);
	mis = luby.findMIS();
	std::cout << "MIS [luby]:" << std::endl;
	printResults(mis);
	NEW_LINE;

	system("pause");
    return 0;
}
