#include <cstdlib>
#include <iostream>
#include "GenericalDeque.h"
#include "DequeStack.h"

LinkedDeque LD;
DequeStack DS;

void imprimirFuncionesSADT() {
	std::cout << "Seleccione una funcion a usar." << std::endl;
    	std::cout << "1. size()" << std::endl;
    	std::cout << "2. empty()" << std::endl;
    	std::cout << "3. top()" << std::endl;
    	std::cout << "4. push(e)" << std::endl;
    	std::cout << "5. pop()" << std::endl;
    	std::cout << "0. Regresar" << std::endl;
    	std::cout << "> ";
}

void funcionesSADT() {
	int numFuncion;
	while(true) {
		imprimirFuncionesSADT();
		std::cin >> numFuncion;
		std::cout << "\n";
		
		switch(numFuncion) {
			case 0 : { std::cout << "Regresando al menu principal..." << std::endl;	return;	}
			case 1 : { std::cout << DS.size() << std::endl;; break; }
			case 2 : { std::cout << (DS.empty() ? "Verdadero: Esta Vacio" : "Falso: No esta vacio"); break; }
			case 3 : { std::cout << DS.top() << std::endl; break; }
			case 4 : { 
				std::string elemento;
				std::cout << "Ingrese el elemento: " << std::endl;
				std::cin >> elemento;
				std::cout << "\n";
				DS.push(elemento);
				break; 
			}
			case 5 : { DS.pop(); break; }
			default: { std::cout << "Funcion invalida" << std::endl; break; }
		}
		
		std::cout << "\n";
	}
}

void imprimirFuncionesDLL() {
	std::cout << "Seleccione una funcion a usar." << std::endl;
    	std::cout << "1. size()" << std::endl;
    	std::cout << "2. empty()" << std::endl;
    	std::cout << "3. front()" << std::endl;
    	std::cout << "4. back()" << std::endl;
    	std::cout << "5. insertFront(e)" << std::endl;
    	std::cout << "6. insertBack(e)" << std::endl;
    	std::cout << "7. eraseFront()" << std::endl;
    	std::cout << "8. eraseBack()" << std::endl;
    	std::cout << "0. Regresar" << std::endl;
    	std::cout << "> ";
}
		
void funcionesDLL() {
	int numFuncion;
	while(true) {
		imprimirFuncionesDLL();
		std::cin >> numFuncion;
		std::cout << "\n";
		
		switch(numFuncion) {
			case 0 : { std::cout << "Regresando al menu principal..." << std::endl;	return;	}
			case 1 : { std::cout << LD.size() << std::endl;; break; }
			case 2 : { std::cout << (LD.empty() ? "Verdadero: Esta Vacio" : "Falso: No esta vacio"); break; }
			case 3 : { std::cout << LD.front() << std::endl; break; }
			case 4 : { std::cout << LD.back() << std::endl; break; }
			case 5 : { 
				std::string elemento;
				std::cout << "Ingrese el elemento: " << std::endl;
				std::cin >> elemento;
				std::cout << "\n";
				LD.insertFront(elemento);
				break; 
			}
			case 6 : { 
				std::string elemento;
				std::cout << "Ingrese el elemento: " << std::endl;
				std::cin >> elemento;
				std::cout << "\n";
				LD.insertBack(elemento);
				break; 
			}
			case 7 : { LD.removeFront(); break; }
			case 8 : { LD.removeBack(); break; }
			default: { std::cout << "Funcion invalida" << std::endl; break; }
		}
		
		std::cout << "\n";
	}
}

void imprimirMenu() {
	std::cout << "Selecciona el tipo de dato que se almacenaran en las operaciones posteriores del Deque STL y ADT." << std::endl;
	std::cout << "	1. Entero (int)" << std::endl; 
	std::cout << "	2. Cadena de texto (string)" << std::endl; 
	std::cout << "	3. Flotante (float)" << std::endl;
	std::cout << "4. Implementar un deque con Listas Doblemente Enlistadas (string)" << std::endl;
	std::cout << "5. Implementar un deque con el Stack ADT(string)" << std::endl;
	std::cout << "0. Terminar Programa" << std::endl;
	std::cout << "> ";
}

void menu() {
	int opcion;
	
	GenericalDeque<int> intDeque;
	GenericalDeque<std::string> stringDeque;
	GenericalDeque<float> floatDeque;
	while(true) {
		imprimirMenu();
		std::cin >> opcion;
		std::cout << "\n";
		
		switch(opcion) {
			case 0 : {
				std::cout << "Se termino el programa..." << std::endl;
				return;
			}
			case 1 : { 
				intDeque.listaAcciones();
				break; 
			}
			case 2 : { 
				stringDeque.listaAcciones();
				break; 
			}
			case 3 : { 
				floatDeque.listaAcciones();
				break; 
			}
			case 4 : {
				funcionesDLL();
				break;
			}
			case 5 : {
				funcionesSADT();
				break;
			}
			default: {
				std::cout << "Valor invalido" << std::endl;
				break;
			}
		}
		
		std::cout << "\n";
	}
}

int main() {
	menu();
	
	return 0;
}
