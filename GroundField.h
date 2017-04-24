#ifndef GROUNDFIELD_H
#define GROUNDFIELD_H

#include "BoardField.h"

class GroundField : public BoardField
{
public:
    GroundField();
    FieldType getType() const { return FieldType::GROUND; }
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget);
    BoardField* clone() const;
    void setOvergrow( int overgrow_level );
    void modifyOvergrow( int value );

    int getOvergrow() const;
private:
    int overgrow_level_;

};

#endif // GROUNDFIELD_H
