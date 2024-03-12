#pragma once

#include <QWidget>
#include <list>
#include <queue>
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
    
    void DFS();
    void DFSUtil(Graph &, std::unordered_set<int> &);
    void BFS();
    void BFSUtil(Graph &, std::unordered_set<int> &);
    void limpiarNodosVisitados();
  protected:
    void paintEvent(QPaintEvent *event);
    void timerEvent(QTimerEvent *event);

  private:
    std::unordered_set<int> nodosVisitados;
    int x, w, h;
    int altoC, anchoC;
    qreal opacity;
    int timerId;
    int velocidad;
    QColor colorPincel;
    void doPainting();
    QString dfsOutputText;
};
