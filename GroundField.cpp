#include "GroundField.h"

const Range GroundField::GRASS_RANGE = Range(0,50);
const Range GroundField::GROWTH_RATE_RANGE = Range(0.01, 0.03);

GroundField::GroundField(qreal overgrow_level)
    :overgrow_level_(overgrow_level)
    ,overgrowing_speed_(BASE_OVERGROW_SPEED)
{
    updateAvailable();
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

void GroundField::updateAvailable()
{
   available_= (overgrow_level_ >= OVERGROW_THRESHOLD);

}


BoardField *GroundField::clone() const
{
    GroundField* temp = new GroundField;
    temp->overgrow_level_ = overgrow_level_;
    return temp;
}

QColor GroundField::getColor() const
{
	return QColor(200-overgrow_level_*(200/GRASS_RANGE.end()),150,0);
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
	modifyOvergrow(growthRate());
	updateAvailable();
}

qreal GroundField::growthRate()
{
	return overgrowing_speed_*GROWTH_RATE_RANGE.transform(overgrow_level_, GRASS_RANGE);
}
