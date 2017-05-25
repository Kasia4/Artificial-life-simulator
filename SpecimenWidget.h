#ifndef SPECIMENWIDGET_H
#define SPECIMENWIDGET_H

#include <QWidget>
#include "Specimen.h"

namespace Ui {
class SpecimenWidget;
}

class SpecimenWidget : public QWidget
{
    Q_OBJECT

public:
    explicit SpecimenWidget(QWidget *parent = 0);
    ~SpecimenWidget();

    void setSpecimen(Specimen* specimen);
    Specimen* getSpecimen() const;

private:
    Ui::SpecimenWidget *ui;
    Specimen* specimen_;
};

#endif // SPECIMENWIDGET_H
