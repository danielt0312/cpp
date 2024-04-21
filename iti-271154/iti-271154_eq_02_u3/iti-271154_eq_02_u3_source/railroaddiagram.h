// railroaddiagram.h
#ifndef RAILROADDIAGRAM_H
#define RAILROADDIAGRAM_H

#include <QGraphicsScene>

class RailroadDiagram
{
public:
    static void generate(QGraphicsScene *scene, const QString &grammar);
};

#endif // RAILROADDIAGRAM_H
