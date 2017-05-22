/* SpecimensModel.h
 * author: Karol Checinski
 * The SpecimensModel class provides communication
 * between SimulatorEngine and QTableView. Provides information
 * about specimens on board.
 */
#ifndef SPECIMENSMODEL_H
#define SPECIMENSMODEL_H

#include <QObject>
#include <QAbstractTableModel>
#include <QList>

#include "SimulationEngine.h"
#include "Specimen.h"

class SpecimensModel : public QAbstractTableModel
{
public:
    SpecimensModel(const SimulationEngine& engine);
    void linkEngine(const SimulationEngine& engine);
    int rowCount(const QModelIndex &parent) const;
    int columnCount(const QModelIndex &parent) const;
    QVariant data(const QModelIndex &index, int role) const;
    QVariant headerData(int section, Qt::Orientation orientation, int role) const;
private:
    void setAttributesStrings();
    const QList<Specimen*> *specimens_handle_;
    QMap<AttributeType, QString> attributes_strings_;

};

#endif // SPECIMENSMODEL_H
