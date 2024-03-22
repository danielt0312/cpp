#include <QApplication>
#include "puff.h"

int main(int argc, char *argv[]) {
    
  QApplication app(argc, argv); 

  Puff window;

  window.resize(700, 700);
  window.setWindowTitle("Puff");
  window.show();

  return app.exec();
}
