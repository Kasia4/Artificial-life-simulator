#include "BoardEditor.h"
#include "ui_BoardEditor.h"

BoardEditor::BoardEditor(QWidget *parent) :
	QWidget(parent),
	ui(new Ui::BoardEditor)
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

void BoardEditor::changeFieldType(QAbstractButton* btn)
{
	std::cout<<(int)(buttons_map_.value(btn))<<std::endl;
	emit fieldTypeChanged(buttons_map_.value(btn));
}

