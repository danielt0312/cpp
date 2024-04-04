#include <QApplication>
#include <QPushButton>
#include <QMouseEvent>
#include <QLayout>

class DraggableButton : public QPushButton
{
    Q_OBJECT // Necesario para usar señales y ranuras de Qt

public:
    DraggableButton(QWidget *parent = nullptr) : QPushButton(parent)
    {
        setMouseTracking(true);
        setFixedSize(300, 150); // Tamaño del botón

        // Creamos un layout y lo establecemos en el botón
        layout = new QVBoxLayout(this);
        layout->setContentsMargins(0, 0, 0, 0);
        setLayout(layout);

        // Creamos el botón interno y lo agregamos al layout
        innerButton = new QPushButton("Inner Button", this);
        layout->
        innerButton);

        // Conexiones de señales y ranuras para el manejo de eventos de mouse
        connect(innerButton, &QPushButton::pressed, this, &DraggableButton::onInnerButtonPressed);
        connect(innerButton, &QPushButton::released, this, &DraggableButton::onInnerButtonReleased);
    }

protected:
    void mousePressEvent(QMouseEvent *event) override
    {
        if (event->button() == Qt::LeftButton)
        {
            isDragging = true;
            dragStartPosition = event->pos() - pos();
        }
        QPushButton::mousePressEvent(event);
    }

    void mouseMoveEvent(QMouseEvent *event) override
    {
        if (event->buttons() & Qt::LeftButton && isDragging)
        {
            move(event->pos() - dragStartPosition);
        }
        QPushButton::mouseMoveEvent(event);
    }

    void mouseReleaseEvent(QMouseEvent *event) override
    {
        if (event->button() == Qt::LeftButton)
        {
            isDragging = false;
        }
        QPushButton::mouseReleaseEvent(event);
    }

private slots:
    void onInnerButtonPressed()
    {
        emit pressed(); // Emitir la señal de presionado del botón externo
    }

    void onInnerButtonReleased()
    {
        emit released(); // Emitir la señal de liberación del botón externo
    }

signals:
    void pressed();
    void released();

private:
    bool isDragging = false;
    QPoint dragStartPosition;
    QVBoxLayout *layout;
    QPushButton *innerButton;
};

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    QWidget window;
    window.resize(800, 600);

    DraggableButton *button = new DraggableButton(&window);
    button->setText("Outer Button"); // Texto del botón externo
    button->move(100, 100);

    window.show();

    return a.exec();
}

#include "main.moc" // Necesario para que Qt pueda procesar las señales y ranuras

