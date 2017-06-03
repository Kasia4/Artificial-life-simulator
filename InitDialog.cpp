#include "InitDialog.h"
#include "ui_InitDialog.h"

InitDialog::InitDialog(QWidget *parent) :
    QDialog(parent)
    ,ui(new Ui::InitDialog)
{
    ui->setupUi(this);
    this->setSizeGripEnabled(false);
}

InitDialog::~InitDialog()
{
    delete ui;
}

QPoint InitDialog::getBoardSize() const
{
    return QPoint(ui->sizeXBox->value(), ui->sizeYBox->value());
}

int InitDialog::getHerbivoreCount() const
{
    return ui->herbivoreBox->value();
}

int InitDialog::getCarnivoreCount() const
{
    return ui->carnivoreBox->value();
}
