#pragma once

#include <QWidget>
#include "puff_and_mouse.h"

class QPushButton;


class Review : public QWidget {

  public:
    Review(QWidget *parent = nullptr);

  private:
    void az_aljo();

        void guardadoPuntos();
                void cargadoPuntos();

    Puff_and_Mouse *pm1;

};
