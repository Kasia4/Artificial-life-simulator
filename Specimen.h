/* Specimen.h
 * author: Katarzyna Rybacka
 * The Specimen class provides abstract base for concrete specimens types
 */
#ifndef SPECIMEN_H
#define SPECIMEN_H

#include <QGraphicsItem>
#include <QVector2D>
#include <QPainter>
#include <QtMath>
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
    void setVelocity(float velocity);
    void setAngularVelocity(float velocity);

    float getSize() const;
    float getEyesSize() const;
    float getEyesDist() const;
    float getVelocity() const;
    float getAngularVelocity() const;
    QColor getSkinColor() const;
protected:
    void advance(int step);
    float size_;
    float eyes_size_;
    float eyes_dist_;
    QColor skin_color_;


private:
    float velocity_;
    float angular_velocity_;


};

#endif // SPECIMEN_H
