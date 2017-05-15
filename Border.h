#ifndef BORDER_H
#define BORDER_H
#include "ItemType.h"
#include <QGraphicsItem>

class Border : public QGraphicsItem
{
public:
    Border();
    int type() const;
};

#endif // BORDER_H
