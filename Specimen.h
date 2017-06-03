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
#include <cmath>

#include "SimulationObject.h"
#include "ItemType.h"
#include "Attribute.h"
#include "AttributeType.h"
#include "Needs.h"
#include "BoardField.h"
#include "SpecimenSenses.h"
#include "FocusRing.h"
#include "Genome.h"
#include "StateAttributeFactorMap.h"

class State;
//#include "State.h"

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
	static constexpr qreal BASE_NECESSITY = 1;
	static constexpr qreal BASE_ANGULAR_VELOCITY = 0.5;

public:
    Specimen(Specimen* first_parent,Specimen* second_parent);
	virtual ~Specimen();
    virtual SpecimenType getSpec() const = 0;
    virtual Specimen* clone() const = 0;
    virtual QColor skinColor() const = 0;

    int type() const;

	static void setMovingRect(QRectF rect);
	static QRectF getMovingRect();

	virtual QRectF boundingRect() const;
    virtual void paint(QPainter* painter, const QStyleOptionGraphicsItem* option, QWidget* widget = 0);

	void setSize(qreal size);
    void setAngularVelocity(qreal velocity);
	void setTarget(SimulationObject* target);
    void setMove(bool move);
	void setAttributesStateFactors(const AttFactorsMap& map);
	void setNeedValue(NeedType type, qreal value);
	void setChaser(SimulationObject *chaser);
	void setHp(const qreal &value);
	void setNeedChanged(bool value);
	void setCurrentNeed(const NeedType &currentNeed);
	void setCurrentState(State *currentState);
	void setIsChased(bool isChased);
	void setNeeds(const Needs &needs);
	void setGenome(const Genome& genome);
	void setProduceNewSpecimen(bool value);
	void setInterrupted(bool interupted);



    qreal getSize() const;
    qreal getEyesSize() const;
	qreal getEyesDist() const;
    qreal getAngularVelocity() const;
	qreal getAttributeValue(AttributeType type) const;
	qreal getNeedValue(NeedType type) const;
	SimulationObject* getTarget() const;
    bool getMove() const;
	SimulationObject* getChaser() const;

    qreal getDistToChaser() const;
    bool getEscapedFromChaser() const;
    QMap<AttributeType, Attribute> getAttributes() const;
    qreal getHp() const;
    bool getNeedChanged() const;
    NeedType getCurrentNeed() const;
	State* getCurrentState() const;
	SpecimenSenses &getSensesCollider();
	bool getIsChased() const;
    Needs getNeeds() const;
	bool getCaughtTarget() const;
	Genome getGenome() const;
	bool getProduceNewSpecimen() const;
	bool getInterrupted() const;

	Specimen* nearestSpecimen(SpecimenType type);
	BoardField* nearestField(FieldType type);
	void updateHp(qreal value);
	void release();



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
    qreal angular_velocity_;

    SpecimenSenses senses_;
    FocusRing focus_ring_;
    State* currentState_;
    QMap<AttributeType, Attribute> attributes_;

    qreal hp_;
    Needs needs_;

    Genome genome_;

	bool produce_new_specimen_;
	bool need_changed_;
    NeedType currentNeed_;

	bool is_chased_;

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
