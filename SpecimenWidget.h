#ifndef SPECIMENWIDGET_H
#define SPECIMENWIDGET_H

#include <QWidget>
#include <QMouseEvent>
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

    void connectSpecimen(Specimen* specimen);
    Specimen* getSpecimen() const;
    void disconnectSpecimen();


protected:
    void mouseMoveEvent(QMouseEvent *event);

private:
    Ui::SpecimenWidget *ui;
    Specimen* specimen_;
private slots:
    void updateInfo();
};

#endif // SPECIMENWIDGET_H
