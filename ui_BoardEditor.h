/********************************************************************************
** Form generated from reading UI file 'BoardEditor.ui'
**
** Created by: Qt User Interface Compiler version 5.7.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_BOARDEDITOR_H
#define UI_BOARDEDITOR_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_BoardEditor
{
public:
    QPushButton *barrenButton;
    QPushButton *groundButton;
    QPushButton *waterButton;
    QPushButton *cancelButton;
    QButtonGroup *FieldsButtonsGroup;

    void setupUi(QWidget *BoardEditor)
    {
        if (BoardEditor->objectName().isEmpty())
            BoardEditor->setObjectName(QStringLiteral("BoardEditor"));
        BoardEditor->resize(160, 281);
        barrenButton = new QPushButton(BoardEditor);
        FieldsButtonsGroup = new QButtonGroup(BoardEditor);
        FieldsButtonsGroup->setObjectName(QStringLiteral("FieldsButtonsGroup"));
        FieldsButtonsGroup->setExclusive(true);
        FieldsButtonsGroup->addButton(barrenButton);
        barrenButton->setObjectName(QStringLiteral("barrenButton"));
        barrenButton->setGeometry(QRect(80, 0, 41, 41));
        barrenButton->setAutoFillBackground(false);
        barrenButton->setStyleSheet(QStringLiteral("background-color: rgb(192,192,192);"));
        barrenButton->setCheckable(true);
        barrenButton->setAutoRepeatDelay(290);
        groundButton = new QPushButton(BoardEditor);
        FieldsButtonsGroup->addButton(groundButton);
        groundButton->setObjectName(QStringLiteral("groundButton"));
        groundButton->setGeometry(QRect(0, 0, 41, 41));
        groundButton->setAutoFillBackground(false);
        groundButton->setStyleSheet(QStringLiteral("background-color: rgb(200, 150, 0);"));
        groundButton->setCheckable(true);
        groundButton->setAutoRepeat(false);
        groundButton->setAutoExclusive(false);
        groundButton->setAutoRepeatDelay(300);
        waterButton = new QPushButton(BoardEditor);
        FieldsButtonsGroup->addButton(waterButton);
        waterButton->setObjectName(QStringLiteral("waterButton"));
        waterButton->setGeometry(QRect(40, 0, 41, 41));
        waterButton->setAutoFillBackground(false);
        waterButton->setStyleSheet(QStringLiteral("background-color: rgb(0, 0, 255);"));
        waterButton->setCheckable(true);
        waterButton->setAutoRepeatDelay(290);
        cancelButton = new QPushButton(BoardEditor);
        FieldsButtonsGroup->addButton(cancelButton);
        cancelButton->setObjectName(QStringLiteral("cancelButton"));
        cancelButton->setGeometry(QRect(120, 0, 41, 41));
        QFont font;
        font.setPointSize(50);
        cancelButton->setFont(font);
        cancelButton->setAutoFillBackground(false);
        cancelButton->setStyleSheet(QStringLiteral("border-bottom-color: rgb(255, 0, 4);"));
        cancelButton->setCheckable(true);
        cancelButton->setAutoRepeatDelay(290);

        retranslateUi(BoardEditor);

        QMetaObject::connectSlotsByName(BoardEditor);
    } // setupUi

    void retranslateUi(QWidget *BoardEditor)
    {
        BoardEditor->setWindowTitle(QApplication::translate("BoardEditor", "Form", 0));
        barrenButton->setText(QString());
        groundButton->setText(QString());
        waterButton->setText(QString());
        cancelButton->setText(QApplication::translate("BoardEditor", "X", 0));
    } // retranslateUi

};

namespace Ui {
    class BoardEditor: public Ui_BoardEditor {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_BOARDEDITOR_H
