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
#include <cmath>

#include "ItemType.h"
#include "CircleCollider.h"
#include "ConeCollider.h"

enum class SpecimenType : unsigned {
    HERBIVORE = 0,
    CARNIVORE
};


class Specimen :  public QGraphicsItem
{
    static constexpr qreal TRACKING_DISTANCE_THRESHOLD = 5;
    static constexpr qreal ROTATING_DISTANCE_THRESHOLD = 5;
    static constexpr qreal ESCAPING_DISTANCE = 50;
public:
    Specimen();
    virtual SpecimenType getSpec() const = 0;
    virtual Specimen* clone() const = 0;
    int type() const;


    QRectF boundingRect() const;
    virtual void paint(QPainter* painter, const QStyleOptionGraphicsItem* option, QWidget* widget = 0);
    void setSize(qreal size);
    void setVelocity(qreal velocity);
    void setAngularVelocity(qreal velocity);
    void setTarget(QGraphicsItem *target);
    void setMove(bool move);
    void setHearingRange(qreal range);
    void setSightRange(qreal range);
    void setSightAngle(qreal angle);

    void release();

    qreal getSize() const;
    qreal getEyesSize() const;
    qreal getEyesDist() const;
    qreal getVelocity() const;
    qreal getAngularVelocity() const;
    qreal getHearingRange() const;
    qreal getSightRange() const;
    qreal getSightAngle() const;

    QGraphicsItem* getTarget() const;
    bool getMove() const;

    QColor getSkinColor() const;

    void disableTracking();

    QGraphicsItem* getChaser() const;
    void setChaser(QGraphicsItem *chaser);

    qreal getDistToChaser() const;

    bool getEscapedFromChaser() const;

protected:
    void advance(int step);
    qreal size_;
    qreal eyes_size_;
    qreal eyes_dist_;

    QColor skin_color_;

    QGraphicsItem* target_;
    QGraphicsItem* chaser_;

    bool move_;
    bool caught_target_;
    bool see_target_;
    bool hear_target_;
    bool escaped_from_chaser_;
    qreal dist_to_target_;
    qreal dist_to_chaser_;

private:
    qreal velocity_;
    qreal angular_velocity_;

    CircleCollider hearing_;
    ConeCollider sight_;

    void rotateTo(qreal angle);
    void move();


};

#endif // SPECIMEN_H
