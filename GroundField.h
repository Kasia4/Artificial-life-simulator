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
    static constexpr qreal OVERGROW_THRESHOLD = 10;
    static constexpr qreal BASE_OVERGROW_SPEED = 0.02;

    GroundField(qreal overgrow_level = 0);
    FieldType getFieldType() const { return FieldType::GROUND; }
    BoardField* clone() const;
    QColor getColor() const override;
    /* Adds given value to current overgrow_level value*/
    void modifyOvergrow( qreal value );
    virtual void advance(int phase);

    qreal getOvergrow() const;
    void setOvergrow(const qreal& overgrow_level );
    qreal getOvergrowingSpeed() const;
    void setOvergrowingSpeed(const qreal &overgrowingSpeed);

private:
    void updateAvailable();
    qreal overgrow_level_;
    qreal overgrowing_speed_;

};

#endif // GROUNDFIELD_H
