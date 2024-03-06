#pragma once

#include <QWidget>
#include <list>
#include <unordered_set>
#include <iostream>
#include "Graph.h"

using namespace std;  

class ListGraph : public QWidget {

  public:
    list<Graph> listaGrafos;

    ListGraph(QWidget *parent = 0);

    void mousePressEvent(QMouseEvent* event);
    
    void limpiar() { listaGrafos.clear(); std::cout << "Lista de Grafos limpiada" << std::endl;};
    void addEdge(int, int);
    void dibujarFlecha(QPainter &, int, int, int, int);
    void dibujarArista(QPainter &, Graph &);
    void adjacencyMatrix();
    void displayAdajencyMatrix(std::vector<std::vector<int>> &);
    void adjacencyLists();
    void displayAdjacencyLists(list<Graph> &);
    void DFSUtil(Graph &, unordered_set<int> &);
    void DFS();
    void BFSUtil(Graph&, unordered_set<int>&);
    void BFS();
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
