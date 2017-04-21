#ifndef BOARDVIEWOBJECT_H
#define BOARDVIEWOBJECT_H

#include <QObject>
#include <QGraphicsItem>
#include <QPainter>
#include <QStyleOptionGraphicsItem>

class BoardViewObject : public QGraphicsItem
{
public:
    BoardViewObject();
    QRectF boundingRect() const;
    void paint(QPainter * painter, const QStyleOptionGraphicsItem * option, QWidget * widget = 0);
};

#endif // BOARDVIEWOBJECT_H
