#include <QPainter>
#include <QTimer>
#include <QTextStream>
#include <QtWidgets>
#include <QTimer>
#include <QDialog>
#include <QTableWidget>
#include <string>
#include "ListGraph.h"

using namespace std;

ListGraph::ListGraph(QWidget *parent)
    : QWidget(parent) {
    
    x = 1;
    timerId = startTimer(1);
    velocidad = 1;

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
    listaGrafos.push_front(grafo);
        
    std::cout << "Graph '" << listaGrafos.size() << "' guardado en (" << (event->pos().x()) << ","<< (event->pos().y())<< ")"<< '\n';
}

void ListGraph::paintEvent(QPaintEvent *e) {
  Q_UNUSED(e);  
  doPainting();
}

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

    for (Graph grafo : listaGrafos) {
        dibujarArista(painter, grafo);
        
        int centerX = grafo.getContent().getX() - anchoC / 2;
        int centerY = grafo.getContent().getY() - altoC / 2;

        painter.drawEllipse(centerX, centerY, anchoC, altoC);

	QString valor = QString::fromStdString(std::to_string(grafo.getContent().getValor()));
        painter.drawText(grafo.getContent().getX()-6, grafo.getContent().getY()+4, valor);
    }
}

void ListGraph::timerEvent(QTimerEvent *e) {
    Q_UNUSED(e);
    repaint();
}

// Creación de vertices
void ListGraph::addEdge(int i, int j) {
    // validación para las advertencias de entero diferente (verifica que el grafo exista tanto origen como destino al igual que no sea a sí mismo)
    if (static_cast<size_t>(i) <= 0 || static_cast<size_t>(i) > listaGrafos.size() || static_cast<size_t>(j) <= 0 || static_cast<size_t>(j) > listaGrafos.size() || i == j) {
    	std::cout << "Valor(es) invalidos" << std::endl;
    	return;
    }
	
    auto itA = listaGrafos.end();
    std::advance(itA, -i);
    Graph puntoOrigen = *itA;
    std::cout << "Grafo i ( " << i << " ) existe en (" << puntoOrigen.getContent().getX() << "," << puntoOrigen.getContent().getY() << " )" << std::endl;
        
    auto itB = listaGrafos.end();
    std::advance(itB, -j);
    Graph puntoDestino = *itB;
    std::cout << "Grafo j ( " << j << " ) existe en (" << puntoDestino.getContent().getX() << "," << puntoDestino.getContent().getY() << " )" << std::endl;
        
    for(Node nodo : *(puntoOrigen.vertices)) {
        if(nodo == puntoDestino.getContent()){
            std::cout << "Relación previamente ya creada de i ( " << puntoOrigen.getContent().getValor() << " ) en j ( " << puntoDestino.getContent().getValor() << " )" << std::endl;
            return;
     	}
    }
        
    puntoOrigen.vertices->push_front(puntoDestino.getContent());
    std::cout << "( " << puntoOrigen.getContent().getValor() << " ) total de vertices: " << puntoOrigen.vertices->size() << std::endl;
        
    for(Node nodo : *(puntoOrigen.vertices))
       	std::cout << "X: " << nodo.getX() << " Y: " << nodo.getY() << " V: " << nodo.getValor() << std::endl;
}

// dibujos de las aristas de la lista de grafos
void ListGraph::dibujarArista(QPainter &painter, Graph &grafo) {
    for(Node nodoDestino : *(grafo.vertices)) {
	if(grafo.getContent().getY() >= nodoDestino.getY())
	    dibujarFlecha(painter, grafo.getContent().getX(), grafo.getContent().getY()-20, nodoDestino.getX(), nodoDestino.getY()-20);
	else
		dibujarFlecha(painter, grafo.getContent().getX(), grafo.getContent().getY()+20, nodoDestino.getX(), nodoDestino.getY()+20);
    }
}

// metodo para dibujar una flecha
void ListGraph::dibujarFlecha(QPainter &painter, int x1, int y1, int x2, int y2) {
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

// Impresión por consola de la AdjacencyMatrix para después ser procesada por la vista gráfica
void ListGraph::adjacencyMatrix() {
    int numVertices = listaGrafos.size();
    
    // matriz de adyacencia vacia
    std::vector<std::vector<int>> matrix(numVertices, std::vector<int>(numVertices, 0));
    int i = 0;
    for (Graph grafo : listaGrafos) {
    	for (Node nodoDestino : *(grafo.vertices)) {
	    // buscamos el indice del grafo destino
	    auto it = std::find_if(listaGrafos.begin(), listaGrafos.end(), [&nodoDestino](Graph& g) { return g.getContent() == nodoDestino; });
	    if (it != listaGrafos.end()) {
		int j = std::distance(listaGrafos.begin(), it);
		matrix[i][j] = 1;
	    }
	}
	i++;
    }
    
    // matriz de adyacencia ordenada de forma inversa
    std::vector<std::vector<int>> matrixOrdenado(numVertices, std::vector<int>(numVertices, 0));

    for (int i = 0; i < numVertices; ++i) {
    	for (int j = 0; j < numVertices; ++j) {
            matrixOrdenado[i][j] = matrix[numVertices - 1 - i][numVertices - 1 - j];
	}
    }
    
    // impresión de la matriz de adyacencia ordenada de forma inversa
    std::cout << "AdjacencyMatrix\n";
    std::cout << "   ";
    for (int k = 1; k <= numVertices; k++)
    	std::cout << k << "  ";
    	
    std::cout << std::endl;

    i = 1;
    for (const auto& row : matrixOrdenado) {
    	std::cout << i << "  ";
    	for (int value : row)
	    std::cout << value << "  ";
	
	std::cout << std::endl;
    	i++;
    }
    
    displayAdajencyMatrix(matrixOrdenado);
}

// Vista gráfica para AdjacencyMatrix
void ListGraph::displayAdajencyMatrix(std::vector<std::vector<int>> &matrixOrdenado) {
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

// Impresión por consola de la AdjacencyList para después ser procesada por la vista gráfica
void ListGraph::adjacencyLists() {
    // lista de adyacencia orden inverso (ordenado)
    list<Graph> listaGrafosOrdenados(listaGrafos.rbegin(), listaGrafos.rend());
    
    std::cout << "AdjacencyLists\n";
    int i = 1;
    for (const Graph& grafo : listaGrafosOrdenados) {
        std::cout << "( " << i << " ) ";

        for (auto nodoIt = grafo.vertices->rbegin(); nodoIt != grafo.vertices->rend(); ++nodoIt) {
            std::cout << nodoIt->getValor() << " ";
        }

        std::cout << std::endl;
        i++;
    }
    displayAdjacencyLists(listaGrafosOrdenados);
}

// Vista gráfica para AdjacencyLists
void ListGraph::displayAdjacencyLists(list<Graph> &listaGrafosOrdenados) {
    QDialog *ventanaEmergente = new QDialog(nullptr);
    ventanaEmergente->setWindowTitle("Adjacency Lists");
    ventanaEmergente->resize(1000, 640);

    QVBoxLayout *layout = new QVBoxLayout(ventanaEmergente);
    QTableWidget *tabla = new QTableWidget(ventanaEmergente);

    int numFilas = listaGrafosOrdenados.size();
    int numColumnas = 1;  // solo necesitamos una columna para la lista de adyacencia

    tabla->setRowCount(numFilas);
    tabla->setColumnCount(numColumnas);

    QStringList headerLabels;
    headerLabels << " ";
    tabla->setHorizontalHeaderLabels(headerLabels);

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

    // tabla de solo lectura
    tabla->setEditTriggers(QAbstractItemView::NoEditTriggers);

    layout->addWidget(tabla);

    QPushButton *botonCerrar = new QPushButton("Cerrar", ventanaEmergente);
    connect(botonCerrar, &QPushButton::clicked, ventanaEmergente, &QDialog::close);
    layout->addWidget(botonCerrar);

    ventanaEmergente->setLayout(layout);
    ventanaEmergente->exec();
}

void ListGraph::limpiarNodosVisitados() { 
    nodosVisitados.clear();
    dfsOutputText.clear();
}

void ListGraph::DFSUtil(Graph &grafo, std::unordered_set<int> &visitados) {
    nodosVisitados.insert(grafo.getContent().getValor());

    dfsOutputText += "( " + QString::number(grafo.getContent().getValor()) + " ) contiene " + QString::number(grafo.vertices->size()) + " vertices: ";
    std::cout << "( " << grafo.getContent().getValor() << " ) contiene " << grafo.vertices->size() << " vertices: ";
    for (Node nodoDestino : *(grafo.vertices)) {
	dfsOutputText += QString::number(nodoDestino.getValor()) + " ";        
	std::cout << nodoDestino.getValor() << " ";
        if (visitados.find(nodoDestino.getValor()) == visitados.end()) {
            // Si el nodo de destino no ha sido visitado, realiza la búsqueda en profundidad desde ese nodo
            auto it = std::find_if(listaGrafos.begin(), listaGrafos.end(),
                [&nodoDestino](Graph &g) { return g.getContent() == nodoDestino; });

            if (it != listaGrafos.end()) {
                DFSUtil(*it, visitados);
            }
        }
    }
    dfsOutputText += "\n";
    std::cout << "\n";
}

void ListGraph::DFS() {
    limpiarNodosVisitados();

    std::cout << "Depth First Search (DFS)\n";
    for (Graph &grafo : listaGrafos) {
        if (nodosVisitados.find(grafo.getContent().getValor()) == nodosVisitados.end())
            DFSUtil(grafo, nodosVisitados);
    }
    
    QMessageBox mb;
    mb.setWindowTitle("Depth First Search (DFS)");
    mb.setText(dfsOutputText);
    mb.exec();
}

void ListGraph::BFSUtil(Graph &grafo, std::unordered_set<int> &visitados) {
    std::queue<Graph> cola;
    cola.push(grafo);

    while (!cola.empty()) {
        Graph actual = cola.front();
        cola.pop();

        if (visitados.find(actual.getContent().getValor()) == visitados.end()) {
            nodosVisitados.insert(actual.getContent().getValor());

            dfsOutputText += "( " + QString::number(actual.getContent().getValor()) + " ) contiene " +
                             QString::number(actual.vertices->size()) + " vertices: ";

            std::cout << "( " << actual.getContent().getValor() << " ) contiene " << actual.vertices->size() << " vertices: ";
            for (Node nodoDestino : *(actual.vertices)) {
                dfsOutputText += QString::number(nodoDestino.getValor()) + " ";
                std::cout << nodoDestino.getValor() << " ";
                cola.push(*std::find_if(listaGrafos.begin(), listaGrafos.end(),
                    [&nodoDestino](Graph &g) { return g.getContent() == nodoDestino; }));
            }
            dfsOutputText += "\n";
            std::cout << "\n";
        }
    }
}

void ListGraph::BFS() {
    limpiarNodosVisitados();

    std::cout << "Breadth-First Search (BFS)\n";
    for (Graph &grafo : listaGrafos) {
        if (nodosVisitados.find(grafo.getContent().getValor()) == nodosVisitados.end()) {
            BFSUtil(grafo, nodosVisitados);
        }
    }
    
    QMessageBox mb;
    mb.setWindowTitle("Breadth-First Search (BFS)");
    mb.setText(dfsOutputText);
    mb.exec();
}

