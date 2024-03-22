
#include <list>
#include "punto.h"


Punto::Punto(int X, int Y){
    this->X = X;
    this->Y = Y;
}

int Punto::getX () {
    return X;
}

int Punto::getY () {
    return Y;
}
