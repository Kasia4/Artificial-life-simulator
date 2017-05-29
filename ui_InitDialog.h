/********************************************************************************
** Form generated from reading UI file 'InitDialog.ui'
**
** Created by: Qt User Interface Compiler version 5.7.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_INITDIALOG_H
#define UI_INITDIALOG_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDialog>
#include <QtWidgets/QDialogButtonBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QSpinBox>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_InitDialog
{
public:
    QDialogButtonBox *buttonBox;
    QWidget *widget;
    QVBoxLayout *verticalLayout;
    QLabel *sizeLabel;
    QHBoxLayout *horizontalLayout_2;
    QLabel *sizeXlabel;
    QSpinBox *sizeXBox;
    QHBoxLayout *horizontalLayout;
    QLabel *sizeYlabel;
    QSpinBox *sizeYBox;
    QWidget *widget1;
    QVBoxLayout *verticalLayout_2;
    QLabel *label;
    QHBoxLayout *horizontalLayout_4;
    QLabel *herbivoreLabel;
    QSpinBox *herbivoreBox;
    QHBoxLayout *horizontalLayout_3;
    QLabel *carnivoreLabel;
    QSpinBox *carnivoreBox;

    void setupUi(QDialog *InitDialog)
    {
        if (InitDialog->objectName().isEmpty())
            InitDialog->setObjectName(QStringLiteral("InitDialog"));
        InitDialog->resize(239, 217);
        buttonBox = new QDialogButtonBox(InitDialog);
        buttonBox->setObjectName(QStringLiteral("buttonBox"));
        buttonBox->setGeometry(QRect(10, 180, 221, 32));
        buttonBox->setOrientation(Qt::Horizontal);
        buttonBox->setStandardButtons(QDialogButtonBox::Cancel|QDialogButtonBox::Ok);
        widget = new QWidget(InitDialog);
        widget->setObjectName(QStringLiteral("widget"));
        widget->setGeometry(QRect(10, 10, 221, 71));
        verticalLayout = new QVBoxLayout(widget);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        sizeLabel = new QLabel(widget);
        sizeLabel->setObjectName(QStringLiteral("sizeLabel"));

        verticalLayout->addWidget(sizeLabel);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        sizeXlabel = new QLabel(widget);
        sizeXlabel->setObjectName(QStringLiteral("sizeXlabel"));

        horizontalLayout_2->addWidget(sizeXlabel);

        sizeXBox = new QSpinBox(widget);
        sizeXBox->setObjectName(QStringLiteral("sizeXBox"));
        sizeXBox->setMinimum(1);
        sizeXBox->setMaximum(100);
        sizeXBox->setValue(15);

        horizontalLayout_2->addWidget(sizeXBox);


        verticalLayout->addLayout(horizontalLayout_2);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        sizeYlabel = new QLabel(widget);
        sizeYlabel->setObjectName(QStringLiteral("sizeYlabel"));

        horizontalLayout->addWidget(sizeYlabel);

        sizeYBox = new QSpinBox(widget);
        sizeYBox->setObjectName(QStringLiteral("sizeYBox"));
        sizeYBox->setMinimum(1);
        sizeYBox->setMaximum(100);
        sizeYBox->setValue(15);

        horizontalLayout->addWidget(sizeYBox);


        verticalLayout->addLayout(horizontalLayout);

        widget1 = new QWidget(InitDialog);
        widget1->setObjectName(QStringLiteral("widget1"));
        widget1->setGeometry(QRect(10, 100, 221, 71));
        verticalLayout_2 = new QVBoxLayout(widget1);
        verticalLayout_2->setObjectName(QStringLiteral("verticalLayout_2"));
        verticalLayout_2->setContentsMargins(0, 0, 0, 0);
        label = new QLabel(widget1);
        label->setObjectName(QStringLiteral("label"));

        verticalLayout_2->addWidget(label);

        horizontalLayout_4 = new QHBoxLayout();
        horizontalLayout_4->setObjectName(QStringLiteral("horizontalLayout_4"));
        herbivoreLabel = new QLabel(widget1);
        herbivoreLabel->setObjectName(QStringLiteral("herbivoreLabel"));

        horizontalLayout_4->addWidget(herbivoreLabel);

        herbivoreBox = new QSpinBox(widget1);
        herbivoreBox->setObjectName(QStringLiteral("herbivoreBox"));
        herbivoreBox->setMaximum(15);

        horizontalLayout_4->addWidget(herbivoreBox);


        verticalLayout_2->addLayout(horizontalLayout_4);

        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setObjectName(QStringLiteral("horizontalLayout_3"));
        carnivoreLabel = new QLabel(widget1);
        carnivoreLabel->setObjectName(QStringLiteral("carnivoreLabel"));

        horizontalLayout_3->addWidget(carnivoreLabel);

        carnivoreBox = new QSpinBox(widget1);
        carnivoreBox->setObjectName(QStringLiteral("carnivoreBox"));
        carnivoreBox->setMaximum(15);

        horizontalLayout_3->addWidget(carnivoreBox);


        verticalLayout_2->addLayout(horizontalLayout_3);


        retranslateUi(InitDialog);
        QObject::connect(buttonBox, SIGNAL(accepted()), InitDialog, SLOT(accept()));
        QObject::connect(buttonBox, SIGNAL(rejected()), InitDialog, SLOT(reject()));

        QMetaObject::connectSlotsByName(InitDialog);
    } // setupUi

    void retranslateUi(QDialog *InitDialog)
    {
        InitDialog->setWindowTitle(QApplication::translate("InitDialog", "Dialog", 0));
        sizeLabel->setText(QApplication::translate("InitDialog", "Podaj rozmiar planszy", 0));
        sizeXlabel->setText(QApplication::translate("InitDialog", "Szeroko\305\233\304\207", 0));
        sizeYlabel->setText(QApplication::translate("InitDialog", "Wysoko\305\233\304\207", 0));
        label->setText(QApplication::translate("InitDialog", "Podaj pocz\304\205tkow\304\205 liczb\304\231 osobnik\303\263w", 0));
        herbivoreLabel->setText(QApplication::translate("InitDialog", "Ro\305\233lino\305\274ercy", 0));
        carnivoreLabel->setText(QApplication::translate("InitDialog", "Mi\304\231so\305\274ercy", 0));
    } // retranslateUi

};

namespace Ui {
    class InitDialog: public Ui_InitDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_INITDIALOG_H
