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
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QListWidget>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QGroupBox *groupBox_chat;
    QListWidget *listWidget_chat;
    QPushButton *pushButton_send;
    QLineEdit *lineEdit_messageInput;
    QGroupBox *groupBox_users;
    QListWidget *listWidget_users;
    QListWidget *listWidget_search;
    QWidget *layoutWidget;
    QVBoxLayout *verticalLayout;
    QWidget *layoutWidget1;
    QHBoxLayout *horizontalLayout_2;
    QHBoxLayout *horizontalLayout;
    QLabel *label_search;
    QLineEdit *lineEdit_search;
    QPushButton *pushButton_search;
    QPushButton *pushButton_close;
    QWidget *layoutWidget2;
    QHBoxLayout *horizontalLayout_4;
    QVBoxLayout *verticalLayout_3;
    QPushButton *pushButton_settings;
    QPushButton *pushButton;
    QVBoxLayout *verticalLayout_2;
    QHBoxLayout *horizontalLayout_3;
    QLabel *label_loggedas;
    QSpacerItem *horizontalSpacer;
    QLabel *label_yourid;
    QLabel *label_id;
    QLabel *label_name;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName("MainWindow");
        MainWindow->resize(619, 583);
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName("centralwidget");
        groupBox_chat = new QGroupBox(centralwidget);
        groupBox_chat->setObjectName("groupBox_chat");
        groupBox_chat->setGeometry(QRect(260, 40, 351, 481));
        listWidget_chat = new QListWidget(groupBox_chat);
        listWidget_chat->setObjectName("listWidget_chat");
        listWidget_chat->setGeometry(QRect(10, 30, 331, 401));
        pushButton_send = new QPushButton(groupBox_chat);
        pushButton_send->setObjectName("pushButton_send");
        pushButton_send->setGeometry(QRect(300, 440, 41, 31));
        lineEdit_messageInput = new QLineEdit(groupBox_chat);
        lineEdit_messageInput->setObjectName("lineEdit_messageInput");
        lineEdit_messageInput->setGeometry(QRect(10, 440, 291, 31));
        groupBox_users = new QGroupBox(centralwidget);
        groupBox_users->setObjectName("groupBox_users");
        groupBox_users->setGeometry(QRect(10, 40, 231, 431));
        listWidget_users = new QListWidget(groupBox_users);
        listWidget_users->setObjectName("listWidget_users");
        listWidget_users->setGeometry(QRect(10, 30, 211, 391));
        listWidget_search = new QListWidget(groupBox_users);
        listWidget_search->setObjectName("listWidget_search");
        listWidget_search->setGeometry(QRect(73, 1, 141, 192));
        layoutWidget = new QWidget(centralwidget);
        layoutWidget->setObjectName("layoutWidget");
        layoutWidget->setGeometry(QRect(0, 0, 2, 2));
        verticalLayout = new QVBoxLayout(layoutWidget);
        verticalLayout->setObjectName("verticalLayout");
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        layoutWidget1 = new QWidget(centralwidget);
        layoutWidget1->setObjectName("layoutWidget1");
        layoutWidget1->setGeometry(QRect(14, 10, 301, 28));
        horizontalLayout_2 = new QHBoxLayout(layoutWidget1);
        horizontalLayout_2->setObjectName("horizontalLayout_2");
        horizontalLayout_2->setContentsMargins(0, 0, 0, 0);
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName("horizontalLayout");
        label_search = new QLabel(layoutWidget1);
        label_search->setObjectName("label_search");

        horizontalLayout->addWidget(label_search);

        lineEdit_search = new QLineEdit(layoutWidget1);
        lineEdit_search->setObjectName("lineEdit_search");

        horizontalLayout->addWidget(lineEdit_search);


        horizontalLayout_2->addLayout(horizontalLayout);

        pushButton_search = new QPushButton(layoutWidget1);
        pushButton_search->setObjectName("pushButton_search");

        horizontalLayout_2->addWidget(pushButton_search);

        pushButton_close = new QPushButton(layoutWidget1);
        pushButton_close->setObjectName("pushButton_close");

        horizontalLayout_2->addWidget(pushButton_close);

        layoutWidget2 = new QWidget(centralwidget);
        layoutWidget2->setObjectName("layoutWidget2");
        layoutWidget2->setGeometry(QRect(0, 467, 241, 71));
        horizontalLayout_4 = new QHBoxLayout(layoutWidget2);
        horizontalLayout_4->setObjectName("horizontalLayout_4");
        horizontalLayout_4->setContentsMargins(0, 0, 0, 0);
        verticalLayout_3 = new QVBoxLayout();
        verticalLayout_3->setObjectName("verticalLayout_3");
        pushButton_settings = new QPushButton(layoutWidget2);
        pushButton_settings->setObjectName("pushButton_settings");

        verticalLayout_3->addWidget(pushButton_settings);

        pushButton = new QPushButton(layoutWidget2);
        pushButton->setObjectName("pushButton");

        verticalLayout_3->addWidget(pushButton);


        horizontalLayout_4->addLayout(verticalLayout_3);

        verticalLayout_2 = new QVBoxLayout();
        verticalLayout_2->setObjectName("verticalLayout_2");
        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setObjectName("horizontalLayout_3");
        label_loggedas = new QLabel(layoutWidget2);
        label_loggedas->setObjectName("label_loggedas");

        horizontalLayout_3->addWidget(label_loggedas);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Minimum);

        horizontalLayout_3->addItem(horizontalSpacer);

        label_yourid = new QLabel(layoutWidget2);
        label_yourid->setObjectName("label_yourid");

        horizontalLayout_3->addWidget(label_yourid);

        label_id = new QLabel(layoutWidget2);
        label_id->setObjectName("label_id");

        horizontalLayout_3->addWidget(label_id);


        verticalLayout_2->addLayout(horizontalLayout_3);

        label_name = new QLabel(layoutWidget2);
        label_name->setObjectName("label_name");

        verticalLayout_2->addWidget(label_name);


        horizontalLayout_4->addLayout(verticalLayout_2);

        MainWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName("menubar");
        menubar->setGeometry(QRect(0, 0, 619, 21));
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
        groupBox_chat->setTitle(QCoreApplication::translate("MainWindow", "Chat name", nullptr));
        pushButton_send->setText(QCoreApplication::translate("MainWindow", "Send", nullptr));
        groupBox_users->setTitle(QCoreApplication::translate("MainWindow", "List of chats:", nullptr));
        label_search->setText(QCoreApplication::translate("MainWindow", "Find friend:", nullptr));
        pushButton_search->setText(QCoreApplication::translate("MainWindow", "Search", nullptr));
        pushButton_close->setText(QCoreApplication::translate("MainWindow", "Close", nullptr));
        pushButton_settings->setText(QCoreApplication::translate("MainWindow", "Settings", nullptr));
        pushButton->setText(QCoreApplication::translate("MainWindow", "Log Out", nullptr));
        label_loggedas->setText(QCoreApplication::translate("MainWindow", "Logged as: ", nullptr));
        label_yourid->setText(QCoreApplication::translate("MainWindow", " ID:", nullptr));
        label_id->setText(QCoreApplication::translate("MainWindow", "id", nullptr));
        label_name->setText(QCoreApplication::translate("MainWindow", "Name Surname", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
