#include "Specimen.h"

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
    ,thirst_(0)
    ,hunger_(0)
    ,tiredness_(0)
    ,needChanged_(false)
{
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
    addAttribute(AttributeType::SLEEPING_NECESSITY, Attribute(0.1));

    hp_ = attributes_.value(AttributeType::ENDURANCE).getValue();
    currentState_ = new State();
    currentNeed_ = Need::NONE;
    hearing_.setVisiblity(true);
    sight_.setVisiblity(true);
}

int Specimen::type() const
{
    return ItemType::SPECIMEN;

}


QRectF Specimen::boundingRect() const
{
    return QRectF(-size_/2,-size_/2, size_, size_);

}

void Specimen::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    Q_UNUSED(option);
    Q_UNUSED(widget);
    QPainterPath circle_path;
    circle_path.addEllipse(boundingRect());
    circle_path.addEllipse(size_/5, -eyes_dist_/2 - eyes_size_/2, eyes_size_, eyes_size_);
    circle_path.addEllipse(size_/5,  eyes_dist_/2 - eyes_size_/2, eyes_size_, eyes_size_);
    painter->setPen(QPen(QColor(0, 0, 0),2));
    painter->setBrush(skin_color_);
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


QGraphicsItem *Specimen::getTarget() const
{
    return target_;
}

bool Specimen::getMove() const
{
    return move_;
}

QColor Specimen::getSkinColor() const
{
    return skin_color_;
}

void Specimen::advance(int step)
{
    if(!step)return;
    if(chaser_)
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
    else if(target_)
    {
        see_target_ = sight_.collidingItems(ItemType::SPECIMEN).contains(target_);
        hear_target_ = sight_.collidingItems(ItemType::SPECIMEN).contains(target_);
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
    else
    {
        if(move_)
        {
            setRotation(rotation() + angular_velocity_);
            move();
        }
    }
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

Need Specimen::getCurrentNeed() const
{
    return currentNeed_;
}

void Specimen::setCurrentNeed(const Need &currentNeed)
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

qreal Specimen::getTiredness() const
{
    return tiredness_;
}

void Specimen::setTiredness(const qreal &value)
{
    tiredness_ = value;
}

qreal Specimen::getHunger() const
{
    return hunger_;
}

void Specimen::setHunger(const qreal &value)
{
    hunger_ = value;
}

qreal Specimen::getThirst() const
{
    return thirst_;
}

void Specimen::setThirst(const qreal &value)
{
    thirst_ = value;
}

void Specimen::addAttribute(AttributeType type, Attribute attribute)
{
    attributes_.insert(type, attribute);
}

QMap<AttributeType, Attribute> Specimen::getAttributes() const
{
    return attributes_;
}

bool Specimen::getEscapedFromChaser() const
{
    return escaped_from_chaser_;
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


void Specimen::rotateTo(qreal angle)
{
    //    qreal rot = fmod(rotation(), 360) - 180;
    //    if(rot<-180)rot+=360;
    //    qreal diff = rot - angle;
//    std::cout<<diff<<" = "<<rot <<" - "<<angle<<std::endl;
//    if(qAbs(diff) < ROTATING_DISTANCE_THRESHOLD)
//        return;
//    qreal vel = (diff <= 180) ? qAbs(angular_velocity_) :
//                                -qAbs(angular_velocity_);
//    setRotation(rotation() + vel);

}
void Specimen::move(){
    setPos(mapToParent(velocity_,0));
}
