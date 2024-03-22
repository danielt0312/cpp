#pragma once

#include <QWidget>
#include "puff_and_mouse.h"

class Review : public QWidget {

  public:
    Review(QWidget *parent = nullptr);
    void az_aljo(); // Metodo recien agregado...

    Puff_and_Mouse *pm1;
};
