#include "mainwindow.h"
#include "railroaddiagram.h"
#include <QTextEdit>
#include <QPushButton>
#include <QVBoxLayout>
#include <QGraphicsView>
#include <QGraphicsScene>
#include <QApplication>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
{
    textEdit = new QTextEdit(this);
    generateButton = new QPushButton("Generate Diagram", this);
    graphicsView = new QGraphicsView(this);
    scene = new QGraphicsScene(this);

    connect(generateButton, &QPushButton::clicked, this, &MainWindow::generateRailroadDiagram);

    // Configurar la política de tamaño de QTextEdit y QPushButton
    textEdit->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Fixed);
    generateButton->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Fixed);

    QGridLayout *layout = new QGridLayout;
    layout->addWidget(textEdit, 0, 0);
    layout->addWidget(generateButton, 1, 0, 0);
    layout->addWidget(graphicsView, 2, 0, 1, 2); // Se extiende a través de dos columnas

    QWidget *centralWidget = new QWidget;
    centralWidget->setLayout(layout);
    setCentralWidget(centralWidget);

    // Establecer tamaño mínimo para el QGraphicsView
    graphicsView->setMinimumSize(1520, 1080);

    graphicsView->setScene(scene);
}

void MainWindow::generateRailroadDiagram()
{
    QString grammar = textEdit->toPlainText();
    scene->clear();
    RailroadDiagram::generate(scene, grammar);
}

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    w.show();
    return a.exec();
}
