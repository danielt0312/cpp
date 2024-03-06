#pragma once

#include <QWidget>
#include <QLineEdit>
#include "puff_and_mouse.h"

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
      	Puff_and_Mouse *pm1;

};
