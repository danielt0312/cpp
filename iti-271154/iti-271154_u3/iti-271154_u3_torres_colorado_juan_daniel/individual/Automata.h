#pragma once

#include <QWidget>
#include <deque>
#include <iostream>
#include <string>
#include <list>

#include "Node.h"

using namespace std;  

class Automata : public QWidget {
    Q_OBJECT // habilita la funcionalidad de señales 
public:
    Automata(QWidget *parent = 0);
    deque<Node> estados;
    Node *inicial = new Node(30,380,-404); // estado inicial predeterminado con valor 'unico'
    void mousePressEvent(QMouseEvent* event);
    void mouseMoveEvent(QMouseEvent* event);
    void mouseReleaseEvent(QMouseEvent* event);
    void limpiar();
    void dibujarEstado(QPainter&, Node&);
    void dibujarTransicion(QPainter&, Node&);
    void dibujarFlecha(QPainter&, Node&, Node&, int);
    void pointItSelf(QPainter&, Node&, int);
    void limpiarColores();
    void addTransition(int,int,int,int);
    void setCharTransition(Node&, Node&);
    void reiniciarIF();
    std::string toString(QString&);
    void selectFinalState();
    
    void PDA(QString);
    void navigate(Node& , list<std::string>& , list<std::string>&);
    void mostrarEjemplo();
    
    int inix = -1;
    int iniy = -1;
    int finx = -1;
    int finy = -1;
    int opcion = 1; // Definir que boton se presionó

signals:
    void emitResult(float);

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

