#include "FieldFactory.h"

FieldFactory::FieldFactory()
{
    registerField(FieldType::GROUND, new GroundField);
    registerField(FieldType::WATER, new WaterField);
    registerField(FieldType::BARREN, new BarrenField);
}

FieldFactory::~FieldFactory()
{
    for(auto field : prototypes_)
         delete field;
}

FieldFactory& FieldFactory::getInstance()
{
    static FieldFactory instance;
    return instance;
}

void FieldFactory::registerField(FieldType type, BoardField *prototype)
{
    prototypes_.insert(type, prototype);
}

BoardField* FieldFactory::create(FieldType type, const QPoint &position)
{
    BoardField* created = prototypes_.value(type)->clone();
    created->setPosition(position);
    return created;
}

