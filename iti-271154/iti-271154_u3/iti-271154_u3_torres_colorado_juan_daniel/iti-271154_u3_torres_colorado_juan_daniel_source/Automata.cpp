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

Automata::Automata(QWidget *parent) : QWidget(parent) {
    x = 1;
    timerId = startTimer(10);

    h = height();
    w = width();

    // Diametro
    altoC = anchoC = 40;
}

// Cuando se presiona
void Automata::mousePressEvent(QMouseEvent* event) {
    QWidget::mousePressEvent(event);
    if(opcion == 1) {
	//std::cout << "ini: " << inix << ", " << iniy << "   fin: " << finx << ", " << finy << std::endl;
	    Node nodo(event->pos().x(),event->pos().y(), estados.size());
	    estados.push_back(nodo);
		
	    std::cout << "'q" << nodo.getValor() << "' guardado en (" << (event->pos().x()) << ","<< (event->pos().y())<< ")"<< std::endl;
    }
    
    if(opcion == 2) {
    	inix = event->pos().x();
    	iniy = event->pos().y();
    }
}

// Cuando se mueve
void Automata::mouseMoveEvent(QMouseEvent* event) {
    QWidget::mousePressEvent(event);
    //std::cout << "Mouse Move ("<<event->pos().x() << ","<< event->pos().y()<< ")"<< '\n';
    
    if(opcion == 2) {
    	finx = event->pos().x();
    	finy = event->pos().y();
    }
}

// Cuando se suelta
void Automata::mouseReleaseEvent(QMouseEvent* event) {
    QWidget::mousePressEvent(event);
    //std::cout << "Mouse Release ("<<event->pos().x() << ","<< event->pos().y()<< ")"<< '\n';
    if(opcion == 2) {
    	addTransition(inix, iniy, finx, finy);
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
    
    if(opcion == 2 && inix != -1 && iniy != -1 && finx != -1 && finy != -1) {
    	painter.drawLine(inix, iniy, finx, finy);
    }
    
    // Primero dibujamos las transiciones por debajo de los nodos
    for (Node nodo : estados)
        dibujarTransicion(painter, nodo);
    
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
void Automata::dibujarTransicion(QPainter &painter, Node &nodo) {
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
    	
	if (nodo.getY() >= nodoDestino->getY()) dibujarFlecha(painter, nodo.getX(), nodo.getY()-20, nodoDestino->getX(), nodoDestino->getY()-20);
	else dibujarFlecha(painter, nodo.getX(), nodo.getY()+20, nodoDestino->getX(), nodoDestino->getY()+20);
    }
}

// Dibujar cabeza de flecha
void Automata::dibujarFlecha(QPainter &painter, int x1, int y1, int x2, int y2) {
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

// Buscar estado
void Automata::addTransition(int ix, int iy, int fx, int fy) {
	// No hay estados
	if (estados.size() == 0) {
		std::cout << "No hay nigún estado en el autómata" << std::endl;
		return;
	}

	// Variable para validar si el origen y el destino se encontró
	int validate = 0;
    	
	for (Node& A : estados) {
	    	// Aunque el radio sea de 20, dar una tolerancia de 10 puntos más
	    	// Ambos son el mismo
	    	if (std::abs(A.getX() - ix) <= 30 && std::abs(A.getY() - iy) <= 30 && std::abs(A.getX() - fx) <= 30 && std::abs(A.getY() - fy) <= 30) {
	    	     	std::cout << "(EQ) 'q" << A.getValor() << "' -> 'q" << A.getValor() << "'" << std::endl;
	    	     	A.transiciones.push_back(&A);
	    	     	validate = 2;
	    	     	break;

	    	// Ambos son diferentes pero A es el Origen
	    	} else if (std::abs(A.getX() - ix) <= 30 && std::abs(A.getY() - iy) <= 30) {
	    		++validate;
	    	 	for (Node& B : estados) {
	    	     		if (std::abs(B.getX() - fx) <= 30 && std::abs(B.getY() - fy) <= 30) {
					std::cout << "'q" << A.getValor() << "' -> 'q" << B.getValor() << "'" << std::endl;
	    	     			A.transiciones.push_back(&B);
					++validate;
	    	     			break;
	    	     		}
	    	     	}
	    	     	
	    	     	break;
	    	     	
	    	// Ambos son diferentes pero A es el Destino
	    	} else if (std::abs(A.getX() - fx) <= 30 && std::abs(A.getY() - fy) <= 30) {
	    		++validate;
	    		
	    		for (Node& B : estados) {
	    	     		if(std::abs(B.getX() - ix) <= 30 && std::abs(B.getY() - iy) <= 30) {
					std::cout << "'q" << B.getValor() << "' -> 'q" << A.getValor() << "'" << std::endl;
	    	     			B.transiciones.push_back(&A);
					++validate;
	    	     			break;
	    	     		}
	    	     	}
	    		
	    		break;
		}
	}
	
	if (validate != 2) std::cout << "No se encontró el estado de origen/destino" << std::endl;

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
	inix = -1;
    	iniy = -1;
    	finx = -1;
    	finy = -1;
}

