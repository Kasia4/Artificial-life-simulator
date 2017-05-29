#include "SearchFoodState.h"

SearchFoodState::SearchFoodState()
{

}

State* SearchFoodState::action(Specimen *specimen)
{
    State* result = State::action(specimen);
    if(result)
       return result;
    return searchForFood(specimen);
}

State* SearchFoodState::searchForFood(Specimen *specimen)
{
    std::cout<<"szukam jedzenia ";
    if(!specimen->getTarget() /*|| specimen->getTarget() != nearestFood(specimen)*/)
    {
        std::cout<<"\nustawiam\n"<<specimen->getTarget()<<"\n";
        specimen->disableTracking();
        specimen->setTarget(nearestFood(specimen));
        std::cout<<"na to "<<specimen->getTarget();
    }

    if(specimen->getCaughtTarget())
       return new EatState();
    std::cout<<"nie znalazlem ";
    return this;
}




QGraphicsItem *SearchFoodState::nearestFood(Specimen *specimen)
{
    std::cout<<"TU ";
    if(specimen->getSpec() == SpecimenType::HERBIVORE)
    {
        std::cout<<"najblizszy "<<specimen->nearestField(FieldType::GROUND)<<"\n";
        return specimen->nearestField(FieldType::GROUND);
    }

    return specimen->nearestSpecimen(SpecimenType::HERBIVORE);

}
