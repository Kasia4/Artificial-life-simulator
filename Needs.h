#ifndef NEEDS_H
#define NEEDS_H
#include "NeedType.h"
#include <QPair>
#include <QList>
#include <QtMath>

class Needs
{
public:
    typedef QPair<NeedType, qreal> Need;
    Needs(qreal criticalLevel);
    void addNeed(NeedType needType, qreal value, int priority = 0);
    void removeNeed(NeedType needType);
    int getPriority(NeedType needType) const;
    void setValue(NeedType needType, qreal value);
    qreal getValue();

    NeedType mostImportant();

    qreal getCriticalLevel() const;
    void setCriticalLevel(const qreal &criticalLevel);

    QList<QPair<NeedType, qreal>> getNeeds() const;
    void setNeeds(const QList<QPair<NeedType, qreal>> &needs);

private:
    QList<QPair<NeedType, qreal>> needs_;
    qreal criticalLevel_;
};


#endif // NEEDS_H
