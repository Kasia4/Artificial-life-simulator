#ifndef ATTRIBUTE_H
#define ATTRIBUTE_H
#include <QtMath>

class Attribute
{
public:
    Attribute();
    Attribute(qreal base, qreal factor = 1);
    qreal getValue() const;
private:
    qreal base;
    qreal factor;
};

#endif // ATTRIBUTE_H
