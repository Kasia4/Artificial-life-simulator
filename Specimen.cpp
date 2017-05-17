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

QGraphicsItem *Specimen::getTarget() const
{
    return target_;
}

bool Specimen::getMove() const
{
    return move_;
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
        see_target_ = sight_.collidingItems(ItemType::SPECIMEN).contains(target_);
        hear_target_ = sight_.collidingItems(ItemType::SPECIMEN).contains(target_);
        if(see_target_ || hear_target_)
        {
            QLine dist_line(pos().x(), pos().y(), target_->pos().x(), target_->pos().y());
            qreal angle = qRadiansToDegrees( qAtan2(dist_line.dy(), dist_line.dx()));
            std::cout<<angle<<std::endl;
            qreal dist = qSqrt(dist_line.dx()*dist_line.dx() + dist_line.dy()*dist_line.dy());
            if(escape_)
            {
                angle+=180;
            }
            if(dist < TRACKING_DISTANCE_THRESHOLD)
            {
                on_target_ = true;
            }
            setRotation(angle);
            if(move_ && !on_target_)
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


void Specimen::rotateTo(qreal angle)
{

}
void Specimen::move(){
    setPos(mapToParent(velocity_,0));
}
