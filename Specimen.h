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

#include "SimulationObject.h"
#include "ItemType.h"
#include "CircleCollider.h"
#include "ConeCollider.h"
#include "Attribute.h"
#include "AttributeType.h"
#include "Needs.h"
#include "BoardField.h"
#include "SpecimenSenses.h"
#include "FocusRing.h"
#include "Genome.h"
#include "StateAttributeFactorMap.h"

class State;
#include "State.h"

enum class SpecimenType : unsigned {
    HERBIVORE = 0,
    CARNIVORE
};



class Specimen :  public SimulationObject
{
    Q_OBJECT

	static QRectF moving_rect;


	static const Range SIZE_RANGE;
	static constexpr qreal FOCUS_RING_SCALE = 0.7;
    static constexpr qreal TRACKING_DISTANCE_THRESHOLD = 7;
    static constexpr qreal ROTATING_DISTANCE_THRESHOLD = 3;
    static constexpr qreal ESCAPING_DISTANCE = 50;
public:
    Specimen(Specimen* first_parent,Specimen* second_parent);
    virtual ~Specimen() {};
    virtual SpecimenType getSpec() const = 0;
    virtual Specimen* clone() const = 0;
    virtual QColor skinColor() const = 0;

    int type() const;

	static void setMovingRect(QRectF rect);
	static QRectF getMovingRect();

    QRectF boundingRect() const;
    virtual void paint(QPainter* painter, const QStyleOptionGraphicsItem* option, QWidget* widget = 0);
    void setSize(qreal size);
    //void setVelocity(qreal velocity);
    void setAngularVelocity(qreal velocity);
	void setTarget(SimulationObject* target);
    void setMove(bool move);

    void release();

    qreal getSize() const;
    qreal getEyesSize() const;
	qreal getEyesDist() const;
    qreal getAngularVelocity() const;
    qreal getAttributeValue(AttributeType type) const;
	void setAttributesStateFactors(const AttFactorsMap& map);
    qreal getNeedValue(NeedType type) const;
    void setNeedValue(NeedType type, qreal value);

	SimulationObject* getTarget() const;
    bool getMove() const;



	SimulationObject* getChaser() const;
	void setChaser(SimulationObject *chaser);

    qreal getDistToChaser() const;

    bool getEscapedFromChaser() const;

    QMap<AttributeType, Attribute> getAttributes() const;

    qreal getHp() const;
    void setHp(const qreal &value);

    bool getNeedChanged() const;
    void setNeedChanged(bool value);

    NeedType getCurrentNeed() const;
    void setCurrentNeed(const NeedType &currentNeed);

    State *getCurrentState() const;
    void setCurrentState(State *currentState);

    SpecimenSenses &getSensesCollider();

//    bool getIsDead() const;
//    void setIsDead(bool isDead);

    bool getIsChased() const;
    void setIsChased(bool isChased);

    Specimen* nearestSpecimen(SpecimenType type);
    BoardField* nearestField(FieldType type);


//    qreal getReproduce() const;
//    void setReproduce(const qreal &reproduce);

    Needs getNeeds() const;
    void setNeeds(const Needs &needs);

    bool getCaughtTarget() const;
    void updateHp(qreal value);



    Genome getGenome() const;
    void setGenome(const Genome& genome);

    bool getProduceNewSpecimen() const;
    void setProduceNewSpecimen(bool value);

    bool getInterrupted() const;
    void setInterrupted(bool interupted);

protected:
    void advance(int step);
    virtual bool shouldRunAway();

    void hoverEnterEvent(QGraphicsSceneHoverEvent *event);
    void hoverLeaveEvent(QGraphicsSceneHoverEvent *event);
    void focusInEvent(QFocusEvent *event);
	void focusOutEvent(QFocusEvent *event);
    qreal size_;
    qreal eyes_size_;
    qreal eyes_dist_;


	SimulationObject* target_;
	SimulationObject* chaser_;

    bool move_;
    bool caught_target_;
    bool sense_target_;
    bool escaped_from_chaser_;
    qreal dist_to_target_;
    qreal dist_to_chaser_;

    QList<Specimen*> collidingSpecimens(SpecimenType type);
    QList<BoardField*> collidingFields(FieldType type);


private:
    //qreal velocity_;
    qreal angular_velocity_;

    SpecimenSenses senses_;
    FocusRing focus_ring_;
    State* currentState_;
    QMap<AttributeType, Attribute> attributes_;
//    qreal thirst_;
//    qreal hunger_;
//    qreal tiredness_;
//    qreal reproduce_;
    qreal hp_;
    Needs needs_;

    Genome genome_;

    bool produce_new_specimen;
    bool needChanged_;
    NeedType currentNeed_;

  //  bool isDead_;
    bool isChased_;

    bool interrupted_;

    void addAttribute(AttributeType type, Attribute attribute);
    void runAway();
    void chaseTarget();
    void move();
    bool shouldDie();
    void updateState();
    void generateGenome();
    void generateGenome(Specimen* first_parent, Specimen* second_parent);
    void setAttributesValues();
	void updateNeeds();
	void checkBorders();

public slots:
	void chooseNeed();
	void disableTracking();

signals:
    void hoverEnter(Specimen* spec);
    void hoverLeave();
    void attributesChanged();
    void killed(Specimen* spec);


};

#endif // SPECIMEN_H
