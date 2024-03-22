#pragma once

#include <QWidget>

class Shapes : public QWidget {
    
  public:
    Shapes(QWidget *parent = 0);

  protected:
    void paintEvent(QPaintEvent *e);

  private:
    void doPainting();
};
