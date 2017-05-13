#include "Specimen.h"

Specimen::Specimen()
{

}


QRectF Specimen::boundingRect() const
{
    return QRectF(-size_/2,  -size_/2, size_, size_);

}

void Specimen::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    Q_UNUSED(option);
    Q_UNUSED(widget);
    painter->drawEllipse(boundingRect());
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

float Specimen::getVelocity() const
{
    return velocity_;
}

float Specimen::getAngularVelocity() const
{
    return angular_velocity_;
}

void Specimen::advance(int step)
{
    if(!step)return;
    float dx = qCos(rotation())*velocity_;
    float dy = qSin(rotation())*velocity_;
    moveBy(dx, dy);
    std::cout<<pos().x()<<", "<<pos().y()<<std::endl;
    setRotation(rotation() + angular_velocity_);
}
