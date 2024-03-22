#include <QDesktopWidget>
#include <QApplication>
#include "shapes.h"

int main(int argc, char *argv[]) {
    
  QApplication app(argc, argv);  
    
  Shapes window;

  window.resize(350, 280);  
  window.setWindowTitle("Shapes");
  window.show();

  return app.exec();
}
