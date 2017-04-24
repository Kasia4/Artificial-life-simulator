#include "FieldFactory.h"

FieldFactory::FieldFactory()
{
    registerField(FieldType::GROUND, new GroundField);
    registerField(FieldType::WATER, new WaterField);
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

BoardField* FieldFactory::create(FieldType type)
{
    if(!prototypes_.take(type))std::cout<<"yoooo"<<std::endl;
    return prototypes_.take(type)->clone();
}

