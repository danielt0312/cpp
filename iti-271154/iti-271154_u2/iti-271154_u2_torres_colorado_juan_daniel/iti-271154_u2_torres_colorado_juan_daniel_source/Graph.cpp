#include "Graph.h"

Graph::Graph(int x, int y, int valor) : x(x), y(y), valor(valor) { color = Qt::white; }

int Graph::getX() const { return x; }
int Graph::getY() const { return y; }
int Graph::getValor() const { return valor; }
bool Graph::operator==(const Graph& other) const { return x == other.x && y == other.y && valor == other.valor; }

