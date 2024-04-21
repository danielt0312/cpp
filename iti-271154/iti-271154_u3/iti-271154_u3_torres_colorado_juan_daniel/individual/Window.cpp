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
	
	inProbar = new QLineEdit(this);
	inProbar->setPlaceholderText("AB...");
	auto *boton0 = new QPushButton("Probar", this);		
	auto *boton1 = new QPushButton("Nuevo Estado", this);
	auto *boton2 = new QPushButton("Nueva Transición", this);
	auto *boton4 = new QPushButton("Cargar Ejemplo", this);
	auto *boton6 = new QPushButton("Estado Final", this);
	auto *boton5 = new QPushButton("Eliminar Estados", this);
	
	comentario = new QLabel("Presiona sobre\nel mapa para\nagregar estado");
	QLresultado = new QLabel("");
	
	
	
	vbOpciones->addWidget(inProbar);
	vbOpciones->addWidget(boton0);
	vbOpciones->addSpacing(30);
	vbOpciones->addWidget(boton1);
	vbOpciones->addWidget(boton2);
	vbOpciones->addWidget(boton4);
	vbOpciones->addWidget(boton6);
	vbOpciones->addWidget(boton5);
	vbOpciones->addWidget(comentario);
	vbOpciones->addSpacing(10);
	vbOpciones->addWidget(QLresultado);
	
	vbMenu->addLayout(vbOpciones);
	
	// Layout para el automata
	auto *hbAutomata = new QHBoxLayout;
	
	automaton = new Automata(this);
	QPalette pal = QPalette();
	pal.setColor(QPalette::Window, Qt::white);
	automaton->setAutoFillBackground(true);
	automaton->setPalette(pal);
	
	hbAutomata->addWidget(automaton);
	
	hbContenido->addSpacing(5);
	hbContenido->addLayout(vbMenu, 0);
	
	hbContenido->addSpacing(5);
	hbContenido->addLayout(hbAutomata, 3);
	setLayout(hbContenido);
	
	// Conexiones de los botones
	connect(boton0, &QPushButton::clicked, this, &Window::test);
	connect(boton1, &QPushButton::clicked, this, &Window::agregar);
	connect(boton2, &QPushButton::clicked, this, &Window::transicion);
	connect(boton4, &QPushButton::clicked, this, &Window::ejemplo);
	connect(boton5, &QPushButton::clicked, this, &Window::limpiar);
	connect(boton6, &QPushButton::clicked, this, &Window::selectFinalState);
	
	connect(automaton, &Automata::emitResult, this, &Window::resultado);
}

void Window::test() {
	std::cout << "Modo: Test" << std::endl;
	QLresultado->setText(""); 
	automaton->PDA(inProbar->text());
}

void Window::agregar() {
	std::cout << "Modo: Agregar Automata" << std::endl;
	comentario->setText("Presiona sobre\nel mapa para\nagregar estado");
	QLresultado->setText(""); 
	automaton->opcion = 1;
}

void Window::transicion() {
	std::cout << "Modo: Agregar Transicion" << std::endl;
	comentario->setText("Mantén presionado\nsobre un estado y\narrastra en\ndirección hacia\nel destino");	
	QLresultado->setText(""); 
	automaton->opcion = 2;
}

void Window::selectFinalState() {
	std::cout << "Modo: Seleccionar / Eliminar estado final" << std::endl;
	comentario->setText("Presiona sobre\nel/los estado(s)\npara ser o quitar\nestado final");
	QLresultado->setText(""); 
	automaton->opcion = 3;
}

void Window::limpiar() {
	automaton->limpiar();
	automaton->opcion = 1;
	comentario->setText("Presiona sobre\nel mapa para\nagregar estado");
	QLresultado->setText("Estados limpiados");
}

void Window::resultado(int op) {
	switch (op) {
		case 1: QLresultado->setText("Estado guardado"); break;
		case -1: QLresultado->setText("Error al\nguardar estado"); break;
		
		case 2: QLresultado->setText("Transición guardada"); break;
		case 22: QLresultado->setText("Transición\ncancelada"); break;
		case -2: QLresultado->setText("No se encontró\nel origen/destino"); break;
		
		case 3: QLresultado->setText("Estado final\nseleccionado ó\ndeseleccionado"); break;
		case -3: QLresultado->setText("Estado no encontrado"); break;
		
		case 4: QLresultado->setText("Aceptado"); break;
		case -4: QLresultado->setText("Rechazado"); break;
		default: break;
	}
}

void Window::ejemplo() {
	automaton->mostrarEjemplo();
	automaton->opcion = 1;
	comentario->setText("Presiona sobre\nel mapa para\nagregar estado");
	QLresultado->setText("Ejemplo cargado");
}

