/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 6.6.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QAction *actionOpen;
    QAction *actionSave;
    QAction *actionExit;
    QAction *actionAbout;
    QWidget *centralwidget;
    QVBoxLayout *verticalLayout;
    QComboBox *shapeComboBox;
    QLineEdit *lineEdit1;
    QLineEdit *lineEdit2;
    QLineEdit *lineEdit3;
    QPushButton *calculateButton;
    QLabel *resultLabel;
    QPushButton *settingsButton;
    QMenuBar *menuBar;
    QMenu *menuFile;
    QMenu *menuHelp;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName("MainWindow");
        MainWindow->resize(400, 300);
        actionOpen = new QAction(MainWindow);
        actionOpen->setObjectName("actionOpen");
        actionSave = new QAction(MainWindow);
        actionSave->setObjectName("actionSave");
        actionExit = new QAction(MainWindow);
        actionExit->setObjectName("actionExit");
        actionAbout = new QAction(MainWindow);
        actionAbout->setObjectName("actionAbout");
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName("centralwidget");
        verticalLayout = new QVBoxLayout(centralwidget);
        verticalLayout->setObjectName("verticalLayout");
        shapeComboBox = new QComboBox(centralwidget);
        shapeComboBox->addItem(QString());
        shapeComboBox->addItem(QString());
        shapeComboBox->addItem(QString());
        shapeComboBox->addItem(QString());
        shapeComboBox->addItem(QString());
        shapeComboBox->setObjectName("shapeComboBox");

        verticalLayout->addWidget(shapeComboBox);

        lineEdit1 = new QLineEdit(centralwidget);
        lineEdit1->setObjectName("lineEdit1");

        verticalLayout->addWidget(lineEdit1);

        lineEdit2 = new QLineEdit(centralwidget);
        lineEdit2->setObjectName("lineEdit2");

        verticalLayout->addWidget(lineEdit2);

        lineEdit3 = new QLineEdit(centralwidget);
        lineEdit3->setObjectName("lineEdit3");

        verticalLayout->addWidget(lineEdit3);

        calculateButton = new QPushButton(centralwidget);
        calculateButton->setObjectName("calculateButton");

        verticalLayout->addWidget(calculateButton);

        resultLabel = new QLabel(centralwidget);
        resultLabel->setObjectName("resultLabel");

        verticalLayout->addWidget(resultLabel);

        settingsButton = new QPushButton(centralwidget);
        settingsButton->setObjectName("settingsButton");

        verticalLayout->addWidget(settingsButton);

        MainWindow->setCentralWidget(centralwidget);
        menuBar = new QMenuBar(MainWindow);
        menuBar->setObjectName("menuBar");
        menuBar->setGeometry(QRect(0, 0, 400, 22));
        menuFile = new QMenu(menuBar);
        menuFile->setObjectName("menuFile");
        menuHelp = new QMenu(menuBar);
        menuHelp->setObjectName("menuHelp");
        MainWindow->setMenuBar(menuBar);
        statusBar = new QStatusBar(MainWindow);
        statusBar->setObjectName("statusBar");
        MainWindow->setStatusBar(statusBar);

        menuBar->addAction(menuFile->menuAction());
        menuBar->addAction(menuHelp->menuAction());
        menuFile->addAction(actionOpen);
        menuFile->addAction(actionSave);
        menuFile->addAction(actionExit);
        menuHelp->addAction(actionAbout);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "Area Calculator", nullptr));
        actionOpen->setText(QCoreApplication::translate("MainWindow", "&Open", nullptr));
        actionSave->setText(QCoreApplication::translate("MainWindow", "&Save", nullptr));
        actionExit->setText(QCoreApplication::translate("MainWindow", "E&xit", nullptr));
        actionAbout->setText(QCoreApplication::translate("MainWindow", "&About", nullptr));
        shapeComboBox->setItemText(0, QCoreApplication::translate("MainWindow", "Square", nullptr));
        shapeComboBox->setItemText(1, QCoreApplication::translate("MainWindow", "Rectangle", nullptr));
        shapeComboBox->setItemText(2, QCoreApplication::translate("MainWindow", "Circle", nullptr));
        shapeComboBox->setItemText(3, QCoreApplication::translate("MainWindow", "Triangle", nullptr));
        shapeComboBox->setItemText(4, QCoreApplication::translate("MainWindow", "Trapezoid", nullptr));

        lineEdit1->setPlaceholderText(QCoreApplication::translate("MainWindow", "Enter first dimension", nullptr));
        lineEdit2->setPlaceholderText(QCoreApplication::translate("MainWindow", "Enter second dimension (if applicable)", nullptr));
        lineEdit3->setPlaceholderText(QCoreApplication::translate("MainWindow", "Enter third dimension (if applicable)", nullptr));
        calculateButton->setText(QCoreApplication::translate("MainWindow", "Calculate", nullptr));
        resultLabel->setText(QCoreApplication::translate("MainWindow", "Result will be displayed here", nullptr));
        settingsButton->setText(QCoreApplication::translate("MainWindow", "Settings", nullptr));
        menuFile->setTitle(QCoreApplication::translate("MainWindow", "&File", nullptr));
        menuHelp->setTitle(QCoreApplication::translate("MainWindow", "&Help", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
