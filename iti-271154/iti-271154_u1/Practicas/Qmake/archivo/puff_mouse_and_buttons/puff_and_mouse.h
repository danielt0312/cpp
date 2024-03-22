#pragma once

#include <QWidget>
#include <list>
// Estos dos compas deben ir juntos, si no hay pdos
//#include "puff_and_mouse.h"
#include <punto.h>
#include <fstream> // Incluye la biblioteca para trabajar con archivos

using namespace std;  


class Puff_and_Mouse : public QWidget {

  public:
    //~Puff_and_Mouse(); // Agrega el destructor

    list<Punto> listaPuntos; // Lista de Puntos

    Puff_and_Mouse(QWidget *parent = 0);

    void mousePressEvent(QMouseEvent* event);
    void mouseMoveEvent(QMouseEvent* event);
    void mouseReleaseEvent(QMouseEvent* event);

    void LimpiarPuntos ();
        void guardarPuntos ();
                void cargarPuntos ();
    void reiniciar(const QColor &color);

  protected:
    void paintEvent(QPaintEvent *event);
    void timerEvent(QTimerEvent *event);

  private:
    int x, w, h;
    int altoC, anchoC;
    qreal opacity;
    int timerId;
    int velocidad;
    QColor colorPincel;
    void doPainting();
        std::ofstream archivoSalida; // Declara el objeto ofstream para escribir en archivos

};
