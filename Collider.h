#ifndef COLLIDER_H
#define COLLIDER_H
#include <QGraphicsItem>
#include <QPainter>

#include "ItemType.h"


class Collider : public QGraphicsItem
{
public:
    Collider();
    int type() const;
    QPainterPath shape() const;
    void setVisiblity(bool is_visible);
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget);
    QList<QGraphicsItem *> collidingItems(ItemType type);


protected:
    QPainterPath shape_;
    virtual void generateShape() = 0;

private:
    bool generated_;
    bool is_visible_;


};

#endif // COLLIDER_H
