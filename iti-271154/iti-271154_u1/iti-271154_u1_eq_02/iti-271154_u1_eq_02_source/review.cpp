#include <QGridLayout>
#include <QLabel>
#include <QTextEdit>
#include <QPushButton>
#include <QDebug> 
#include "review.h"
#include "puff_and_mouse.h"
#include <QColorDialog>
#include <QDialog>
#include <QFormLayout>
#include <QVBoxLayout>
#include <QString>
#include <QHBoxLayout>

Review::Review(QWidget *parent) : QWidget(parent) {
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
	
	auto *boton2 = new QPushButton("AdjacencyMatrix", this);
	auto *boton3 = new QPushButton("AdjacencyLists", this);
	auto *boton4 = new QPushButton("Breadth-First Search", this);
	auto *boton5 = new QPushButton("Depth-First Search", this);
	auto *boton6 = new QPushButton("Limpiar", this);
	
	hbOp2Fila1->addWidget(boton2);
	hbOp2Fila1->addWidget(boton3);
	
	hbOp2Fila2->addWidget(boton4);
	hbOp2Fila2->addWidget(boton5);

	hbOp2Fila3->addWidget(boton6);
	
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
	
	pm1 = new Puff_and_Mouse(this);
    	QPalette pal = QPalette();
	pm1->setAutoFillBackground(true);
	pm1->setPalette(pal);

	hbGrafos->addWidget(pm1);
	
	vbContenido->addLayout(hbOpciones, 0);
	vbContenido->addSpacing(20);
	vbContenido->addLayout(hbGrafos, 3);
	setLayout(vbContenido);
	
	
	// Conexiones de los botones
	connect(boton1, &QPushButton::clicked, this, &Review::guardarConexion);
	connect(boton2, &QPushButton::clicked, this, &Review::matrix);
	connect(boton3, &QPushButton::clicked, this, &Review::list);
	connect(boton6, &QPushButton::clicked, this, &Review::limpiarTablero);
}

void Review::guardarConexion() {
	QString puntoA = inputGrafoA->text();
	QString puntoB = inputGrafoB->text();
	pm1->addEdge(puntoA.toInt(), puntoB.toInt());
}

void Review::matrix() {
	pm1->adjacencyMatrix();
}

void Review::list() {
	pm1->adjacencyLists();
}

void Review::limpiarTablero() {
	pm1->limpiar();
}

