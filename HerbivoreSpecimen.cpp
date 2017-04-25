#include "HerbivoreSpecimen.h"

HerbivoreSpecimen::HerbivoreSpecimen()
{

}


void HerbivoreSpecimen::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    Q_UNUSED(option);
    Q_UNUSED(widget);
    QPainterPath circle_path;
    circle_path.addEllipse(boundingRect());
    painter->setPen(QPen(QColor(0, 160, 0),2));
    painter->setBrush(QColor(0,210,0));
    painter->drawPath(circle_path);
}

Specimen* HerbivoreSpecimen::clone() const
{
    HerbivoreSpecimen* temp = new HerbivoreSpecimen();
    return temp;
}
