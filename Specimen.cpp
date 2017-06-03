#include "Specimen.h"
#include "State.h"

const Range Specimen::SIZE_RANGE = Range(10,15);
QRectF Specimen::moving_rect;

void Specimen::setMovingRect(QRectF rect)
{
	moving_rect = rect;
}

QRectF Specimen::getMovingRect()
{
	return moving_rect;
}

Specimen::Specimen(Specimen* first_parent, Specimen* second_parent)
    :target_(nullptr)
    ,chaser_(nullptr)
    ,move_(false)
    ,caught_target_(false)
    ,sense_target_(false)
    ,escaped_from_chaser_(true)
   // ,velocity_(0)
    ,angular_velocity_(0)
//    ,thirst_(0)
//    ,hunger_(0)
//    ,tiredness_(0)
    ,needChanged_(true)
   // ,isDead_(false)
    ,isChased_(false)
    ,produce_new_specimen(false)
    ,interrupted_(false)
{
    setFlags(QGraphicsItem::ItemIsFocusable | QGraphicsItem::ItemIsMovable);
    setAcceptHoverEvents(true);
	setZValue(0.5);

    std::cout<<"a on tylko elo i odwraca glowe\n";

    senses_.setParentItem(this);

    focus_ring_.setParentItem(this);
    focus_ring_.setVisible(false);
    if(!first_parent || !second_parent)
        generateGenome();
    else
       generateGenome(first_parent, second_parent);

    setAttributesValues();

	Range endurance_range = genome_.getAttributeRange(AttributeType::ENDURANCE);

	setSize(SIZE_RANGE.transform(getAttributeValue(AttributeType::ENDURANCE), endurance_range));

    std::cout<<"moje atrybuty\n";
    std::cout<<"wytrzymalosc "<<getAttributeValue(AttributeType::ENDURANCE)<<"\n";
    std::cout<<"sila "<<getAttributeValue(AttributeType::STRENGTH)<<"\n";
    std::cout<<"zasieg wzroku "<<getAttributeValue(AttributeType::SIGHT_RANGE)<<"\n";
    std::cout<<"kat widzenia "<<getAttributeValue(AttributeType::SIGHT_ANGLE)<<"\n";
    std::cout<<"zasieg sluchu "<<getAttributeValue(AttributeType::HEARING_RANGE)<<"\n";
    std::cout<<"szybkosc "<<getAttributeValue(AttributeType::SPEED)<<"\n";

    std::cout<<"zapotrzebowanie na jedzenie "<<getAttributeValue(AttributeType::FOOD_NECESSITY)<<"\n";
    std::cout<<"zapotrzebowanie na wode "<<getAttributeValue(AttributeType::WATER_NECESSITY)<<"\n";
    std::cout<<"zapotrzebowanie na sen "<<getAttributeValue(AttributeType::SLEEP_NECESSITY)<<"\n";

    /*Example values*/
    senses_.setHearingRange(getAttributeValue(AttributeType::HEARING_RANGE));
    senses_.setSightRange(getAttributeValue(AttributeType::SIGHT_RANGE));
    senses_.setSightAngle(getAttributeValue(AttributeType::SIGHT_ANGLE));

//    addAttribute(AttributeType::ENDURANCE, Attribute(20));
//    addAttribute(AttributeType::SIGHT_RANGE, Attribute(200));
//    addAttribute(AttributeType::SIGHT_ANGLE, Attribute(30));
//    addAttribute(AttributeType::HEARING_RANGE, Attribute(50));
//    addAttribute(AttributeType::SPEED, Attribute(1));
//    addAttribute(AttributeType::STRENGTH, Attribute(40));

//    addAttribute(AttributeType::FOOD_NECESSITY, Attribute(0.1));
//    addAttribute(AttributeType::WATER_NECESSITY, Attribute(0.1));
//    addAttribute(AttributeType::SLEEP_NECESSITY, Attribute(0.1));

    hp_ = attributes_.value(AttributeType::ENDURANCE).getValue();
	needs_.addNeed(NeedType::EAT, 40, 0);
	needs_.addNeed(NeedType::DRINK, 40, 1);
	needs_.addNeed(NeedType::SLEEP, 40, 2);
    needs_.addNeed(NeedType::REPRODUCE, 20, 3);

    currentState_ = new State();
    currentNeed_ = NeedType::NONE;

	chooseNeed();
	emit attributesChanged();
}

Specimen::~Specimen()
{
	delete currentState_;
}

int Specimen::type() const
{
    return ItemType::SPECIMEN;

}


QRectF Specimen::boundingRect() const
{
    return QRectF(-size_/2, -size_/2 , size_ , size_);
}

void Specimen::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    Q_UNUSED(option);
    Q_UNUSED(widget);
    QPainterPath circle_path;
    circle_path.addEllipse(-size_/2,-size_/2, size_, size_);
    circle_path.addEllipse(size_/5, -eyes_dist_/2 - eyes_size_/2, eyes_size_, eyes_size_);
    circle_path.addEllipse(size_/5,  eyes_dist_/2 - eyes_size_/2, eyes_size_, eyes_size_);
	painter->setPen(QPen(QColor(0, 0, 0),1));
    painter->setBrush(skinColor());
    painter->drawPath(circle_path);
}

void Specimen::setSize(qreal size)
{
    size_ = size;
    eyes_dist_ = size/2;
    eyes_size_ = size/5;
    focus_ring_.setRadius(size_*FOCUS_RING_SCALE);
}

void Specimen::setAngularVelocity(qreal velocity)
{
    angular_velocity_ = velocity;
}

void Specimen::setTarget(SimulationObject* target)
{
	target_ = target;
	if(target_)connect(target, SIGNAL(destroyed(QObject*)), this, SLOT(disableTracking()));
}


void Specimen::setMove(bool move)
{
    move_ = move;
}

void Specimen::disableTracking()
{
	if(target_)disconnect(target_, SIGNAL(destroyed(QObject*)), this, SLOT(disableTracking()));
	caught_target_=false;
    target_ = nullptr;
    sense_target_ = false;

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

qreal Specimen::getAngularVelocity() const
{
    return angular_velocity_;
}

qreal Specimen::getAttributeValue(AttributeType type) const
{
	return attributes_.value(type).getValue();
}

void Specimen::setAttributesStateFactors(const AttFactorsMap& map)
{
	for(auto key : attributes_.keys())
	{
		attributes_[key].setStateFactor(map.value(key, 1));
	}
}

qreal Specimen::getNeedValue(NeedType type) const
{
    return needs_.getValue(type);
}

void Specimen::setNeedValue(NeedType type, qreal value)
{
    needs_.setValue(type,value);
}


SimulationObject *Specimen::getTarget() const
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
    updateNeeds();
    //chooseNeed();
    if(shouldDie())
        emit killed(this);
    else if(shouldRunAway())
        isChased_=true;
	if(chaser_)
        runAway();
    else if(target_)
        chaseTarget();
    else if(move_)
        {
            setRotation(rotation() + angular_velocity_);
            move();
        }

    updateState();
	checkBorders();
    emit attributesChanged();
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
        //isChased_= false;
    }
    else
        setRotation(angle);
    if(move_)
    {
        move();
    }
}

void Specimen::chaseTarget()
{
//    if(getSpec() == SpecimenType::HERBIVORE)
//        sense_target_ = senses_.collidingItems(ItemType::FIELD).contains(target_);
//    else
//        sense_target_ = senses_.collidingItems(ItemType::SPECIMEN).contains(target_);
    //if(sense_target_)
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
//    else
//    {
//        if(move_)
//        {
//            setRotation(rotation() + angular_velocity_);
//            move();
//        }
//    }
}

//bool Specimen::getIsDead() const
//{
//    return isDead_;
//}

//void Specimen::setIsDead(bool isDead)
//{
//    isDead_ = isDead;
//}

State *Specimen::getCurrentState() const
{
    return currentState_;
}

void Specimen::setCurrentState(State *currentState)
{
    delete currentState_;
    currentState_ = currentState;
}

SpecimenSenses &Specimen::getSensesCollider()
{
    return senses_;
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

SimulationObject* Specimen::getChaser() const
{
    return chaser_;
}

void Specimen::setChaser(SimulationObject *chaser)
{
	SimulationObject* old = chaser_;
    chaser_ = chaser;
    escaped_from_chaser_ = (chaser_ != old);
}


void Specimen::move(){
    setPos(mapToParent(getAttributeValue(AttributeType::SPEED),0));
}

bool Specimen::shouldDie()
{
	if(hp_ <= 0 || needs_.getValue(NeedType::EAT) >= 100 || needs_.getValue(NeedType::DRINK) >= 100 || needs_.getValue(NeedType::SLEEP) >= 100 || needs_.getValue(NeedType::REPRODUCE) >= 100 )
		return true;
    return false;
}

void Specimen::chooseNeed()
{
    NeedType old = currentNeed_;
    currentNeed_=needs_.mostImportant();
    needChanged_ = (old != currentNeed_);
}

void Specimen::updateState()
{
	State* result = currentState_->action(this);
	if(result && result != currentState_ )
	{
		delete currentState_;
		currentState_ = result;
	}
}

void Specimen::generateGenome()
{
    genome_.addAttributesPair(AttributeType::ENDURANCE, AttributeType::STRENGTH);
    genome_.addAttributesPair(AttributeType::SIGHT_ANGLE,AttributeType::SIGHT_RANGE);
    genome_.addAttributesPair(AttributeType::HEARING_RANGE,AttributeType::SPEED);
    genome_.setAttributeRange(AttributeType::ENDURANCE, Range(10,40));
	genome_.setAttributeRange(AttributeType::STRENGTH, Range(2,4));
    genome_.setAttributeRange(AttributeType::SIGHT_ANGLE, Range(10,90));
	genome_.setAttributeRange(AttributeType::SIGHT_RANGE, Range(50,100));
	genome_.setAttributeRange(AttributeType::HEARING_RANGE, Range(20,40));
	genome_.setAttributeRange(AttributeType::SPEED,Range(1,1.5));

}

void Specimen::generateGenome(Specimen* first_parent, Specimen* second_parent)
{
    genome_ = Genome::crossing(first_parent->getGenome(), second_parent->getGenome());

}

void Specimen::setAttributesValues()
{
    addAttribute(AttributeType::ENDURANCE, Attribute(genome_.getAttributeValue(AttributeType::ENDURANCE)));
    addAttribute(AttributeType::SIGHT_RANGE, Attribute(genome_.getAttributeValue(AttributeType::SIGHT_RANGE)));
    addAttribute(AttributeType::SIGHT_ANGLE, Attribute(genome_.getAttributeValue(AttributeType::SIGHT_ANGLE)));
    addAttribute(AttributeType::HEARING_RANGE, Attribute(genome_.getAttributeValue(AttributeType::HEARING_RANGE)));
    addAttribute(AttributeType::SPEED, Attribute(genome_.getAttributeValue(AttributeType::SPEED)));
    addAttribute(AttributeType::STRENGTH, Attribute(genome_.getAttributeValue(AttributeType::STRENGTH)));

	addAttribute(AttributeType::FOOD_NECESSITY, Attribute(1 + genome_.getAttributeEnchancement(AttributeType::ENDURANCE)+genome_.getAttributeEnchancement(AttributeType::STRENGTH)));
	addAttribute(AttributeType::WATER_NECESSITY, Attribute(1 + genome_.getAttributeEnchancement(AttributeType::HEARING_RANGE)+genome_.getAttributeEnchancement(AttributeType::SPEED)));
	addAttribute(AttributeType::SLEEP_NECESSITY, Attribute(1 + genome_.getAttributeEnchancement(AttributeType::SIGHT_ANGLE)+genome_.getAttributeEnchancement(AttributeType::SIGHT_RANGE)));


}

void Specimen::updateNeeds()
{
	needs_.modifyValue(NeedType::DRINK, getAttributeValue(AttributeType::WATER_NECESSITY)/60);
	needs_.modifyValue(NeedType::EAT, getAttributeValue(AttributeType::FOOD_NECESSITY)/60);
	needs_.modifyValue(NeedType::SLEEP, getAttributeValue(AttributeType::SLEEP_NECESSITY)/60);
    needs_.modifyValue(NeedType::REPRODUCE, 0.016);


}

void Specimen::checkBorders()
{
	QPointF veryfied_pos = pos();
	if(pos().x() > moving_rect.right())
		veryfied_pos.setX(moving_rect.left());
	else if(pos().x() < moving_rect.left())
		veryfied_pos.setX(moving_rect.right());
	if(pos().y() < moving_rect.top())
		veryfied_pos.setY(moving_rect.bottom());
	else if(pos().y() > moving_rect.bottom())
		veryfied_pos.setY(moving_rect.top());
	setPos(veryfied_pos);
}

bool Specimen::shouldRunAway()
{
    return false;
}

void Specimen::hoverEnterEvent(QGraphicsSceneHoverEvent *event)
{
    Q_UNUSED(event);
    emit hoverEnter(this);
}

void Specimen::hoverLeaveEvent(QGraphicsSceneHoverEvent *event)
{
    Q_UNUSED(event);
    emit hoverLeave();
}

void Specimen::focusInEvent(QFocusEvent *event)
{
    Q_UNUSED(event);
    focus_ring_.setVisible(true);
}

void Specimen::focusOutEvent(QFocusEvent *event)
{
    Q_UNUSED(event);
	focus_ring_.setVisible(false);
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
    if(hp_ <0)
        hp_ = 0;
}



QList<Specimen*> Specimen::collidingSpecimens(SpecimenType type)
{
    QList<Specimen*> specimens;
    for(QGraphicsItem* item : senses_.collidingItems(ItemType::SPECIMEN))
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
    for(QGraphicsItem* item : senses_.collidingItems(ItemType::FIELD))
    {
        BoardField* field = dynamic_cast<BoardField*>(item);
        if(field->getFieldType() == type)
            fields.append(field);
    }
    return fields;
}

bool Specimen::getInterrupted() const
{
    return interrupted_;
}

void Specimen::setInterrupted(bool interrupted)
{
    interrupted_ = interrupted;
}

bool Specimen::getProduceNewSpecimen() const
{
    return produce_new_specimen;
}

void Specimen::setProduceNewSpecimen(bool value)
{
    produce_new_specimen = value;
}

Genome Specimen::getGenome() const
{
    return genome_;
}

void Specimen::setGenome(const Genome& genome)
{
    genome_ = genome;
}

Specimen* Specimen::nearestSpecimen(SpecimenType type)
{
    //TODO - rozsadna wartosc ?
    qreal minDistance = 100000;
    Specimen* nearestSpec = nullptr;
    for(Specimen* specimen : collidingSpecimens(type))
    {
        QLine dist_line(pos().x(), pos().y(), specimen->pos().x(), specimen->pos().y());
        qreal distance = dist_line.dx()*dist_line.dx() + dist_line.dy()*dist_line.dy();
        if(distance < minDistance)
        {
            nearestSpec = specimen;
            minDistance = distance;
        }
    }

    return nearestSpec;
}

BoardField *Specimen::nearestField(FieldType type)
{
    //TODO - rozsadna wartosc ?
    qreal minDistance = 100000;
    BoardField* nearestField = nullptr;
    for(BoardField* field : collidingFields(type))
    {
        QLine dist_line(pos().x(), pos().y(), field->pos().x(), field->pos().y());
        qreal distance = dist_line.dx()*dist_line.dx() + dist_line.dy()*dist_line.dy();
        if(distance < minDistance && field->getAvailable())
        {
            nearestField = field;
            minDistance = distance;
        }
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

