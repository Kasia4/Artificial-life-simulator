#ifndef BOARDMODEL_H
#define BOARDMODEL_H

#include <QObject>
#include <QAbstractTableModel>

#include "SimulationEngine.h"
#include "Board.h"



class BoardModel : public QAbstractTableModel
{
public:
    static const int FIELD_TYPE_ROLE = 33;
    static const int FIELD_VALUE_ROLE = 34;

    BoardModel(const SimulationEngine& engine, QObject *parent = 0);
    int rowCount(const QModelIndex &parent) const;
    int columnCount(const QModelIndex &parent) const;
    QVariant data(const QModelIndex &index, int role) const;
    QVariant headerData(int section, Qt::Orientation orientation, int role) const;
    void linkEngine(const SimulationEngine& engine);

private:
    Board* board_handle_;
};

#endif // BOARDMODEL_H
