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
    circle_path.addEllipse(getSize(), 2, 4, 4);
    circle_path.addEllipse(getSize(),-6, 4, 4);
    painter->setPen(QPen(QColor(0, 0, 0),2));
    painter->setBrush(QColor(210,0,0));
    painter->drawPath(circle_path);
}

Specimen* CarnivoreSpecimen::clone() const
{
    CarnivoreSpecimen* temp = new CarnivoreSpecimen();
    return temp;
}
