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

#include "ItemType.h"
#include "CircleCollider.h"

enum class SpecimenType : unsigned {
    HERBIVORE = 0,
    CARNIVORE
};


class Specimen : public QGraphicsItem
{
    static constexpr float TRACKING_DISTANCE_THRESHOLD = 5;
public:
    Specimen();
    virtual SpecimenType getSpec() const = 0;
    virtual Specimen* clone() const = 0;
    int type() const;

    QRectF boundingRect() const;
    virtual void paint(QPainter* painter, const QStyleOptionGraphicsItem* option, QWidget* widget = 0);
    void setSize(float size);
    void setVelocity(float velocity);
    void setAngularVelocity(float velocity);
    void setTarget(const QGraphicsItem* target);
    void setEscape(bool escape);
    void setHearingRange(qreal range);
    void disableTracking();


    float getSize() const;
    float getEyesSize() const;
    float getEyesDist() const;
    float getVelocity() const;
    float getAngularVelocity() const;
    qreal getHearingRange() const;

    const QGraphicsItem *getTarget() const;
    bool  getEscape() const;
    QColor getSkinColor() const;
protected:
    void advance(int step);
    float size_;
    float eyes_size_;
    float eyes_dist_;
    QColor skin_color_;

    const QGraphicsItem* target_;
    bool escape_;
    bool on_target_;



private:
    float velocity_;
    float angular_velocity_;

    qreal hearing_range_;
    CircleCollider hearing_;


};

#endif // SPECIMEN_H
