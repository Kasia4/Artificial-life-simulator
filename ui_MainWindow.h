/********************************************************************************
** Form generated from reading UI file 'MainWindow.ui'
**
** Created by: Qt User Interface Compiler version 5.7.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>
#include <SimulationView.h>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralWidget;
    SimulationView *boardView;
    QPushButton *pushButton;
    QPushButton *pushButton_2;
    QCheckBox *collidersCheckBox;
    QPushButton *pauseButton;
    QPushButton *resumeButton;
    QPushButton *addHerbivoreButton;
    QPushButton *addCarnivoreButton;
    QPushButton *pushButton_3;
    QPushButton *pushButton_4;
    QPushButton *pushButton_5;
    QMenuBar *menuBar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QStringLiteral("MainWindow"));
        MainWindow->resize(854, 620);
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        boardView = new SimulationView(centralWidget);
        boardView->setObjectName(QStringLiteral("boardView"));
        boardView->setGeometry(QRect(0, 0, 601, 601));
        pushButton = new QPushButton(centralWidget);
        pushButton->setObjectName(QStringLiteral("pushButton"));
        pushButton->setGeometry(QRect(610, 550, 111, 41));
        pushButton_2 = new QPushButton(centralWidget);
        pushButton_2->setObjectName(QStringLiteral("pushButton_2"));
        pushButton_2->setGeometry(QRect(730, 550, 111, 41));
        collidersCheckBox = new QCheckBox(centralWidget);
        collidersCheckBox->setObjectName(QStringLiteral("collidersCheckBox"));
        collidersCheckBox->setGeometry(QRect(700, 10, 101, 19));
        collidersCheckBox->setTristate(false);
        pauseButton = new QPushButton(centralWidget);
        pauseButton->setObjectName(QStringLiteral("pauseButton"));
        pauseButton->setGeometry(QRect(640, 10, 31, 31));
        QFont font;
        font.setFamily(QStringLiteral("Purisa"));
        font.setPointSize(16);
        font.setBold(false);
        font.setItalic(false);
        font.setWeight(50);
        pauseButton->setFont(font);
        pauseButton->setMouseTracking(false);
        pauseButton->setAutoFillBackground(false);
        pauseButton->setIconSize(QSize(32, 32));
        resumeButton = new QPushButton(centralWidget);
        resumeButton->setObjectName(QStringLiteral("resumeButton"));
        resumeButton->setGeometry(QRect(610, 10, 31, 31));
        resumeButton->setFont(font);
        resumeButton->setMouseTracking(false);
        resumeButton->setAutoFillBackground(false);
        resumeButton->setIconSize(QSize(32, 32));
        addHerbivoreButton = new QPushButton(centralWidget);
        addHerbivoreButton->setObjectName(QStringLiteral("addHerbivoreButton"));
        addHerbivoreButton->setGeometry(QRect(610, 50, 111, 31));
        addCarnivoreButton = new QPushButton(centralWidget);
        addCarnivoreButton->setObjectName(QStringLiteral("addCarnivoreButton"));
        addCarnivoreButton->setGeometry(QRect(610, 80, 111, 31));
        pushButton_3 = new QPushButton(centralWidget);
        pushButton_3->setObjectName(QStringLiteral("pushButton_3"));
        pushButton_3->setGeometry(QRect(730, 50, 31, 31));
        pushButton_3->setAutoFillBackground(false);
        pushButton_3->setStyleSheet(QStringLiteral("background-color: rgb(200, 150, 0);"));
        pushButton_3->setAutoRepeatDelay(300);
        pushButton_4 = new QPushButton(centralWidget);
        pushButton_4->setObjectName(QStringLiteral("pushButton_4"));
        pushButton_4->setGeometry(QRect(760, 50, 31, 31));
        pushButton_4->setAutoFillBackground(false);
        pushButton_4->setStyleSheet(QStringLiteral("background-color: rgb(0, 0, 255);"));
        pushButton_4->setAutoRepeatDelay(290);
        pushButton_5 = new QPushButton(centralWidget);
        pushButton_5->setObjectName(QStringLiteral("pushButton_5"));
        pushButton_5->setGeometry(QRect(790, 50, 31, 31));
        pushButton_5->setAutoFillBackground(false);
        pushButton_5->setStyleSheet(QStringLiteral("background-color: rgb(192,192,192);"));
        pushButton_5->setAutoRepeatDelay(290);
        MainWindow->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(MainWindow);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 854, 18));
        MainWindow->setMenuBar(menuBar);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "MainWindow", 0));
        pushButton->setText(QApplication::translate("MainWindow", "Edit Mode", 0));
        pushButton_2->setText(QApplication::translate("MainWindow", "Statistics", 0));
        collidersCheckBox->setText(QApplication::translate("MainWindow", "Show Colliders", 0));
        pauseButton->setText(QApplication::translate("MainWindow", "\342\217\270", 0));
        resumeButton->setText(QApplication::translate("MainWindow", "\342\226\266", 0));
        addHerbivoreButton->setText(QApplication::translate("MainWindow", "Add Herbivore", 0));
        addCarnivoreButton->setText(QApplication::translate("MainWindow", "Add Carnivore", 0));
        pushButton_3->setText(QString());
        pushButton_4->setText(QString());
        pushButton_5->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
