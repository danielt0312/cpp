#pragma once
#include <list>
#include "Node.h"

class Graph {
private:
	Node content;
public:
	Graph(int, int, int);
	std::list<Node>* vertices = new std::list<Node>();
	Node getContent();
};

