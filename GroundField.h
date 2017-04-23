#ifndef GROUNDFIELD_H
#define GROUNDFIELD_H

#include "BoardField.h"

class GroundField : public BoardField
{
public:
    GroundField();
    FieldType type() const { return FieldType::GROUND; }
    void setOvergrow( int overgrow_level );
    void modifyOvergrow( int value );

    int getOvergrow() const;
private:
    int overgrow_level_;

};

#endif // GROUNDFIELD_H
