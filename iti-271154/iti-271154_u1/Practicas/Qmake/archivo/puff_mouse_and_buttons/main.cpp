#include <QApplication>
#include <list>

#include "review.h"

int main(int argc, char *argv[]) {

    QApplication app(argc, argv);

    Review window;

    //window.setStyleSheet("background-color: cyan;"); 

    window.resize(800, 600);
    window.setWindowTitle("Review");
    window.show();

  return app.exec();
}
