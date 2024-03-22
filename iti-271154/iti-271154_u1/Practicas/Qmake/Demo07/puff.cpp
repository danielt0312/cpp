#include <QPainter>
#include <QTimer>
#include <QTextStream>
#include "puff.h"

Puff::Puff(QWidget *parent)
    : QWidget(parent) {
        
  x = 1;
  opacity = 1.0;
  timerId = startTimer(15);
  velocidad = 10;
  
  h = height();
  w = width();
  
  altoC = 100;
  anchoC = 100;
}

void Puff::paintEvent(QPaintEvent *e) {
    
  Q_UNUSED(e);  
  
  doPainting();
}

void Puff::doPainting() {
  
  QPainter painter(this);
  QTextStream out(stdout);

  QString text = "Daniel";

  painter.setPen(QPen(QBrush("#575555"), 1));

  QFont font("Courier", x, QFont::DemiBold);
  QFontMetrics fm(font);
  int textWidth = fm.width(text);  
  painter.setFont(font);
  if (x > 10) {
    opacity -= 0.01;
    //painter.setOpacity(opacity);
  }

  if (opacity <= 0) {
    //    killTimer(timerId);
    // out << "timer stopped" << endl;
  }

  h = height();
  w = width();

//  painter.translate(QPoint(w/2, h/2));
//  painter.drawText(-textWidth/2, 0, text);
  painter.drawEllipse(x, (h/2)-50, anchoC, altoC);
}

void Puff::timerEvent(QTimerEvent *e) {
  Q_UNUSED(e);
  
  if(x > (w-anchoC))
    velocidad*=-1;
  if(x < 0) 
    velocidad*=-1;
 
  x += velocidad;
  repaint();
}
