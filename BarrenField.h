#ifndef BARRENFIELD_H
#define BARRENFIELD_H

#include "BoardField.h"

class BarrenField : public BoardField
{
public:
    BarrenField();
    FieldType getFieldType() const override { return FieldType::BARREN; }
    BoardField* clone() const override;
    QColor getColor() const override;

private:
    void updateAvailable();
};

#endif // BARRENFIELD_H
