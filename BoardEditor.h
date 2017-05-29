#ifndef BOARDEDITOR_H
#define BOARDEDITOR_H

#include <QWidget>
#include <QPushButton>
#include <QMap>

#include <iostream>

#include "BoardField.h"

namespace Ui {
class BoardEditor;
}

class BoardEditor : public QWidget
{
	Q_OBJECT

public:
	explicit BoardEditor(QWidget *parent = 0);
	void registerField(QPushButton button, FieldType type);
	~BoardEditor();

public slots:
	void changeFieldType(QAbstractButton* btn);
private:
	Ui::BoardEditor *ui;
	QMap<QAbstractButton*, FieldType> buttons_map_;

signals:
	void fieldTypeChanged(FieldType type);
};

#endif // BOARDEDITOR_H
