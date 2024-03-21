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

class CircleWidget : public QWidget {
public:
    CircleWidget(QWidget *parent = nullptr) : QWidget(parent) {}

    QVector<QPointF> getCirclePositions() const {
        return circlePositions;
    }

    void setCircleCount(int count) {
        circleCount = count;
        generateCirclePositions(); // Generar nuevas posiciones de círculos
        update(); // Redraw
    }

    void clearCanvas() {
        circlePositions.clear(); // Limpiar las posiciones de los círculos
        update(); // Redraw
    }
    
    void clearCircles() {
        circlePositions.clear(); // Limpiar todas las posiciones de los círculos
        update(); // Redibujar
    }

    void setCirclePositions(const QVector<QPointF>& positions) {
        circlePositions = positions;
        update(); // Redibujar con las nuevas posiciones
    }

    void addCircle(const QPointF& position) {
        circlePositions.append(position);
        update(); // Redibujar el widget para mostrar el nuevo círculo
    }

   void drawSquare() {
    // Limpiar el lienzo antes de dibujar nuevos círculos
    clearCanvas();

    // Obtener el tamaño del círculo
    qreal radius = 70;

    // Obtener el centro del widget
    qreal centerX = width() / 2.0;
    qreal centerY = height() / 2.0;

    // Calcular las posiciones de los cuatro vértices del cuadrado
    qreal x1 = centerX - radius * 2; // Arriba a la izquierda
    qreal y1 = centerY - radius * 2;
    qreal x2 = centerX + radius * 2; // Arriba a la derecha
    qreal y2 = centerY - radius * 2;
    qreal x3 = centerX - radius * 2; // Abajo a la izquierda
    qreal y3 = centerY + radius * 2;
    qreal x4 = centerX + radius * 2; // Abajo a la derecha
    qreal y4 = centerY + radius * 2;

    // Agregar las posiciones de los cuatro círculos a la lista de posiciones
    circlePositions.clear();
    circlePositions.append(QPointF(x1, y1));
    circlePositions.append(QPointF(x2, y2));
    circlePositions.append(QPointF(x3, y3));
    circlePositions.append(QPointF(x4, y4));

    // Dibujar los círculos con relleno blanco y contorno negro
    QPainter painter(this);
    painter.setRenderHint(QPainter::Antialiasing, true);
    painter.setBrush(Qt::white); // Relleno blanco
    painter.setPen(Qt::black); // Contorno negro
    for (const QPointF &position : circlePositions) {
        painter.drawEllipse(position, radius, radius);
    }

    // Redibujar los círculos
    update();
}

void drawPentagon() {
    // Limpiar el lienzo antes de dibujar nuevos círculos
    clearCanvas();

    // Obtener el tamaño del círculo (vértice)
    qreal radius = 60;

    // Obtener el centro del widget
    qreal centerX = width() / 2.0;
    qreal centerY = height() / 2.0;

    // Calcular las posiciones de los vértices del pentágono
    qreal angle = 360.0 / 5;
    qreal pentagonRadius = 2 * radius * qSin(qDegreesToRadians(54.0)) / qSin(qDegreesToRadians(126.0));

    qreal x1 = centerX;  // Punto superior
    qreal y1 = centerY - pentagonRadius;
    qreal x2 = centerX + pentagonRadius * qCos(qDegreesToRadians(angle)); // Superior derecho
    qreal y2 = centerY + pentagonRadius * qSin(qDegreesToRadians(angle));
    qreal x3 = centerX + pentagonRadius * qCos(qDegreesToRadians(2 * angle)); // Inferior derecho
    qreal y3 = centerY + pentagonRadius * qSin(qDegreesToRadians(2 * angle));
    qreal x4 = centerX - pentagonRadius * qCos(qDegreesToRadians(2 * angle)); // Inferior izquierdo
    qreal y4 = centerY + pentagonRadius * qSin(qDegreesToRadians(2 * angle));
    qreal x5 = centerX - pentagonRadius * qCos(qDegreesToRadians(angle)); // Superior izquierdo
    qreal y5 = centerY + pentagonRadius * qSin(qDegreesToRadians(angle));

    qreal x6 = centerX;
    qreal y6 = centerY;

    //enmedio

    // Ajustar la coordenada y de los círculos en el medio
    //y2 -= 10;
    y3 -= 80;
    y4 -= 80;

    // Agregar las posiciones de los vértices del pentágono a la lista de posiciones
    circlePositions.clear();
    circlePositions.append(QPointF(x1, y1));
    circlePositions.append(QPointF(x2, y2));
    circlePositions.append(QPointF(x3, y3));
    circlePositions.append(QPointF(x4, y4));
    circlePositions.append(QPointF(x5, y5));
    circlePositions.append(QPointF(x6, y6));
    
    // Dibujar los vértices del pentágono como círculos con relleno blanco y contorno negro
    QPainter painter(this);
    painter.setRenderHint(QPainter::Antialiasing, true);
    painter.setBrush(Qt::white); // Relleno blanco
    painter.setPen(Qt::black); // Contorno negro
    for (const QPointF &position : circlePositions) {
        painter.drawEllipse(position, radius, radius);
    }

    // Redibujar los vértices del pentágono
    update();
}

void drawCrescent() {
    // Limpiar el lienzo antes de dibujar nuevos círculos
    clearCanvas();

    // Obtener el tamaño del círculo (vértice)
    qreal radius = 70;

    // Obtener el centro del widget
    qreal centerX = width() / 2.0;
    qreal centerY = height() / 2.0;

    // Variables para los primeros 5 círculos con ángulo negativo
    qreal angleIncrement5 = 180.0 / 12.0; // Incremento de ángulo para cada vértice
    qreal startAngleLeft5 = 90.0 + angleIncrement5 * 5; // Ángulo inicial (a la izquierda) negativo
    qreal currentAngle5 = startAngleLeft5;

    // Variables para los siguientes 7 círculos
    qreal angleIncrement7 = 180.0 / 12.0; // Incremento de ángulo para cada vértice
    qreal startAngleLeft7 = 90.0 - angleIncrement7 * 5; // Ángulo inicial (a la izquierda)
    qreal startAngleRight7 = startAngleLeft7 + angleIncrement7 * 5; // Ángulo inicial (a la derecha)
    qreal currentAngle7 = startAngleRight7; // Comenzar desde la derecha

    // Agregar las posiciones de los círculos a la lista de posiciones (primeros 5 círculos)
    for (int i = 0; i < 5; ++i) {
        qreal x5 = centerX + radius * qCos(qDegreesToRadians(currentAngle5));
        qreal y5 = centerY - radius * qSin(qDegreesToRadians(currentAngle5));
        circlePositions.append(QPointF(x5, y5));
        currentAngle5 -= angleIncrement5; // Disminuir el ángulo para el siguiente vértice (negativo)
    }

    // Aplicar desplazamientos a las posiciones de los círculos (primeros 5 círculos)
    qreal xOffset5 = -20; // Desplazamiento en el eje x
    qreal yOffset5 = -22;   // Desplazamiento en el eje y
    for (int i = 0; i < 5; ++i) {
        circlePositions[i].rx() += xOffset5;
        circlePositions[i].ry() += yOffset5;
    }

    // Agregar las posiciones de los círculos a la lista de posiciones (siguientes 7 círculos)
    for (int i = 0; i < 7; ++i) {
        qreal x7 = centerX + radius * qCos(qDegreesToRadians(currentAngle7));
        qreal y7 = centerY - radius * qSin(qDegreesToRadians(currentAngle7));
        circlePositions.append(QPointF(x7, y7));
        currentAngle7 += angleIncrement7; // Aumentar el ángulo para el siguiente vértice
    }

    // Dibujar los círculos con relleno blanco y contorno negro
    QPainter painter(this);
    painter.setRenderHint(QPainter::Antialiasing, true);
    painter.setBrush(Qt::white); // Relleno blanco
    painter.setPen(Qt::black);   // Contorno negro

    // Dibujar los primeros 5 círculos
    for (int i = 0; i < 5; ++i) {
        painter.drawEllipse(circlePositions[i], radius, radius);
    }

    // Dibujar los siguientes 7 círculos
    for (int i = 5; i < 12; ++i) {
        painter.drawEllipse(circlePositions[i], radius, radius);
    }

    // Redibujar los círculos
    update();
}

void drawCircle() {
    // Limpiar el lienzo antes de dibujar nuevos círculos
    clearCanvas();

    // Obtener el tamaño del círculo (vértice)
    qreal radius = 60;

    // Obtener el centro del widget
    qreal centerX = width() / 2.0;
    qreal centerY = height() / 2.0;

    // Calcular las posiciones de los vértices del círculo
    qreal angleIncrement = 360.0 / 12.0; // Incremento de ángulo para cada vértice
    qreal startAngle = 90.0; // Ángulo inicial
    qreal currentAngle = startAngle;

    // Agregar las posiciones de los círculos a la lista de posiciones
    circlePositions.clear();
    for (int i = 0; i < 12; ++i) {
        qreal x = centerX + radius * qCos(qDegreesToRadians(currentAngle));
        qreal y = centerY - radius * qSin(qDegreesToRadians(currentAngle));
        circlePositions.append(QPointF(x, y));
        currentAngle += angleIncrement; // Aumentar el ángulo para el siguiente círculo
    }

    // Calcular la posición del círculo central
    qreal x6 = centerX;
    qreal y6 = centerY;

    // Dibujar los círculos con relleno blanco y contorno negro
    QPainter painter(this);
    painter.setRenderHint(QPainter::Antialiasing, true);
    painter.setBrush(Qt::white); // Relleno blanco
    painter.setPen(Qt::black);   // Contorno negro

    // Dibujar los círculos en el perímetro
    for (int i = 0; i < 12; ++i) {
        painter.drawEllipse(circlePositions[i], radius, radius);
    }

    // Dibujar el círculo central
    painter.drawEllipse(QPointF(x6, y6), radius, radius);

    // Redibujar los círculos
    update();
}



protected:
    void paintEvent(QPaintEvent *event) override {
        Q_UNUSED(event);
        QPainter painter(this);
        painter.setRenderHint(QPainter::Antialiasing, true);
        painter.setPen(Qt::black);   // Set pen color to black

        qreal radius = 10; // Fixed radius size
        for (const QPointF &position : circlePositions) {
            painter.drawEllipse(position, radius, radius);
        }
    }   
    // Captura el evento de clic del mouse para agregar un nuevo círculo en la posición del clic
    void mousePressEvent(QMouseEvent *event) override {
            if (event->button() == Qt::LeftButton) {
                addCircle(event->localPos()); // Agregar un nuevo círculo en la posición del clic
            }
        }
    
    

private:
    QVector<QPointF> circlePositions;
    int circleCount;

    void generateCirclePositions() {
        circlePositions.clear();
        // Agrega las posiciones de los círculos basadas en el tamaño del widget
        for (int i = 0; i < circleCount; ++i) {
            qreal x = QRandomGenerator::global()->bounded(width());
            qreal y = QRandomGenerator::global()->bounded(height());
            circlePositions.append(QPointF(x, y));
        }
    }
};


class TextDialog : public QDialog {
public:
    TextDialog(QWidget *parent = nullptr) : QDialog(parent) {
        setWindowTitle("Text Dialog");

        QVBoxLayout *layout = new QVBoxLayout(this);
        QLabel *label = new QLabel(this);
        label->setText("Indexing the vertices\n"
                       "while (i < N) // i=0, N=len(points), k=len(H)\n"
                       "while ((k>=2)&&!ccw(H[k-2],H[k-1],P[i])) --k\n"
                       "H[k++] = P[i++]\n"
                       "while (i >= 0) // i = N - 2, t = k + 1\n"
                       "while ((k>=t)&&!ccw(H[k-2],H[k-1],P[i])) --k\n"
                       "H[k++] = P[i--]");

        layout->addWidget(label);
    }
};

class TextDialog2 : public QDialog {
public:
    TextDialog2(QWidget *parent = nullptr) : QDialog(parent) {
        setWindowTitle("Text Dialog");

        QVBoxLayout *layout = new QVBoxLayout(this);
        QLabel *label = new QLabel(this);
        label->setText("Indexing the vertices\n\n"
                               "push P[N-1], P[0], P[1] into stack S\n\n"
                               "while (i < N) // i = 2, N = size of P\n"
                               "  if (ccw(S[S.size()-2],S[S.size()-1],P[i])\n"
                               "    push P[i] into stack and increase i\n"
                               "  else pop from S\n\n"
                               "S is the result");

        layout->addWidget(label);
    }
};



class MainWindow : public QWidget {
public:
 MainWindow(QWidget *parent = nullptr) : QWidget(parent) {
    resize(1920, 720);

    // Botón "Create"
    buttonCreate.setText("Create");
    buttonCreate.setFixedSize(100, 30); // Tamaño fijo
    layout.addWidget(&buttonCreate);

    // Botón "Edit Points"
    buttonEditPoints.setText("Edit Points");
    buttonEditPoints.setFixedSize(100, 30); // Tamaño fijo
    layout.addWidget(&buttonEditPoints);

    // Botón "Example Point"
    buttonExamplePoint.setText("Example Point");
    buttonExamplePoint.setFixedSize(100, 30); // Tamaño fijo
    layout.addWidget(&buttonExamplePoint);

    // Botón "Andrew Chain"
    buttonAndrew.setText("Andrew_chain(pts)");
    buttonAndrew.setFixedSize(100, 30); // Tamaño fijo
    layout.addWidget(&buttonAndrew);

    // Botón "ch graham"
    buttonCHGraham.setText("ch graham");
    buttonCHGraham.setFixedSize(100, 30); // Tamaño fijo
    layout.addWidget(&buttonCHGraham);

    buttonShamos.setText("Shamos");
    buttonShamos.setFixedSize(100, 30); // Tamaño fijo
    layout.addWidget(&buttonShamos);

    // Agregar el widget de círculo al diseño
    layout.addWidget(&circleWidget);

    // Establecer el diseño en la ventana principal
    setLayout(&layout);

    // Conectar los botones a las funciones correspondientes
    connect(&buttonCreate, &QPushButton::clicked, this, &MainWindow::createCircles);
    connect(&buttonEditPoints, &QPushButton::clicked, this, &MainWindow::editPoints);
    connect(&buttonExamplePoint, &QPushButton::clicked, this, &MainWindow::showExamplePointMenu);
    connect(&buttonAndrew, &QPushButton::clicked, this, &MainWindow::andrewChain);
    connect(&buttonCHGraham, &QPushButton::clicked, this, &MainWindow::chGrahamAlgorithm);
    connect(&buttonShamos, &QPushButton::clicked, this, &MainWindow::shamosAlgorithm);
    
    // Configurar el temporizador para controlar la animación
    connect(&timer, &QTimer::timeout, this, &MainWindow::animateCircle);
}
    void createCircles() {
        bool ok;
        int count = QInputDialog::getInt(this, "Ingrese un número", "Número de círculos:", 1, 1, 30, 1, &ok);
        if (ok) {
            circleWidget.setCircleCount(count);
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
    connect(&clearButton, &QPushButton::clicked, [&circleWidgetCopy]() {
        circleWidgetCopy.clearCanvas();
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

    
void andrewChain() {
    // Limpiar el lienzo antes de dibujar los círculos
    numAndrewCircles = 10; // Restablecer el número de círculos
    currentCircleIndex = 0; // Restablecer el índice del círculo actual
    circlePositions.clear(); // Limpiar la lista de posiciones de círculos
    ActiveMethod = 1;

    // Agregar puntos iniciales a circlePositions
    qreal centerX = width() / 2.0;
    qreal centerY = height() / 2.0;
    qreal squareSize = 400;
    qreal squareLeft = centerX - squareSize / 2.0;
    qreal squareTop = centerY - squareSize / 2.0;

circlePositions.append(QPointF(squareLeft + 50, squareTop + 100));
//circlePositions.append(QPointF(squareLeft + 200, squareTop + 150));
circlePositions.append(QPointF(squareLeft + 250, squareTop + 300));
circlePositions.append(QPointF(squareLeft + 200, squareTop + 150));
circlePositions.append(QPointF(squareLeft + 300, squareTop + 150));
circlePositions.append(QPointF(squareLeft + 400, squareTop + 200));
circlePositions.append(QPointF(squareLeft + 500, squareTop + 300));
circlePositions.append(QPointF(squareLeft + 150, squareTop + 400));
circlePositions.append(QPointF(squareLeft + 300, squareTop + 450));

    timer.start(1500); // Este valor controla la velocidad de la animación en milisegundos
    TextDialog dialog;
    dialog.exec();
}



void animateCircle() {
    qDebug() << "Animando círculo...";

    // Verificar el tamaño de circlePositions
    qDebug() << "Tamaño de circlePositions:" << circlePositions.size();
    if (currentCircleIndex < numAndrewCircles) {
        QPainter painter(this);
        painter.setRenderHint(QPainter::Antialiasing, true);

        // Definir el radio de los círculos
        qreal circleRadius = 20;

        // Dibujar el círculo actual
        QPointF center = circlePositions[currentCircleIndex];
        painter.drawEllipse(center, circleRadius, circleRadius);
        QRectF textRect(center.x() - circleRadius, center.y() - circleRadius, 2 * circleRadius, 2 * circleRadius);
        painter.drawText(textRect, Qt::AlignCenter, QString::number(currentCircleIndex + 1));

        // Dibujar la línea desde el círculo anterior al círculo actual
        if (currentCircleIndex > 0) {
            QPointF startPoint = circlePositions[currentCircleIndex - 1];
            QPointF endPoint = center;
            painter.drawLine(startPoint, endPoint);
        }

        // Incrementar el índice del círculo actual
        ++currentCircleIndex;

        // Solicitar un redibujado
        update();

    } else {
        // Si se han dibujado todos los círculos, detener el temporizador
        qDebug() << "Animación completa.";
        timer.stop();
        // Llamar al segundo método de animación
        //animateCircle2();

        // Limpiar la pantalla solicitando un redibujado
        repaint();
    }
}



void chGrahamAlgorithm() {

    ActiveMethod = 2; // Establecer activeMethod en 2 para indicar el método CHGrahamAlgorithm}
     // Limpiar el lienzo antes de dibujar los círculos
    numAndrewCircles = 10; // Restablecer el número de círculos
    currentCircleIndex = 0; // Restablecer el índice del círculo actual
    circlePositions.clear(); // Limpiar la lista de posiciones de círculos

    // Agregar puntos iniciales a circlePositions
    qreal centerX = width() / 2.0;
    qreal centerY = height() / 2.0;
    qreal squareSize = 400;
    qreal squareLeft = centerX - squareSize / 2.0;
    qreal squareTop = centerY - squareSize / 2.0;

    circlePositions.append(QPointF(squareLeft + 50, squareTop + 100));
    circlePositions.append(QPointF(squareLeft + 350, squareTop + 50));
    circlePositions.append(QPointF(squareLeft + 250, squareTop + 300));
    circlePositions.append(QPointF(squareLeft + 200, squareTop + 150));
    circlePositions.append(QPointF(squareLeft + 300, squareTop + 150));
    circlePositions.append(QPointF(squareLeft + 400, squareTop + 200));
    circlePositions.append(QPointF(squareLeft + 500, squareTop + 300));
    circlePositions.append(QPointF(squareLeft + 150, squareTop + 400));
    circlePositions.append(QPointF(squareLeft + 300, squareTop + 450));
    circlePositions.append(QPointF(squareLeft + 400, squareTop + 290));

    timer.start(1500); // Este valor controla la velocidad de la animación en milisegundos
    TextDialog2 dialog;
    dialog.exec();
}


void shamosAlgorithm() {

    ActiveMethod = 3; // Establecer activeMethod en 2 para indicar el método CHGrahamAlgorithm}
     // Limpiar el lienzo antes de dibujar los círculos
    numAndrewCircles = 10; // Restablecer el número de círculos
    currentCircleIndex = 0; // Restablecer el índice del círculo actual
    circlePositions.clear(); // Limpiar la lista de posiciones de círculos

    // Agregar puntos iniciales a circlePositions
    qreal centerX = width() / 2.0;
    qreal centerY = height() / 2.0;
    qreal squareSize = 400;
    qreal squareLeft = centerX - squareSize / 2.0;
    qreal squareTop = centerY - squareSize / 2.0;

// Definir las esquinas del rectángulo (círculos 0, 1, 4 y 9)
// circlePositions.append(QPointF(squareLeft + 50, squareTop + 50));   // Círculo 0
// circlePositions.append(QPointF(squareLeft + 250, squareTop + 200)); // Círculo 9
// circlePositions.append(QPointF(squareLeft + 350, squareTop + 50));  // Círculo 1
circlePositions.append(QPointF(squareLeft + 50, squareTop + 250));  // Círculo 2
circlePositions.append(QPointF(squareLeft + 350, squareTop + 250));
// circlePositions.append(QPointF(squareLeft + 50, squareTop + 250));  // Círculo 2
circlePositions.append(QPointF(squareLeft + 250, squareTop + 200)); // Círculo 9
circlePositions.append(QPointF(squareLeft + 150, squareTop + 100));
// circlePositions.append(QPointF(squareLeft + 350, squareTop + 250)); // Círculo 3

// Definir las posiciones de los círculos dentro del rectángulo
// Puedes ajustar estas posiciones según sea necesario
// circlePositions.append(QPointF(squareLeft + 350, squareTop + 250));
circlePositions.append(QPointF(squareLeft + 350, squareTop + 50));  // Círculo 1
//circlePositions.append(QPointF(squareLeft + 150, squareTop + 100)); // Círculo 4
circlePositions.append(QPointF(squareLeft + 250, squareTop + 100)); // Círculo 5
circlePositions.append(QPointF(squareLeft + 100, squareTop + 150)); // Círculo 6
circlePositions.append(QPointF(squareLeft + 300, squareTop + 150)); // Círculo 7
circlePositions.append(QPointF(squareLeft + 150, squareTop + 200)); // Círculo 8
circlePositions.append(QPointF(squareLeft + 50, squareTop + 50));   // Círculo 0
// circlePositions.append(QPointF(squareLeft + 250, squareTop + 200)); // Círculo 9


    timer.start(1500); // Este valor controla la velocidad de la animación en milisegundos
    TextDialog2 dialog;
    dialog.exec();
}


protected:
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
            drawCirclesAndLines(painter);
            break;
        case 2:
            qDebug() << "Graham";
            drawCirclesGH(painter);
            break;
        case 3:
            qDebug() << "shamos";
            drawCirclesSH(painter);
            break;
    }
}


void drawCirclesAndLines(QPainter &painter) {
    qDebug() << "Andrew";
    circleWidget.clearCircles();
    QColor transparent(255, 255, 255,   0); // Color blanco totalmente transparente
    qreal circleRadius = 20;

    for (int i = 0; i < currentCircleIndex && i < circlePositions.size(); ++i) {
        // Dibujar el círculo actual
        QPointF center = circlePositions[i];
        painter.drawEllipse(center, circleRadius, circleRadius);
        QRectF textRect(center.x() - circleRadius, center.y() - circleRadius, 2 * circleRadius, 2 * circleRadius);
        painter.drawText(textRect, Qt::AlignCenter, QString::number(i));

        // Dibujar la línea desde el círculo actual al siguiente
        if (i > 0) {
            QPointF startPoint = circlePositions[i - 1];
            QPointF endPoint = circlePositions[i];

            // Borrar la línea anterior
            painter.setPen(Qt::white); // Color del pincel para borrar
            painter.drawLine(startPoint, endPoint);
            painter.setPen(Qt::black); // Restaurar el color del pincel

            // Dibujar la nueva línea
            painter.drawLine(startPoint, endPoint);
        }
    }

    // Dibujar el círculo actual
    if (currentCircleIndex < circlePositions.size()) {
        QPointF center = circlePositions[currentCircleIndex];
        painter.drawEllipse(center, circleRadius, circleRadius);
        QRectF textRect(center.x() - circleRadius, center.y() - circleRadius, 2 * circleRadius, 2 * circleRadius);
        painter.drawText(textRect, Qt::AlignCenter, QString::number(currentCircleIndex));
    } else {
        // Si se han dibujado todos los círculos, borrar las líneas
        for (int i = 1; i < currentCircleIndex && i < circlePositions.size(); ++i) {
            QPointF startPoint = circlePositions[i - 1];
            QPointF endPoint = circlePositions[i];
            painter.setPen(Qt::white); // Color del pincel para borrar
            painter.drawLine(startPoint, endPoint);
        }

    // Dibujar nuevas líneas que conectan los círculos 0, 1 y 2, y 0 con 2
    if (circlePositions.size() >= 3) {
        
        // Dibujar las nuevas líneas
        painter.setPen(Qt::black);
        painter.drawLine(circlePositions[0], circlePositions[1]);
        painter.drawLine(circlePositions[1], circlePositions[2]);
        painter.drawLine(circlePositions[2], circlePositions[0]);
        
        // Borrar la línea de 2 a 1
        painter.setPen(Qt::white);
        painter.drawLine(circlePositions[1], circlePositions[2]);

        // Borrar la línea de 1 a 0
        painter.drawLine(circlePositions[0], circlePositions[1]);
    }

        // Dibujar nuevas líneas que van desde el círculo 2 a 3, 2 a 4 y 3 a 4
        if (circlePositions.size() >= 5) {
            painter.setPen(Qt::black);
            painter.drawLine(circlePositions[2], circlePositions[3]);
            painter.drawLine(circlePositions[2], circlePositions[4]);
            painter.drawLine(circlePositions[3], circlePositions[4]);
            painter.drawLine(circlePositions[4], circlePositions[5]);
            painter.drawLine(circlePositions[2], circlePositions[5]);
            //Borrar las lineas
            painter.setPen(Qt::white);
            
            painter.drawLine(circlePositions[2], circlePositions[3]);
            painter.drawLine(circlePositions[2], circlePositions[4]);
            painter.drawLine(circlePositions[3], circlePositions[4]);
            painter.drawLine(circlePositions[4], circlePositions[5]);


            }
                    // Dibujar nuevas líneas que van desde el círculo 2 a 3, 2 a 4 y 3 a 4
        if (circlePositions.size() >= 7) {
            painter.setPen(Qt::black);
            painter.drawLine(circlePositions[5], circlePositions[6]);
            painter.drawLine(circlePositions[6], circlePositions[7]);
            painter.drawLine(circlePositions[5], circlePositions[7]);
            //Borrar las lineas
            painter.setPen(Qt::white);
            
            painter.drawLine(circlePositions[5], circlePositions[6]);
            painter.drawLine(circlePositions[6], circlePositions[7]);
            }

        //De regreso
        if (circlePositions.size() >= 7) {
            painter.setPen(Qt::black);
            painter.drawLine(circlePositions[7], circlePositions[6]);
            painter.drawLine(circlePositions[6], circlePositions[5]);
            painter.drawLine(circlePositions[6], circlePositions[4]);
            painter.drawLine(circlePositions[4], circlePositions[3]);
            painter.drawLine(circlePositions[6], circlePositions[3]);
            painter.drawLine(circlePositions[3], circlePositions[1]);
            painter.drawLine(circlePositions[6], circlePositions[1]);
            painter.drawLine(circlePositions[1], circlePositions[0]);


            //Borrar las lineas
            painter.setPen(Qt::white);
            painter.drawLine(circlePositions[6], circlePositions[5]);
            painter.drawLine(circlePositions[4], circlePositions[3]);
            painter.drawLine(circlePositions[3], circlePositions[1]);
            painter.drawLine(circlePositions[6], circlePositions[3]);
            painter.drawLine(circlePositions[6], circlePositions[4]);

            }
    }
}

void drawCirclesGH(QPainter &painter) {
    circleWidget.clearCircles();
    qreal circleRadius = 20;
    int numCirclesDrawn = 0; // Contador para el número de círculos dibujados
    // Dibujar los círculos y las líneas
    for (int i = 0; i < currentCircleIndex && i < circlePositions.size(); ++i) {
        QPointF center = circlePositions[i];
        painter.drawEllipse(center, circleRadius, circleRadius);
        QRectF textRect(center.x() - circleRadius, center.y() - circleRadius, 2 * circleRadius, 2 * circleRadius);
        painter.drawText(textRect, Qt::AlignCenter, QString::number(i));
        ++numCirclesDrawn; // Incrementar el contador de círculos dibujados
        // Dibujar la línea desde el círculo en la posición 0 hasta el círculo actual
    if (i > 0) {
            painter.drawLine(circlePositions[0], center);
    }
    if (i>=9)
    {
            //Borrar las lineas
            painter.setPen(Qt::white);
            painter.drawLine(circlePositions[0], circlePositions[1]);
            painter.drawLine(circlePositions[0], circlePositions[2]);
            painter.drawLine(circlePositions[0], circlePositions[3]);
            painter.drawLine(circlePositions[0], circlePositions[4]);
            painter.drawLine(circlePositions[0], circlePositions[5]);
            painter.drawLine(circlePositions[0], circlePositions[6]);
            painter.drawLine(circlePositions[0], circlePositions[7]);
            painter.drawLine(circlePositions[0], circlePositions[8]);
            painter.drawLine(circlePositions[0], circlePositions[9]);
            }
    }

    // Dibujar el círculo actual
    if (currentCircleIndex < circlePositions.size()) {
        QPointF center = circlePositions[currentCircleIndex];
        painter.drawEllipse(center, circleRadius, circleRadius);
        QRectF textRect(center.x() - circleRadius, center.y() - circleRadius, 2 * circleRadius, 2 * circleRadius);
        painter.drawText(textRect, Qt::AlignCenter, QString::number(currentCircleIndex));

        // Dibujar la línea desde el círculo en la posición 0 hasta el círculo actual
        if (currentCircleIndex > 0) {
            painter.drawLine(circlePositions[0], center);
        }
    }
        // Dibujar nuevas líneas que conectan los círculos 0, 1 y 2, y 0 con 2
    if (numCirclesDrawn>= 9) {
        // Dibujar las nuevas líneas
        painter.setPen(Qt::black);
        painter.drawLine(circlePositions[0], circlePositions[1]);
        painter.drawLine(circlePositions[1], circlePositions[4]);
        painter.drawLine(circlePositions[4], circlePositions[9]);
        painter.drawLine(circlePositions[9], circlePositions[0]);
        }
}

void drawCirclesSH(QPainter &painter) {
    circleWidget.clearCircles();
    qreal circleRadius = 20;
    int numCirclesDrawn = 0; // Contador para el número de círculos dibujados

    // Variables para calcular el centro del rectángulo
    qreal centerX = 0;
    qreal centerY = 0;

    // Dibujar los círculos
    for (int i = 0; i < currentCircleIndex && i < circlePositions.size(); ++i) {
        QPointF center = circlePositions[i];
        painter.drawEllipse(center, circleRadius, circleRadius);
        QRectF textRect(center.x() - circleRadius, center.y() - circleRadius, 2 * circleRadius, 2 * circleRadius);
        painter.drawText(textRect, Qt::AlignCenter, QString::number(i));

        // Sumar las coordenadas x e y de los círculos
        if (i == 0 || i == 1 || i == 4 || i == 9) {
            centerX += center.x();
            centerY += center.y();
            ++numCirclesDrawn;
        }
    }
    timer.stop();

    // Dibujar las líneas entre los círculos 0, 1, 4 y 9
    if (numCirclesDrawn == 4) { // Asegurar que se hayan dibujado exactamente 4 círculos
        timer.start(1500);
        painter.setPen(Qt::black);

        int circleIndices[] = {0, 1, 1, 4, 4, 9, 9, 0}; // Pares de índices para las líneas

        // Establecer una variable de contador para el índice de la línea actual
        static int lineIndex = 0;

        // Dibujar la línea actual
        painter.drawLine(circlePositions[circleIndices[lineIndex]], circlePositions[circleIndices[lineIndex + 1]]);

        // Incrementar el índice de la línea actual
        lineIndex += 2;
        // Si se ha dibujado la última línea, detener el temporizador
    if (numCirclesDrawn == 4 && lineIndex < sizeof(circleIndices) / sizeof(int)) {
            painter.drawLine(circlePositions[0], circlePositions[1]);
            painter.drawLine(circlePositions[1], circlePositions[4]);
            painter.drawLine(circlePositions[4], circlePositions[9]);
            painter.drawLine(circlePositions[4], circlePositions[9]);
            timer.stop();
        }
    }
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
    QVector<QPointF> circlePositions; // Declarar circlePositions como un miembro de la clase
    int ActiveMethod = 0;
};


int main(int argc, char *argv[]) {
    QApplication app(argc, argv);
    MainWindow mainWindow;
    mainWindow.show();
    return app.exec();
}