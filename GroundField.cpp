#include "GroundField.h"

GroundField::GroundField()
    :overgrow_level_(0)
{

}

int GroundField::getOvergrow() const
{
    return overgrow_level_;
}

void GroundField::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    painter->fillRect(boundingRect(), QColor(200-overgrow_level_*2,150,0));
}

BoardField *GroundField::clone() const
{
    return new GroundField;
}

void GroundField::setOvergrow(int overgrow_level)
{
    if(overgrow_level < 0)
    {
        overgrow_level_=0;
        return;
    }
    else if(overgrow_level > 100)
    {
        overgrow_level_ = 100;
        return;
    }
    overgrow_level_ = overgrow_level;

}
