#include <iostream>
using namespace std;

void Objeto::agregar(int x, int y) {
    this.x = x;
    this.y = y;
    
    this.imprimirCoordenadas();
}

void Objeto::imprimirCoordenadas() {
    cout << "Coordenada guardada en: (" << this.getX() << ", " << this.getY() << " )" << endl;
}

int Objeto::getX() {
    return x;
}

int Objeto::getY() {
    return y;
}
