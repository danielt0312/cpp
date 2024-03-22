#include <QGridLayout>
#include <QLabel>
#include <QLineEdit>
#include <QTextEdit>
#include <QPushButton>
#include "review.h"
#include "puff_and_mouse.h"

#include <iostream>
using namespace std; 


Review::Review(QWidget *parent)
    : QWidget(parent) {

    auto *grid = new QGridLayout(this);
    grid->setVerticalSpacing(15);
    grid->setHorizontalSpacing(10);

// Paneles originales
/*    auto *title = new QLabel("Title:", this);
    grid->addWidget(title, 0, 0, 1, 1);
    title->setAlignment(Qt::AlignRight | Qt::AlignVCenter);

    auto *edt1 = new QLineEdit(this);
    grid->addWidget(edt1, 0, 1, 1, 1);

    auto *author = new QLabel("Author:", this);
    grid->addWidget(author, 1, 0, 1, 1);
    author->setAlignment(Qt::AlignRight | Qt::AlignVCenter);

    auto *edt2 = new QLineEdit(this);
    grid->addWidget(edt2, 1, 1, 1, 1); */

    auto *boton1 = new QPushButton ("Funcion1", this);
    auto *boton2 = new QPushButton ("Funcion2", this);
    auto *boton3 = new QPushButton ("Funcion3", this);
    auto *boton4 = new QPushButton ("Funcion4", this);
    auto *boton5 = new QPushButton ("Funcion5", this);
    auto *boton6 = new QPushButton ("Funcion6", this);
    grid->addWidget(boton1, 0, 0, 1, 1);
    grid->addWidget(boton2, 0, 1, 1, 1);
    grid->addWidget(boton3, 1, 0, 1, 1);
    grid->addWidget(boton4, 1, 1, 1, 1);
    grid->addWidget(boton5, 0, 2, 1, 1);    
    grid->addWidget(boton6, 1, 2, 1, 1);

//  Lineas Originales del Demo Review - ZetCode
//  auto *review = new QLabel("Review:", this);
//  grid->addWidget(review, 2, 0, 1, 1);
//  review->setAlignment(Qt::AlignRight | Qt::AlignTop);
//  auto *te = new QTextEdit(this);
//  grid->addWidget(te, 2, 1, 3, 1);

//  Lineas Nuevas (Incluyendo las clases Puff and Mouse trabajadas en clase)

    //Puff_and_Mouse *pm1 = new Puff_and_Mouse(this);
    pm1 = new Puff_and_Mouse(this);
    QPalette pal = QPalette();

    pal.setColor(QPalette::Window, Qt::cyan);
    pm1->setAutoFillBackground(true); 
    pm1->setPalette(pal);

    grid->addWidget(pm1, 2, 0, 3, 3);

    setLayout(grid);

    connect(boton1, &QPushButton::clicked, this, &Review::az_aljo);
}

void Review::az_aljo() {
    cout<<"ES que me as klickedo"<< '\n';
    pm1->LimpiarPuntos();
  //int val = lbl->text().toInt();
  //val++;
  //lbl->setText(QString::number(val));
}
