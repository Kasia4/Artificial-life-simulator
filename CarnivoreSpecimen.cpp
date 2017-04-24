#include "CarnivoreSpecimen.h"

CarnivoreSpecimen::CarnivoreSpecimen()
{

}

void CarnivoreSpecimen::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    Q_UNUSED(option);
    Q_UNUSED(widget);
    QPainterPath circle_path;
    circle_path.addEllipse(boundingRect());
    painter->setPen(QPen(QColor(160, 0, 0),2));
    painter->setBrush(QColor(210,0,0));
    painter->drawPath(circle_path);
}

Specimen* CarnivoreSpecimen::clone() const
{
    CarnivoreSpecimen* temp = new CarnivoreSpecimen();
    return temp;
}
