/* BoardField.h
 * author: Karol Checinski
 * The BoardField class provides single board field.
 */

#ifndef BOARDFIELD_H
#define BOARDFIELD_H

#include <QGraphicsItem>
#include <QPainter>


enum class FieldType : unsigned{
    GROUND = 0,
    WATER,
    BARREN
};

class BoardField : public QGraphicsItem
{
public:
    BoardField();
    virtual FieldType getType() const = 0;
    virtual BoardField* clone() const = 0;
    QRectF boundingRect() const override;
    virtual void paint(QPainter * painter, const QStyleOptionGraphicsItem * option, QWidget * widget = 0) override;
    void setSize(float size);
    float getSize() const;

private:
    float size_;
};

#endif // BOARDFIELD_H
