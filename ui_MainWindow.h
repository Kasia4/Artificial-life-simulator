/********************************************************************************
** Form generated from reading UI file 'MainWindow.ui'
**
** Created by: Qt User Interface Compiler version 5.7.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <BoardEditor.h>
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
    BoardEditor *boardEditor;
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
        boardView->setGeometry(QRect(0, 0, 600, 600));
        pushButton = new QPushButton(centralWidget);
        pushButton->setObjectName(QStringLiteral("pushButton"));
        pushButton->setGeometry(QRect(610, 550, 111, 41));
        pushButton_2 = new QPushButton(centralWidget);
        pushButton_2->setObjectName(QStringLiteral("pushButton_2"));
        pushButton_2->setGeometry(QRect(730, 550, 111, 41));
        collidersCheckBox = new QCheckBox(centralWidget);
        collidersCheckBox->setObjectName(QStringLiteral("collidersCheckBox"));
        collidersCheckBox->setGeometry(QRect(710, 10, 111, 41));
        collidersCheckBox->setTristate(false);
        pauseButton = new QPushButton(centralWidget);
        pauseButton->setObjectName(QStringLiteral("pauseButton"));
        pauseButton->setGeometry(QRect(650, 10, 41, 41));
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
        resumeButton->setGeometry(QRect(610, 10, 41, 41));
        resumeButton->setFont(font);
        resumeButton->setMouseTracking(false);
        resumeButton->setAutoFillBackground(false);
        resumeButton->setIconSize(QSize(32, 32));
        addHerbivoreButton = new QPushButton(centralWidget);
        addHerbivoreButton->setObjectName(QStringLiteral("addHerbivoreButton"));
        addHerbivoreButton->setGeometry(QRect(610, 60, 121, 41));
        addHerbivoreButton->setStyleSheet(QStringLiteral("background-color: rgb(4, 255, 0);"));
        addCarnivoreButton = new QPushButton(centralWidget);
        addCarnivoreButton->setObjectName(QStringLiteral("addCarnivoreButton"));
        addCarnivoreButton->setGeometry(QRect(610, 100, 121, 41));
        addCarnivoreButton->setStyleSheet(QStringLiteral("background-color: rgb(255, 0, 0);"));
        boardEditor = new BoardEditor(centralWidget);
        boardEditor->setObjectName(QStringLiteral("boardEditor"));
        boardEditor->setGeometry(QRect(610, 150, 191, 251));
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
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
