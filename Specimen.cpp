#include "Specimen.h"

Specimen::Specimen()
    :target_(nullptr)
    ,escape_(false)
    ,velocity_(0)
    ,angular_velocity_(0)
    ,on_target_(false)
    ,see_target_(false)
    ,hear_target_(false)
{
    hearing_.setParentItem(this);
    sight_.setParentItem(this);

    /*Example values*/
    setHearingRange(50);
    setSightRange(200);
    setSightAngle(30);

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

void Specimen::setSize(float size)
{
    size_ = size;
    eyes_dist_ = size/2;
    eyes_size_ = size/5;
}

void Specimen::setVelocity(float velocity)
{
    velocity_ = velocity;
}

void Specimen::setAngularVelocity(float velocity)
{
    angular_velocity_ = velocity;
}

void Specimen::setTarget(QGraphicsItem* target)
{
    target_ = target;
}

void Specimen::setEscape(bool escape)
{
    escape_ = escape;
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
}

float Specimen::getSize() const
{
    return size_;
}

float Specimen::getEyesSize() const
{
    return eyes_size_;
}

float Specimen::getEyesDist() const
{
    return eyes_dist_;
}

float Specimen::getVelocity() const
{
    return velocity_;
}

float Specimen::getAngularVelocity() const
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

QGraphicsItem *Specimen::getTarget() const
{
    return target_;
}

bool Specimen::getEscape() const
{
    return escape_;
}

QColor Specimen::getSkinColor() const
{
    return skin_color_;
}

void Specimen::advance(int step)
{
    if(!step)return;
    if(target_)
    {
        QList<QGraphicsItem*> seen_specimens = sight_.collidingItems(ItemType::SPECIMEN);
        see_target_ = seen_specimens.contains(target_);
        hear_target_ = hearing_.collidingItems(ItemType::SPECIMEN).contains(target_);
        //if(seen_specimens.count()>1)std::cout<<"Widze "<<seen_specimens.count()<<" osobnikow\n";
        if(see_target_ || hear_target_)
        {
            QPointF dist_v = target_->pos() - pos();
            qreal dist = qSqrt(dist_v.x()*dist_v.x() + dist_v.y()*dist_v.y());
            qreal angle = qRadiansToDegrees( qAtan2(dist_v.y(), dist_v.x()) );
            if(escape_)angle+=180;
            setRotation(angle);
            on_target_ = dist<TRACKING_DISTANCE_THRESHOLD;
            if(!on_target_)
            {
                setPos(mapToParent(velocity_,0));
            }
        }
        else
        {
            setRotation(rotation() + angular_velocity_);
            setPos(mapToParent(velocity_,0));
        }
    }
    else
    {
        setRotation(rotation() + angular_velocity_);
        setPos(mapToParent(velocity_,0));
    }
    if(DEBUG)std::cout<<pos().x()<<", "<<pos().y()<<"|\t on_target_ "<<on_target_<<"\t"<<"see "<<see_target_<<"\t hear"<<hear_target_<<std::endl;
}
