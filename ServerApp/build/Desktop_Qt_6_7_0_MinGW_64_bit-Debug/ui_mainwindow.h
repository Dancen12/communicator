/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 6.7.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QLabel>
#include <QtWidgets/QListWidget>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QLabel *_title;
    QPushButton *pushButton;
    QPushButton *pushButton_2;
    QListWidget *listWidget_logs;
    QLabel *label_logs;
    QLabel *label_ipTitle;
    QLabel *label_portTitle;
    QLabel *label_connectedhostTitle;
    QLabel *label_ip;
    QLabel *label_port;
    QLabel *label_connectedHostNr;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName("MainWindow");
        MainWindow->resize(546, 468);
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName("centralwidget");
        _title = new QLabel(centralwidget);
        _title->setObjectName("_title");
        _title->setGeometry(QRect(10, 0, 91, 31));
        pushButton = new QPushButton(centralwidget);
        pushButton->setObjectName("pushButton");
        pushButton->setGeometry(QRect(10, 40, 91, 41));
        pushButton_2 = new QPushButton(centralwidget);
        pushButton_2->setObjectName("pushButton_2");
        pushButton_2->setGeometry(QRect(10, 90, 91, 41));
        listWidget_logs = new QListWidget(centralwidget);
        listWidget_logs->setObjectName("listWidget_logs");
        listWidget_logs->setGeometry(QRect(120, 30, 411, 381));
        label_logs = new QLabel(centralwidget);
        label_logs->setObjectName("label_logs");
        label_logs->setGeometry(QRect(120, 0, 101, 31));
        label_ipTitle = new QLabel(centralwidget);
        label_ipTitle->setObjectName("label_ipTitle");
        label_ipTitle->setGeometry(QRect(10, 150, 61, 16));
        label_portTitle = new QLabel(centralwidget);
        label_portTitle->setObjectName("label_portTitle");
        label_portTitle->setGeometry(QRect(10, 200, 61, 16));
        label_connectedhostTitle = new QLabel(centralwidget);
        label_connectedhostTitle->setObjectName("label_connectedhostTitle");
        label_connectedhostTitle->setGeometry(QRect(10, 250, 111, 16));
        label_ip = new QLabel(centralwidget);
        label_ip->setObjectName("label_ip");
        label_ip->setGeometry(QRect(10, 170, 101, 16));
        label_port = new QLabel(centralwidget);
        label_port->setObjectName("label_port");
        label_port->setGeometry(QRect(10, 220, 101, 16));
        label_connectedHostNr = new QLabel(centralwidget);
        label_connectedHostNr->setObjectName("label_connectedHostNr");
        label_connectedHostNr->setGeometry(QRect(10, 270, 111, 16));
        MainWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName("menubar");
        menubar->setGeometry(QRect(0, 0, 546, 21));
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
        _title->setText(QCoreApplication::translate("MainWindow", "server ON/OFF", nullptr));
        pushButton->setText(QCoreApplication::translate("MainWindow", "Start", nullptr));
        pushButton_2->setText(QCoreApplication::translate("MainWindow", "Stop", nullptr));
        label_logs->setText(QCoreApplication::translate("MainWindow", "Logs:", nullptr));
        label_ipTitle->setText(QCoreApplication::translate("MainWindow", "IP Adress:", nullptr));
        label_portTitle->setText(QCoreApplication::translate("MainWindow", "Port:", nullptr));
        label_connectedhostTitle->setText(QCoreApplication::translate("MainWindow", "Connected hosts:", nullptr));
        label_ip->setText(QCoreApplication::translate("MainWindow", "123.123.123.123", nullptr));
        label_port->setText(QCoreApplication::translate("MainWindow", "1234", nullptr));
        label_connectedHostNr->setText(QCoreApplication::translate("MainWindow", "number", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
