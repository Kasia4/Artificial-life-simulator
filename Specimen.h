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
#include "ConeCollider.h"

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
    void setSightRange(qreal range);
    void setSightAngle(qreal angle);
    void disableTracking();


    float getSize() const;
    float getEyesSize() const;
    float getEyesDist() const;
    float getVelocity() const;
    float getAngularVelocity() const;
    qreal getHearingRange() const;
    qreal getSightRange() const;
    qreal getSightAngle() const;

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

    CircleCollider hearing_;
    ConeCollider sight_;




};

#endif // SPECIMEN_H
