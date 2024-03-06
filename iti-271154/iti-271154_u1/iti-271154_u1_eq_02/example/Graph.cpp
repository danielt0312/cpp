#include <list>
#include "Graph.h"

// Constructor
Graph::Graph(int x, int y, int valor) : content(x, y, valor){ }

Node Graph::getContent() { return content; }


