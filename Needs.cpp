#include "Needs.h"

const Range Needs::NEED_RANGE = Range(0,100);

Needs::Needs(qreal criticalLevel)
{
	critical_level_ = criticalLevel;
}

void Needs::addNeed(NeedType need_type, qreal value, int priority)
{
    //needs_[priority]=qMakePair(needType, value);
	needs_.insert(priority, qMakePair(need_type, value));
}

void Needs::removeNeed(NeedType need_type)
{
    for(auto it=needs_.begin(); it != needs_.end(); ++it)
    {
		if(it->first == need_type)
            needs_.erase(it);
    }
}

void Needs::setValue(NeedType need_type, qreal value)
{
    for(auto it=needs_.begin(); it != needs_.end(); ++it)
    {
		if(it->first == need_type)
		{
			it->second = value;
			break;
		}
	}
}

void Needs::modifyValue(NeedType need_type, qreal difference)
{
	for(auto it=needs_.begin(); it != needs_.end(); ++it)
	{
		if(it->first == need_type)
		{
			it->second += NEED_RANGE.cutValue(difference);
			break;
		}
	}
}

qreal Needs::getValue(NeedType need_type) const
{
    auto it=needs_.begin();
    for( ; it != needs_.end(); ++it)
    {
		if(it->first == need_type)
            break;
    }
    return it->second;
}



NeedType Needs::mostImportant()
{
    auto temp = needs_.begin();
    for(auto it = needs_.begin(); it != needs_.end(); ++it)
    {
		if(it->second >= critical_level_)
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
	return critical_level_;
}

void Needs::setCriticalLevel(const qreal &criticalLevel)
{
	critical_level_ = criticalLevel;
}

QList<QPair<NeedType, qreal> > Needs::getNeeds() const
{
    return needs_;
}

void Needs::setNeeds(const QList<QPair<NeedType, qreal> > &needs)
{
    needs_ = needs;
}

qreal Needs::getFatalLevel() const
{
	return fatal_level_;
}

void Needs::setFatalLevel(const qreal& fatal_level)
{
	fatal_level_ = fatal_level;
}
