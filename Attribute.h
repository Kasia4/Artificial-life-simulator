#ifndef ATTRIBUTE_H
#define ATTRIBUTE_H
#include <QtMath>

class Attribute
{
public:
    Attribute();
    Attribute(qreal base, qreal factor);
    qreal getValue();
private:
    qreal base;
    qreal factor;
};

#endif // ATTRIBUTE_H
