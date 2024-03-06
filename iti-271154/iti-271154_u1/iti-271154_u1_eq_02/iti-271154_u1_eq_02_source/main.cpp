#include <QApplication>
#include <list>

#include "Window.h"

int main(int argc, char *argv[]) {

    QApplication app(argc, argv);

    Window window;

    //window.setStyleSheet("background-color: cyan;"); 

    window.resize(1280, 720);
    window.setWindowTitle("Graph Traversal");
    window.show();

  return app.exec();
}
