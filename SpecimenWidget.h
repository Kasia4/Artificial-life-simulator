#ifndef SPECIMENWIDGET_H
#define SPECIMENWIDGET_H

#include <QWidget>

namespace Ui {
class SpecimenWidget;
}

class SpecimenWidget : public QWidget
{
    Q_OBJECT

public:
    explicit SpecimenWidget(QWidget *parent = 0);
    ~SpecimenWidget();

private:
    Ui::SpecimenWidget *ui;
};

#endif // SPECIMENWIDGET_H
