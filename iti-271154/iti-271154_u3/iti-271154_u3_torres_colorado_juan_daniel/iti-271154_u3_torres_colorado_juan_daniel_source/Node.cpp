#include "Node.h"

Node::Node(int x, int y, int valor) : x(x), y(y), valor(valor) { color = Qt::white; }

int Node::getX() const { return x; }
int Node::getY() const { return y; }
int Node::getValor() const { return valor; }
bool Node::operator==(const Node& other) const { return x == other.x && y == other.y && valor == other.valor; }

