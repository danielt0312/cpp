#include <QPainter>
#include <QTimer>
#include <QTextStream>
#include <QtWidgets>
#include <iostream>
#include <QTimer>
#include <QObject>
#include <algorithm>
#include <iostream>
#include <list>


#include <iostream>
using namespace std;

#include "puff_and_mouse.h"
#include "objeto.h"

Puff_and_Mouse::Puff_and_Mouse(QWidget *parent) QWidget(parent) {
    QTextStream out(stdout);

    x = 1;
    opacity = 1.0;
    timerId = startTimer(1);
    velocidad = 5;

    h = height();
    w = width();

    out << "h" << h << "\n"<< endl;
    out << "w" << w << "\n"<< endl;        

    altoC = 100;
    anchoC = 100;
}


void Puff_and_Mouse::mousePressEvent(QMouseEvent* event)
{
    QWidget::mousePressEvent(event);
    //int a = event->pos().x();
    //std::cout << "Mouse Down ("<< event->pos()<< '\n';
    std::cout << "Mouse Down ("<< (event->pos().x()) << ","<< (event->pos().y())<< ")"<< '\n';
}

void Puff_and_Mouse::mouseMoveEvent(QMouseEvent* event)
{
    QWidget::mousePressEvent(event);
    std::cout << "Mouse Move ("<<event->pos().x() << ","<< event->pos().y()<< ")"<< '\n';
}

void Puff_and_Mouse::mouseReleaseEvent(QMouseEvent* event)
{
    QWidget::mousePressEvent(event);
    std::cout << "Mouse Release ("<<event->pos().x() << ","<< event->pos().y()<< ")"<< '\n';
    
    listaObjetos.agregar(event->pos().x(), event->pos().y());
}

void Puff_and_Mouse::paintEvent(QPaintEvent *e) {
  Q_UNUSED(e);  
  doPainting();
}

void Puff_and_Mouse::doPainting() {
    QPainter painter(this);

    h = height();
    w = width();
    
    for(int i = lista

    painter.drawEllipse(x, (h/2)-50, anchoC, altoC);
}

void Puff_and_Mouse::timerEvent(QTimerEvent *e) {
    Q_UNUSED(e);
    if (x > (w-anchoC))
        velocidad*=-1;
    if (x  < 0)    
        velocidad*=-1;
    x += velocidad;
    repaint();
}
