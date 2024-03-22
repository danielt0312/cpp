#pragma once

#include <QWidget>
#include <list>
#include "objeto.h"

using namespace std;

class Puff_and_Mouse : public QWidget {

  public:
    Puff_and_Mouse(QWidget *parent = 0);
    void mousePressEvent(QMouseEvent* event);
    void mouseMoveEvent(QMouseEvent* event);
    void mouseReleaseEvent(QMouseEvent* event);
    list<objeto> listaObjetos;

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
