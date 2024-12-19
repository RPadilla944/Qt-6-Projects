/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 6.7.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QListWidget>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QGroupBox *groupBox;
    QVBoxLayout *verticalLayout;
    QLineEdit *lineEdit;
    QPushButton *pick;
    QListWidget *listWidget;
    QGroupBox *groupBox_2;
    QHBoxLayout *horizontalLayout;
    QPushButton *deleteb;
    QPushButton *backb;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName("MainWindow");
        MainWindow->resize(628, 530);
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName("centralwidget");
        groupBox = new QGroupBox(centralwidget);
        groupBox->setObjectName("groupBox");
        groupBox->setGeometry(QRect(460, 130, 141, 197));
        verticalLayout = new QVBoxLayout(groupBox);
        verticalLayout->setObjectName("verticalLayout");
        lineEdit = new QLineEdit(groupBox);
        lineEdit->setObjectName("lineEdit");

        verticalLayout->addWidget(lineEdit);

        pick = new QPushButton(groupBox);
        pick->setObjectName("pick");

        verticalLayout->addWidget(pick);

        listWidget = new QListWidget(centralwidget);
        listWidget->setObjectName("listWidget");
        listWidget->setGeometry(QRect(60, 70, 381, 321));
        groupBox_2 = new QGroupBox(centralwidget);
        groupBox_2->setObjectName("groupBox_2");
        groupBox_2->setGeometry(QRect(160, 400, 217, 53));
        horizontalLayout = new QHBoxLayout(groupBox_2);
        horizontalLayout->setObjectName("horizontalLayout");
        deleteb = new QPushButton(groupBox_2);
        deleteb->setObjectName("deleteb");

        horizontalLayout->addWidget(deleteb);

        backb = new QPushButton(groupBox_2);
        backb->setObjectName("backb");

        horizontalLayout->addWidget(backb);

        MainWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName("menubar");
        menubar->setGeometry(QRect(0, 0, 628, 26));
        MainWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName("statusbar");
        MainWindow->setStatusBar(statusbar);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "MainWindow", nullptr));
        groupBox->setTitle(QCoreApplication::translate("MainWindow", "Select file number", nullptr));
        lineEdit->setPlaceholderText(QCoreApplication::translate("MainWindow", "1 or 2", nullptr));
        pick->setText(QCoreApplication::translate("MainWindow", "Select", nullptr));
        groupBox_2->setTitle(QString());
        deleteb->setText(QCoreApplication::translate("MainWindow", "Delete", nullptr));
        backb->setText(QCoreApplication::translate("MainWindow", "Back", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
