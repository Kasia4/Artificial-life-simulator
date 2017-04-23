#ifndef WATERFIELD_H
#define WATERFIELD_H

#include "BoardField.h"

class WaterField : public BoardField
{
public:
    WaterField();
    FieldType getType() const { return FieldType::WATER; }
    void paint(QPainter * painter, const QStyleOptionGraphicsItem * option, QWidget * widget = 0);

};

#endif // WATERFIELD_H
