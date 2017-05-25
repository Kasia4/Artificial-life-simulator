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

void SpecimenWidget::setSpecimen(Specimen *specimen)
{
    specimen_ = specimen;
    //ui->health_value->setText("" + specimen_->getHp() + "/" + specimen_->getAttributeValue(AttributeType::ENDURANCE));
}
