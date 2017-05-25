#ifndef HOVERSPECIMENEVENTFILTER_H
#define HOVERSPECIMENEVENTFILTER_H

#include <QObject>
#include <QEvent>
#include <iostream>

class HoverSpecimenEventFilter : public QObject
{
    Q_OBJECT
public:
    HoverSpecimenEventFilter();
    virtual ~HoverSpecimenEventFilter() {};

protected:
    bool eventFilter(QObject *watched, QEvent *event);
};

#endif // HOVERSPECIMENEVENTFILTER_H
