#include <QLabel>
#include <QTextEdit>
#include <QPushButton>
#include <QDebug> 
#include <QColorDialog>
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QString>
#include <QMessageBox>
#include <thread>

#include "Window.h"

Window::Window(QWidget *parent) : QWidget(parent) {
	// Layout para todo el contenido
	auto *vbContenido = new QVBoxLayout;
	
	// Layout para los botones / inputs
	auto *hbOpciones = new QHBoxLayout;
	auto *vbOp1 = new QVBoxLayout;
	auto *hbOp1Fila1 = new QHBoxLayout;
	auto *hbOp1Fila2 = new QHBoxLayout;
	auto *hbOp1Fila3 = new QHBoxLayout;
	
	auto *boton1 = new QPushButton("Crear Arista", this);
	auto *boton5 = new QPushButton("Eliminar Arista", this);
	inputGrafoA = new QLineEdit(this);
	inputGrafoB = new QLineEdit(this);
	inputBipartite = new QLineEdit(this);
		
	hbOp1Fila1->addWidget((new QLabel("Grafo Origen:")), 1);
	hbOp1Fila1->addWidget(inputGrafoA, 3);
	
	hbOp1Fila2->addWidget((new QLabel("Grafo Destino:")), 1);
	hbOp1Fila2->addWidget(inputGrafoB, 3);
	
	hbOp1Fila3->addWidget(boton1);
	hbOp1Fila3->addWidget(boton5);
	
	vbOp1->addLayout(hbOp1Fila1);
	vbOp1->addLayout(hbOp1Fila2);
	vbOp1->addLayout(hbOp1Fila3);
	
	auto *vbOp2 = new QVBoxLayout;
	auto *hbOp2Fila1 = new QHBoxLayout;
	auto *hbOp2Fila2 = new QHBoxLayout;
	auto *hbOp2Fila3 = new QHBoxLayout;
	
	auto *boton2 = new QPushButton("¿Es Grafo Bipartito?", this);
	
	auto *boton3 = new QPushButton("Eliminar grafos existentes", this);
	auto *boton4 = new QPushButton("Reestablecer colores de grafos", this);
	
	hbOp2Fila1->addWidget((new QLabel("Iniciar en Grafo ('A' por defecto):")), 1);
	hbOp2Fila1->addWidget(inputBipartite, 3);
	
	hbOp2Fila2->addWidget(boton2);
	
	hbOp2Fila3->addWidget(boton4);
	hbOp2Fila3->addWidget(boton3);
		
	vbOp2->addLayout(hbOp2Fila1);
	vbOp2->addLayout(hbOp2Fila2);
	vbOp2->addLayout(hbOp2Fila3);
	
	hbOpciones->addSpacing(50);
	hbOpciones->addLayout(vbOp1,1);
	hbOpciones->addSpacing(50);
	hbOpciones->addLayout(vbOp2,1);
	hbOpciones->addSpacing(50);
	
	// Layout para dibujar los grafos
	auto *hbGrafos = new QHBoxLayout;
	
	grafo = new Graph(this);
    	QPalette pal = QPalette();
    	pal.setColor(QPalette::Window, Qt::white);
	grafo->setAutoFillBackground(true);
	grafo->setPalette(pal);

	hbGrafos->addWidget(grafo);
	
	vbContenido->addSpacing(5);
	vbContenido->addLayout(hbOpciones, 1);
	vbContenido->addSpacing(5);
	vbContenido->addLayout(hbGrafos, 3);
	setLayout(vbContenido);
	
	// Conexiones de los botones
	connect(boton1, &QPushButton::clicked, this, &Window::guardarConexion);
	connect(boton2, &QPushButton::clicked, this, &Window::bipartite);
	connect(boton3, &QPushButton::clicked, this, &Window::limpiarTablero);
	connect(boton4, &QPushButton::clicked, this, &Window::limpiarColores);
	connect(boton5, &QPushButton::clicked, this, &Window::eliminarConexion);
	
	// señales
	connect(grafo, &Graph::bipartiteResult, this, &Window::mostrarMensajeBipartito);
	connect(grafo, &Graph::advertencia, this, &Window::mostrarAdvertencia);
}

// Conveción de letra a número con ASCII
int Window::letraNumero(char letra) {
    // Convertir letra a mayúscula para facilitar la comparación
    letra = std::toupper(letra);
    
    if (!std::isalpha(letra))
        return -1;
    
    return letra - 'A' + 1;
}

// Creación de aristas
void Window::guardarConexion() {
    // Extraer el primer carácter del texto de los QLineEdit y convertirlo a char
    char letraA = inputGrafoA->text().isEmpty() ? '\0' : inputGrafoA->text().at(0).toLatin1();
    char letraB = inputGrafoB->text().isEmpty() ? '\0' : inputGrafoB->text().at(0).toLatin1();
    
    // Convertir las letras a números
    int puntoA = letraNumero(letraA);
    int puntoB = letraNumero(letraB);
    
    if (puntoA != -1 and puntoB != -1)
        grafo->addEdge(puntoA, puntoB);
}

// Eliminiacion de aristas
void Window::eliminarConexion() {
    char letraA = inputGrafoA->text().isEmpty() ? '\0' : inputGrafoA->text().at(0).toLatin1();
    char letraB = inputGrafoB->text().isEmpty() ? '\0' : inputGrafoB->text().at(0).toLatin1();
    
    int puntoA = letraNumero(letraA);
    int puntoB = letraNumero(letraB);
    
    if (puntoA != -1 and puntoB != -1)
        grafo->removeEdge(puntoA, puntoB);
}

void Window::bipartite() {
    // Creamos un hilo secundario para no interrumpir el principal
    char letra = inputBipartite->text().isEmpty() ? 'A' : inputBipartite->text().at(0).toLatin1();
    int punto = letraNumero(letra);
    
    if (punto!= -1) {
        std::thread bfsThread(&Graph::bipartite, grafo, --punto);
        bfsThread.detach(); // Liberamos el hilo para que se ejecute independientemente
    }
}


void Window::limpiarTablero() {
	grafo->limpiar();
}

void Window::limpiarColores() {
	grafo->limpiarColores();
}

void Window::mostrarMensajeBipartito(bool isBipartite) {
    if (isBipartite) {
        QMessageBox::information(nullptr, "¿Es Grafo Bipartito?", "El Grafo sí es bipartito");
    } else {
        QMessageBox::information(nullptr, "¿Es Grafo Bipartito?", "El Grafo no es bipartito");
    }
}

void Window::mostrarAdvertencia() {
        QMessageBox::information(nullptr, "Advertencia", "No hay ningún vértice en el grafo");
}

