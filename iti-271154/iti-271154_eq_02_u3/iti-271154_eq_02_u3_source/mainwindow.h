// mainwindow.h
#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

class QTextEdit;
class QPushButton;
class QGraphicsView;
class QGraphicsScene;

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);

private slots:
    void generateRailroadDiagram();

private:
    QTextEdit *textEdit;
    QPushButton *generateButton;
    QGraphicsView *graphicsView;
    QGraphicsScene *scene;
};

#endif // MAINWINDOW_H
