#include "GroundField.h"

const Range GroundField::GRASS_RANGE = Range(0,100);

GroundField::GroundField()
    :overgrow_level_(0)
    ,overgrowing_speed_(0.1)
{

}

qreal GroundField::getOvergrow() const
{
    return overgrow_level_;
}

qreal GroundField::getOvergrowingSpeed() const
{
    return overgrowing_speed_;
}

void GroundField::setOvergrowingSpeed(const qreal &overgrowingSpeed)
{
    overgrowing_speed_ = overgrowingSpeed;
}


BoardField *GroundField::clone() const
{
    GroundField* temp = new GroundField;
    temp->overgrow_level_ = overgrow_level_;
    return temp;
}

QColor GroundField::getColor() const
{
    return QColor(200-overgrow_level_*2,150,0);
}

void GroundField::setOvergrow(const qreal& overgrow_level)
{
    overgrow_level_ = GroundField::GRASS_RANGE.cutValue(overgrow_level);

}

void GroundField::modifyOvergrow(qreal value)
{
    overgrow_level_ = GroundField::GRASS_RANGE.cutValue(overgrow_level_ + value);
    this->update();
}

void GroundField::advance(int phase)
{
    if(!phase)return;
    modifyOvergrow(overgrowing_speed_);
}
