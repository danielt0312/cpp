#include <QPainter>
#include <QTimer>
#include <QColor>
#include <QTextStream>
#include <QtWidgets>
#include <QTimer>
#include <QDialog>
#include <QTableWidget>

#include <iostream>
#include <thread>
#include <cmath>
#include <chrono>

#include <string>
#include <queue>
#include "Automata.h"

using namespace std;

Automata::Automata(QWidget *parent)
    : QWidget(parent) {
    
    x = 1;
    timerId = startTimer(10);

    h = height();
    w = width();

    // Diametro
    altoC = anchoC = 40;
}

// Cuando se presiona
void Automata::mousePressEvent(QMouseEvent* event)
{
    QWidget::mousePressEvent(event);
    if(opcion == 1) {
	    Node nodo(event->pos().x(),event->pos().y(), estados.size());
	    estados.push_back(nodo);
		
	    std::cout << "'q" << nodo.getValor() << "' guardado en (" << (event->pos().x()) << ","<< (event->pos().y())<< ")"<< std::endl;
    }
    
    if(opcion == 2) {
    std::cout << "in" << std::endl;
    	ix = event->pos().x();
    	iy = event->pos().y();
    }
}

// Cuando se mueve
void Automata::mouseMoveEvent(QMouseEvent* event)
{
    QWidget::mousePressEvent(event);
    //std::cout << "Mouse Move ("<<event->pos().x() << ","<< event->pos().y()<< ")"<< '\n';
    
    if(opcion == 2) {
    	fx = event->pos().x();
    	fy = event->pos().y();
    }
}

// Cuando se suelta
void Automata::mouseReleaseEvent(QMouseEvent* event)
{
    QWidget::mousePressEvent(event);
    //std::cout << "Mouse Release ("<<event->pos().x() << ","<< event->pos().y()<< ")"<< '\n';
    if(opcion == 2) {
    	addTransition(ix, iy, fx, fy);
    	reiniciarIF();
    	//std::cout << ix << ", " << iy << ", " << fx << ", " << fy << std::endl;
    }
}

void Automata::timerEvent(QTimerEvent *e) {
    Q_UNUSED(e);
    repaint();
}

void Automata::paintEvent(QPaintEvent *e) {
    Q_UNUSED(e);
    doPainting();
}

// Función para limpiar los vértices
void Automata::limpiar() { estados.clear(); std::cout << "Grafo limpiado" << std::endl; }

// Dibujar Grafo
void Automata::doPainting() {
    QPainter painter(this);
    painter.setBackgroundMode(Qt::OpaqueMode);

    h = height();
    w = width();

    QPen pen = painter.pen();
    pen.setWidth(3.5);
    painter.setPen(pen);

    QFont font;
    font.setPointSize(9);
    font.setWeight(QFont::Bold);
    painter.setFont(font);
    
    if(opcion == 2 && ix != -1 && iy != -1 && fx != -1 && fy != -1) {
    	painter.drawLine(ix, iy, fx, fy);
    }
    
    // Primero dibujamos las transiciones por debajo de los nodos
    for (Node nodo : estados)
        dibujarArista(painter, nodo);
    
    // Dibujado de nodos
    for (Node nodo : estados) {
        int centerX = nodo.getX() - anchoC / 2;
        int centerY = nodo.getY() - altoC / 2;
                
        painter.setBackground(nodo.color);
        painter.setBrush(nodo.color);
        painter.drawEllipse(centerX, centerY, anchoC, altoC);
        
        QString valor = "q" + QString::number(nodo.getValor());
        if(nodo.getValor() > 9) painter.drawText(nodo.getX()-10, nodo.getY()+4, valor);
        else painter.drawText(nodo.getX()-7, nodo.getY()+4, valor);
    }
}

// dibujos de las transiciones de la lista de nodos
void Automata::dibujarArista(QPainter &painter, Node &nodo) {
    for(Node* nodoDestino : nodo.transiciones){
    	if(nodo.getX() == nodoDestino->getX() && nodo.getY() == nodoDestino->getY()) {
            // Crear el trazado de la curva bezier
            QPainterPath bezierPath;
            bezierPath.moveTo(nodo.getX() + 10, nodo.getY() + 10); // Punto inicial
            QPointF controlPoint1(nodo.getX() + 50, nodo.getY() + 50); // Punto de control 1
            QPointF controlPoint2(nodo.getX() - 50, nodo.getY() + 50); // Punto de control 2
            QPointF endPoint(nodo.getX() - 10, nodo.getY() - 10); // Punto final
            bezierPath.cubicTo(controlPoint1, controlPoint2, endPoint); // Agregar la curva bezier al trazado

            // Dibujar la curva bezier
            painter.drawPath(bezierPath);
	    continue;
    	}
    	painter.drawLine(nodo.getX(), nodo.getY(), nodoDestino->getX(), nodoDestino->getY());
    	std::cout << nodo.getX() << ", " << nodo.getY() << ", " << nodoDestino->getX() << ", " << nodoDestino->getY() << std::endl;
    }
}

// Buscar estado
void Automata::addTransition(int ix, int iy, int fx, int fy) {
    // Buscar nodo inicio y final
    for (Node& nodoA : estados) {
    	// Aunque el radio sea de 20, dar una tolerancia de 10 puntos
    	// Ambos son el mismo
    	if (std::abs(nodoA.getX() - ix) <= 30 && std::abs(nodoA.getY() - iy) <= 30 && std::abs(nodoA.getX() - fx) <= 30 && std::abs(nodoA.getY() - fy) <= 30 ) {
    	     	std::cout << "ambos son el mismo" << std::endl;
    	     	nodoA.transiciones.push_back(&nodoA);
    	     	break;

    	// Ambos son diferentes
    	} else if ((std::abs(nodoA.getX() - ix) <= 30 && std::abs(nodoA.getY() - iy) <= 30) || (std::abs(nodoA.getX() - fx) <= 30 && std::abs(nodoA.getY() - fy) <= 30)) {
    	 	for (Node& nodoB : estados) {
    	 		std::cout << "size: " << estados.size() << std::endl;
    	     		if(nodoA == nodoB) {
    	     			std::cout << nodoA.getValor() << " - " << nodoB.getValor() << std::endl;
    	     			continue;
    	     		}
    	     		if((std::abs(nodoB.getX() - ix) <= 30 && std::abs(nodoB.getY() - iy) <= 30) || (std::abs(nodoB.getX() - fx) <= 30 && std::abs(nodoB.getY() - fy) <= 30)) {
    	     			nodoA.transiciones.push_back(&nodoB);
    	     			std::cout << "'q" << nodoA.getValor() << "' -> 'q" << nodoB.getValor() << "'" << std::endl;
    	     		}
    	     	}
    	}
    }
    
    opcion = 1;
    std::cout << "Modo: Agregar Automata" << std::endl;
}


// Establecer colores en estado base (blanco)
void Automata::limpiarColores() {
    for (Node& nodo : estados) {
    	nodo.color = Qt::white;
    }
}

// Para reiniciar la flecha que se genera al agregar una transicion
void Automata::reiniciarIF() {
	ix = -1;
    	iy = -1;
    	fx = -1;
    	fy = -1;
}

