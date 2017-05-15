#ifndef BORDER_H
#define BORDER_H
#include "ItemType.h"
#include <QGraphicsItem>

class Border : public QGraphicsItem
{
public:
    Border(QPointF topLeft, QPointF topRight, QPointF bottomLeft, QPointF bottomRight);
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget) override;
    QRectF boundingRect() const override;
    int type() const;

    QLineF *getTopLine() const;
    void setTopLine(QLineF *value);

    QLineF *getLeftLine() const;
    void setLeftLine(QLineF *value);

    QLineF *getRightLine() const;
    void setRightLine(QLineF *value);

    QLineF *getBottomLine() const;
    void setBottomLine(QLineF *value);

private:
    QLineF* topLine;
    QLineF* leftLine;
    QLineF* rightLine;
    QLineF* bottomLine;

};

#endif // BORDER_H
