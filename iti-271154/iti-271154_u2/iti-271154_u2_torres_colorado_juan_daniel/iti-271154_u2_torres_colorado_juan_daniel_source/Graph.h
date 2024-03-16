#pragma once

#include <QWidget>
#include <deque>
#include <iostream>
#include "Node.h"

using namespace std;  

class Graph : public QWidget {
    Q_OBJECT // habilita la funcionalidad de señales 
public:
    Graph(QWidget *parent = 0);
    deque<Node> vertices;
    deque<Node*> conjuntoA;
    deque<Node*> conjuntoB;
    void mousePressEvent(QMouseEvent* event);
    void limpiar();
    void addEdge(int, int);
    void removeEdge(int, int);
    std::string numeroLetra(int);
    void dibujarArista(QPainter &, Node &);
    void limpiarColores();
    void bipartite(int);

// Dado que se trabaja en un hilo secundario, los qmensajesbox se deben de mostrar en el principal
signals:
    void bipartiteResult(bool isBipartite);
    void advertencia();

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

