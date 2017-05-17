#include "Specimen.h"

Specimen::Specimen()
    :target_(nullptr)
    ,escape_(false)
    ,velocity_(0)
    ,angular_velocity_(0)
{

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

void Specimen::setTarget(const QGraphicsItem* target)
{
    target_ = target;
}

void Specimen::setEscape(bool escape)
{
    escape_ = escape;
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

const QGraphicsItem *Specimen::getTarget() const
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
        QPointF dist_v = target_->pos() - pos();
        qreal dist = qSqrt(dist_v.x()*dist_v.x() + dist_v.y()*dist_v.y());
        qreal angle = qRadiansToDegrees( qAtan2(dist_v.y(), dist_v.x()) );
        if(escape_)
            angle+=180;
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
