#include "SpecimensModel.h"

SpecimensModel::SpecimensModel(const SimulationEngine &engine)
{
    specimens_handle_ = &(engine.getSpecimens());
    setAttributesStrings();
}

int SpecimensModel::rowCount(const QModelIndex &parent) const
{
    Q_UNUSED(parent);
    return specimens_handle_->count();
}

int SpecimensModel::columnCount(const QModelIndex &parent) const
{
    Q_UNUSED(parent);
    return specimens_handle_->first()->getAttributes().size();
}

QVariant SpecimensModel::data(const QModelIndex &index, int role) const
{
    if(!index.isValid())
        return QVariant();
    if(role == Qt::TextAlignmentRole)
        return int(Qt::AlignCenter | Qt::AlignVCenter);
    if(role == Qt::DisplayRole)
    {
        qreal value = specimens_handle_->at(index.row())->getAttributeValue(static_cast<AttributeType>(index.column()));
        return QVariant(value);
    }
    return QVariant();
}

QVariant SpecimensModel::headerData(int section, Qt::Orientation orientation, int role) const
{
    if(role != Qt::DisplayRole)
        return QVariant();
    if(orientation == Qt::Vertical) return QVariant(section);
    return attributes_strings_.value(static_cast<AttributeType>(section));
}

void SpecimensModel::setAttributesStrings()
{
    attributes_strings_.insert(AttributeType::ENDURANCE,            "Endurance"             );
    attributes_strings_.insert(AttributeType::FOOD_NECESSITY,       "Food necessity"        );
    attributes_strings_.insert(AttributeType::HEARING_RANGE,        "Hearing range"         );
    attributes_strings_.insert(AttributeType::SIGHT_ANGLE,          "Sight angle"           );
    attributes_strings_.insert(AttributeType::SIGHT_RANGE,          "Sight range"           );
    attributes_strings_.insert(AttributeType::SLEEP_NECESSITY,   "Sleeping necessity"    );
    attributes_strings_.insert(AttributeType::SPEED,                "Speed"                 );
    attributes_strings_.insert(AttributeType::STRENGTH,             "Strenght"              );
    attributes_strings_.insert(AttributeType::WATER_NECESSITY,      "Water necessity"       );
}


