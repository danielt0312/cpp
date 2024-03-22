#pragma once

#include <QWidget>
#include <list>
// Estos dos compas deben ir juntos, si no hay pdos
//#include "puff_and_mouse.h"
#include <punto.h>
using namespace std;  


class Puff_and_Mouse : public QWidget {

  public:

    list<Punto> listaPuntos; // Lista de Puntos

    Puff_and_Mouse(QWidget *parent = 0);

    void mousePressEvent(QMouseEvent* event);
    void mouseMoveEvent(QMouseEvent* event);
    void mouseReleaseEvent(QMouseEvent* event);

    void LimpiarPuntos ();


  protected:
    void paintEvent(QPaintEvent *event);
    void timerEvent(QTimerEvent *event);

  private:
    int x, w, h;
    int altoC, anchoC;
    qreal opacity;
    int timerId;
    int velocidad;
    
    void doPainting();


};
