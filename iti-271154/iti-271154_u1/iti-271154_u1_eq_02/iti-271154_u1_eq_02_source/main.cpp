#include <QApplication>
#include <list>

#include "review.h"

int main(int argc, char *argv[]) {

    QApplication app(argc, argv);

    Review window;

    //window.setStyleSheet("background-color: cyan;"); 

    window.resize(1280, 720);
    window.setWindowTitle("Graph Transversal");
    window.show();

  return app.exec();
}
