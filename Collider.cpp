#include "Collider.h"

Collider::Collider()
    :generated_(false)
    ,is_visible_(false)
{
    setOpacity(0);
}

int Collider::type() const
{
    return ItemType :: COLLIDER;
}

QPainterPath Collider::shape() const
{
    return shape_;
}

void Collider::setVisiblity(bool is_visible)
{
    is_visible_ = is_visible;
    setOpacity(is_visible_ ? 0.2 : 0);
}

void Collider::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    Q_UNUSED(option);
    Q_UNUSED(widget);
    if(!is_visible_)
        return;
    painter->setPen(QPen(QColor(0, 0, 0),2));
    painter->setBrush(QColor(0,120,0));
    painter->drawPath(shape());
}

QList<QGraphicsItem*> Collider::collidingItems(ItemType type)
{
    QList<QGraphicsItem*> items;
    for(QGraphicsItem* item : QGraphicsItem::collidingItems(Qt::IntersectsItemBoundingRect))
    {
        if(item->type() == type)
            items.append(item);
    }
    items.removeOne(parentItem());
    return items;
}
