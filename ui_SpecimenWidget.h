/********************************************************************************
** Form generated from reading UI file 'SpecimenWidget.ui'
**
** Created by: Qt User Interface Compiler version 5.7.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_SPECIMENWIDGET_H
#define UI_SPECIMENWIDGET_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_SpecimenWidget
{
public:
    QWidget *layoutWidget;
    QHBoxLayout *horizontalLayout;
    QVBoxLayout *verticalLayout;
    QLabel *health_label;
    QLabel *strenght_label;
    QLabel *speed_label;
    QLabel *sight_range_label;
    QLabel *sight_angle_label;
    QLabel *hearing_range_label;
    QLabel *sleep_necessity_label;
    QLabel *food_necessity_label;
    QLabel *water_necessity_label;
    QVBoxLayout *values_group;
    QLabel *health_value;
    QLabel *strenght_value_label;
    QLabel *speed_value;
    QLabel *sight_range_value;
    QLabel *sight_angle_value;
    QLabel *hearing_range_value;
    QLabel *sleep_necessity_value;
    QLabel *food_necessity_value;
    QLabel *water_necessity_value;

    void setupUi(QWidget *SpecimenWidget)
    {
        if (SpecimenWidget->objectName().isEmpty())
            SpecimenWidget->setObjectName(QStringLiteral("SpecimenWidget"));
        SpecimenWidget->resize(170, 198);
        QPalette palette;
        QBrush brush(QColor(225, 225, 225, 255));
        brush.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Active, QPalette::Base, brush);
        palette.setBrush(QPalette::Inactive, QPalette::Base, brush);
        QBrush brush1(QColor(239, 235, 231, 255));
        brush1.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Disabled, QPalette::Base, brush1);
        SpecimenWidget->setPalette(palette);
        SpecimenWidget->setAutoFillBackground(false);
        layoutWidget = new QWidget(SpecimenWidget);
        layoutWidget->setObjectName(QStringLiteral("layoutWidget"));
        layoutWidget->setGeometry(QRect(10, 10, 151, 178));
        horizontalLayout = new QHBoxLayout(layoutWidget);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        horizontalLayout->setContentsMargins(0, 0, 0, 0);
        verticalLayout = new QVBoxLayout();
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        health_label = new QLabel(layoutWidget);
        health_label->setObjectName(QStringLiteral("health_label"));

        verticalLayout->addWidget(health_label);

        strenght_label = new QLabel(layoutWidget);
        strenght_label->setObjectName(QStringLiteral("strenght_label"));

        verticalLayout->addWidget(strenght_label);

        speed_label = new QLabel(layoutWidget);
        speed_label->setObjectName(QStringLiteral("speed_label"));

        verticalLayout->addWidget(speed_label);

        sight_range_label = new QLabel(layoutWidget);
        sight_range_label->setObjectName(QStringLiteral("sight_range_label"));

        verticalLayout->addWidget(sight_range_label);

        sight_angle_label = new QLabel(layoutWidget);
        sight_angle_label->setObjectName(QStringLiteral("sight_angle_label"));

        verticalLayout->addWidget(sight_angle_label);

        hearing_range_label = new QLabel(layoutWidget);
        hearing_range_label->setObjectName(QStringLiteral("hearing_range_label"));

        verticalLayout->addWidget(hearing_range_label);

        sleep_necessity_label = new QLabel(layoutWidget);
        sleep_necessity_label->setObjectName(QStringLiteral("sleep_necessity_label"));

        verticalLayout->addWidget(sleep_necessity_label);

        food_necessity_label = new QLabel(layoutWidget);
        food_necessity_label->setObjectName(QStringLiteral("food_necessity_label"));

        verticalLayout->addWidget(food_necessity_label);

        water_necessity_label = new QLabel(layoutWidget);
        water_necessity_label->setObjectName(QStringLiteral("water_necessity_label"));

        verticalLayout->addWidget(water_necessity_label);


        horizontalLayout->addLayout(verticalLayout);

        values_group = new QVBoxLayout();
        values_group->setObjectName(QStringLiteral("values_group"));
        health_value = new QLabel(layoutWidget);
        health_value->setObjectName(QStringLiteral("health_value"));

        values_group->addWidget(health_value);

        strenght_value_label = new QLabel(layoutWidget);
        strenght_value_label->setObjectName(QStringLiteral("strenght_value_label"));

        values_group->addWidget(strenght_value_label);

        speed_value = new QLabel(layoutWidget);
        speed_value->setObjectName(QStringLiteral("speed_value"));

        values_group->addWidget(speed_value);

        sight_range_value = new QLabel(layoutWidget);
        sight_range_value->setObjectName(QStringLiteral("sight_range_value"));

        values_group->addWidget(sight_range_value);

        sight_angle_value = new QLabel(layoutWidget);
        sight_angle_value->setObjectName(QStringLiteral("sight_angle_value"));

        values_group->addWidget(sight_angle_value);

        hearing_range_value = new QLabel(layoutWidget);
        hearing_range_value->setObjectName(QStringLiteral("hearing_range_value"));

        values_group->addWidget(hearing_range_value);

        sleep_necessity_value = new QLabel(layoutWidget);
        sleep_necessity_value->setObjectName(QStringLiteral("sleep_necessity_value"));

        values_group->addWidget(sleep_necessity_value);

        food_necessity_value = new QLabel(layoutWidget);
        food_necessity_value->setObjectName(QStringLiteral("food_necessity_value"));

        values_group->addWidget(food_necessity_value);

        water_necessity_value = new QLabel(layoutWidget);
        water_necessity_value->setObjectName(QStringLiteral("water_necessity_value"));

        values_group->addWidget(water_necessity_value);


        horizontalLayout->addLayout(values_group);


        retranslateUi(SpecimenWidget);

        QMetaObject::connectSlotsByName(SpecimenWidget);
    } // setupUi

    void retranslateUi(QWidget *SpecimenWidget)
    {
        SpecimenWidget->setWindowTitle(QApplication::translate("SpecimenWidget", "Form", 0));
        health_label->setText(QApplication::translate("SpecimenWidget", "Zdrowie:", 0));
        strenght_label->setText(QApplication::translate("SpecimenWidget", "Si\305\202a:", 0));
        speed_label->setText(QApplication::translate("SpecimenWidget", "Szybko\305\233\304\207:", 0));
        sight_range_label->setText(QApplication::translate("SpecimenWidget", "Zasi\304\231g widzenia:", 0));
        sight_angle_label->setText(QApplication::translate("SpecimenWidget", "K\304\205t widzenia:", 0));
        hearing_range_label->setText(QApplication::translate("SpecimenWidget", "Zasi\304\231g s\305\202uchu:", 0));
        sleep_necessity_label->setText(QApplication::translate("SpecimenWidget", "Porzeba snu:", 0));
        food_necessity_label->setText(QApplication::translate("SpecimenWidget", "Potrzeba jedzenia:", 0));
        water_necessity_label->setText(QApplication::translate("SpecimenWidget", "Potrzeba picia:", 0));
        health_value->setText(QApplication::translate("SpecimenWidget", "0/0", 0));
        strenght_value_label->setText(QApplication::translate("SpecimenWidget", "0", 0));
        speed_value->setText(QApplication::translate("SpecimenWidget", "0", 0));
        sight_range_value->setText(QApplication::translate("SpecimenWidget", "0", 0));
        sight_angle_value->setText(QApplication::translate("SpecimenWidget", "0", 0));
        hearing_range_value->setText(QApplication::translate("SpecimenWidget", "0", 0));
        sleep_necessity_value->setText(QApplication::translate("SpecimenWidget", "0", 0));
        food_necessity_value->setText(QApplication::translate("SpecimenWidget", "0", 0));
        water_necessity_value->setText(QApplication::translate("SpecimenWidget", "0", 0));
    } // retranslateUi

};

namespace Ui {
    class SpecimenWidget: public Ui_SpecimenWidget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SPECIMENWIDGET_H
