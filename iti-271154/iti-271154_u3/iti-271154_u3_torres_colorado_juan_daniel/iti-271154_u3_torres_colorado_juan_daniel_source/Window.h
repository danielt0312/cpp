#pragma once

#include <QWidget>
#include <QLineEdit>
#include <QLabel>

#include "Automata.h"

class Window : public QWidget {
public:
	Window(QWidget *parent = nullptr);
private:
    	Automata *automaton;
    	void agregar();
	void transicion();
	void limpiar();
	QLineEdit* inProbar;
	QLabel* comentario;
};

