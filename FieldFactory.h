/* FieldFactory.h
 * author: Karol Checinski
 * The FieldFactory class provides Factory to create default fields by cloning prototypes
 */

#ifndef FIELDFACTORY_H
#define FIELDFACTORY_H

#include <QMap>

#include "GroundField.h"
#include "WaterField.h"
#include "BarrenField.h"

class FieldFactory
{
public:
	~FieldFactory();
    static FieldFactory& getInstance();
    void registerField(FieldType type, BoardField* prototype);
    BoardField* create(FieldType type, const QPoint& position);

private:
    FieldFactory();
    FieldFactory( const FieldFactory & ) = delete;
    FieldFactory& operator=(const FieldFactory&) = delete;

    QMap<FieldType, BoardField*> prototypes_;
};

#endif // FIELDFACTORY_H
