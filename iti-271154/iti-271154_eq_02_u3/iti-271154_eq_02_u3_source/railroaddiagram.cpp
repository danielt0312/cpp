#include "railroaddiagram.h"
#include <QGraphicsTextItem>
#include <QGraphicsLineItem>
#include <QFont>
#include <QBrush>
#include <QPen>
#include <QGraphicsScene>
#include <QList>
#include <QPair>
#include <QMessageBox>
#include <stack>

void RailroadDiagram::generate(QGraphicsScene *scene, const QString &grammar)
{
    // Tamaño y posición inicial
    const int startX = 50;
    const int startY = 50;
    int currentX = startX;
    int currentY = startY;

    // Fuente para el texto
    QFont font;
    font.setPointSize(12);

    // Lista para almacenar los rectángulos creados
    QList<QGraphicsRectItem *> rectangles;
    QList<QPair<int, int>> positions;
    QList<QPair<int, int>> corchetes;
    QList<QString> pCorchetes;
    QList<QString> Saltos;

    QString texto = grammar;
    QString despuesDelIgual = texto.mid(texto.indexOf("=") + 1).trimmed();
    texto = despuesDelIgual;
    texto.replace(";", "");
    texto.replace("{", "{ ");
    texto.replace("[", "[ ");
    texto.replace("]", " ]");
    // Analizar la gramática BNF
    QStringList productions = texto.split("\\", QString::SkipEmptyParts); // Dividir por '\' para cada producción

    for (const QString &production : productions)
    {
        QString cleanedProduction = production.trimmed();
        if (cleanedProduction.isEmpty()) // Omitir líneas vacías
            continue;

        QStringList parts = cleanedProduction.split(QRegExp("\\s+")); // Dividir por espacios
        int numParts = parts.size();
        if (numParts == 0) // No hay partes válidas
            continue;

        // Lista para almacenar las partes combinadas
        QStringList combinedParts;

        // Crear un rectángulo para cada parte de la producción
        for (int i = 0; i < numParts; ++i)
        {
            QString part = parts[i];

            // Verificar si la palabra está entre comillas
            if (part.startsWith("'"))
            {
                // Combinar con la siguiente palabra si termina con comillas
                while (!part.endsWith("'") && i + 1 < numParts)
                {
                    part += " " + parts[++i];
                }
            }

            // Verificar si la siguiente parte es '{}'
            if (i + 1 < numParts && parts[i + 1] == "{}")
            {
                // Agregar una coma sobre la palabra actual
                combinedParts.append(part + ",");
                // Saltar la parte '{}'
                ++i;
            }
            else
            {
                combinedParts.append(part);
            }
        }

        int especialX;
        int especialY;
        int inCor = 0;
        int newY = 0;
        bool prevEx = false;
        int lastXCor = 0;
        int lastN = 0;
        // Ahora tenemos partes combinadas, procedemos a crear los rectángulos
        for (const QString &part : combinedParts)
        {
            QBrush brush = Qt::lightGray; // Color predeterminado

            // Verificar si la palabra está entre comillas
            if (part.startsWith("'") && part.endsWith("'"))
            {
                brush = Qt::blue; // Cambiar el color a azul si está entre comillas
                if (part == "','")
                {
                    QString texto = part;
                    texto.replace("'", "");
                    especialX = currentX - 150;
                    especialY = currentY - 50;
                    QGraphicsRectItem *rect = scene->addRect(especialX, especialY, 100, 30, QPen(), brush);
                    QGraphicsTextItem *text = scene->addText(texto, font);
                    text->setPos(especialX + 5, especialY + 5); // Ajuste para centrar el texto en el rectángulo
                    scene->addLine(especialX, especialY + 15, especialX - 15, especialY + 15, QPen(Qt::black, 3));
                    scene->addLine(especialX + 100, especialY + 15, especialX + 115, especialY + 15, QPen(Qt::black, 3));
                    scene->addLine(especialX - 15, especialY + 15, especialX - 15, especialY + 65, QPen(Qt::black, 3));
                    scene->addLine(especialX + 115, especialY + 15, especialX + 115, especialY + 65, QPen(Qt::black, 3));
                    scene->addLine(especialX + 100, especialY + 65, especialX + 115, especialY + 65, QPen(Qt::black, 3));
                }
                else
                {
                    especialX = currentX;
                    especialY = currentY;
                    if (prevEx)
                    {
                        newY = especialY + (50 * inCor);
                        prevEx = false;
                        QString texto = part;
                        texto.replace("'", "");
                        QGraphicsRectItem *rect = scene->addRect(especialX, newY, 100, 30, QPen(), brush);
                        QGraphicsTextItem *text = scene->addText(texto, font);
                        text->setPos(currentX + 5, newY + 5); // Ajuste para centrar el texto en el rectángulo
                        currentX += 150;                      // Incrementar la posición X para la próxima parte
                        scene->addLine(especialX + 115, especialY + 15, especialX + 115, newY + 15, QPen(Qt::black, 3));
                        scene->addLine(especialX + 100, newY + 15, especialX + 115, newY + 15, QPen(Qt::black, 3));
                        scene->addLine(especialX, newY + 15, lastXCor, newY + 15, QPen(Qt::black, 3));
                    }
                    else
                    {
                        newY = especialY;
                        QString texto = part;
                        texto.replace("'", "");
                        QGraphicsRectItem *rect = scene->addRect(especialX, newY, 100, 30, QPen(), brush);
                        QGraphicsTextItem *text = scene->addText(texto, font);
                        text->setPos(currentX + 5, newY + 5); // Ajuste para centrar el texto en el rectángulo
                        positions.append(QPair<int, int>(currentX, newY));
                        currentX += 150; // Incrementar la posición X para la próxima parte
                        rectangles.append(rect);
                    }
                }
            }
            else if (!part.contains(QRegExp("[\\[\\]{}()]"))) // Omitir los caracteres []{}()|
            {
                if (part == "|")
                {
                    prevEx = true;
                    inCor++;
                }
                else
                {
                    brush = Qt::white; // Cambiar el color a negro si no es uno de los caracteres especiales
                    QGraphicsRectItem *rect = scene->addRect(currentX, currentY, 100, 30, QPen(), brush);
                    QGraphicsTextItem *text = scene->addText(part, font);
                    text->setPos(currentX + 5, currentY + 5); // Ajuste para centrar el texto en el rectángulo
                    positions.append(QPair<int, int>(currentX, currentY));
                    currentX += 150; // Incrementar la posición X para la próxima parte
                    rectangles.append(rect);
                }
            }
            else if (!part.contains(QRegExp("[{}()|]")))
            {
                if (part == "[")
                {
                    corchetes.append(QPair<int, int>(currentX - 110, currentY));
                    pCorchetes.append("[");
                    lastN = currentX - 15;
                    lastXCor += lastN;
                }
                else if (part == "]")
                {
                    corchetes.append(QPair<int, int>(currentX + 15, currentY));
                    pCorchetes.append("]");
                    lastXCor -= lastN;
                }
            }
        }

        // Incrementar la posición Y solo si no hay un salto de línea en la producción
        if (!cleanedProduction.contains("\\n"))
        {
            currentY += 150;
            currentY += (inCor * 25);
        }
        currentX = startX;
        positions.append(QPair<int, int>(0, 0));
        corchetes.append(QPair<int, int>(0, 0));
        pCorchetes.append("_");
        Saltos.append(QString::number(inCor));

        inCor = 0;
    }

    // Conectar los rectángulos con líneas
    for (int i = 1; i < positions.size(); ++i)
    {
        if (positions[i - 1].first != 0 && positions[i - 1].second != 0 && positions[i].first != 0 && positions[i].second != 0)
        {
            scene->addLine(positions[i - 1].first + 100, positions[i - 1].second + 15, positions[i].first, positions[i].second + 15, QPen(Qt::black, 3));
        }
    }

    std::stack<QPair<int, int>> openingBrackets;
    int renglon = 0;
    int extra = 0;
    int jump = 0;
    bool last = false;

    for (int i = 0; i < pCorchetes.size(); ++i)
    {

        if (pCorchetes[i] == '[')
        {
            // Es una posición de apertura de corchete
            openingBrackets.push(corchetes[i]);
        }
        else if (pCorchetes[i] == ']')
        {
            // Es una posición de cierre de corchete
            if (!openingBrackets.empty())
            {
                QPair<int, int> openingPos = openingBrackets.top();
                openingBrackets.pop();

                int e = Saltos.at(jump).toInt();
                e *= 5;
                // ión de apertura y cierre con una línea
                //  scene->addLine(openingPos.first, openingPos.second, corchetes[i].first, corchetes[i].second, QPen(Qt::black, 3));
                scene->addLine(openingPos.first + 90, openingPos.second + 45 + ((renglon + e) * 10), corchetes[i].first - 50, corchetes[i].second + 45 + ((renglon + e) * 10), QPen(Qt::black, 3));
                scene->addLine(openingPos.first + 90, openingPos.second + 45 + ((renglon + e) * 10), openingPos.first + 90, openingPos.second + 15, QPen(Qt::black, 3));
                scene->addLine(corchetes[i].first - 50, corchetes[i].second + 45 + ((renglon + e) * 10), corchetes[i].first - 50, corchetes[i].second + 15, QPen(Qt::black, 3));
                scene->addLine(corchetes[i].first - 50, corchetes[i].second + 15, corchetes[i].first - 65, corchetes[i].second + 15, QPen(Qt::black, 3));
                scene->addLine(openingPos.first + 90, openingPos.second + 15, openingPos.first + 105, openingPos.second + 15, QPen(Qt::black, 3));
                renglon++;
            }
        }
        if (pCorchetes[i] == "_")
        {
            renglon = 0;
            jump++;
        }
    }
}
