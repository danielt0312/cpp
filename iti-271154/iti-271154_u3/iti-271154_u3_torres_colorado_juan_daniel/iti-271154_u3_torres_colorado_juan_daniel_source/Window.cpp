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
	auto *hbContenido = new QHBoxLayout;
	
	// Layout para menu izquierdo
	auto *vbMenu = new QVBoxLayout;	
	
	// Layout para los botones / inputs
	auto *vbOpciones = new QVBoxLayout;
	
	auto *vbProbar = new QVBoxLayout;
	inProbar = new QLineEdit(this);
	inProbar->setPlaceholderText("AB...");
	auto *boton0 = new QPushButton("Probar", this);
	vbProbar->addWidget(inProbar);
	vbProbar->addWidget(boton0);
		
	auto *boton1 = new QPushButton("Dibujar", this);
	auto *boton2 = new QPushButton("Nueva Transición", this);
	auto *boton3 = new QPushButton("Eliminar ", this);
	auto *boton4 = new QPushButton("Eliminar Relación", this);
	auto *boton5 = new QPushButton("Limpiar", this);
	
	comentario = new QLabel("");

	vbOpciones->addWidget(boton1);
	vbOpciones->addWidget(boton2);
	vbOpciones->addWidget(boton3);
	vbOpciones->addWidget(boton4);
	vbOpciones->addWidget(boton5);
	vbOpciones->addWidget(comentario);
	
	vbMenu->addLayout(vbProbar);
	vbMenu->addLayout(vbOpciones);
	
	// Layout para dibujar los grafos
	auto *hbGrafos = new QHBoxLayout;
	
	automaton = new Automata(this);
    	QPalette pal = QPalette();
    	pal.setColor(QPalette::Window, Qt::white);
	automaton->setAutoFillBackground(true);
	automaton->setPalette(pal);
	
	hbGrafos->addWidget(automaton);
	
	hbContenido->addSpacing(5);
	hbContenido->addLayout(vbMenu, 0);
	
	hbContenido->addSpacing(5);
	hbContenido->addLayout(hbGrafos, 3);
	setLayout(hbContenido);
	
	// Conexiones de los botones
	connect(boton1, &QPushButton::clicked, this, &Window::agregar);
	connect(boton2, &QPushButton::clicked, this, &Window::transicion);
	connect(boton5, &QPushButton::clicked, this, &Window::limpiar);
	
	/*connect(boton1, &QPushButton::clicked, this, &Window::guardarConexion);
	connect(boton2, &QPushButton::clicked, this, &Window::bipartite);
	connect(boton3, &QPushButton::clicked, this, &Window::limpiarTablero);
	connect(boton4, &QPushButton::clicked, this, &Window::limpiarColores);
	connect(boton5, &QPushButton::clicked, this, &Window::eliminarConexion);
	
	// señales
	connect(grafo, &Graph::bipartiteResult, this, &Window::mostrarMensajeBipartito);
	connect(grafo, &Graph::advertencia, this, &Window::mostrarAdvertencia);
	*/
}

void Window::agregar() {
	std::cout << "Modo: Agregar Automata" << std::endl;
	automaton->opcion = 1;
}

void Window::transicion() {
	std::cout << "Modo: Agregar Transicion" << std::endl;
	automaton->opcion = 2;
}

void Window::limpiar() {
	automaton->limpiar();
}

