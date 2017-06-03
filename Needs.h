#ifndef NEEDS_H
#define NEEDS_H

#include "Range.h"
#include "NeedType.h"
#include <QPair>
#include <QList>
#include <QtMath>


class Needs
{
public:
	static const Range NEED_RANGE;

    typedef QPair<NeedType, qreal> Need;
	Needs(qreal criticalLevel = 70);
	void addNeed(NeedType need_type, qreal value, int priority = 0);
	void removeNeed(NeedType need_type);
	int getPriority(NeedType need_type) const;
	void setValue(NeedType need_type, qreal value);
	void modifyValue(NeedType need_type, qreal difference);
	qreal getValue(NeedType need_type) const;

    NeedType mostImportant();

    qreal getCriticalLevel() const;
    void setCriticalLevel(const qreal &criticalLevel);

    QList<QPair<NeedType, qreal>> getNeeds() const;
    void setNeeds(const QList<QPair<NeedType, qreal>> &needs);

	qreal getFatalLevel() const;
	void setFatalLevel(const qreal& fatal_level);

private:
	QList<QPair<NeedType, qreal>> needs_;
	qreal fatal_level_;
	qreal critical_level_;
};


#endif // NEEDS_H
