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
	void test();
	void selectFinalState();
	void resultado(int);
	void ejemplo();
	QLineEdit *inProbar;
	QLabel *comentario, *QLresultado;
};

