/********************************************************************************
** Form generated from reading UI file 'PopulationChart.ui'
**
** Created by: Qt User Interface Compiler version 5.7.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_POPULATIONCHART_H
#define UI_POPULATIONCHART_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QGraphicsView>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_PopulationChart
{
public:
    QGraphicsView *graphicsView;
    QWidget *widget;
    QVBoxLayout *verticalLayout;
    QLabel *population_label;
    QHBoxLayout *horizontalLayout;
    QLabel *herbivores_label;
    QLabel *herbivores_population;
    QHBoxLayout *horizontalLayout_2;
    QLabel *carnivore_label;
    QLabel *carnivore_population;

    void setupUi(QWidget *PopulationChart)
    {
        if (PopulationChart->objectName().isEmpty())
            PopulationChart->setObjectName(QStringLiteral("PopulationChart"));
        PopulationChart->resize(640, 480);
        graphicsView = new QGraphicsView(PopulationChart);
        graphicsView->setObjectName(QStringLiteral("graphicsView"));
        graphicsView->setGeometry(QRect(10, 10, 621, 381));
        widget = new QWidget(PopulationChart);
        widget->setObjectName(QStringLiteral("widget"));
        widget->setGeometry(QRect(11, 401, 131, 71));
        verticalLayout = new QVBoxLayout(widget);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        population_label = new QLabel(widget);
        population_label->setObjectName(QStringLiteral("population_label"));
        population_label->setAlignment(Qt::AlignCenter);

        verticalLayout->addWidget(population_label);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        herbivores_label = new QLabel(widget);
        herbivores_label->setObjectName(QStringLiteral("herbivores_label"));
        herbivores_label->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        horizontalLayout->addWidget(herbivores_label);

        herbivores_population = new QLabel(widget);
        herbivores_population->setObjectName(QStringLiteral("herbivores_population"));
        herbivores_population->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        horizontalLayout->addWidget(herbivores_population);


        verticalLayout->addLayout(horizontalLayout);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        carnivore_label = new QLabel(widget);
        carnivore_label->setObjectName(QStringLiteral("carnivore_label"));
        carnivore_label->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        horizontalLayout_2->addWidget(carnivore_label);

        carnivore_population = new QLabel(widget);
        carnivore_population->setObjectName(QStringLiteral("carnivore_population"));
        carnivore_population->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        horizontalLayout_2->addWidget(carnivore_population);


        verticalLayout->addLayout(horizontalLayout_2);


        retranslateUi(PopulationChart);

        QMetaObject::connectSlotsByName(PopulationChart);
    } // setupUi

    void retranslateUi(QWidget *PopulationChart)
    {
        PopulationChart->setWindowTitle(QApplication::translate("PopulationChart", "Form", 0));
        population_label->setText(QApplication::translate("PopulationChart", "Aktualna populacja", 0));
        herbivores_label->setText(QApplication::translate("PopulationChart", "Ro\305\233lino\305\274ercy:  ", 0));
        herbivores_population->setText(QApplication::translate("PopulationChart", "0", 0));
        carnivore_label->setText(QApplication::translate("PopulationChart", "Mi\304\231so\305\274ercy:     ", 0));
        carnivore_population->setText(QApplication::translate("PopulationChart", "0", 0));
    } // retranslateUi

};

namespace Ui {
    class PopulationChart: public Ui_PopulationChart {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_POPULATIONCHART_H
