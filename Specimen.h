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
#include <QMap>
#include <iostream>
#include <cmath>

#include "ItemType.h"
#include "CircleCollider.h"
#include "ConeCollider.h"
#include "Attribute.h"
#include "AttributeType.h"
#include "Needs.h"

class State;
#include "State.h"

enum class SpecimenType : unsigned {
    HERBIVORE = 0,
    CARNIVORE
};



class Specimen :  public QObject, public QGraphicsItem
{
    Q_OBJECT

    static constexpr qreal SELECTION_RING_SCALE = 1.7;
    inline qreal selectionRingSize() const;
    static constexpr qreal TRACKING_DISTANCE_THRESHOLD = 5;
    static constexpr qreal ROTATING_DISTANCE_THRESHOLD = 5;
    static constexpr qreal ESCAPING_DISTANCE = 50;
public:
    Specimen();
    virtual ~Specimen() {};
    virtual SpecimenType getSpec() const = 0;
    virtual Specimen* clone() const = 0;
    virtual QColor skinColor() const = 0;

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
    qreal getAttributeValue(AttributeType type) const;
    qreal getNeedValue(NeedType type) const;

    QGraphicsItem* getTarget() const;
    bool getMove() const;

    void disableTracking();

    QGraphicsItem* getChaser() const;
    void setChaser(QGraphicsItem *chaser);

    qreal getDistToChaser() const;

    bool getEscapedFromChaser() const;

    QMap<AttributeType, Attribute> getAttributes() const;

//    qreal getThirst() const;
//    void setThirst(const qreal &value);

//    qreal getHunger() const;
//    void setHunger(const qreal &value);

//    qreal getTiredness() const;
//    void setTiredness(const qreal &value);

    qreal getHp() const;
    void setHp(const qreal &value);

    bool getNeedChanged() const;
    void setNeedChanged(bool value);

    NeedType getCurrentNeed() const;
    void setCurrentNeed(const NeedType &currentNeed);

    State *getCurrentState() const;
    void setCurrentState(State *currentState);

    CircleCollider& getHearingCollider();
    ConeCollider& getSightCollider();

    bool getIsDead() const;
    void setIsDead(bool isDead);

    bool getIsChased() const;
    void setIsChased(bool isChased);



//    qreal getReproduce() const;
//    void setReproduce(const qreal &reproduce);

    Needs getNeeds() const;
    void setNeeds(const Needs &needs);

protected:
    void advance(int step);
    virtual bool shouldRunAway();
    qreal size_;
    qreal eyes_size_;
    qreal eyes_dist_;


    QGraphicsItem* target_;
    QGraphicsItem* chaser_;

    bool move_;
    bool caught_target_;
    bool see_target_;
    bool hear_target_;
    bool escaped_from_chaser_;
    qreal dist_to_target_;
    qreal dist_to_chaser_;

    QList<Specimen*> collidingSpecimens(SpecimenType type);
    Specimen* nearestSpecimen(SpecimenType type);


private:
    qreal velocity_;
    qreal angular_velocity_;

    CircleCollider hearing_;
    ConeCollider sight_;

    State* currentState_;
    QMap<AttributeType, Attribute> attributes_;
//    qreal thirst_;
//    qreal hunger_;
//    qreal tiredness_;
//    qreal reproduce_;
    qreal hp_;
    Needs needs_;

    bool needChanged_;
    NeedType currentNeed_;

    bool isDead_;
    bool isChased_;

    void addAttribute(AttributeType type, Attribute attribute);
    void runAway();
    void chaseTarget();
    void move();
    bool shouldDie();
    void chooseNeed();



};

#endif // SPECIMEN_H
