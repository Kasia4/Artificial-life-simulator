#ifndef BOARDFIELD_H
#define BOARDFIELD_H

enum class FieldType : unsigned{
    GROUND = 0,
    WATER,
    BARREN
};

class BoardField
{
public:
    BoardField();
    virtual FieldType type() const = 0;
};

#endif // BOARDFIELD_H
