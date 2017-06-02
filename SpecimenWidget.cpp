#include "SpecimenWidget.h"
#include "ui_SpecimenWidget.h"

SpecimenWidget::SpecimenWidget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::SpecimenWidget)
{
	ui->setupUi(this);

	needs_strings_.insert(NeedType::DRINK, "Pragnienie");
	needs_strings_.insert(NeedType::EAT, "Glod");
	needs_strings_.insert(NeedType::REPRODUCE, "Rozmnazanie");
	needs_strings_.insert(NeedType::SLEEP, "Sen");
	needs_strings_.insert(NeedType::NONE, "Brak");
}

SpecimenWidget::~SpecimenWidget()
{
    delete ui;
}

void SpecimenWidget::disconnectSpecimen()
{
    disconnect(specimen_, SIGNAL(attributesChanged()), this, SLOT(updateInfo()));
	hideWidget();
}

void SpecimenWidget::hideWidget()
{
	setEnabled(false);
	hide();
	specimen_ = nullptr;
}
void SpecimenWidget::connectSpecimen(Specimen *specimen)
{
    specimen_ = specimen;
	setEnabled(true);
	show();
    connect(specimen_, SIGNAL(attributesChanged()), this, SLOT(updateInfo()));
	connect(specimen_, SIGNAL(killed(Specimen*)), this, SLOT(hideWidget()));
}


void SpecimenWidget::mouseMoveEvent(QMouseEvent *event)
{
	this->move(event->pos());
}

void SpecimenWidget::updateLabelValue(QLabel* label, qreal value)
{
	label->setText(QString::number(value));
}

void SpecimenWidget::updateInfo()
{
	if(!specimen_)return;
	updateLabelValue(ui->health_value,			specimen_->getHp());
	updateLabelValue(ui->endurance_value,		specimen_->getAttributeValue(AttributeType::ENDURANCE));
	updateLabelValue(ui->strenght_value,		specimen_->getAttributeValue(AttributeType::STRENGTH));
	updateLabelValue(ui->speed_value,			specimen_->getAttributeValue(AttributeType::SPEED));
	updateLabelValue(ui->sight_range_value,		specimen_->getAttributeValue(AttributeType::SIGHT_RANGE));
	updateLabelValue(ui->sight_angle_value,		specimen_->getAttributeValue(AttributeType::SIGHT_ANGLE));
	updateLabelValue(ui->hearing_range_value,	specimen_->getAttributeValue(AttributeType::HEARING_RANGE));
	updateLabelValue(ui->sleep_necessity_value, specimen_->getAttributeValue(AttributeType::SLEEP_NECESSITY));
	updateLabelValue(ui->food_necessity_value,	specimen_->getAttributeValue(AttributeType::FOOD_NECESSITY));
	updateLabelValue(ui->water_necessity_value, specimen_->getAttributeValue(AttributeType::WATER_NECESSITY));
	ui->sleep_bar->setValue(specimen_->getNeedValue(NeedType::SLEEP));
	ui->food_bar->setValue(specimen_->getNeedValue(NeedType::EAT));
	ui->water_bar->setValue(specimen_->getNeedValue(NeedType::DRINK));
    ui->reproduce_bar->setValue(specimen_->getNeedValue(NeedType::REPRODUCE));
	ui->current_need->setText(needs_strings_.value(specimen_->getCurrentNeed()));
}
