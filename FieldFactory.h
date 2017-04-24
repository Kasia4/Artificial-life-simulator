#ifndef FIELDFACTORY_H
#define FIELDFACTORY_H

#include <QMap>
#include <iostream>

#include "GroundField.h"
#include "WaterField.h"

class FieldFactory
{
public:
    static FieldFactory& getInstance();
    void registerField(FieldType type, BoardField* prototype);
    BoardField* create(FieldType type);

private:
    QMap<FieldType, BoardField*> prototypes_;

    FieldFactory();
    FieldFactory( const FieldFactory & ) = delete;
    FieldFactory& operator=(const FieldFactory&) = delete;


};

#endif // FIELDFACTORY_H
