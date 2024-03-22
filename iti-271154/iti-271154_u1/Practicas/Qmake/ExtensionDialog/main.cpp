/*
  #include <QApplication>

  #include "finddialog.h"

  int main(int argc, char *argv[])
  {
      QApplication app(argc, argv);
      FindDialog dialog;

      dialog.show();

      return app.exec();
  }
*/

#include <QApplication>
#include <QWidget>
#include <QPushButton>
#include <QFileDialog>
#include <QScreen>

#include<iostream>
using namespace std;
#include "finddialog.h"

class MyButton : public QWidget {

 private:
     FindDialog * findDialog; //(".",this);

 public:
     MyButton(QWidget *parent = nullptr);
     void MetodoBoton (void);
};


MyButton::MyButton(QWidget *parent)
    : QWidget(parent) {

    auto *quitBtn = new QPushButton("Quit", this);
    quitBtn->setGeometry(50, 40, 75, 30);

    findDialog = new FindDialog();

    //connect(quitBtn, &QPushButton::clicked, qApp, &QApplication::quit);
    connect(quitBtn, &QPushButton::clicked, this, &MyButton::MetodoBoton);
}

void MyButton::MetodoBoton () {
    std::cout <<"Disparaddo por el boton \n";
    //findDialog->show();
    findDialog->setString("yes i will");                  

    findDialog->exec();                  
    std::cout << "Variable String "<< findDialog->getResultingString()<<"\n";
    std::cout << "Valor "<<findDialog->Variable<<"\n";
}

int main(int argc, char *argv[]) {

    int AnchoVentana = 800;
    int AltoVentana =600;

    QApplication app(argc, argv);
    QRect screenGeometry = app.primaryScreen()->geometry();
    int height = screenGeometry.height();
    int width = screenGeometry.width();

    std::cout << "Ancho "<<width<<" Alto "<<height<<"\n";

    MyButton window;
    window.resize(AnchoVentana, AltoVentana);
    window.setWindowTitle("QPushButton");

    window.move ((width/2)-(AnchoVentana/2),(height/2)-(AltoVentana/2));

    window.show();

    return app.exec();
}

