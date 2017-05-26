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

void SpecimenWidget::disconnectSpecimen()
{
    disconnect(specimen_, SIGNAL(attributesChanged()), this, SLOT(updateInfo()));
    specimen_ = nullptr;
}

void SpecimenWidget::connectSpecimen(Specimen *specimen)
{
    specimen_ = specimen;
    connect(specimen_, SIGNAL(attributesChanged()), this, SLOT(updateInfo()));
}


void SpecimenWidget::mouseMoveEvent(QMouseEvent *event)
{
    this->move(event->pos());
}

void SpecimenWidget::updateInfo()
{

}
