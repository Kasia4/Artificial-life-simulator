#include "SpecimenWidget.h"
#include "ui_SpecimenWidget.h"

SpecimenWidget::SpecimenWidget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::SpecimenWidget)
{
    ui->setupUi(this);
}

SpecimenWidget::~SpecimenWidget()
{
    delete ui;
}
