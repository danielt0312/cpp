#include <QApplication>
#include <QWidget>
#include <QFrame>
#include <QGridLayout>
#include <QPushButton>

class MyButton : public QWidget {

 public:
     MyButton(QWidget *parent = nullptr);
};

MyButton::MyButton(QWidget *parent)
    : QWidget(parent) {

  auto *quitBtn = new QPushButton("Salir", this);
  quitBtn->setGeometry(50, 40, 75, 30);

  connect(quitBtn, &QPushButton::clicked, qApp, &QApplication::quit);
}

class Cursors : public QWidget {

 public:
     Cursors(QWidget *parent = nullptr);
};

Cursors::Cursors(QWidget *parent)
    : QWidget(parent) {
  

  auto *frame1 = new QFrame(this);
  frame1->setFrameStyle(QFrame::Box);
  frame1->setCursor(Qt::SizeAllCursor);

  auto *frame2 = new QFrame(this);
  frame2->setFrameStyle(QFrame::Box);
  frame2->setCursor(Qt::WaitCursor);

  auto *frame3 = new QFrame(this);
  frame3->setFrameStyle(QFrame::Box);
  frame3->setCursor(Qt::PointingHandCursor);

  auto *grid = new QGridLayout(this);
  grid->addWidget(frame1, 0, 0);
  grid->addWidget(frame2, 0, 1);
  grid->addWidget(frame3, 0, 2);

  setLayout(grid);
}

int main(int argc, char *argv[]) {

  QApplication app(argc, argv);

  Cursors window;

  window.resize(350, 150);
  window.setWindowTitle("Cursors");
  window.show();

  return app.exec();
}


/*
int main(int argc, char *argv[]) {

  QApplication app(argc, argv);

  MyButton window;

  window.resize(250, 150);
  window.setWindowTitle("QPushButton");
  window.show();

  return app.exec();
}

*/
