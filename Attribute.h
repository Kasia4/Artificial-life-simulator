#ifndef ATTRIBUTE_H
#define ATTRIBUTE_H
#include <QtMath>

class Attribute
{
public:
    Attribute();
	Attribute(qreal base, qreal state_factor = 1, qreal need_factor = 1);
    qreal getValue() const;

	qreal getStateFactor() const;
	void setStateFactor(const qreal& state_factor);

	qreal getNeedFactor() const;
	void setNeedFactor(const qreal& need_factor);

    qreal getBase() const;
    void setBase(const qreal& base);

private:
    qreal base_;
	qreal state_factor_;
	qreal need_factor_;
};

#endif // ATTRIBUTE_H
