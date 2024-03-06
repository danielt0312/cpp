#include "Node.h"

Node::Node(int x, int y, int valor){
	this->x = x;
	this->y = y;
	this->valor = valor;
}

int Node::getX() {
	return x;
}

int Node::getY() {
	return y;
}

int Node::getValor() {
	return valor;
}
