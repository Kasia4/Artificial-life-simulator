/* GroundField.h
 * author: Karol Checinski
 * The GroundField class provides ground field type. Have grass overgrow level.
 */

#ifndef GROUNDFIELD_H
#define GROUNDFIELD_H

#include "BoardField.h"
class GroundField : public BoardField
{
public:
    GroundField();
    FieldType getFieldType() const { return FieldType::GROUND; }
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget);
    BoardField* clone() const;
    void setOvergrow( int overgrow_level );

    /* Adds given value to current overgrow_level value*/
    void modifyOvergrow( int value );

    int getOvergrow() const;
private:
    int overgrow_level_;

};

#endif // GROUNDFIELD_H
