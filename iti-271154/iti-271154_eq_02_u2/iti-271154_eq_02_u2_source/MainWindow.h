#include <QApplication>
#include <QWidget>
#include <QPushButton>
#include <QInputDialog>
#include <QPainter>
#include <QPointF>
#include <QVector>
#include <QRandomGenerator>
#include <QVBoxLayout>
#include <QMenu>
#include <QtMath>
#include <QMainWindow>
#include <QMouseEvent>
#include <QMessageBox>
#include <QLabel>
#include <QDebug>
#include <QTimer>
#include <QTextEdit>
#include <QThread>
#include "CircleWidget.h"
#include "TextDialog.h"
#include "TextDialog2.h"

class MainWindow : public QWidget {
public:
 MainWindow(QWidget *parent = nullptr) : QWidget(parent) {
    resize(1920, 820);

    // Botón Create
    buttonCreate.setText("Create");
    buttonCreate.setFixedSize(100, 30); 
    layout.addWidget(&buttonCreate);

    // Botón Edit Points
    buttonEditPoints.setText("Edit Points");
    buttonEditPoints.setFixedSize(100, 30);
    layout.addWidget(&buttonEditPoints);

    // Botón Example Point
    buttonExamplePoint.setText("Example Point");
    buttonExamplePoint.setFixedSize(100, 30); 
    layout.addWidget(&buttonExamplePoint);

    // Botón "Andrew Chain"
    buttonAndrew.setText("Andrew_Chain");
    buttonAndrew.setFixedSize(100, 30); 
    layout.addWidget(&buttonAndrew);

    // Botón "ch graham"
    buttonCHGraham.setText("Ch Graham");
    buttonCHGraham.setFixedSize(100, 30); 
    layout.addWidget(&buttonCHGraham);

    buttonShamos.setText("Shamos");
    buttonShamos.setFixedSize(100, 30); 
    layout.addWidget(&buttonShamos);

    // Agregar el widget de círculo al diseño
    layout.addWidget(&circleWidget);

    // Establecer el diseño en la ventana principal
    setLayout(&layout);

    // Conectar los botones a las funciones correspondientes
    connect(&buttonCreate, &QPushButton::clicked, this, &MainWindow::createCircles);
    connect(&buttonEditPoints, &QPushButton::clicked, this, &MainWindow::editPoints);
    connect(&buttonExamplePoint, &QPushButton::clicked, this, &MainWindow::showExamplePointMenu);
    connect(&buttonAndrew, &QPushButton::clicked, this, &MainWindow::AndrewChain);
    connect(&buttonCHGraham, &QPushButton::clicked, this, &MainWindow::CHgraham);
    connect(&buttonShamos, &QPushButton::clicked, this, &MainWindow::CHgraham);

}


void createCircles() {
    bool ok;
    int count = QInputDialog::getInt(this, "Ingrese un número", "Número de círculos:", 1, 1, 30, 1, &ok);
    if (ok) {
        circleWidget.clearCanvas(); // Limpiar círculos y líneas
        QVector<QPointF> positions;
        QRandomGenerator randomGenerator;
        // Generar posiciones aleatorias para los círculos
        for (int i = 0; i < count; ++i) {
            qreal x = randomGenerator.bounded(width() - 100);  // Limitar el rango para evitar que los círculos se dibujen fuera de la ventana
            qreal y = randomGenerator.bounded(height() - 100); // Limitar el rango para evitar que los círculos se dibujen fuera de la ventana
            positions.push_back(QPointF(x, y));
        }
        // Establecer las posiciones de los círculos en el CircleWidget
        circleWidget.setCirclePositions(positions);
    }
}

    void showExamplePointMenu() {
        QMenu menu(this);
        QAction *squareAction = menu.addAction("Square");
        QAction *pentagonAction = menu.addAction("Pentagon");
        QAction *crescentAction = menu.addAction("Crescent");
        QAction *circleAction = menu.addAction("Circle");

        connect(squareAction, &QAction::triggered, this, &MainWindow::createSquare);
        connect(pentagonAction, &QAction::triggered, this, &MainWindow::createPentagon);
        connect(crescentAction, &QAction::triggered, this, &MainWindow::createCrescent);
        connect(circleAction, &QAction::triggered, this, &MainWindow::createCircle);

        menu.exec(buttonExamplePoint.mapToGlobal(QPoint(0, buttonExamplePoint.height())));
    }
void editPoints() {
    // Crear una instancia de la ventana de edición de puntos
    QDialog editPointsDialog(this);
    editPointsDialog.setWindowTitle("Edit Points");

    // Configurar la geometría de la ventana
    editPointsDialog.resize(1920, 720);

    // Crear un widget personalizado para mostrar los dibujos
    CircleWidget circleWidgetCopy(&editPointsDialog);
    circleWidgetCopy.setCirclePositions(circleWidget.getCirclePositions());

    // Mostrar los dibujos en la ventana de edición de puntos
    QVBoxLayout dialogLayout(&editPointsDialog);
    dialogLayout.addWidget(&circleWidgetCopy);

    // Agregar un botón "Cancelar"
    QPushButton cancelButton("Cancelar", &editPointsDialog);
    dialogLayout.addWidget(&cancelButton);

    // Agregar un botón "Borrar Dibujos"
    QPushButton clearButton("Borrar Dibujos", &editPointsDialog);
    dialogLayout.addWidget(&clearButton);

    // Agregar un botón "Done"
    QPushButton doneButton("Done", &editPointsDialog);
    dialogLayout.addWidget(&doneButton);
    editPointsDialog.setLayout(&dialogLayout);

    // Conectar la señal clicked del botón "Cancelar" para cerrar la ventana de edición de puntos
    connect(&cancelButton, &QPushButton::clicked, &editPointsDialog, &QDialog::reject);

    // Conectar la señal clicked del botón "Borrar Dibujos" para limpiar los dibujos en la segunda pantalla
    connect(&clearButton, &QPushButton::clicked, [&circleWidgetCopy, this]() {
        circleWidgetCopy.clearCanvas();
        this->circleWidget.clearCanvas(); // Corrección: Capturar circleWidget usando this->circleWidget

        // Restablecer ActiveMethod a 0
        ActiveMethod = 0;

        // Detener el temporizador
        timer.stop();

        // Actualizar los círculos en circleWidget con las posiciones de circleWidgetCopy
        this->circleWidget.setCirclePositions(circleWidgetCopy.getCirclePositions());

        // Actualizar los widgets para que se repinten
        circleWidgetCopy.update(); // Actualizar circleWidgetCopy
        this->circleWidget.update(); // Corrección: Actualizar circleWidget usando this->circleWidget
    });

    // Conectar la señal clicked del botón "Done" para transferir los dibujos de la segunda ventana a la primera ventana
    connect(&doneButton, &QPushButton::clicked, [&circleWidgetCopy, &editPointsDialog, this]() {
        QVector<QPointF> positions = circleWidgetCopy.getCirclePositions();
        circleWidget.setCirclePositions(positions);
        editPointsDialog.accept(); // Cerrar la ventana de edición de puntos después de transferir los dibujos
    });

    // Mostrar la ventana de edición de puntos
    editPointsDialog.exec();
}


    void createSquare() {
        circleWidget.drawSquare();
    }

    void createPentagon() {
        circleWidget.drawPentagon();
    }

    void createCrescent() {
        circleWidget.drawCrescent();    
    }

    void createCircle() {
        circleWidget.drawCircle();    
    }

        void AndrewChain() {
            ActiveMethod = 1;
            // Desconectar la señal timeout() antes de volver a conectarla
            disconnect(&timer, SIGNAL(timeout()), this, SLOT(repaint()));

            // Configurar el QTimer para llamar a repaint cada 100 milisegundos
            connect(&timer, SIGNAL(timeout()), this, SLOT(repaint()));
            timer.start(500); // Intervalo de 100 milisegundos

            // Obtener las coordenadas de los círculos desde CircleWidget
            QVector<QPointF> circlePositions = circleWidget.getCirclePositions();

            // Imprimir las coordenadas de los círculos antes de dibujar el recorrido
            qDebug() << "Coordenadas de los círculos antes de dibujar el recorrido:";
            for (const QPointF &pos : circlePositions) {
                qDebug() << pos;
            }

       update();
        }


        void CHgraham(){
            ActiveMethod = 2;
            
            // Desconectar la señal timeout() antes de volver a conectarla
            disconnect(&timer, SIGNAL(timeout()), this, SLOT(repaint()));

            // Configurar el QTimer para llamar a repaint cada 500 milisegundos
            connect(&timer, SIGNAL(timeout()), this, SLOT(repaint()));
            timer.start(500); // Intervalo de 500 milisegundos

            // Obtener las coordenadas de los círculos desde CircleWidget
            QVector<QPointF> circlePositions = circleWidget.getCirclePositions();

            // Imprimir las coordenadas de los círculos antes de dibujar el recorrido
            qDebug() << "Coordenadas de los círculos antes de dibujar el recorrido:";
            for (const QPointF &pos : circlePositions) {
                qDebug() << pos;
            }

        update();
    }


    void shamos(){
        ActiveMethod = 3;
            
            // Desconectar la señal timeout() antes de volver a conectarla
            disconnect(&timer, SIGNAL(timeout()), this, SLOT(repaint()));

            // Configurar el QTimer para llamar a repaint cada 500 milisegundos
            connect(&timer, SIGNAL(timeout()), this, SLOT(repaint()));
            timer.start(500); // Intervalo de 500 milisegundos

            // Obtener las coordenadas de los círculos desde CircleWidget
            QVector<QPointF> circlePositions = circleWidget.getCirclePositions();

            // Imprimir las coordenadas de los círculos antes de dibujar el recorrido
            qDebug() << "Coordenadas de los círculos antes de dibujar el recorrido:";
            for (const QPointF &pos : circlePositions) {
                qDebug() << pos;
            }
    }


protected:
void paintEvent(QPaintEvent *event) override {
    QWidget::paintEvent(event);
    QPainter painter(this);
    painter.setRenderHint(QPainter::Antialiasing, true);

    // Determinar el método activo y tomar decisiones basadas en él
    switch (ActiveMethod) {
        case 0:
            qDebug() << "aaa";
            timer.stop();
            break;
        case 1:
            qDebug() << "Andrew";
            drawAndrew(painter);          
            break;
        case 2:
            qDebug() << "Graham";
            drawCirclesGH(painter);
            break;
        case 3:
            qDebug() << "shamos";  
            drawCirclesShamos(painter);
            break;
}
}

//______________________________________________________________________________________________________________________________

void drawAndrew(QPainter &painter) {
    static int currentIndex = 0; // Variable para almacenar el índice actual
    QVector<QPointF> circlePositions = circleWidget.getCirclePositions();
    qreal offsetX = 10; // Desplazamiento en X
    qreal offsetY = 220; // Desplazamiento en Y
    
    // Limpiar la pantalla antes de dibujar las nuevas líneas
    clearScreen(painter);

    // Establecer el color de las líneas para dibujar la conexión de todos los puntos
    painter.setPen(Qt::blue);

    // Dibujar las líneas que conectan todos los puntos (unir todos los círculos)
    for (int i = 0; i < circlePositions.size(); ++i) {
        for (int j = i + 1; j < circlePositions.size(); ++j) {
            QPointF currentPos = circlePositions[i] + QPointF(offsetX, offsetY);
            QPointF nextPos = circlePositions[j] + QPointF(offsetX, offsetY);
            painter.drawLine(currentPos, nextPos);
        }
    }

    // Calcular la envolvente convexa utilizando el algoritmo de Andrew's Chain
    QVector<QPointF> convexHull = andrewsChain(circlePositions);

    // Verificar si la envolvente convexa se ha calculado correctamente
    if (convexHull.size() < 3) {
        qDebug() << "No se pueden formar suficientes puntos para la envolvente convexa.";
        return;
    }

    // Establecer el color y el grosor de las líneas para dibujar la envolvente convexa
    QPen pen(Qt::red); // Crear un pincel rojo
    pen.setWidth(2); // Establecer el grosor de la línea
    painter.setPen(pen); // Configurar el pincel
    
    // Dibujar las líneas que conectan los puntos de la envolvente convexa
    for (int i = 0; i <= currentIndex; ++i) {
        QPointF currentPos = convexHull[i] + QPointF(offsetX, offsetY);
        QPointF nextPos = convexHull[(i + 1) % convexHull.size()] + QPointF(offsetX, offsetY); // Para hacerlo cíclico
        painter.drawLine(currentPos, nextPos);
    }

    // Incrementar el índice para dibujar el siguiente paso en el próximo ciclo
    currentIndex++;

    // Si hemos alcanzado el último punto, reiniciamos el índice y detenemos el temporizador
    if (currentIndex == convexHull.size()) {
        currentIndex = 0;
        timer.stop(); // Detener el temporizador una vez que se han dibujado todas las líneas
    }
}


// Función para calcular el producto cruzado de tres puntos
qreal crossProduct(const QPointF &p1, const QPointF &p2, const QPointF &p3) {
    return (p2.x() - p1.x()) * (p3.y() - p1.y()) - (p2.y() - p1.y()) * (p3.x() - p1.x());
}

QVector<QPointF> andrewsChain(const QVector<QPointF> &points) {
    // Ordenar los puntos según sus coordenadas x
    QVector<QPointF> sortedPoints = points;
    std::sort(sortedPoints.begin(), sortedPoints.end(), [](const QPointF &a, const QPointF &b) {
        return a.x() < b.x() || (a.x() == b.x() && a.y() < b.y());
    });

    // Construir la envolvente inferior
    QVector<QPointF> lowerHull;
    for (const QPointF &p : sortedPoints) {
        while (lowerHull.size() >= 2 && crossProduct(lowerHull[lowerHull.size() - 2], lowerHull.back(), p) <= 0) {
            lowerHull.pop_back();
        }
        lowerHull.push_back(p);
    }

    // Construir la envolvente superior
    QVector<QPointF> upperHull;
    for (int i = sortedPoints.size() - 1; i >= 0; --i) {
        const QPointF &p = sortedPoints[i];
        while (upperHull.size() >= 2 && crossProduct(upperHull[upperHull.size() - 2], upperHull.back(), p) <= 0) {
            upperHull.pop_back();
        }
        upperHull.push_back(p);
    }

    // Combinar la envolvente inferior y superior para obtener el contorno convexo
    QVector<QPointF> convexHull;
    convexHull.reserve(lowerHull.size() + upperHull.size() - 2);
    for (int i = 0; i < lowerHull.size() - 1; ++i) {
        convexHull.push_back(lowerHull[i]);
    }
    for (int i = 0; i < upperHull.size() - 1; ++i) {
        convexHull.push_back(upperHull[i]);
    }

    return convexHull;
}


//______________________________________________________________________________________________________________________________
void drawCirclesGH(QPainter &painter) {
    static int currentIndex = 0; // Variable para almacenar el índice actual
    QVector<QPointF> circlePositions = circleWidget.getCirclePositions();
    qreal offsetX = 10; // Desplazamiento en X
    qreal offsetY = 220; // Desplazamiento en Y
    
    // Limpiar la pantalla antes de dibujar las nuevas líneas
    clearScreen(painter);

    // Establecer el color de las líneas para dibujar la conexión de todos los puntos
    painter.setPen(Qt::blue);

    // Dibujar las líneas que conectan todos los puntos (unir todos los círculos)
    for (int i = 0; i < circlePositions.size(); ++i) {
        for (int j = i + 1; j < circlePositions.size(); ++j) {
            QPointF currentPos = circlePositions[i] + QPointF(offsetX, offsetY);
            QPointF nextPos = circlePositions[j] + QPointF(offsetX, offsetY);
            painter.drawLine(currentPos, nextPos);
        }
    }

    // Calcular la envolvente convexa utilizando el algoritmo de Graham Scan
    QVector<QPointF> convexHull = grahamScan(circlePositions);

    // Verificar si la envolvente convexa se ha calculado correctamente
    if (convexHull.size() < 3) {
        qDebug() << "No se pueden formar suficientes puntos para la envolvente convexa.";
        return;
    }

    // Establecer el color de las líneas para dibujar la envolvente convexa
    painter.setPen(Qt::red); // Inicialmente en azul
    
    // Dibujar las líneas que conectan los puntos de la envolvente convexa
    for (int i = 0; i <= currentIndex; ++i) {
        QPointF currentPos = convexHull[i] + QPointF(offsetX, offsetY);
        QPointF nextPos = convexHull[(i + 1) % convexHull.size()] + QPointF(offsetX, offsetY); // Para hacerlo cíclico
        painter.drawLine(currentPos, nextPos);
    }

    // Incrementar el índice para dibujar el siguiente paso en el próximo ciclo
    currentIndex++;

    // Si hemos alcanzado el último punto, reiniciamos el índice y detenemos el temporizador
    if (currentIndex == convexHull.size()) {
        currentIndex = 0;
        timer.stop(); // Detener el temporizador una vez que se han dibujado todas las líneas
    }
}


QVector<QPointF> grahamScan(const QVector<QPointF> &points) {
    // Verificar si hay suficientes puntos para formar una envolvente convexa
    if (points.size() < 3) {
        qDebug() << "No se pueden formar suficientes puntos para la envolvente convexa.";
        return QVector<QPointF>();
    }

    // Encontrar el punto con la coordenada Y más baja (y más izquierda en caso de empate)
    int minYIndex = 0;
    qreal minY = points[0].y();
    for (int i = 1; i < points.size(); ++i) {
        qreal y = points[i].y();
        if (y < minY || (y == minY && points[i].x() < points[minYIndex].x())) {
            minY = y;
            minYIndex = i;
        }
    }

    // Ordenar los puntos según su ángulo polar con respecto al punto minYIndex
    QVector<QPointF> sortedPoints = points;
    std::sort(sortedPoints.begin(), sortedPoints.end(), [&](const QPointF &p1, const QPointF &p2) {
        int orientation = getOrientation(points[minYIndex], p1, p2);
        if (orientation == 0)
            return distSquared(points[minYIndex], p1) < distSquared(points[minYIndex], p2);
        return orientation == 2;
    });

    // Inicializar el stack para almacenar los puntos de la envolvente convexa
    QVector<QPointF> convexHull;
    convexHull.push_back(sortedPoints[0]);
    convexHull.push_back(sortedPoints[1]);

    // Procesar el resto de los puntos para construir la envolvente convexa
    for (int i = 2; i < sortedPoints.size(); ++i) {
        while (convexHull.size() >= 2 && getOrientation(convexHull[convexHull.size() - 2], convexHull[convexHull.size() - 1], sortedPoints[i]) != 2) {
            convexHull.pop_back();
        }
        convexHull.push_back(sortedPoints[i]);
    }

    return convexHull;
}

// Función para calcular la orientación de tres puntos (utilizada en el algoritmo de Graham Scan)
int getOrientation(const QPointF &p1, const QPointF &p2, const QPointF &p3) {
    qreal val = (p2.y() - p1.y()) * (p3.x() - p2.x()) -
                (p2.x() - p1.x()) * (p3.y() - p2.y());

    if (qFuzzyCompare(val, 0))
        return 0; // Colineales
    return (val > 0) ? 1 : 2; // Sentido horario o antihorario
}

// Función para calcular la distancia al cuadrado entre dos puntos (utilizada en el algoritmo de Graham Scan)
qreal distSquared(const QPointF &p1, const QPointF &p2) {
    qreal dx = p2.x() - p1.x();
    qreal dy = p2.y() - p1.y();
    return dx * dx + dy * dy;
}

//______________________________________________________________________________________________________________________________
void drawCirclesShamos(QPainter &painter) {
    static int currentIndex = 0; // Variable para almacenar el índice actual
    QVector<QPointF> circlePositions = circleWidget.getCirclePositions();
    qreal offsetX = 10; // Desplazamiento en X
    qreal offsetY = 220; // Desplazamiento en Y
    
    // Limpiar la pantalla antes de dibujar las nuevas líneas
    clearScreen(painter);

    // Calcular la envolvente convexa utilizando el algoritmo de Shamos
    QVector<QPointF> convexHull = shamosAlgorithm(circlePositions);

    // Verificar si la envolvente convexa se ha calculado correctamente
    if (convexHull.size() < 3) {
        qDebug() << "No se pueden formar suficientes puntos para la envolvente convexa.";
        return;
    }

    // Establecer el color de las líneas para dibujar la envolvente convexa
    painter.setPen(Qt::green);

    // Dibujar las líneas que conectan los puntos de la envolvente convexa
    for (int i = 0; i <= currentIndex; ++i) {
        QPointF currentPos = convexHull[i] + QPointF(offsetX, offsetY);
        QPointF nextPos = convexHull[(i + 1) % convexHull.size()] + QPointF(offsetX, offsetY); // Para hacerlo cíclico
        painter.drawLine(currentPos, nextPos);
    }

    // Calcular los puntos de las tangentes superior e inferior
    QPointF leftmostPoint = convexHull[0] + QPointF(offsetX, offsetY);
    QPointF rightmostPoint = convexHull[convexHull.size() - 1] + QPointF(offsetX, offsetY);
    QPointF upperTangentPoint = upperTangent(convexHull, convexHull, leftmostPoint, rightmostPoint);
    QPointF lowerTangentPoint = lowerTangent(convexHull, convexHull, leftmostPoint, rightmostPoint);

    // Dibujar las líneas de las tangentes superior e inferior
    painter.setPen(Qt::red); // Color rojo para las líneas de las tangentes
    painter.drawLine(leftmostPoint, upperTangentPoint);
    painter.drawLine(leftmostPoint, lowerTangentPoint);

    // Incrementar el índice para dibujar el siguiente paso en el próximo ciclo
    currentIndex++;

    // Si hemos alcanzado el último punto, reiniciamos el índice y detenemos el temporizador
    if (currentIndex == convexHull.size()) {
        currentIndex = 0;
        timer.stop(); // Detener el temporizador una vez que se han dibujado todas las líneas
    }
}

QVector<QPointF> shamosAlgorithm(const QVector<QPointF> &points) {
    // Verificar si hay suficientes puntos para formar una envolvente convexa
    if (points.size() < 3) {
        qDebug() << "No se pueden formar suficientes puntos para la envolvente convexa.";
        return QVector<QPointF>();
    }

    // Ordenar los puntos según sus coordenadas x
    QVector<QPointF> sortedPoints = points;
    std::sort(sortedPoints.begin(), sortedPoints.end(), [](const QPointF &a, const QPointF &b) {
        return a.x() < b.x() || (a.x() == b.x() && a.y() < b.y());
    });

    // Llamar a la función recursiva para calcular la envolvente convexa
    return divideAndConquer(sortedPoints);
}

QVector<QPointF> divideAndConquer(const QVector<QPointF> &points) {
    // Si hay pocos puntos, se calcula la envolvente convexa directamente
    if (points.size() <= 3) {
        return grahamScan(points);
    }

    // Dividir los puntos en dos grupos
    int mid = points.size() / 2;
    QVector<QPointF> leftPoints(points.begin(), points.begin() + mid);
    QVector<QPointF> rightPoints(points.begin() + mid, points.end());

    // Calcular la envolvente convexa de cada grupo recursivamente
    QVector<QPointF> leftHull = divideAndConquer(leftPoints);
    QVector<QPointF> rightHull = divideAndConquer(rightPoints);

    // Combinar las envolventes convexas de ambos grupos
    return mergeHulls(leftHull, rightHull);
}

QVector<QPointF> mergeHulls(const QVector<QPointF> &leftHull, const QVector<QPointF> &rightHull) {
    // Encontrar los puntos extremos en la envolvente convexa izquierda y derecha
    QPointF leftmostPoint = *std::min_element(leftHull.begin(), leftHull.end(), [](const QPointF &a, const QPointF &b) {
        return a.x() < b.x();
    });
    QPointF rightmostPoint = *std::max_element(rightHull.begin(), rightHull.end(), [](const QPointF &a, const QPointF &b) {
        return a.x() < b.x();
    });

    // Encontrar los puntos superiores e inferiores comunes entre las envolventes convexas izquierda y derecha
    QPointF upperCommon = upperTangent(leftHull, rightHull, leftmostPoint, rightmostPoint);
    QPointF lowerCommon = lowerTangent(leftHull, rightHull, leftmostPoint, rightmostPoint);

    // Concatenar las envolventes convexas izquierda y derecha para formar la envolvente convexa global
    QVector<QPointF> convexHull;
    convexHull.reserve(leftHull.size() + rightHull.size());

    // Agregar la envolvente convexa izquierda hasta el punto superior común
    int index = std::find(leftHull.begin(), leftHull.end(), upperCommon) - leftHull.begin();
    for (int i = 0; i <= index; ++i) {
        convexHull.push_back(leftHull[i]);
    }

    // Agregar la envolvente convexa derecha desde el punto inferior común hacia atrás
    index = std::find(rightHull.begin(), rightHull.end(), lowerCommon) - rightHull.begin();
    for (int i = rightHull.size() - 1; i >= index; --i) {
        convexHull.push_back(rightHull[i]);
    }

    return convexHull;
}

QPointF upperTangent(const QVector<QPointF> &leftHull, const QVector<QPointF> &rightHull,
                     const QPointF &leftmostPoint, const QPointF &rightmostPoint) {
    // Encontrar el punto en la envolvente convexa izquierda con la pendiente más grande
    QPointF upperTangentPoint;
    qreal maxSlope = -std::numeric_limits<qreal>::infinity();
    for (const QPointF &point : leftHull) {
        qreal slope = (point.y() - rightmostPoint.y()) / (point.x() - rightmostPoint.x());
        if (slope > maxSlope) {
            maxSlope = slope;
            upperTangentPoint = point;
        }
    }

    // Encontrar el punto en la envolvente convexa derecha con la pendiente más pequeña
    for (const QPointF &point : rightHull) {
        qreal slope = (point.y() - leftmostPoint.y()) / (point.x() - leftmostPoint.x());
        if (slope < maxSlope) {
            maxSlope = slope;
            upperTangentPoint = point;
        }
    }

    return upperTangentPoint;
}

QPointF lowerTangent(const QVector<QPointF> &leftHull, const QVector<QPointF> &rightHull,
                     const QPointF &leftmostPoint, const QPointF &rightmostPoint) {
    // Encontrar el punto en la envolvente convexa izquierda con la pendiente más pequeña
    QPointF lowerTangentPoint;
    qreal minSlope = std::numeric_limits<qreal>::infinity();
    for (const QPointF &point : leftHull) {
        qreal slope = (point.y() - rightmostPoint.y()) / (point.x() - rightmostPoint.x());
        if (slope < minSlope) {
            minSlope = slope;
            lowerTangentPoint = point;
        }
    }

    // Encontrar el punto en la envolvente convexa derecha con la pendiente más grande
    for (const QPointF &point : rightHull) {
        qreal slope = (point.y() - leftmostPoint.y()) / (point.x() - leftmostPoint.x());
        if (slope > minSlope) {
            minSlope = slope;
            lowerTangentPoint = point;
        }
    }

    return lowerTangentPoint;
}


void clearScreen(QPainter &painter) {
    painter.fillRect(rect(), Qt::white);
}


private:
    int numAndrewCircles = 0;
    int currentCircleIndex = 0;
    QPushButton buttonCHGraham;
    QTimer timer;
    QPushButton buttonCreate;
    QPushButton buttonEditPoints;
    QPushButton buttonExamplePoint;
    QPushButton buttonAndrew;
    QPushButton buttonShamos;
    CircleWidget circleWidget;
    QVBoxLayout layout;
    qreal squareLeft;
    qreal squareTop;
    QVector<QPointF> circlePositions; 
    int ActiveMethod = 0;
    int animationIndex;
    QVector<QPointF> positions;
    qreal radius;
};
