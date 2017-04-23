#ifndef WATERFIELD_H
#define WATERFIELD_H

#include "BoardField.h"

class WaterField : public BoardField
{
public:
    WaterField();
    FieldType type() const { return FieldType::WATER; }

};

#endif // WATERFIELD_H
