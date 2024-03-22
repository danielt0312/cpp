#include <QApplication>
#include "puff_and_mouse.h"

int main(int argc, char *argv[]) {
    
  QApplication app(argc, argv); 

  Puff_and_Mouse window;

  window.resize(600, 600);
  window.setWindowTitle("Puff");
  window.show();

  return app.exec();
}
