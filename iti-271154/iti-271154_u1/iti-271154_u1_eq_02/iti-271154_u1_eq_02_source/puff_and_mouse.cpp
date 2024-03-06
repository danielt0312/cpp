#include <QPainter>
#include <QTimer>
#include <QTextStream>
#include <QtWidgets>
#include <iostream>
#include <QTimer>
#include <QObject>
#include <algorithm>
#include <QInputDialog>
#include <iostream>
#include <list>
#include <iostream>

#include "punto.h"
#include "puff_and_mouse.h"
#include <fstream>
#include <string>

#include <algorithm>

using namespace std;

Puff_and_Mouse::Puff_and_Mouse(QWidget *parent)
    : QWidget(parent) {
    
    x = 1;
    timerId = startTimer(1);
    velocidad = 1;

    h = height();
    w = width();

    std::cout << "h" << h << "\n"<< endl;
    std::cout << "w" << w << "\n"<< endl;        

    altoC = 40;
    anchoC = 40;
}


void Puff_and_Mouse::mousePressEvent(QMouseEvent* event)
{
    QWidget::mousePressEvent(event);
    Punto P1 (event->pos().x(),event->pos().y());
    P1.valor = listaPuntos.size()+1;
    listaPuntos.push_front (P1);
        
    std::cout << "Punto '" << listaPuntos.size() << "' guardado en (" << (event->pos().x()) << ","<< (event->pos().y())<< ")"<< '\n';
}

void Puff_and_Mouse::paintEvent(QPaintEvent *e) {
  Q_UNUSED(e);  
  doPainting();
}

void Puff_and_Mouse::doPainting() {
    QPainter painter(this);

    painter.setBackgroundMode(Qt::OpaqueMode);

    h = height();
    w = width();

    QPen pen = painter.pen();
    pen.setWidth(3.5);
    painter.setPen(pen);

    QFont font;
    font.setPointSize(9);
    painter.setFont(font);

    for (Punto punto : listaPuntos) {
        int centerX = punto.getX() - anchoC / 2;
        int centerY = punto.getY() - altoC / 2;

        painter.drawEllipse(centerX, centerY, anchoC, altoC);

	QString valor = QString::fromStdString(std::to_string(punto.valor));
        painter.drawText(punto.getX()-6, punto.getY()+4, valor);
    }

    dibujarFlecha(puntoOrigen.getX(), puntoOrigen.getY(), puntoDestino.getX(), puntoDestino.getY());
}

void Puff_and_Mouse::timerEvent(QTimerEvent *e) {
    Q_UNUSED(e);
    repaint();
}


void Puff_and_Mouse::crearArista(int puntoA, int puntoB) {
	if(puntoA <= 0 or puntoA > listaPuntos.size() or puntoB <= 0 or puntoB > listaPuntos.size()) {
		std::cout << "Valor(es) invalidos" << std::endl;
		return;
	}
	
        auto itA = listaPuntos.end();
        std::advance(itA, -puntoA);

        Punto puntoOrigen = *itA;

        std::cout << "Punto A (valor ingresado: " << puntoA << ") existe en: " << puntoOrigen.getX() << " , " << puntoOrigen.getY() << std::endl;
        
        auto itB = listaPuntos.end();
        std::advance(itB, -puntoB);

        Punto puntoDestino = *itB;

        std::cout << "Punto B (valor ingresado: " << puntoB << ") existe en: " << puntoDestino.getX() << " , " << puntoDestino.getY() << std::endl;
        
}

void Puff_and_Mouse::dibujarFlecha(int x1, int y1, int x2, int y2) {
    QPainter painter(this);

    QPen pen = painter.pen();
    pen.setWidth(2.5);
    painter.setPen(pen);

    // Dibujar línea desde el punto A al punto B
    painter.drawLine(x1, y1, x2, y2);

    // Calcular ángulo de la flecha
    double angle = atan2(y2 - y1, x2 - x1);
    int arrowSize = 10;

    // Calcular las coordenadas de la cabeza de la flecha
    QPointF arrowP1 = QPointF(x2 - arrowSize * cos(angle + M_PI / 6), y2 - arrowSize * sin(angle + M_PI / 6));
    QPointF arrowP2 = QPointF(x2 - arrowSize * cos(angle - M_PI / 6), y2 - arrowSize * sin(angle - M_PI / 6));

    // Dibujar cabeza de flecha
    painter.drawLine(QLineF(QPointF(x2, y2), arrowP1));
    painter.drawLine(QLineF(QPointF(x2, y2), arrowP2));
}

