#ifndef SPECIMEN_H
#define SPECIMEN_H

#include <QGraphicsItem>
#include <QPainter>


enum class SpecimenType : unsigned {
    HERBIVORE = 0,
    CARNIVORE
};


class Specimen : public QGraphicsItem
{
public:
    Specimen();
    virtual SpecimenType getType() const = 0;
    virtual Specimen* clone() const = 0;
    QRectF boundingRect() const;
    virtual void paint(QPainter* painter, const QStyleOptionGraphicsItem* option, QWidget* widget = 0);
    void setSize(float size);
    float getSize() const;

private:
    float size_;

};

#endif // SPECIMEN_H
