#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QTextEdit>
#include "buttons.h"

Buttons::Buttons(QWidget *parent)
    : QWidget(parent) {

  auto *vbox1 = new QVBoxLayout();
  auto *vbox2 = new QVBoxLayout();
  auto *hbox = new QHBoxLayout(this);
  
  auto *textArea = new QTextEdit(this);

  okBtn = new QPushButton("OK", this);
    
  btn0 = new QPushButton("B0", this);
  btn1 = new QPushButton("B1", this);
  btn2 = new QPushButton("B2", this);
  btn3 = new QPushButton("B4", this);
  
  vbox1->addWidget(btn0, 0, Qt::AlignCenter);
  vbox1->addWidget(btn1, 0, Qt::AlignCenter);
  vbox1->addWidget(btn2, 0, Qt::AlignCenter);
  vbox1->addWidget(btn3, 0, Qt::AlignCenter);
  
  vbox2->addWidget(textArea, 1, Qt::AlignCenter);
  vbox2->addWidget(okBtn, 0, Qt::AlignCenter);
  
  hbox->addLayout(vbox1, 1);
  hbox->addLayout(vbox2, 2);
}
