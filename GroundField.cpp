#include "GroundField.h"

const Range GroundField::GRASS_RANGE = Range(0,100);

GroundField::GroundField()
    :overgrow_level_(0)
{

}

qreal GroundField::getOvergrow() const
{
    return overgrow_level_;
}

void GroundField::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    Q_UNUSED(option);
    Q_UNUSED(widget);
    painter->fillRect(boundingRect(), QColor(200-overgrow_level_*2,150,0));
}

BoardField *GroundField::clone() const
{
    GroundField* temp = new GroundField;
    temp->overgrow_level_ = overgrow_level_;
    return temp;
}

void GroundField::setOvergrow(qreal overgrow_level)
{
    overgrow_level_ = GroundField::GRASS_RANGE.cutValue(overgrow_level);

}

void GroundField::modifyOvergrow(qreal value)
{
    overgrow_level_ = GroundField::GRASS_RANGE.cutValue(overgrow_level_ + value);
}
