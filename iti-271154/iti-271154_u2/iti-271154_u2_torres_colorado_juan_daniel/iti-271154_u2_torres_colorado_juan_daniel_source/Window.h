#pragma once

#include <QWidget>
#include <QLineEdit>

#include "Graph.h"

class Window : public QWidget {
public:
    Window(QWidget *parent = nullptr);
    void guardarConexion();
    void eliminarConexion();
    void bipartite();
    void limpiarTablero();
    void limpiarColores();
    int letraNumero(char);
    void mostrarMensajeBipartito(bool);
    void mostrarAdvertencia();
    QLineEdit* inputGrafoA;
    QLineEdit* inputGrafoB; 
    QLineEdit* inputBipartite;

private:
      	Graph *grafo;
};

