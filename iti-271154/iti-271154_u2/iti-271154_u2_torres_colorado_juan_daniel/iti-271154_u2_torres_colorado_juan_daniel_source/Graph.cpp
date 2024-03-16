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
#include <chrono>

#include <string>
#include <queue>
#include "Graph.h"

using namespace std;

Graph::Graph(QWidget *parent)
    : QWidget(parent) {
    
    x = 1;
    timerId = startTimer(10);

    h = height();
    w = width();

    altoC = 40;
    anchoC = 40;
}

void Graph::mousePressEvent(QMouseEvent* event)
{
    QWidget::mousePressEvent(event);
    int valorGrafo = vertices.size()+1;
    Node nodo(event->pos().x(),event->pos().y(), valorGrafo);
    vertices.push_back(nodo);
        
    std::cout << "Nodo '" << numeroLetra(vertices.size()) << "' guardado en (" << (event->pos().x()) << ","<< (event->pos().y())<< ")"<< '\n';
}

void Graph::timerEvent(QTimerEvent *e) {
    Q_UNUSED(e);
    repaint();
}

void Graph::paintEvent(QPaintEvent *e) {
    Q_UNUSED(e);  
    doPainting();
}

void Graph::limpiar() { vertices.clear(); std::cout << "Grafo limpiado" << std::endl; }

void Graph::doPainting() {
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
    
    // Primero dibujamos las aristas por debajo de los nodos
    for (Node nodo : vertices)
        dibujarArista(painter, nodo);
    
    // Dibujado de nodos
    for (Node nodo : vertices) {
        int centerX = nodo.getX() - anchoC / 2;
        int centerY = nodo.getY() - altoC / 2;
        
        painter.setBackground(nodo.color);
        painter.setBrush(nodo.color);
        painter.drawEllipse(centerX, centerY, anchoC, altoC);

        QString valor = QString::fromStdString(numeroLetra(nodo.getValor()));
        painter.drawText(nodo.getX()-4, nodo.getY()+4, valor);
    }

    // No es necesario llamar a painter.end() aquí
}


// dibujos de las aristas de la lista de nodos
void Graph::dibujarArista(QPainter &painter, Node &nodo) {
    for(Node* nodoDestino : nodo.aristas)
	painter.drawLine(nodo.getX(), nodo.getY(), nodoDestino->getX(), nodoDestino->getY());
}

// Traducción de número a letra con ASCII
std::string Graph::numeroLetra(int valor) {
    if (valor < 1 || valor > 26) {
        return "-";
    }

    return std::string(1, 'A' + valor - 1);
}

// Creación de aristas
void Graph::addEdge(int i, int j) {
    // Validación de índices
    if (static_cast<size_t>(i) <= 0 || static_cast<size_t>(i) > vertices.size() || static_cast<size_t>(j) <= 0 || static_cast<size_t>(j) > vertices.size() || i == j) {
        std::cout << "Valor(es) inválidos" << std::endl;
        return;
    }
    
    // Obtener los vértices correspondientes
    Node& puntoOrigen = vertices[i - 1];
    Node& puntoDestino = vertices[j - 1];

    // Comprobar si la arista ya existe
    for (Node* graph : puntoOrigen.aristas) {
        if (*graph == puntoDestino) {
            std::cout << "Relación previamente creada de i ( " << numeroLetra(puntoOrigen.getValor()) << " ) en j ( " << numeroLetra(puntoDestino.getValor()) << " )" << std::endl;
            return;
        }
    }

    // Agregar el vértice de destino a las listas de vértices
    puntoOrigen.aristas.push_back(&puntoDestino);
    puntoDestino.aristas.push_back(&puntoOrigen);
    std::cout << "Se agregó una arista: ( " << numeroLetra(puntoOrigen.getValor()) << " ) --- ( " << numeroLetra(puntoDestino.getValor()) << " )" << std::endl;
}

// Eliminar aristas
void Graph::removeEdge(int i, int j) {
    // Validación de índices
    if (static_cast<size_t>(i) <= 0 || static_cast<size_t>(i) > vertices.size() || static_cast<size_t>(j) <= 0 || static_cast<size_t>(j) > vertices.size() || i == j) {
        std::cout << "Valor(es) inválidos" << std::endl;
        return;
    }
    
    // Obtener los vértices correspondientes
    Node& puntoOrigen = vertices[i - 1];
    Node& puntoDestino = vertices[j - 1];

    // Encontrar y eliminar la arista entre los vértices
    auto itOrigen = std::find(puntoOrigen.aristas.begin(), puntoOrigen.aristas.end(), &puntoDestino);
    auto itDestino = std::find(puntoDestino.aristas.begin(), puntoDestino.aristas.end(), &puntoOrigen);

    if (itOrigen != puntoOrigen.aristas.end() && itDestino != puntoDestino.aristas.end()) {
        puntoOrigen.aristas.erase(itOrigen);
        puntoDestino.aristas.erase(itDestino);
        std::cout << "Se eliminó la arista entre los vértices " << numeroLetra(puntoOrigen.getValor()) << " y " << numeroLetra(puntoDestino.getValor()) << std::endl;
    } else {
        std::cout << "No se encontró una arista entre los vértices " << numeroLetra(puntoOrigen.getValor()) << " y " << numeroLetra(puntoDestino.getValor()) << std::endl;
    }
}

// Establecer colores en estado base (blanco)
void Graph::limpiarColores() {
    for (Node& nodo : vertices) {
    	nodo.color = Qt::white;
    }
}

// Grafo Bipartito
void Graph::bipartite(int inicio) {
    limpiarColores();
    
    if(vertices.size() == 0) {
    	emit advertencia();
    	//QMessageBox::information(nullptr, "Advertencia", "No hay ningún vértice en el nodo  ");
    	return;
    }
    
    // Empezando desde el nodo ingresado
    Node* nodoInicio = &vertices[inicio];

    // Coloreamos el vértice de inicio como parte del pimer conjunto
    nodoInicio->color = Qt::red;
    conjuntoA.push_back(nodoInicio);
    
    std::this_thread::sleep_for(std::chrono::seconds(1)); // Esperamos un segundo
    
    std::queue<Node*> cola;
    cola.push(nodoInicio);

    while (!cola.empty()) {
        Node* currentVertex = cola.front();
        cola.pop();
	
        for (Node* vecino : currentVertex->aristas) {
            if (vecino->color == Qt::white) {
                vecino->color = (currentVertex->color == Qt::red) ? Qt::blue : Qt::red;
                cola.push(vecino);
                std::this_thread::sleep_for(std::chrono::seconds(1));
                
                if (vecino->color == Qt::red)
                    conjuntoA.push_back(vecino);
                else
                    conjuntoB.push_back(vecino);
            } else {
                if (vecino->color == currentVertex->color) {
                    std::cout << "El Grafo no es bipartito" << std::endl;
                    emit bipartiteResult(false);
                    //QMessageBox::information(nullptr, "¿Es Grafo Bipartito?", "El Grafo no es bipartito  ");
                    return;
                }
            }
        }
    }

    std::cout << "El Grafo si es bipartito" << std::endl;
    emit bipartiteResult(true);
    //QMessageBox::information(nullptr, "¿Es Grafo Bipartito?", "El Grafo si es bipartito  ");
}

