#ifndef FOCUSRING_H
#define FOCUSRING_H

#include <QGraphicsItem>
#include <QPainter>

class FocusRing : public QGraphicsItem
{    
public:
    FocusRing();

    qreal radius() const;
    void setRadius(const qreal &radius);

    QPen pen() const;
    void setPen(const QPen &pen);

    QRectF boundingRect() const;
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget);


private:
    qreal radius_;
    QPen pen_;
};


#endif // FOCUSRING_H
