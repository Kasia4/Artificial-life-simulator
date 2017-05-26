#include "Specimen.h"

qreal Specimen::selectionRingSize() const
{
    return SELECTION_RING_SCALE * size_;
}

Specimen::Specimen()
    :target_(nullptr)
    ,chaser_(nullptr)
    ,move_(false)
    ,caught_target_(false)
    ,see_target_(false)
    ,hear_target_(false)
    ,escaped_from_chaser_(true)
    ,velocity_(0)
    ,angular_velocity_(0)
//    ,thirst_(0)
//    ,hunger_(0)
//    ,tiredness_(0)
    ,needChanged_(false)
    ,isDead_(false)
    ,isChased_(false)
{
    setFlags(QGraphicsItem::ItemIsFocusable | QGraphicsItem::ItemIsSelectable | QGraphicsItem::ItemIsMovable);
    setAcceptHoverEvents(true);

    hearing_.setParentItem(this);
    sight_.setParentItem(this);

    /*Example values*/
    setHearingRange(50);
    setSightRange(200);
    setSightAngle(30);

    addAttribute(AttributeType::ENDURANCE, Attribute(20));
    addAttribute(AttributeType::SIGHT_RANGE, Attribute(200));
    addAttribute(AttributeType::SIGHT_ANGLE, Attribute(30));
    addAttribute(AttributeType::HEARING_RANGE, Attribute(50));
    addAttribute(AttributeType::SPEED, Attribute(1));
    addAttribute(AttributeType::STRENGTH, Attribute(40));

    addAttribute(AttributeType::FOOD_NECESSITY, Attribute(0.1));
    addAttribute(AttributeType::WATER_NECESSITY, Attribute(0.1));
    addAttribute(AttributeType::SLEEP_NECESSITY, Attribute(0.1));

    hp_ = attributes_.value(AttributeType::ENDURANCE).getValue();
    needs_.addNeed(NeedType::EAT, 0.1, 0);
    needs_.addNeed(NeedType::DRINK, 0.1, 1);
    needs_.addNeed(NeedType::SLEEP, 0.1, 2);
    needs_.addNeed(NeedType::REPRODUCE, 0.1, 3);

    currentState_ = new State();
    currentNeed_ = NeedType::NONE;
}

int Specimen::type() const
{
    return ItemType::SPECIMEN;

}


QRectF Specimen::boundingRect() const
{
    return QRectF(-selectionRingSize()/2, -selectionRingSize()/2 , selectionRingSize() , selectionRingSize());
}

void Specimen::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    Q_UNUSED(option);
    Q_UNUSED(widget);
    if(hasFocus() || isSelected())
    {
        QPainterPath focus_path;
        focus_path.addEllipse(-selectionRingSize()/2, -selectionRingSize()/2 , selectionRingSize() , selectionRingSize());
        QPen focus_pen(Qt::DotLine);
        focus_pen.setWidth(3);
        painter->setPen(focus_pen);
        painter->drawPath(focus_path);

    }
    QPainterPath circle_path;
    circle_path.addEllipse(-size_/2,-size_/2, size_, size_);
    circle_path.addEllipse(size_/5, -eyes_dist_/2 - eyes_size_/2, eyes_size_, eyes_size_);
    circle_path.addEllipse(size_/5,  eyes_dist_/2 - eyes_size_/2, eyes_size_, eyes_size_);
    painter->setPen(QPen(QColor(0, 0, 0),2));
    painter->setBrush(skinColor());
    painter->drawPath(circle_path);
}

void Specimen::setSize(qreal size)
{
    size_ = size;
    eyes_dist_ = size/2;
    eyes_size_ = size/5;
}

void Specimen::setVelocity(qreal velocity)
{
    velocity_ = velocity;
}

void Specimen::setAngularVelocity(qreal velocity)
{
    angular_velocity_ = velocity;
}

void Specimen::setTarget(QGraphicsItem* target)
{
    target_ = target;
}


void Specimen::setMove(bool move)
{
    move_ = move;
}


void Specimen::setHearingRange(qreal range)
{
    hearing_.setRadius(range);
}

void Specimen::setSightRange(qreal range)
{
    sight_.setRadius(range);
}

void Specimen::setSightAngle(qreal angle)
{
    sight_.setApexAngle(angle);
}

void Specimen::disableTracking()
{
    target_ = nullptr;
    see_target_ = false;
    hear_target_ = false;
}

qreal Specimen::getSize() const
{
    return size_;
}

qreal Specimen::getEyesSize() const
{
    return eyes_size_;
}

qreal Specimen::getEyesDist() const
{
    return eyes_dist_;
}

qreal Specimen::getVelocity() const
{
    return velocity_;
}

qreal Specimen::getAngularVelocity() const
{
    return angular_velocity_;
}

qreal Specimen::getHearingRange() const
{
    return hearing_.getRadius();
}

qreal Specimen::getSightRange() const
{
    return sight_.getRadius();
}

qreal Specimen::getSightAngle() const
{
    return sight_.getApexAngle();
}

qreal Specimen::getAttributeValue(AttributeType type) const
{
    return attributes_.value(type).getValue();
}

qreal Specimen::getNeedValue(NeedType type) const
{
    return needs_.getValue(type);
}

void Specimen::setNeedValue(NeedType type, qreal value)
{
    needs_.setValue(type,value);
}


QGraphicsItem *Specimen::getTarget() const
{
    return target_;
}

bool Specimen::getMove() const
{
    return move_;
}

void Specimen::advance(int step)
{
    if(!step)
        return;
    chooseNeed();
    if(shouldDie())
        isDead_=true;
    else if(shouldRunAway())
        isChased_=true;
    else if(chaser_)
        runAway();
    else if(target_)
        chaseTarget();
    else if(move_)
        {
            setRotation(rotation() + angular_velocity_);
            move();
        }
}

bool Specimen::getIsChased() const
{
    return isChased_;
}

void Specimen::setIsChased(bool isChased)
{
    isChased_ = isChased;
}

void Specimen::runAway()
{
    QLine dist_line(pos().x(), pos().y(), chaser_->pos().x(), chaser_->pos().y());
    qreal angle = qRadiansToDegrees( qAtan2(dist_line.dy(), dist_line.dx())) + 180;
    dist_to_chaser_ = qSqrt(dist_line.dx()*dist_line.dx() + dist_line.dy()*dist_line.dy());
    if(dist_to_chaser_ > ESCAPING_DISTANCE)
    {
        escaped_from_chaser_ = true;
    }
    else
        setRotation(rotation() + angle);
    if(move_)
    {
        move();
    }
}

void Specimen::chaseTarget()
{
    see_target_ = sight_.collidingItems(ItemType::SPECIMEN).contains(target_);
    hear_target_ = hearing_.collidingItems(ItemType::SPECIMEN).contains(target_);
    if(see_target_ || hear_target_)
    {
        QLine dist_line(pos().x(), pos().y(), target_->pos().x(), target_->pos().y());
        qreal angle = qRadiansToDegrees( qAtan2(dist_line.dy(), dist_line.dx()));
        dist_to_target_ = qSqrt(dist_line.dx()*dist_line.dx() + dist_line.dy()*dist_line.dy());
        if(dist_to_target_ < TRACKING_DISTANCE_THRESHOLD)
        {
            caught_target_ = true;
        }
        else
            setRotation(angle);
        if(move_)
        {
            move();
        }
    }
    else
    {
        if(move_)
        {
            setRotation(rotation() + angular_velocity_);
            move();
        }
    }
}

bool Specimen::getIsDead() const
{
    return isDead_;
}

void Specimen::setIsDead(bool isDead)
{
    isDead_ = isDead;
}

State *Specimen::getCurrentState() const
{
    return currentState_;
}

void Specimen::setCurrentState(State *currentState)
{
    delete currentState_;
    currentState_ = currentState;
}

CircleCollider &Specimen::getHearingCollider()
{
    return hearing_;
}

ConeCollider &Specimen::getSightCollider()
{
    return sight_;
}

NeedType Specimen::getCurrentNeed() const
{
    return currentNeed_;
}

void Specimen::setCurrentNeed(const NeedType &currentNeed)
{
    currentNeed_ = currentNeed;
}

bool Specimen::getNeedChanged() const
{
    return needChanged_;
}

void Specimen::setNeedChanged(bool value)
{
    needChanged_ = value;
}

qreal Specimen::getHp() const
{
    return hp_;
}

void Specimen::setHp(const qreal &value)
{
    hp_ = value;
}

//qreal Specimen::getTiredness() const
//{
//    return tiredness_;
//}

//void Specimen::setTiredness(const qreal &value)
//{
//    tiredness_ = value;
//}

//qreal Specimen::getHunger() const
//{
//    return hunger_;
//}

//void Specimen::setHunger(const qreal &value)
//{
//    hunger_ = value;
//}

//qreal Specimen::getThirst() const
//{
//    return thirst_;
//}

//void Specimen::setThirst(const qreal &value)
//{
//    thirst_ = value;
//}

void Specimen::addAttribute(AttributeType type, Attribute attribute)
{
    attributes_.insert(type, attribute);
}

QMap<AttributeType, Attribute> Specimen::getAttributes() const
{
    return attributes_;
}



qreal Specimen::getDistToChaser() const
{
    return dist_to_chaser_;
}

QGraphicsItem* Specimen::getChaser() const
{
    return chaser_;
}

void Specimen::setChaser(QGraphicsItem *chaser)
{
    chaser_ = chaser;
    escaped_from_chaser_ = false;
}


void Specimen::move(){
    setPos(mapToParent(velocity_,0));
}

bool Specimen::shouldDie()
{
    if(hp_ <= 0 || needs_.getValue(NeedType::EAT) >= 1 || needs_.getValue(NeedType::DRINK) >= 1 || needs_.getValue(NeedType::SLEEP) >= 1 || needs_.getValue(NeedType::REPRODUCE) >= 1 )
        return true;
    return false;
}

void Specimen::chooseNeed()
{
    NeedType old = currentNeed_;
    currentNeed_=needs_.mostImportant();
    needChanged_ = (old == currentNeed_);
}

void Specimen::updateState(State* state)
{
    if(currentState_ == state)
        return;
    delete currentState_;
    currentState_ = state;
}

bool Specimen::shouldRunAway()
{
    return false;
}

void Specimen::hoverEnterEvent(QGraphicsSceneHoverEvent *event)
{
    emit hoverEnter(this);
}

void Specimen::hoverLeaveEvent(QGraphicsSceneHoverEvent *event)
{
    emit hoverLeave();
}

bool Specimen::getEscapedFromChaser() const
{
    return escaped_from_chaser_;
}


bool Specimen::getCaughtTarget() const
{
    return caught_target_;
}

void Specimen::updateHp(qreal value)
{
    hp_+=value;
}



QList<Specimen*> Specimen::collidingSpecimens(SpecimenType type)
{
    QList<Specimen*> specimens;
    for(QGraphicsItem* item : sight_.collidingItems(ItemType::SPECIMEN))
    {
        Specimen* specimen = dynamic_cast<Specimen*>(item);
        if(specimen->getSpec() == type)
            specimens.append(specimen);
    }
    for(QGraphicsItem* item : hearing_.collidingItems(ItemType::SPECIMEN))
    {
        Specimen* specimen = dynamic_cast<Specimen*>(item);
        if(specimen->getSpec() == type)
            specimens.append(specimen);
    }
    return specimens;
}

QList<BoardField *> Specimen::collidingFields(FieldType type)
{
    QList<BoardField*> fields;
    for(QGraphicsItem* item : sight_.collidingItems(ItemType::FIELD))
    {
        BoardField* field = dynamic_cast<BoardField*>(item);
        if(field->getFieldType() == type)
            fields.append(field);
    }
    for(QGraphicsItem* item : hearing_.collidingItems(ItemType::FIELD))
    {
        BoardField* field = dynamic_cast<BoardField*>(item);
        if(field->getFieldType() == type)
            fields.append(field);
    }
    return fields;
}

Specimen* Specimen::nearestSpecimen(SpecimenType type)
{
    qreal minDistance = hearing_.getRadius() > sight_.getRadius() ? hearing_.getRadius() : sight_.getRadius();
    Specimen* nearestSpec = nullptr;
    for(Specimen* specimen : collidingSpecimens(type))
    {
        QLine dist_line(pos().x(), pos().y(), specimen->pos().x(), specimen->pos().y());
        qreal distance = dist_line.dx()*dist_line.dx() + dist_line.dy()*dist_line.dy();
        if(distance < minDistance)
            nearestSpec = specimen;
    }

    return nearestSpec;
}

BoardField *Specimen::nearestField(FieldType type)
{
    qreal minDistance = hearing_.getRadius() > sight_.getRadius() ? hearing_.getRadius() : sight_.getRadius();
    BoardField* nearestField = nullptr;
    for(BoardField* field : collidingFields(type))
    {
        QLine dist_line(pos().x(), pos().y(), field->pos().x(), field->pos().y());
        qreal distance = dist_line.dx()*dist_line.dx() + dist_line.dy()*dist_line.dy();
        if(distance < minDistance)
            nearestField = field;
    }

    return nearestField;
}

Needs Specimen::getNeeds() const
{
    return needs_;
}

void Specimen::setNeeds(const Needs &needs)
{
    needs_ = needs;
}


//qreal Specimen::getReproduce() const
//{
//    return reproduce_;
//}

//void Specimen::setReproduce(const qreal &reproduce)
//{
//    reproduce_ = reproduce;
//}

