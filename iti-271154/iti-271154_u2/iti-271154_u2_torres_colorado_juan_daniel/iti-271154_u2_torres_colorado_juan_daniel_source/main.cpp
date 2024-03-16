#include <QApplication>
#include "Window.h"

int main(int argc, char *argv[]) {
    QApplication app(argc, argv);

    Window window;
    window.resize(1366, 768);
    window.setWindowTitle("Identificando Grafos Bipartito");
    window.show();

  return app.exec();
}

