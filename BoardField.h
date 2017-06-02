/* BoardField.h
 * author: Karol Checinski
 * The BoardField class provides single board field.
 */

#ifndef BOARDFIELD_H
#define BOARDFIELD_H

#include <QGraphicsItem>
#include <QPainter>

#include "SimulationObject.h"
#include "ItemType.h"

enum class FieldType : unsigned{
    GROUND = 0,
    WATER,
    BARREN,
    VOID = 99
};

class BoardField : public SimulationObject
{
public:
    BoardField();
    BoardField(const QPoint& position);
    virtual FieldType getFieldType() const = 0;
    virtual BoardField* clone() const = 0;
    virtual QColor getColor() const = 0;

    QRectF fieldRect() const;
    int type() const;

    QRectF boundingRect() const override;
    virtual void paint(QPainter * painter, const QStyleOptionGraphicsItem * option, QWidget * widget = 0) override;
    void setSize(qreal size);
    qreal getSize() const;

    QPoint getPosition() const;
    void setPosition(const QPoint &position);

    bool getAvailable() const;
    void setAvailable(bool available);
    void lockField();
protected:
    virtual void updateAvailable() = 0;
    virtual void advance(int step);
    bool available_;
private:
    qreal size_;
    QPoint position_;

};


#endif // BOARDFIELD_H
