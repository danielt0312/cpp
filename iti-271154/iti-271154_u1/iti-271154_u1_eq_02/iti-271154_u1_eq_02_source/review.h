#pragma once

#include <QWidget>
#include <QLineEdit>
#include "puff_and_mouse.h"

class QPushButton;

class Review : public QWidget {

  public:
    Review(QWidget *parent = nullptr);
    void guardarConexion();
    void limpiarTablero();
    QLineEdit* inputGrafoA;
    QLineEdit* inputGrafoB; 

  private:
      	Puff_and_Mouse *pm1;

};
