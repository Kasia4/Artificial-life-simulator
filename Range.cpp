#include "Range.h"

Range::Range()
    :begin_(0)
    ,end_(1)
{}

Range::Range(const qreal &begin, const qreal &end)
    :begin_(begin)
    ,end_(end)
{}

qreal Range::transform(const qreal &value,const Range& origin) const
{
    return (value - origin.begin())*(lenght()/origin.lenght()) + begin();
}

qreal Range::cutValue(const qreal &value) const
{
    if(value > end_)return end_;
    if(value < begin_)return begin_;
    return value;
}

qreal Range::lenght() const
{
    return end_ - begin_;
}

qreal Range::begin() const
{
    return begin_;
}

void Range::setBegin(const qreal &begin)
{
    begin_ = begin;
}

qreal Range::end() const
{
    return end_;
}

void Range::setEnd(const qreal &end)
{
    end_ = end;
}
