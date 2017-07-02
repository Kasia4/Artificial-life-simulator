#include "BoardEditor.h"
#include "ui_BoardEditor.h"

BoardEditor::BoardEditor(QWidget *parent) :
    QWidget(parent)
    ,ui(new Ui::BoardEditor)
	,current_type_(FieldType::VOID)
{
	ui->setupUi(this);
	connect(ui->FieldsButtonsGroup, SIGNAL(buttonClicked(QAbstractButton*)), this, SLOT(changeFieldType(QAbstractButton*)));
	buttons_map_.insert(ui->groundButton, FieldType::GROUND);
	buttons_map_.insert(ui->waterButton, FieldType::WATER);
	buttons_map_.insert(ui->barrenButton, FieldType::BARREN);
	buttons_map_.insert(ui->cancelButton, FieldType::VOID);
}

BoardEditor::~BoardEditor()
{
	delete ui;
}

FieldType BoardEditor::getCurrentFieldType() const
{
	return current_type_;
}

void BoardEditor::changeFieldType(QAbstractButton* btn)
{
	current_type_ = buttons_map_.value(btn);
}

void BoardEditor::updateLastField(const QPoint& position)
{
	last_field_ = position;
}

QPoint BoardEditor::getLastField() const
{
	return last_field_;
}

void BoardEditor::setFieldType(FieldType type)
{
	current_type_ = type;
}

