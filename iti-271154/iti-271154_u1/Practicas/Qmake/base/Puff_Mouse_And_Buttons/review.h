#pragma once

#include <QWidget>
#include "puff_and_mouse.h"
#include "finddialog.h"

class Review : public QWidget {
  public:
    Review(QWidget *parent = nullptr);
    void az_aljo(); // Metodo recien agregado...
    void cambiarRadio();
    void setRadio(int);
    FindDialog * findDialog; //(".",this);
    
    Puff_and_Mouse *pm1;
};
