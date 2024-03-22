#include <QApplication>
#include <list>

#include "funciones.h"
#include "review.h"

int main(int argc, char *argv[]) {

    QApplication app(argc, argv);

    Review window;

    //window.setStyleSheet("background-color: cyan;"); 
    
    Funciones f;
    f.crearCarpeta("dibujos");
    f.guardarDibujos("dibujos/1.txt");

    window.resize(800, 600);
    window.setWindowTitle("Review");
    window.show();

  return app.exec();
}
