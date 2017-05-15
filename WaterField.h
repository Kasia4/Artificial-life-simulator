/* WaterField.h
 * author: Karol Checinski
 * The WaterField class provides water field type
 */

#ifndef WATERFIELD_H
#define WATERFIELD_H

#include "BoardField.h"

class WaterField : public BoardField
{
public:
    WaterField();
    FieldType getFieldType() const override { return FieldType::WATER; }
    BoardField* clone() const override;
    void paint(QPainter * painter, const QStyleOptionGraphicsItem * option, QWidget * widget = 0) override;

};

#endif // WATERFIELD_H
