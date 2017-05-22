/* GroundField.h
 * author: Karol Checinski
 * The GroundField class provides ground field type. Have grass overgrow level.
 */

#ifndef GROUNDFIELD_H
#define GROUNDFIELD_H

#include "BoardField.h"
#include "Range.h"

class GroundField : public BoardField
{
public:
    static const Range GRASS_RANGE;
    GroundField();
    FieldType getFieldType() const { return FieldType::GROUND; }
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget);
    BoardField* clone() const;
    void setOvergrow( qreal overgrow_level );

    /* Adds given value to current overgrow_level value*/
    void modifyOvergrow( qreal value );

    qreal getOvergrow() const;
private:
    qreal overgrow_level_;

};

#endif // GROUNDFIELD_H
