#include <QApplication>
#include <QDebug>
#include "buttons.h"

int main(int argc, char *argv[]) {
  QApplication app(argc, argv);

  Buttons window;

  window.resize(400, 200);
  window.setWindowTitle("A1");
  window.show();

  return app.exec();
}

