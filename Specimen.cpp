#include "Specimen.h"

Specimen::Specimen()
{

}


QRectF Specimen::boundingRect() const
{
    return QRectF(x() - size_, y() - size_, size_*2, size_*2);

}

void Specimen::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    painter->drawEllipse(boundingRect());
}

void Specimen::setSize(float size)
{
    size_=size;
}

void Specimen::setVelocity(QVector2D velocity)
{
    velocity_ = velocity;
}

float Specimen::getSize() const
{
    return size_;
}

QVector2D Specimen::getVelocity() const
{
    return velocity_;
}

void Specimen::advance(int step)
{
    if(!step)return;
    moveBy(velocity_.x(), velocity_.y());
    std::cout<<pos().x()<<", "<<pos().y()<<std::endl;
    setRotation(rotation() + angular_velocity_);
}
