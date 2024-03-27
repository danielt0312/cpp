class CircleWidget : public QWidget {
public:
    CircleWidget(QWidget *parent = nullptr) : QWidget(parent) {}

    QVector<QPointF> getCirclePositions() const {
        return circlePositions;
    }

    void setCircleCount(int count) {
        circleCount = count;
        generateCirclePositions();
        update(); 
    }

    void clearCanvas() {
        circlePositions.clear(); 
        update(); 
    }
    
    void clearCircles() {
        circlePositions.clear();
        update(); 
    }

    void setCirclePositions(const QVector<QPointF>& positions) {
        circlePositions = positions;
        update(); 
    }

    void addCircle(const QPointF& position) {
    qreal radius = 50;

    // Verificar si la nueva posición del círculo se superpone con algún otro círculo
    bool overlap = false;
    for (const QPointF& existingPosition : circlePositions) {
        qreal distance = QLineF(position, existingPosition).length();
        if (distance < radius * 2) {
            overlap = true;
            break;
        }
    }

    // Si hay superposición, no agregar el círculo
    if (overlap) {
        return;
    }

    // Imprimir las coordenadas antes de agregar el círculo
    qDebug() << "Coordenadas del nuevo círculo:" << position.x() << "," << position.y();

    // Agregar la nueva posición del círculo
    circlePositions.append(position);

    // Redibujar el widget para mostrar el nuevo círculo
    update();
}


   void drawSquare() {
    // Limpiar el lienzo antes de dibujar nuevos círculos
    clearCanvas();

    // Obtener el tamaño del círculo
    qreal radius = 100;

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
    painter.setBrush(Qt::white);
    painter.setPen(Qt::black);
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
    qreal radius = 100;

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
    qreal radius = 100;

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
    qreal radius = 100;

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
        painter.setPen(Qt::black);

        for (const QPointF &position : circlePositions) {
            qreal radius = 50; // Tamaño del radio de los círculos
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
    qreal radius = 100; // Definir el radio de los círculos
void generateCirclePositions() {
    circlePositions.clear();

    // Definir el rango de valores aleatorios dentro del área visible del widget
    qreal radius = 50; // Tamaño del radio de los círculos
    int minX = static_cast<int>(radius); // Mínimo x
    int maxX = static_cast<int>(width() - radius); // Máximo x
    int minY = static_cast<int>(radius); // Mínimo y
    int maxY = static_cast<int>(height() - radius); // Máximo y

    // Lista para almacenar los rectángulos ocupados por los círculos
    QList<QRectF> occupiedRects;

    // Agrega las posiciones de los círculos dentro del rango específico
    for (int i = 0; i < circleCount; ++i) {
        bool overlap = true;
        QPointF newCircleCenter;
        qreal newCircleRadius = 2 * radius; // Diámetro del círculo

        // Generar nuevas posiciones hasta que no se superpongan con círculos existentes
        while (overlap) {
            // Generar una posición aleatoria dentro del área visible
            int x = QRandomGenerator::global()->bounded(minX, maxX); // Convertir a int
            int y = QRandomGenerator::global()->bounded(minY, maxY); // Convertir a int
            newCircleCenter = QPointF(x, y);

            // Crear un rectángulo que represente el círculo propuesto
            QRectF newCircleRect(newCircleCenter.x() - radius, newCircleCenter.y() - radius, newCircleRadius, newCircleRadius);

            // Verificar si el nuevo círculo se superpone con círculos existentes
            overlap = false;
            for (const QRectF& rect : occupiedRects) {
                if (rect.intersects(newCircleRect)) {
                    overlap = true;
                    break;
                }
            }
        }

        // Agregar la posición del nuevo círculo y su rectángulo ocupado a las listas correspondientes
        circlePositions.append(newCircleCenter);
        occupiedRects.append(QRectF(newCircleCenter.x() - radius, newCircleCenter.y() - radius, newCircleRadius, newCircleRadius));
    }
}


};
