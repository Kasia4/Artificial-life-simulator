/* BoardField.h
 * author: Karol Checinski
 * The BoardField class provides single board field.
 */

#ifndef BOARDFIELD_H
#define BOARDFIELD_H

#include <QGraphicsItem>
#include <QPainter>
#include "ItemType.h"

enum class FieldType : unsigned{
    GROUND = 0,
    WATER,
    BARREN
};

class BoardField : public QGraphicsItem
{
public:
    BoardField();
    virtual FieldType getFieldType() const = 0;
    virtual BoardField* clone() const = 0;
    int type() const;

    QRectF boundingRect() const override;
    virtual void paint(QPainter * painter, const QStyleOptionGraphicsItem * option, QWidget * widget = 0) override;
    void setSize(qreal size);
    qreal getSize() const;

private:
    qreal size_;
};

#endif // BOARDFIELD_H
