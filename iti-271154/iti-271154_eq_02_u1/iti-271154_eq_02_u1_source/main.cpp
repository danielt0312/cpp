#include <QApplication>
#include "Window.h"

int main(int argc, char *argv[]) {
    QApplication app(argc, argv);

    Window window;
    window.resize(1280, 720);
    window.setWindowTitle("Graph Traversal");
    window.show();

  return app.exec();
}
