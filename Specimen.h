#ifndef SPECIMEN_H
#define SPECIMEN_H

#include <QGraphicsItem>
#include <QVector2D>
#include <QPainter>
#include <iostream>

enum class SpecimenType : unsigned {
    HERBIVORE = 0,
    CARNIVORE
};


class Specimen : public QGraphicsItem
{
public:
    Specimen();
    virtual SpecimenType getType() const = 0;
    virtual Specimen* clone() const = 0;
    QRectF boundingRect() const;
    virtual void paint(QPainter* painter, const QStyleOptionGraphicsItem* option, QWidget* widget = 0);
    void setSize(float size);
    void setVelocity(QVector2D velocity);
    float getSize() const;
    QVector2D getVelocity() const;
protected:
    void advance(int step);
private:
    float size_;
    QVector2D velocity_;
    float angular_velocity_;

};

#endif // SPECIMEN_H
