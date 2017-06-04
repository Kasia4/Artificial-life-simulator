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

bool InitDialog::getStatsStoreBoxValue() const
{
	return ui->stats_store_box->checkState() == Qt::Checked;
}

int InitDialog::getTimestepValue() const
{
	return ui->timestep_slider->value()*1000;
}

void InitDialog::on_timestep_slider_valueChanged(int value)
{
	ui->timestep_value->setText(QString::number(value) + "s");
}
