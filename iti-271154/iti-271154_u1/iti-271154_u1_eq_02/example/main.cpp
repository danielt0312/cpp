// main.cpp
#include <iostream>
#include "Graph.h"
#include <list>

std::list<Graph> listaGrafos;

int main() {
	listaGrafos.push_back(Graph(4, 5, 1));
	listaGrafos.push_back(Graph(2, 3, 8));
	listaGrafos.push_back(Graph(7, 1, 5));

	// Imprimir los grafos almacenados en listaGrafos
	for (Graph& graph : listaGrafos) {
		std::cout << "Coordenadas: (" << graph.getContent().getX() << ", " << graph.getContent().getY() << ")" << std::endl;
		std::cout << "Valor: " << graph.getContent().getValor() << std::endl;
		std::cout << "---------------------------" << std::endl;
	}

	return 0;
}
