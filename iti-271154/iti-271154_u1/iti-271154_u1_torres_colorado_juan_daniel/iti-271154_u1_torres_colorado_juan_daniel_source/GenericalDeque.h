#include <deque>

template<typename Elem>
class GenericalDeque {
	private:
	    std::deque<Elem> D;
	public:
		void imprimirFuncionesSTL() {
			std::cout << "Seleccione una funcion a usar." << std::endl;
		    	std::cout << "1. size(): Devuelve el numero de elementos del deque" << std::endl;
		    	std::cout << "2. empty(): Devuelve verdadero si el deque esta vacio y sino, falso" << std::endl;
		    	std::cout << "3. push_front(e): Inserta un elemento e al inicio del deque" << std::endl;
		    	std::cout << "4. push_back(e): Inserta un elemento e al final del deque" << std::endl;
		    	std::cout << "5. pop_front(): Elimina el primer elemento del deque; un error ocurre si el deque esta vacio" << std::endl;
		    	std::cout << "6. pop_back(): Elimina el ultimo elemento del deque; un error ocurre si el deque esta vacio" << std::endl;
		    	std::cout << "7. front(): Devuelve el primer elemento del deque; un error ocurre si el deque esta vacio" << std::endl;
		    	std::cout << "8. back(): Devuelve el ultimo elemento del deque; un error ocurre si el deque esta vacio" << std::endl;
	    		std::cout << "0. Regresar" << std::endl;
	    		std::cout << "> ";
		}
		
		void funcionesSTL() {
			int numFuncion;
			while(true) {
				imprimirFuncionesSTL();
				std::cin >> numFuncion;
				std::cout << "\n";
				
				switch(numFuncion) {
					case 0 : { std::cout << "Regresando al menu de acciones..." << std::endl;	return;	}
					case 1 : { std::cout << D.size() << std::endl;; break; }
					case 2 : { std::cout << (D.empty() ? "Verdadero: Esta Vacio" : "Falso: No esta vacio"); break; }
					case 3 : {
						Elem insert;
						std::cout << "Ingresa el elemento: ";
						std::cin >> insert;
						std::cout << "\n";
						D.push_front(insert);
						break;
					}
					case 4 : {
						Elem insert;
						std::cout << "Ingresa el elemento: ";
						std::cin >> insert;
						std::cout << "\n";
						D.push_back(insert);
						break;
					}
					case 5 : { D.pop_front(); break; }
					case 6 : { D.pop_back(); break; }
					case 7 : { std::cout << D.front() << std::endl; break; }
					case 8 : { std::cout << D.back() << std::endl; break; }
					default: { std::cout << "Funcion invalida" << std::endl; break; }
				}
				
				std::cout << "\n";
			}
		}
		
	    void imprimirFuncionesADT() {
		    	std::cout << "Seleccione una funcion a usar." << std::endl;
		    	std::cout << "1. insertFront(e): Inserta un nuevo elemento e al inicio del deque" << std::endl;
		    	std::cout << "2. insertBack(e): Inserta un nuevo elemento e al final del deque" << std::endl;
		    	std::cout << "3. eraseFront(): Elimina el primer elemento del deque; un error ocurre si el deque esta vacio" << std::endl;
		    	std::cout << "4. eraseBack():  Elimina el ultimo elemento del deque; un error ocurre si el deque esta vacio" << std::endl;
		    	std::cout << "5. front(): Devuelve el primer elemento del deque; un error ocurre si el deque esta vacio" << std::endl;
		    	std::cout << "6. back(): Devuelve el ultimo elemento del deque; un error ocurre si el deque esta vacio" << std::endl;
		    	std::cout << "7. size(): Devuelve el numero de elementos del deque" << std::endl;
		    	std::cout << "8. empty(): Devuelve verdadero si el deque esta vacio y sino, falso" << std::endl;
		    	std::cout << "0. Regresar" << std::endl;
		    	std::cout << "> ";
		}
	    
	    void funcionesADT() {
	    	int numFuncion;
	    	while(true) {
	    		imprimirFuncionesADT();
	    		std::cin >> numFuncion;
			std::cout << "\n";
	    		
	    		switch(numFuncion) {
	    			case 0 : { std::cout << "Regresando al menu de acciones..." << std::endl;	return;	}
					case 1 : {
						Elem insert;
						std::cout << "Ingresa el elemento: ";
						std::cin >> insert;
						std::cout << "\n";
						insertFront(insert);
						break;
					}
					case 2 : {
						Elem insert;
						std::cout << "Ingresa el elemento: ";
						std::cin >> insert;
						std::cout << "\n";
						insertBack(insert);
						break;
					}
					case 3 : { eraseFront(); break; }
					case 4 : { eraseBack(); break; }
					case 5 : { std::cout << front() << std::endl; break; }
					case 6 : { std::cout << back() << std::endl; break; }
					case 7 : { std::cout << size() << std::endl; break; }
					case 8 : { std::cout << (empty() ? "Verdadero: Esta vacio" : "Falso: No esta vacio") << std::endl; break; }
					default: { std::cout << "Funcion invalida" << std::endl; break; }
				}
				
				std::cout << "\n";
			}
		}
	    
	    void imprimirAcciones() {
	    	std::cout << "Ingrese una opcion." << std::endl;
	    	std::cout << "1. Funciones del deque ADT" << std::endl;
	    	std::cout << "2. El deque STL" << std::endl;
	    	std::cout << "0. Regresar" << std::endl;
	    	std::cout << "> ";
		}
	    
	    void listaAcciones() {
	    	int accion;
	    	while(true) {
	    		imprimirAcciones();
	    		std::cin >> accion;
			std::cout << "\n";
	    		
	    		switch(accion) {
	    			case 0 : { std::cout << "Regresando al inicio..." << std::endl; return;}
					case 1 : { funcionesADT(); break; }
					case 2 : { funcionesSTL(); break; }
					default : { std::cout << "Accion invalida" << std::endl; break; }
				}
			}
		}
	    
		void insertFront(const Elem& e) {
			D.push_front(e);
		}
		
		void insertBack(const Elem& e) {
			D.push_back(e);
		}
		
		void eraseFront() {
			D.pop_front();
		}
		
		void eraseBack() {
			D.pop_back();
		}
		
		const Elem& front() {
			return D.front();
		}
		
		const Elem& back() {
			return D.back();
		}
		
		int size() {
			return D.size();
		}
		
		bool empty() {
	return D.empty();
}
};

