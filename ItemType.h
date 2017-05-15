#ifndef ITEMTYPE_H
#define ITEMTYPE_H
#include <QGraphicsItem>

enum ItemType : unsigned {
    SPECIMEN = QGraphicsItem::UserType + 1,
    FIELD,
    COLLIDER,
    BORDER
};

#endif // ITEMTYPE_H
