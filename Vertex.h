
#include <vector>
#include <iostream>
#include <sstream>

#ifndef __VERTEX_H__
#define __VERTEX_H__

class Vertex 
{

private:
	
	int id;
	std::vector<Vertex> neighbors;

public:
	
	Vertex(int id);
	
	int getId() const;
	int degree() const;

	bool operator ==(const Vertex& other) const;
	bool operator <(const Vertex& other) const;

	void addNeighbor(Vertex neighbor);
	std::vector<Vertex> getNeighbors() const;
	
	std::string toString() const;
};

#endif // !__VERTEX_H__
