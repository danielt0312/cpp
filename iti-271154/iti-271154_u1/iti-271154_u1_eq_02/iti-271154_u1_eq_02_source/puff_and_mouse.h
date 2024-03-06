#pragma once

#include <QWidget>
#include <list>
#include "Graph.h"

using namespace std;  

class Puff_and_Mouse : public QWidget {

  public:
    list<Graph> listaGrafos;

    Puff_and_Mouse(QWidget *parent = 0);

    void mousePressEvent(QMouseEvent* event);
    
    void limpiar() { listaGrafos.clear();};
    void addEdge(int, int);
    void dibujarFlecha(QPainter &, int, int, int, int);
    void dibujarArista(QPainter &, Graph &);
    void adjacencyMatrix();
    void displayAdajencyMatrix(std::vector<std::vector<int>> &);
    void adjacencyLists();
    void displayAdjacencyLists(list<Graph> &);
  protected:
    void paintEvent(QPaintEvent *event);
    void timerEvent(QTimerEvent *event);

  private:
    int x, w, h;
    int altoC, anchoC;
    qreal opacity;
    int timerId;
    int velocidad;
    QColor colorPincel;
    void doPainting();
};
