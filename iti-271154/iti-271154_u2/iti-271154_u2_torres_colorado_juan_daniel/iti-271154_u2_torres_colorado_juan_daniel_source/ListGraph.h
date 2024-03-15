#pragma once

#include <QWidget>
#include <deque>
#include <iostream>
#include "Graph.h"

using namespace std;  

class ListGraph : public QWidget {
public:
    ListGraph(QWidget *parent = 0);
    deque<Graph> listaGrafos;
    void mousePressEvent(QMouseEvent* event);
    void limpiar();
    void addEdge(int, int);
    std::string numeroLetra(int);
    void dibujarArista(QPainter &, Graph &);
    void BFS();
    void limpiarColores();
protected:
    void paintEvent(QPaintEvent *event);
    void timerEvent(QTimerEvent *event);

private:
    int x, w, h;
    int altoC, anchoC;
    qreal opacity;
    int timerId;
    QColor colorPincel;
    void doPainting();
    QString dfsOutputText;
};

