#include <QPainter>
#include "lines.h"

Lines::Lines(QWidget *parent)
    : QWidget(parent)
{ }

void Lines::paintEvent(QPaintEvent *e) {
    
  Q_UNUSED(e);
  
  QPainter qp(this);
  drawLines(&qp);
}

void Lines::drawLines(QPainter *qp) {
  /*
  QPen pen(Qt::black, 2, Qt::SolidLine);  
  qp->setPen(pen);
  qp->drawLine(20, 40, 250, 40);

  pen.setStyle(Qt::DashLine);
  qp->setPen(pen);
  qp->drawLine(20, 80, 250, 80);

  pen.setStyle(Qt::DashDotLine);
  qp->setPen(pen);
  qp->drawLine(20, 120, 250, 120);

  pen.setStyle(Qt::DotLine);
  qp->setPen(pen);
  qp->drawLine(20, 160, 250, 160);

  pen.setStyle(Qt::DashDotDotLine);
  qp->setPen(pen);
  qp->drawLine(20, 200, 250, 200);

  QVector<qreal> dashes;
  qreal space = 4;

  dashes << 1 << space << 5 << space;

  pen.setStyle(Qt::CustomDashLine);
  pen.setDashPattern(dashes);
  
  qp->setPen(pen);
  qp->drawLine(20, 240, 250, 240);
  */
  /*
  // QPainter painter(this);
  qp->setPen(QColor("#d4d4d4"));

  // qp->setBrush(QBrush("#c56c00"));
  // Patrones
  qp->setBrush(Qt::Dense6Pattern);
  qp->drawRect(10, 15, 90, 60);

  qp->setBrush(QBrush("#1ac500"));
  qp->drawRect(130, 15, 90, 60);

  qp->setBrush(QBrush("#539e47"));
  qp->drawRect(250, 15, 90, 60);
  
  qp->setBrush(QBrush("#004fc5"));
  qp->drawRect(10, 105, 90, 60);

  qp->setBrush(QBrush("#c50024"));
  qp->drawRect(130, 105, 90, 60);

  qp->setBrush(QBrush("#9e4757"));
  qp->drawRect(250, 105, 90, 60);

  qp->setBrush(QBrush("#5f3b00"));
  qp->drawRect(10, 195, 90, 60);

  qp->setBrush(QBrush("#4c4c4c"));
  qp->drawRect(130, 195, 90, 60);

  qp->setBrush(QBrush("#785f36"));
  qp->drawRect(250, 195, 90, 60);
  
  
  for (int i=1; i<=11; i++) {
    qp->setOpacity(i*0.1);
    qp->fillRect(50*i, 270, 40, 40, Qt::darkGray);
  }
  */
  qp->setPen(QPen(QBrush("#535353"), 0.5));
  qp->setRenderHint(QPainter::Antialiasing);

  int h = height();
  int w = width();

  qp->translate(QPoint(w/2, h/2));

  for (qreal rot=0; rot < 360; rot+=5.0 ) {
      qp->drawEllipse(-125, -40, 250, 80);
      qp->rotate(5.0);
  }
}
