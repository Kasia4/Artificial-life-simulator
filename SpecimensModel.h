#ifndef SPECIMENSMODEL_H
#define SPECIMENSMODEL_H

#include <QObject>
#include <QAbstractItemModel>
#include <QList>

#include "SimulationEngine.h"
#include "Specimen.h"

class SpecimensModel : public QAbstractItemModel
{
public:
    SpecimensModel();
    void linkEngine(const SimulationEngine& engine);
private:
    QList<Specimen> *specimens_handle;
};

#endif // SPECIMENSMODEL_H
