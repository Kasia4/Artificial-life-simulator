#include "BoardModel.h"

BoardModel::BoardModel(const SimulationEngine &engine, QObject *parent)
    :QAbstractTableModel(parent)
{
    linkEngine(engine);
}

int BoardModel::rowCount(const QModelIndex &parent) const
{
    Q_UNUSED(parent);
    return board_handle_->getHeight();
}

int BoardModel::columnCount(const QModelIndex &parent) const
{
    Q_UNUSED(parent);
    return board_handle_->getWidth();
}

QVariant BoardModel::data(const QModelIndex &index, int role) const
{
    if(!index.isValid())
        return QVariant();
    BoardField* field = board_handle_->getField(QPoint(index.column(), index.row()));
    if( role == FIELD_TYPE_ROLE )
    {
        return int(field->getFieldType());
    }
    if( index.column() > board_handle_->getWidth() || index.row() > board_handle_->getHeight() )
    {
        return QVariant();
    }
    else if( role == FIELD_VALUE_ROLE )
    {
        if(field->getFieldType() == FieldType::GROUND)
        {
            return (dynamic_cast<GroundField*>(field))->getOvergrow();
        }
        return 0;
    }
    return QVariant();
}

QVariant BoardModel::headerData(int section, Qt::Orientation orientation, int role) const
{
    Q_UNUSED(orientation);
    if (role != Qt::DisplayRole)
        return QVariant();
    return int(section);
}



void BoardModel::linkEngine(const SimulationEngine &engine)
{
    board_handle_ = engine.getBoard();
}

