#include "Needs.h"

Needs::Needs(qreal criticalLevel)
{
    criticalLevel_ = criticalLevel;
}

void Needs::addNeed(NeedType needType, qreal value, int priority)
{
    //needs_[priority]=qMakePair(needType, value);
    needs_.insert(priority, qMakePair(needType, value));
}

void Needs::removeNeed(NeedType needType)
{
    for(auto it=needs_.begin(); it != needs_.end(); ++it)
    {
        if(it->first == needType)
            needs_.erase(it);
    }
}

qreal Needs::getValue(NeedType needType) const
{
    auto it=needs_.begin();
    for( ; it != needs_.end(); ++it)
    {
        if(it->first == needType)
            break;
    }
    return it->second;
}



NeedType Needs::mostImportant()
{
    auto temp = needs_.begin();
    for(auto it = needs_.begin(); it != needs_.end(); ++it)
    {
        if(it->second >= criticalLevel_)
        {
            temp = it;
            break;
        }
        else if (it->second > temp->second)
            temp=it;
    }
    return temp->first;
}

qreal Needs::getCriticalLevel() const
{
    return criticalLevel_;
}

void Needs::setCriticalLevel(const qreal &criticalLevel)
{
    criticalLevel_ = criticalLevel;
}

QList<QPair<NeedType, qreal> > Needs::getNeeds() const
{
    return needs_;
}

void Needs::setNeeds(const QList<QPair<NeedType, qreal> > &needs)
{
    needs_ = needs;
}
