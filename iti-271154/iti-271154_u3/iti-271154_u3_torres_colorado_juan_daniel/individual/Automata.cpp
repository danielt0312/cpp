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
#include <list>
#include "Automata.h"
#include "CustomInputDialog.h"

using namespace std;

Automata::Automata(QWidget *parent) : QWidget(parent) {
    x = 1;
    timerId = startTimer(10);
    
    // estado inicial por predeterminado

    h = height();
    w = width();

    // Diametro
    altoC = anchoC = 40;
}

// Cuando se presiona
void Automata::mousePressEvent(QMouseEvent* event) {
    QWidget::mousePressEvent(event);
	inix = event->pos().x();
	iniy = event->pos().y();
    
    if (opcion == 1) {
	//std::cout << "ini: " << inix << ", " << iniy << "   fin: " << finx << ", " << finy << std::endl;
	    Node nodo(inix, iniy, estados.size());
	    estados.push_back(nodo);
		
	    std::cout << "'q" << nodo.getValor() << "' guardado en (" << nodo.getX() << ","<< nodo.getY() << ")"<< std::endl;
	    emit emitResult(1);
    }
    
    if (opcion == 3) {    
    	selectFinalState();	
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
    }
}

// Temporizador
void Automata::timerEvent(QTimerEvent *e) {
    Q_UNUSED(e);
    repaint();
}

// Para pintar
void Automata::paintEvent(QPaintEvent *e) {
    Q_UNUSED(e);
    doPainting();
}

// Función para eliminar los estados
void Automata::limpiar() {
	estados.clear();
	inicial->transiciones.clear();
	inicial->finalState = false;
	std::cout << "Estados limpiados" << std::endl;
}

// Dibujar Grafo
void Automata::doPainting() {
	// instancia para poder pintar
    QPainter painter(this);
    painter.setBackgroundMode(Qt::OpaqueMode);

	// Configuración para dibujar
    QPen pen = painter.pen();
    pen.setWidth(2);
    painter.setPen(pen);

	// Configuración de fuente
    QFont font;
    font.setPointSize(9);
    font.setWeight(QFont::Bold);
    painter.setFont(font);
 	
 	// dibujar transiciones por debajo de los estados
	// transiciones del estado inicial
    dibujarTransicion(painter, *inicial);
    
    // transiciones de los estados
    for (Node nodo : estados)
        dibujarTransicion(painter, nodo);
     
    // Dibujado de estado inicial
    dibujarEstado(painter, *inicial);
    
    
    // Dibujado de estados restantes
    for (Node nodo : estados) 
    	dibujarEstado(painter, nodo);
    
    // dibujar linea que se usa para hacer una transicion
    if(opcion == 2 && inix != -1 && iniy != -1 && finx != -1 && finy != -1)
    	painter.drawLine(inix, iniy, finx, finy);
}

// dibujado de nodo individual
void Automata::dibujarEstado(QPainter& painter, Node& nodo) {
	// ubicar circulo en el centro del estado
	int centerX = nodo.getX() - anchoC / 2;
	int centerY = nodo.getY() - altoC / 2;

	// configuración para pintar
	painter.setBackground(nodo.color);
	painter.setBrush(nodo.color);
	painter.drawEllipse(centerX, centerY, anchoC, altoC);

	// contenido de estado
	QString valor;
	int txtCenterX = 0;
	int txtCenterY = nodo.getY() + 4;
	// en caso de ser el estado inicial
	if(nodo.getValor() == -404) { 
		valor = "start";
		txtCenterX = nodo.getX() - 14;
	} else {
		valor = "q" + QString::number(nodo.getValor());
		
		if (nodo.getValor() > 9) txtCenterX = nodo.getX() - 10;
		else txtCenterX = nodo.getX()-7;
	}
	
	painter.drawText(txtCenterX, txtCenterY, valor);
	// en caso de ser estado final, dibujar diferencia
	if(nodo.finalState) {
		painter.save(); // guardar estado del pincel
		painter.setBrush(Qt::transparent);
		painter.drawEllipse(centerX+5, centerY+5, anchoC-10, altoC-10);
		painter.restore(); // restaurar estado del pincel
	}
}

// dibujos de las transiciones de la lista de nodos
void Automata::dibujarTransicion(QPainter &painter, Node &nodo) {
    int indice = 0;
    for(Node* nodoDestino : nodo.transiciones) {
    	// indice se suma despues de enviar
    	dibujarFlecha(painter, nodo, *nodoDestino, indice++);
    }
}

// Dibujar cabeza de flecha
void Automata::dibujarFlecha(QPainter &painter, Node& ori, Node& des, int indice) {
    QPen pen = painter.pen();
    pen.setWidth(2.5);
    painter.setPen(pen);
    
    // dibujar un trazo de flecha especial en caso de que se apunte a sí mismo
    if(ori == des) {
    	pointItSelf(painter, ori, indice);
    	return;
    }	
    
    // dibujo de segmento (linea)
    painter.drawLine(ori.getX(), ori.getY(), des.getX(), des.getY());
    
    // contenido de la transicion
    QString valor = QString(QString::fromStdString(ori.input[indice])) + ", " + QString(QString::fromStdString(ori.pop[indice])) + ", " + QString(QString::fromStdString(ori.push[indice]));
    
    int mediaX = (ori.getX() + des.getX()) / 2;
    int mediaY = (ori.getY() + des.getY()) / 2;
    
    qreal arrowSize = 12;
    QPoint start = QPoint(ori.getX(), ori.getY());
    QPoint end = QPoint(des.getX(), des.getY());

    // distancia entre los estados
    double dx = end.x() - start.x();
    double dy = end.y() - start.y();
    double distance = sqrt(dx * dx + dy * dy);

    // Mover el punto final hacia el centro del otro círculo
    end.setX(end.x() - int((dx / distance) * anchoC / 2));
    end.setY(end.y() - int((dy / distance) * anchoC / 2));
    
    QLineF line(end, start);

    double angle = atan2(-line.dy(), line.dx());
    
    // cabeza de la flecha
    QPointF arrowP1 = line.p1() + QPointF(sin(angle + M_PI / 3) * arrowSize, cos(angle + M_PI / 3) * arrowSize);
    QPointF arrowP2 = line.p1() + QPointF(sin(angle + M_PI - M_PI / 3) * arrowSize, cos(angle + M_PI - M_PI / 3) * arrowSize);

    // dibujo de flecha
    painter.setBrush(Qt::black);
    QPolygonF arrowHead;
    arrowHead.clear();
    arrowHead << line.p1() << arrowP1 << arrowP2;
    painter.drawPolygon(arrowHead);
    
    // volver estado normal
    painter.setBrush(Qt::NoBrush);
    painter.drawPolygon(arrowHead);
    
    // dibujar caracteres de la transicion
    painter.drawText(mediaX-20, mediaY, valor);
}

// dibujar flecha que se apunta a sí mismo
void Automata::pointItSelf(QPainter& painter, Node& nodo, int indice) {
	// trazado de la curva de bezier
	QPainterPath bezierPath;
	bezierPath.moveTo(nodo.getX() + 10, nodo.getY() + 10); // Punto inicial
	QPointF controlPoint1(nodo.getX() + 50, nodo.getY() + 50); // Punto de control 1
	QPointF controlPoint2(nodo.getX() - 50, nodo.getY() + 50); // Punto de control 2
	QPointF endPoint(nodo.getX() - 10, nodo.getY() - 10); // Punto final
	bezierPath.cubicTo(controlPoint1, controlPoint2, endPoint); // Agregar la curva bezier al trazado

	// dibujado de la curva de bezier
	painter.drawPath(bezierPath);
	
	// imprimir caracteres
	QString valor = QString(QString::fromStdString(nodo.input[indice])) + ", " + QString(QString::fromStdString(nodo.pop[indice])) + ", " + QString(QString::fromStdString(nodo.push[indice]));
	painter.drawText(nodo.getX(), nodo.getY()+30, valor);
}

// Buscar estado
void Automata::addTransition(int ix, int iy, int fx, int fy) {
	// Variable para validar si el origen y el destino se encontró
	int validate = 0;
	/*
	std::cout << inicial->getX() << ", " << inicial->getY() << std::endl;
	std::cout << ix << ", " << iy << "\t\t" << fx << " " << fy << std::endl;
	std::cout << std::abs(inicial->getX() - ix) << ", " << std::abs(inicial->getY() - iy) << std::endl;
	std::cout << std::abs(inicial->getX() - fx) << ", " << std::abs(inicial->getY() - fy) << std::endl;*/
	
	// el estado inicial es origen y se apunta a sí mismo
   	if (std::abs(inicial->getX() - ix) <= 30 && std::abs(inicial->getY() - iy) <= 30 && std::abs(inicial->getX() - fx) <= 30 && std::abs(inicial->getY() - fy) <= 30) {
   		std::cout << "'start' -> 'start'" << std::endl;
   		setCharTransition(*inicial, *inicial);
   		validate = 2;
   		
   	// el estado inicial es origen
   	} else if(std::abs(inicial->getX() - ix) <= 30 && std::abs(inicial->getY() - iy) <= 30) {
   		++validate;
   		for (Node& A : estados) {
	 		if (std::abs(A.getX() - fx) <= 30 && std::abs(A.getY() - fy) <= 30) {
		 		std::cout << "'start' -> 'q" << A.getValor() << "'" << std::endl;
	 			setCharTransition(*inicial, A);
				++validate;
	 			break;
	 		}
	 	}
	 	
	// el estado inicial es el destino
	} else if(std::abs(inicial->getX() - fx) <= 30 && std::abs(inicial->getY() - fy) <= 30) {
		++validate;
   		for (Node& A : estados) {
	 		if (std::abs(A.getX() - ix) <= 30 && std::abs(A.getY() - iy) <= 30) {
		 		std::cout << "'q" << A.getValor() << "' -> 'start" << std::endl;
	 			setCharTransition(A, *inicial);
				++validate;
	 			break;
	 		}
	 	}
   	
   	// no es el estado inicial
   	} else {
		for (Node& A : estados) {
			// Aunque el radio sea de 20, dar una tolerancia de 10 puntos más
			// Ambos son el mismo
			if (std::abs(A.getX() - ix) <= 30 && std::abs(A.getY() - iy) <= 30 && std::abs(A.getX() - fx) <= 30 && std::abs(A.getY() - fy) <= 30) {
			 	std::cout << "(EQ) 'q" << A.getValor() << "' -> 'q" << A.getValor() << "'" << std::endl;
			 	setCharTransition(A, A);
			 	validate = 2;
			 	break;

			// Ambos son diferentes pero A es el Origen
			} else if (std::abs(A.getX() - ix) <= 30 && std::abs(A.getY() - iy) <= 30) {
				++validate;
			 	for (Node& B : estados) {
			 		if (std::abs(B.getX() - fx) <= 30 && std::abs(B.getY() - fy) <= 30) {
						std::cout << "'q" << A.getValor() << "' -> 'q" << B.getValor() << "'" << std::endl;
			 			setCharTransition(A, B);
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
			 			setCharTransition(B, A);
						++validate;
			 			break;
			 		}
			 	}
				
				break;
			}
		}
	}
	
	if (validate != 2) { 
		std::cout << "No se encontró el estado de origen/destino" << std::endl;
		emit emitResult(-2);
	}
}

// Establecer los caracteres de la transicion
void Automata::setCharTransition(Node& ori, Node& des) {
    // Desplegar dialog 
    CustomInputDialog dialog(this);
    if (dialog.exec() == QDialog::Accepted) {
        QStringList inputs = dialog.getInputs();
        
        // entrada, eliminar y agregar
        ori.input.push_back(toString(inputs[0]));
        ori.pop.push_back(toString(inputs[1]));
        ori.push.push_back(toString(inputs[2]));
        
        ori.transiciones.push_back(&des);
        
        std::cout << "Input: '" << ori.input.back() << "'\nEliminar: '" << ori.pop.back() << "'\nAgregar: '" << ori.push.back() << "'" << std::endl;
        emit emitResult(2);
    } else {
    	emit emitResult(22);
    }
}

// Conversion de QString a string - char
std::string Automata::toString(QString& word) {
	if(word.isEmpty() || word.at(0).isSpace()) return "\u03B5"; // ϵ
	return word.toStdString();
}

void Automata::selectFinalState() {
	// estado inicial también es el final
	if (std::abs(inicial->getX() - inix) <= 30 && std::abs(inicial->getY() - iniy) <= 30) {
		inicial->finalState = !inicial->finalState;
		emit emitResult(3);
		return;
	}
	else {
		for (Node& A : estados) {
	 		if(std::abs(A.getX() - inix) <= 30 && std::abs(A.getY() - iniy) <= 30) {
				std::cout << "'q" << A.getValor() << " como estado final" << std::endl;
				A.finalState = !A.finalState;
				emit emitResult(3);
	 			return;
	 		}
	 	}
	}
	
	std::cout << "Estado no encontrado" << std::endl;
	emit emitResult(-3);
	reiniciarIF();
}

// Establecer colores en estado base (blanco)
void Automata::limpiarColores() {
    for (Node& nodo : estados)
    	nodo.color = Qt::white;
}

// Para reiniciar la flecha que se genera al agregar una transicion
void Automata::reiniciarIF() {
	inix = -1;
	iniy = -1;
	finx = -1;
	finy = -1;
}


// Algoritmo para PDA
void Automata::PDA(QString input) {
	// palabra ingresada
	std::string word = toString(input);
	std::cout << "Input: " <<  word << std::endl;
	
	// lista de caracteres de la cadena
	list<std::string> cadena;
	for (char letra : word) {
	    std::string caracter(1, letra); 
		cadena.push_back(caracter);
	}
	
	// lista para la realizacion del algoritmo
	list<std::string> cola;
	
	navigate(*inicial, cadena, cola);
}

// Transiciones de estados
void Automata::navigate(Node& estado, list<std::string>& cadena, list<std::string>& cola) {
	std::cout << "\n'q" << estado.getValor() << "' IN" << std::endl;
	
	std::string palabra = "";
	for (std::string l : cadena) {
		palabra = palabra + " " + l;
	}
	std::cout << "Cadena: " << palabra << std::endl;
	
	palabra = "";
	for (std::string l : cola) {
		palabra = palabra + " " + l;
	}
	std::cout << "Cola: " << palabra << std::endl;
	
	// validar que siga habiendo una cadena por leer
	if (cadena.size() == 0) {
		if (cola.size() == 0) {
			if (estado.finalState) { 
				std::cout << "Aprobado" << std::endl;
				emit emitResult(4);
			}
			else { 
				std::cout << "Rechazado" << std::endl;
				emit emitResult(-4);
			}
		} else if (estado.transiciones.size() != 0) {
			// Ir en transiciones
			for (std::deque<Node*>::size_type i = 0; i < estado.transiciones.size(); i++) {
				if (estado.input[i] == "\u03B5") {
					if (estado.pop[i] == cadena.front()) {
						if (estado.push[i] != "\u03B5") {
							cadena.push_front(estado.push[i]);
						}
						navigate(*estado.transiciones[i], cadena, cola);
					} 
				}
			}
			std::cout << "Rechazado" << std::endl;
			emit emitResult(-4);
		} else {
			std::cout << "Rechazado" << std::endl;
			emit emitResult(-4);
		}
	}

	// Ir en transiciones
	for (std::deque<Node*>::size_type i = 0; i < estado.transiciones.size(); i++) {
		// diferente de 'ϵ' como lectura (input)
		// 'X,,'
		if (estado.input[i] != "\u03B5") {
			// Verificar que la lectura sea igual al primer caracter de la cadena
			if (estado.input[i] != cadena.front()) continue;
			// 'X,Y,'
			if (estado.pop[i] != "\u03B5") {
				// validar que el (pop) coincida con lo que hay en el top de la cola
				if (estado.pop[i] != cola.front()) continue;
				
				// eliminar caracter de la lista cadena
				cadena.pop_front();
				
				// eliminar lo que haya en la cola
				cola.pop_front();
				
				// verificar si debemos agregar un elemento de (push)
				// 'X,Y,Z'
				if (estado.push[i] != "\u03B5") {
					cola.push_front(estado.push[i]);	
				}
				
				std::cout << "'q" << estado.getValor() << "' -- " << estado.input[i] << ", " << estado.pop[i] << ", " << estado.push[i] << " --> 'q" << estado.transiciones[i]->getValor() << "'" << std::endl;
				// se puede visitar
				navigate(*estado.transiciones[i], cadena, cola);
			} else {
				cadena.pop_front();
				std::cout << "'X,ϵ,Z'" << std::endl;
				// verificar si debemos agregar un elemento de (push)
				// 'X,ϵ,Z'
				if (estado.push[i] != "\u03B5") {
					cola.push_front(estado.push[i]);	
				}
				
				std::cout << "'q" << estado.getValor() << "' -- " << estado.input[i] << ", " << estado.pop[i] << ", " << estado.push[i] << " --> 'q" << estado.transiciones[i]->getValor() << "'" << std::endl;
				// se puede visitar
				navigate(*estado.transiciones[i], cadena, cola);
			}
			
			
		// 'ϵ' como lectura (input)
		// 'ϵ,,'
		} else {
			// 'ϵ,Y,'
			if (estado.pop[i] != "\u03B5") {
				// validar que el (pop) coincida con lo que hay en el top de la cola
				if (estado.pop[i] != cola.front()) continue;
				// eliminar lo que haya en la cola
				cola.pop_front();
				
				// verificar si debemos agregar un elemento de (push)
				// 'ϵ,Y,Z'
				if (estado.push[i] != "\u03B5") {
					cola.push_front(estado.push[i]);	
				}
				
				std::cout << "'q" << estado.getValor() << "' -- " << estado.input[i] << ", " << estado.pop[i] << ", " << estado.push[i] << " --> 'q" << estado.transiciones[i]->getValor() << "'" << std::endl;
				// se puede visitar	
				navigate(*estado.transiciones[i], cadena, cola);
			} else {
				// verificar si debemos agregar un elemento de (push)
				// 'ϵ,ϵ,Z'
				if (estado.push[i] != "\u03B5") {
					cola.push_front(estado.push[i]);	
				}
				
				std::cout << "'q" << estado.getValor() << "' -- " << estado.input[i] << ", " << estado.pop[i] << ", " << estado.push[i] << " --> 'q" << estado.transiciones[i]->getValor() << "'" << std::endl;
				// se puede visitar
				navigate(*estado.transiciones[i], cadena, cola);
			}
		}
	}
	
	std::cout << "'q" << estado.getValor() << "' OUT" << std::endl;
}

// Ejemplo predeterminado
void Automata::mostrarEjemplo() {
	limpiar();
	Node* q0 = new Node(180, 380, 0);
	Node* q1 = new Node(220, 240, 1);
	Node* q2 = new Node(260, 520, 2);
	Node* q3 = new Node(460, 280, 3);
	Node* q4 = new Node(470, 470, 4);
	
	q0->finalState = true;
	q0->transiciones.push_back(q1);
    q0->input.push_back("A");
    q0->pop.push_back("\u03B5");
    q0->push.push_back("A");
    
    q0->transiciones.push_back(q2);
    q0->input.push_back("B");
    q0->pop.push_back("\u03B5");
    q0->push.push_back("B");
    
    q1->transiciones.push_back(q1);
    q1->input.push_back("A");
    q1->pop.push_back("\u03B5");
    q1->push.push_back("A");

    q1->transiciones.push_back(q3);
    q1->input.push_back("B");
    q1->pop.push_back("A");
    q1->push.push_back("\u03B5");
    
    q3->transiciones.push_back(q1);
    q3->input.push_back("A");
    q3->pop.push_back("\u03B5");
    q3->push.push_back("A");
    
    q3->transiciones.push_back(q0);
    q3->input.push_back("\u03B5");
    q3->pop.push_back("#");
    q3->push.push_back("\u03B5");
    
    q3->transiciones.push_back(q3);
    q3->input.push_back("B");
    q3->pop.push_back("A");
    q3->push.push_back("\u03B5");
    
    q2->transiciones.push_back(q2);
    q2->input.push_back("B");
    q2->pop.push_back("\u03B5");
    q2->push.push_back("B");

    q2->transiciones.push_back(q4);
    q2->input.push_back("A");
    q2->pop.push_back("B");
    q2->push.push_back("\u03B5");
    
    q4->transiciones.push_back(q2);
    q4->input.push_back("B");
    q4->pop.push_back("\u03B5");
    q4->push.push_back("B");
    
    q4->transiciones.push_back(q0);
    q4->input.push_back("\u03B5");
    q4->pop.push_back("#");
    q4->push.push_back("#");
    
    q4->transiciones.push_back(q4);
    q4->input.push_back("A");
    q4->pop.push_back("B");
    q4->push.push_back("\u03B5");
	
	estados.push_back(*q0);
	estados.push_back(*q1);
	estados.push_back(*q2);
	estados.push_back(*q3);
	estados.push_back(*q4);
	
	inicial->transiciones.push_back(q0);
	inicial->input.push_back("\u03B5");
    inicial->pop.push_back("\u03B5");
    inicial->push.push_back("#");
}

