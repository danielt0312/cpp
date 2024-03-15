#include <QPainter>
#include <QTimer>
#include <QTextStream>
#include <QtWidgets>
#include <QTimer>
#include <QDialog>
#include <QTableWidget>
#include <string>
#include <queue>
#include "ListGraph.h"

using namespace std;

ListGraph::ListGraph(QWidget *parent)
    : QWidget(parent) {
    
    x = 1;
    timerId = startTimer(10);

    h = height();
    w = width();

    altoC = 40;
    anchoC = 40;
}

void ListGraph::mousePressEvent(QMouseEvent* event)
{
    QWidget::mousePressEvent(event);
    int valorGrafo = listaGrafos.size()+1;
    Graph grafo(event->pos().x(),event->pos().y(), valorGrafo);
    listaGrafos.push_back(grafo);
        
    std::cout << "Graph '" << numeroLetra(listaGrafos.size()) << "' guardado en (" << (event->pos().x()) << ","<< (event->pos().y())<< ")"<< '\n';
}

void ListGraph::timerEvent(QTimerEvent *e) {
    Q_UNUSED(e);
    repaint();
}

void ListGraph::paintEvent(QPaintEvent *e) {
    Q_UNUSED(e);  
    doPainting();
}

void ListGraph::limpiar() { listaGrafos.clear(); std::cout << "Lista de Grafos limpiada" << std::endl; }

// Dibujado de los grafos disponibles (tablero)
void ListGraph::doPainting() {
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
    
    // Primero dibujamos las aristas por debajo de los grafos
    for (Graph grafo : listaGrafos)
        dibujarArista(painter, grafo);
    
    // Dibujado de grafos
    for (Graph grafo : listaGrafos) {
        
        int centerX = grafo.getX() - anchoC / 2;
        int centerY = grafo.getY() - altoC / 2;
        
        painter.setBrush(Qt::white);
        painter.drawEllipse(centerX, centerY, anchoC, altoC);

	//QString valor = QString::fromStdString(std::to_string(grafo.getValor()));
	QString valor = QString::fromStdString(numeroLetra(grafo.getValor()));
        painter.drawText(grafo.getX()-4, grafo.getY()+4, valor);
    }
}

// dibujos de las aristas de la lista de grafos
void ListGraph::dibujarArista(QPainter &painter, Graph &grafo) {
    for(Graph grafoDestino : grafo.vertices) {
	painter.drawLine(grafo.getX(), grafo.getY(), grafoDestino.getX(), grafoDestino.getY());
    }
}

// Traducción de número a letra con ASCII
std::string ListGraph::numeroLetra(int valor) {
    if (valor < 1 || valor > 26) {
        return "-";
    }

    return std::string(1, 'A' + valor - 1);
}

// Creación de vertices
void ListGraph::addEdge(int i, int j) {
    // Validación de índices
    if (static_cast<size_t>(i) <= 0 || static_cast<size_t>(i) > listaGrafos.size() || static_cast<size_t>(j) <= 0 || static_cast<size_t>(j) > listaGrafos.size() || i == j) {
        std::cout << "Valor(es) inválidos" << std::endl;
        return;
    }
    
    // Obtener los vértices correspondientes
    Graph& puntoOrigen = listaGrafos[i - 1];
    Graph& puntoDestino = listaGrafos[j - 1];

    // Comprobar si la arista ya existe
    for (Graph& graph : puntoOrigen.vertices) {
        if (graph == puntoDestino) {
            std::cout << "Relación previamente creada de i ( " << numeroLetra(puntoOrigen.getValor()) << " ) en j ( " << numeroLetra(puntoDestino.getValor()) << " )" << std::endl;
            return;
        }
    }

    // Agregar el vértice de destino a las listas de vértices
    puntoOrigen.vertices.push_back(puntoDestino);
    puntoDestino.vertices.push_back(puntoOrigen);
    std::cout << "Se agregó una arista: ( " << numeroLetra(puntoOrigen.getValor()) << " ) --- ( " << numeroLetra(puntoDestino.getValor()) << " )" << std::endl;
}

void ListGraph::BFS() {
    // Verificar si hay al menos un vértice en el grafo
    if (listaGrafos.empty()) {
        std::cout << "El grafo está vacío." << std::endl;
        return;
    }
    
    // Marcar todos los vértices como no visitados
    const int nV = listaGrafos.size();
    bool visitado[nV] = {false};
    
    // Cola para el recorrido BFS
    std::queue<Graph> cola;
    
    // Empezar el BFS desde el primer vértice
    cola.push(listaGrafos.front());
    visitado[0] = true;
    
    while (!cola.empty()) {
        // Sacar el vértice de la cola
        Graph verticeActual = cola.front();
        cola.pop();
        
        // Mostrar el valor del vértice actual
        std::cout << numeroLetra(verticeActual.getValor()) << " ";
        
        // Recorrer todos los vértices adyacentes al vértice actual
        for (Graph grafoDestino : verticeActual.vertices) {
            int indice = grafoDestino.getValor() - 1; // Obtener el índice del vértice en listaGrafos
            
            // Si el vértice adyacente no ha sido visitado, marcarlo como visitado y agregarlo a la cola
            if (!visitado[indice]) {
                visitado[indice] = true;
                cola.push(grafoDestino);
            }
        }
    }
    std::cout << std::endl;
}
