#include <QPainter>
#include <QTimer>
#include <QTextStream>
#include <QtWidgets>
#include <iostream>
#include <QTimer>
#include <QObject>
#include <algorithm>
#include <QInputDialog>
#include <QDialog>
#include <QTableWidget>
#include <iostream>
#include <list>
#include <iostream>

#include "puff_and_mouse.h"
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
		if(grafo.getContent().getY() >= nodoDestino.getY())
			dibujarFlecha(painter, grafo.getContent().getX(), grafo.getContent().getY()-20, nodoDestino.getX(), nodoDestino.getY()-20);
		else
			dibujarFlecha(painter, grafo.getContent().getX(), grafo.getContent().getY()+20, nodoDestino.getX(), nodoDestino.getY()+20);
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

void Puff_and_Mouse::adjacencyMatrix() {
	int numVertices = listaGrafos.size();

	// matriz de adyacencia vacia
	std::vector<std::vector<int>> matrix(numVertices, std::vector<int>(numVertices, 0));

	// recorrer los grafos y actualizar la matriz
	int i = 0;
	for (Graph grafo : listaGrafos) {
		for (Node nodoDestino : *(grafo.vertices)) {
		    // Obtén el índice del grafo de destino
		    auto it = std::find_if(listaGrafos.begin(), listaGrafos.end(),
			[&nodoDestino](Graph& g) { return g.getContent() == nodoDestino; });

		    if (it != listaGrafos.end()) {
			int j = std::distance(listaGrafos.begin(), it);
			// Actualiza la matriz de adyacencia
			matrix[i][j] = 1;
		    }
		}
		i++;
	}
    
	// Crear matriz de adyacencia ordenada de forma inversa
	std::vector<std::vector<int>> matrixOrdenado(numVertices, std::vector<int>(numVertices, 0));

	for (int i = 0; i < numVertices; ++i) {
	    for (int j = 0; j < numVertices; ++j) {
		matrixOrdenado[i][j] = matrix[numVertices - 1 - i][numVertices - 1 - j];
	    }
	}


	// impresión de la matriz de adyacencia ordenada de forma inversa
	std::cout << "   ";
	for (int k = 1; k <= numVertices; k++) {
	    std::cout << k << "  ";
	}
	std::cout << std::endl;

	i = 1;
	for (const auto& row : matrixOrdenado) {
	    std::cout << i << "  ";
	    for (int value : row) {
		std::cout << value << "  ";
	    }
	    std::cout << std::endl;
	    i++;
	}
	displayAdajencyMatrix(matrixOrdenado);
}

void Puff_and_Mouse::displayAdajencyMatrix(std::vector<std::vector<int>> &matrixOrdenado) {
    QDialog *ventanaEmergente = new QDialog(nullptr);
    ventanaEmergente->setWindowTitle("Adjacency Matrix");

    ventanaEmergente->resize(1000, 640);

    QVBoxLayout *layout = new QVBoxLayout(ventanaEmergente);

    QTableWidget *tabla = new QTableWidget(ventanaEmergente);

    int numFilas = listaGrafos.size();
    int numColumnas = listaGrafos.size();

    tabla->setRowCount(numFilas);
    tabla->setColumnCount(numColumnas);

    for (int i = 0; i < numFilas; ++i) {
        for (int j = 0; j < numColumnas; ++j) {
            QTableWidgetItem *item = new QTableWidgetItem(QString::number(matrixOrdenado[i][j]));

            // Configurar el ítem como de solo lectura
            item->setFlags(item->flags() ^ Qt::ItemIsEditable);

            tabla->setItem(i, j, item);
        }
    }

    // Configurar la tabla como de solo lectura
    tabla->setEditTriggers(QAbstractItemView::NoEditTriggers);

    layout->addWidget(tabla);

    QPushButton *botonCerrar = new QPushButton("Cerrar", ventanaEmergente);
    connect(botonCerrar, &QPushButton::clicked, ventanaEmergente, &QDialog::close);
    layout->addWidget(botonCerrar);

    ventanaEmergente->setLayout(layout);
    ventanaEmergente->exec();
}

void Puff_and_Mouse::adjacencyLists() {
    // lista de grafos orden inverso (ordenado)
    list<Graph> listaGrafosOrdenados(listaGrafos.rbegin(), listaGrafos.rend());

    int i = 1;
    for (const Graph& grafo : listaGrafosOrdenados) {
        std::cout << "Lista de adyacencia para el Grafo " << i << ": ";

        // Imprime la lista de adyacencia en orden inverso
        for (auto nodoIt = grafo.vertices->rbegin(); nodoIt != grafo.vertices->rend(); ++nodoIt) {
            std::cout << nodoIt->getValor() << " ";
        }

        std::cout << std::endl;
        i++;
    }
    displayAdjacencyLists(listaGrafosOrdenados);
}


void Puff_and_Mouse::displayAdjacencyLists(list<Graph> &listaGrafosOrdenados) {
    QDialog *ventanaEmergente = new QDialog(nullptr);
    ventanaEmergente->setWindowTitle("Adjacency Lists");

    ventanaEmergente->resize(1000, 640);

    QVBoxLayout *layout = new QVBoxLayout(ventanaEmergente);

    QTableWidget *tabla = new QTableWidget(ventanaEmergente);

    int numFilas = listaGrafosOrdenados.size();
    int numColumnas = 1;  // Solo necesitamos una columna para la lista de adyacencia

    tabla->setRowCount(numFilas);
    tabla->setColumnCount(numColumnas);

    int i = 0;
    for (const Graph& grafo : listaGrafosOrdenados) {
        QTableWidgetItem *item = new QTableWidgetItem();

        // item como de solo lectura
        item->setFlags(item->flags() ^ Qt::ItemIsEditable);

        // cadena de la lista de adyacencia
        QString adyacencia;
        for (auto nodoIt = grafo.vertices->rbegin(); nodoIt != grafo.vertices->rend(); ++nodoIt) {
            adyacencia += QString::number(nodoIt->getValor()) + " ";
        }

        item->setText(adyacencia);
        tabla->setItem(i, 0, item);
        i++;
    }

    // Configurar la tabla como de solo lectura
    tabla->setEditTriggers(QAbstractItemView::NoEditTriggers);

    layout->addWidget(tabla);

    QPushButton *botonCerrar = new QPushButton("Cerrar", ventanaEmergente);
    connect(botonCerrar, &QPushButton::clicked, ventanaEmergente, &QDialog::close);
    layout->addWidget(botonCerrar);

    ventanaEmergente->setLayout(layout);
    ventanaEmergente->exec();
}


