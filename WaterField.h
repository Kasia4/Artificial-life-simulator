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
    QColor getColor() const override;
private:
    void updateAvailable();
};

#endif // WATERFIELD_H
