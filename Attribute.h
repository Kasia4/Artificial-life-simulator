#ifndef ATTRIBUTE_H
#define ATTRIBUTE_H
#include <QtMath>

class Attribute
{
public:
    Attribute();
    Attribute(qreal base, qreal factor = 1);
    qreal getValue() const;
    void setFactor(const qreal& factor);
    qreal getFactor() const;

private:
    qreal base_;
    qreal factor_;
};

#endif // ATTRIBUTE_H
