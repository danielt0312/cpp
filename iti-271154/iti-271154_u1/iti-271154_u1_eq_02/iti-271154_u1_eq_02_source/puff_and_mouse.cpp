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
    int valorGrafo = listaGrafos.size()+1;
    Graph grafo(event->pos().x(),event->pos().y(), valorGrafo);
    listaGrafos.push_front(grafo);
        
    std::cout << "Graph '" << listaGrafos.size() << "' guardado en (" << (event->pos().x()) << ","<< (event->pos().y())<< ")"<< '\n';
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

    for (Graph grafo : listaGrafos) {
        dibujarArista(painter, grafo);
        
        int centerX = grafo.getContent().getX() - anchoC / 2;
        int centerY = grafo.getContent().getY() - altoC / 2;

        painter.drawEllipse(centerX, centerY, anchoC, altoC);

	QString valor = QString::fromStdString(std::to_string(grafo.getContent().getValor()));
        painter.drawText(grafo.getContent().getX()-6, grafo.getContent().getY()+4, valor);
    }
}

void Puff_and_Mouse::timerEvent(QTimerEvent *e) {
    Q_UNUSED(e);
    repaint();
}


void Puff_and_Mouse::addEdge(int i, int j) {
	if(i <= 0 or i > listaGrafos.size() or j <= 0 or j > listaGrafos.size() or i == j) {
		std::cout << "Valor(es) invalidos" << std::endl;
		return;
	}
	
        auto itA = listaGrafos.end();
        std::advance(itA, -i);

        Graph puntoOrigen = *itA;

        std::cout << "Grafo i (valor ingresado: " << i << ") existe en: " << puntoOrigen.getContent().getX() << " , " << puntoOrigen.getContent().getY() << std::endl;
        
        auto itB = listaGrafos.end();
        std::advance(itB, -j);

        Graph puntoDestino = *itB;

        std::cout << "Grafo j (valor ingresado: " << j << ") existe en: " << puntoDestino.getContent().getX() << " , " << puntoDestino.getContent().getY() << std::endl;
        
        for(Node nodo : *(puntoOrigen.vertices)) {
        	if(nodo == puntoDestino.getContent()){
        		std::cout << "Relación previamente ya creada: i( " << nodo.getValor() << ") j(" << puntoDestino.getContent().getValor() << ")" << std::endl;
        		return;
        	}
        }
        
        puntoOrigen.vertices->push_front(puntoDestino.getContent());
        std::cout << puntoOrigen.vertices->size() << std::endl;
        
        for(Node nodo : *(puntoOrigen.vertices)) {
        	std::cout << "X: " << nodo.getX() << " Y: " << nodo.getY() << " V: " << nodo.getValor() << std::endl;
        }
}

void Puff_and_Mouse::dibujarArista(QPainter &painter, Graph &grafo) {
	for(Node nodoDestino : *(grafo.vertices)) {
		std::cout << "Origen (" << grafo.getContent().getX() << " , " << grafo.getContent().getY()  << ")" << std::endl;
		if(grafo.getContent().getY() >= nodoDestino.getY())
			dibujarFlecha(painter, grafo.getContent().getX(), grafo.getContent().getY()+20, nodoDestino.getX(), nodoDestino.getY()+20);
		else
			dibujarFlecha(painter, grafo.getContent().getX(), grafo.getContent().getY()-20, nodoDestino.getX(), nodoDestino.getY()-20);
	}
}

void Puff_and_Mouse::dibujarFlecha(QPainter &painter, int x1, int y1, int x2, int y2) {
	QPen pen = painter.pen();
	pen.setWidth(2.5);
	painter.setPen(pen);

	painter.drawLine(x1, y1, x2, y2);

	// angulo de la flecha
	double angle = atan2(y2 - y1, x2 - x1);
	int arrowSize = 10;

	// coordenadas de la cabeza de la flecha
	QPointF arrowP1 = QPointF(x2 - arrowSize * cos(angle + M_PI / 6), y2 - arrowSize * sin(angle + M_PI / 6));
	QPointF arrowP2 = QPointF(x2 - arrowSize * cos(angle - M_PI / 6), y2 - arrowSize * sin(angle - M_PI / 6));

	// cabeza de flecha
	painter.drawLine(QLineF(QPointF(x2, y2), arrowP1));
	painter.drawLine(QLineF(QPointF(x2, y2), arrowP2));
}

