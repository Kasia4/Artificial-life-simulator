#ifndef RANGE_H
#define RANGE_H

#include <QtGlobal>

class Range
{
public:
    Range();
    Range(const qreal& begin, const qreal& end);


    qreal transform(const qreal& value, const Range &origin = Range(0.0,1.0)) const;
    qreal cutValue(const qreal &value) const;

    qreal lenght() const;

    qreal begin() const;
    void setBegin(const qreal &begin);

    qreal end() const;
    void setEnd(const qreal &end);


private:
    qreal begin_;
    qreal end_;
};

#endif // RANGE_H
