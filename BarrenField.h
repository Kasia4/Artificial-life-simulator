#ifndef BARRENFIELD_H
#define BARRENFIELD_H

#include "BoardField.h"

class BarrenField : public BoardField
{
public:
    BarrenField();
    FieldType getFieldType() const override { return FieldType::BARREN; }
    BoardField* clone() const override;
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget);
};

#endif // BARRENFIELD_H
