#pragma once

#include <QWidget>
#include <QLineEdit>
#include "ListGraph.h"

class Window : public QWidget {
public:
    Window(QWidget *parent = nullptr);
    void guardarConexion();
    void BFS();
    void limpiarTablero();
    void limpiarColores();
    int letraNumero(char);
    QLineEdit* inputGrafoA;
    QLineEdit* inputGrafoB; 

private:
      	ListGraph *lg;
};
