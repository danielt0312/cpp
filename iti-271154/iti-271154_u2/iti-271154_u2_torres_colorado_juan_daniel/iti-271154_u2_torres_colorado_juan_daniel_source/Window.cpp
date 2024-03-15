#include <QLabel>
#include <QTextEdit>
#include <QPushButton>
#include <QDebug> 
#include <QColorDialog>
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QString>
#include "Window.h"
#include "ListGraph.h"

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
	inputGrafoA = new QLineEdit(this);
	inputGrafoB = new QLineEdit(this);
		
	hbOp1Fila1->addWidget((new QLabel("Grafo Origen:")), 1);
	hbOp1Fila1->addWidget(inputGrafoA, 3);
	
	hbOp1Fila2->addWidget((new QLabel("Grafo Destino:")), 1);
	hbOp1Fila2->addWidget(inputGrafoB, 3);
	
	hbOp1Fila3->addWidget(boton1);
	
	vbOp1->addLayout(hbOp1Fila1);
	vbOp1->addLayout(hbOp1Fila2);
	vbOp1->addLayout(hbOp1Fila3);
	
	auto *vbOp2 = new QVBoxLayout;
	auto *hbOp2Fila1 = new QHBoxLayout;
	auto *hbOp2Fila2 = new QHBoxLayout;
	auto *hbOp2Fila3 = new QHBoxLayout;
	
	auto *boton2 = new QPushButton("Breadth-First Search", this);
	auto *boton3 = new QPushButton("Limpiar", this);
	
	hbOp2Fila2->addWidget(boton2);
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
	
	lg = new ListGraph(this);
    	QPalette pal = QPalette();
    	pal.setColor(QPalette::Window, Qt::white);
	lg->setAutoFillBackground(true);
	lg->setPalette(pal);

	hbGrafos->addWidget(lg);
	
	vbContenido->addLayout(hbOpciones, 0);
	vbContenido->addSpacing(20);
	vbContenido->addLayout(hbGrafos, 3);
	setLayout(vbContenido);
	
	// Conexiones de los botones
	connect(boton1, &QPushButton::clicked, this, &Window::guardarConexion);
	connect(boton2, &QPushButton::clicked, this, &Window::BFS);
	connect(boton3, &QPushButton::clicked, this, &Window::limpiarTablero);
}

// Conveción de letra a número con ASCII
int Window::letraNumero(char letra) {
    // Convertir letra a mayúscula para facilitar la comparación
    letra = std::toupper(letra);
    
    if (!std::isalpha(letra))
        return -1;
    
    return letra - 'A' + 1;
}

void Window::guardarConexion() {
    // Extraer el primer carácter del texto de los QLineEdit y convertirlo a char
    char letraA = inputGrafoA->text().isEmpty() ? '\0' : inputGrafoA->text().at(0).toLatin1();
    char letraB = inputGrafoB->text().isEmpty() ? '\0' : inputGrafoB->text().at(0).toLatin1();
    
    // Convertir las letras a números
    int puntoA = letraNumero(letraA);
    int puntoB = letraNumero(letraB);
    
    if(puntoA != -1 and puntoB != -1)
        lg->addEdge(puntoA, puntoB);
}

void Window::BFS() {
	lg->BFS();
}

void Window::limpiarTablero() {
	lg->limpiar();
}

