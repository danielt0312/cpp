#pragma once

#include <QWidget>

class Puff : public QWidget {

  public:
    Puff(QWidget *parent = 0);

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
