#ifndef ATTRIBUTE_H
#define ATTRIBUTE_H
#include <QtMath>

class Attribute
{
public:
    Attribute();
    Attribute(qreal base, qreal factor_state = 1, qreal factor_need = 1);
    qreal getValue() const;

    qreal getFactor_state() const;
    void setFactor_state(const qreal& factor_state);

    qreal getFactor_need() const;
    void setFactor_need(const qreal& factor_need);

    qreal getBase() const;
    void setBase(const qreal& base);

private:
    qreal base_;
    qreal factor_state_;
    qreal factor_need_;
};

#endif // ATTRIBUTE_H
