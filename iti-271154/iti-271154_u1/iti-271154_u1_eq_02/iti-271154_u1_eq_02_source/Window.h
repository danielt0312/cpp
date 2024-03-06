#pragma once

#include <QWidget>
#include <QLineEdit>
#include "ListGraph.h"

class QPushButton;

class Window : public QWidget {

  public:
    Window(QWidget *parent = nullptr);
    void guardarConexion();
    void matrix();
    void list();
    void limpiarTablero();
    QLineEdit* inputGrafoA;
    QLineEdit* inputGrafoB; 

  private:
      	ListGraph *lg1;

};
