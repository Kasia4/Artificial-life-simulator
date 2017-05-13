#include "Specimen.h"

Specimen::Specimen()
{

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

QColor Specimen::getSkinColor() const
{
    return skin_color_;
}

void Specimen::advance(int step)
{
    if(!step)return;
    setPos(mapToParent(velocity_,0));

    std::cout<<pos().x()<<", "<<pos().y()<<std::endl;
    setRotation(rotation() + angular_velocity_);
}
