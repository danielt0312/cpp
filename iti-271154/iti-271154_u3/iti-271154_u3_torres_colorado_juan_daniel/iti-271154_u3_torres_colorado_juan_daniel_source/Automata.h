#pragma once

#include <QWidget>
#include <deque>
#include <iostream>
#include "Node.h"

using namespace std;  

class Automata : public QWidget {
    Q_OBJECT // habilita la funcionalidad de señales 
public:
    Automata(QWidget *parent = 0);
    deque<Node> estados;
    void mousePressEvent(QMouseEvent* event);
    void mouseMoveEvent(QMouseEvent* event);
    void mouseReleaseEvent(QMouseEvent* event);
    void limpiar();
    void dibujarArista(QPainter &, Node &);
    void limpiarColores();
    void addTransition(int,int,int,int);
    void reiniciarIF();
    int inix = -1;
    int iniy = -1;
    int finx = -1;
    int finy = -1;
    int opcion = 1; // Definir que boton se presiono y, por ende, que accion

// Dado que se trabaja en un hilo secundario, los qmensajesbox se deben de mostrar en el principal
signals:
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

