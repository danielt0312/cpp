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

#include "punto.h"
#include "puff_and_mouse.h"
#include <fstream>

using namespace std;

Puff_and_Mouse::Puff_and_Mouse(QWidget *parent)
    : QWidget(parent) {
    
    archivoSalida.open("coordenadas.txt", ios::out | ios::app);
    if (!archivoSalida.is_open()) {
        cerr << "Error al abrir el archivo de salida." << std::endl;
    }
    
    x = 1;
    timerId = startTimer(1);
    velocidad = 1;

    h = height();
    w = width();

    cout << "h" << h << "\n"<< endl;
    cout << "w" << w << "\n"<< endl;        

    altoC = 100;
    anchoC = 100;
}


void Puff_and_Mouse::mousePressEvent(QMouseEvent* event)
{
    QWidget::mousePressEvent(event);
    //int a = event->pos().x();
    //std::cout << "Mouse Down ("<< event->pos()<< '\n';
    cout << "Mouse Down ("<< (event->pos().x()) << ","<< (event->pos().y())<< ")"<< '\n';
    Punto P1 (event->pos().x(),event->pos().y());
    listaPuntos.push_front (P1);
}

void Puff_and_Mouse::mouseMoveEvent(QMouseEvent* event)
{
    QWidget::mousePressEvent(event);
    cout << "Mouse Move ("<<event->pos().x() << ","<< event->pos().y()<< ")"<< '\n';
}

void Puff_and_Mouse::mouseReleaseEvent(QMouseEvent* event)
{
    QWidget::mousePressEvent(event);
    cout << "Mouse Release ("<<event->pos().x() << ","<< event->pos().y()<< ")"<< '\n';
}

void Puff_and_Mouse::LimpiarPuntos ()
{
    cout<<"Me az clickieado (Clase Puff_and_mouse))"<< '\n';
    listaPuntos.clear(); // limpiar la lista
    //doPainting();
    
    repaint();
}
void Puff_and_Mouse::guardarPuntos ()
{
    for (Punto x : listaPuntos) {
        archivoSalida << x.getX() << " " << x.getY() << std::endl;
    }
    archivoSalida.flush();
    //repaint();
}

void Puff_and_Mouse::cargarPuntos ()
{
 LimpiarPuntos();
 ifstream archivoEntrada("coordenadas.txt");
    if (!archivoEntrada.is_open()) {
        std::cerr << "Error al abrir el archivo de entrada." << std::endl;
        return;
    }
  int x1, y1;
    while (archivoEntrada >> x1 >> y1) {
        Punto punto(x1, y1);
        listaPuntos.push_back(punto);
    }

}

void Puff_and_Mouse::paintEvent(QPaintEvent *e) {
  Q_UNUSED(e);  
  doPainting();
}

void Puff_and_Mouse::doPainting() {
    QPainter painter(this);



    painter.setBackgroundMode (Qt::OpaqueMode);
    painter.setBackground (Qt::red);

    h = height();
    w = width();

//    std::cout << "h" << h << "\n"<< endl;
//    std::cout << "w" << w << "\n"<< endl;        

    painter.drawEllipse(x, (h/2)-50, anchoC, altoC);

    painter.setPen(colorPincel);
    for (Punto x : listaPuntos) {
		//std::cout << "("<<x.getX() << ","<< x.getY()<< ")"<< '\n';
        painter.drawEllipse(x.getX(), x.getY(), 10, 10);

	}


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






