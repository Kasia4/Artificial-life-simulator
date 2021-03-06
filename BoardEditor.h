#ifndef BOARDEDITOR_H
#define BOARDEDITOR_H

#include <QWidget>
#include <QPushButton>
#include <QMap>

#include "BoardField.h"
#include <iostream>

namespace Ui {
class BoardEditor;
}

class BoardEditor : public QWidget
{
	Q_OBJECT

public:
	explicit BoardEditor(QWidget *parent = 0);
	~BoardEditor();
	
	FieldType getCurrentFieldType() const;
	QPoint getLastField() const;

	void setFieldType(FieldType type);
	
public slots:
	void changeFieldType(QAbstractButton* btn);
	void updateLastField(const QPoint& position);

private:
	Ui::BoardEditor *ui;
	FieldType current_type_;
	QPoint last_field_;
	QMap<QAbstractButton*, FieldType> buttons_map_;
};

#endif // BOARDEDITOR_H
