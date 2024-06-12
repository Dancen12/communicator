/********************************************************************************
** Form generated from reading UI file 'settings.ui'
**
** Created by: Qt User Interface Compiler version 6.7.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_SETTINGS_H
#define UI_SETTINGS_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QVBoxLayout>

QT_BEGIN_NAMESPACE

class Ui_Settings
{
public:
    QGroupBox *groupBox;
    QGridLayout *gridLayout;
    QHBoxLayout *horizontalLayout;
    QVBoxLayout *verticalLayout;
    QLabel *label_name;
    QLabel *label_surname;
    QLabel *label_password;
    QVBoxLayout *verticalLayout_2;
    QLineEdit *lineEdit_name;
    QLineEdit *lineEdit_surname;
    QLineEdit *lineEdit_password;
    QVBoxLayout *verticalLayout_3;
    QPushButton *pushButton_name;
    QPushButton *pushButton_surname;
    QPushButton *pushButton_password;

    void setupUi(QDialog *Settings)
    {
        if (Settings->objectName().isEmpty())
            Settings->setObjectName("Settings");
        Settings->resize(392, 255);
        groupBox = new QGroupBox(Settings);
        groupBox->setObjectName("groupBox");
        groupBox->setGeometry(QRect(10, 30, 371, 201));
        gridLayout = new QGridLayout(groupBox);
        gridLayout->setObjectName("gridLayout");
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName("horizontalLayout");
        verticalLayout = new QVBoxLayout();
        verticalLayout->setObjectName("verticalLayout");
        label_name = new QLabel(groupBox);
        label_name->setObjectName("label_name");

        verticalLayout->addWidget(label_name);

        label_surname = new QLabel(groupBox);
        label_surname->setObjectName("label_surname");

        verticalLayout->addWidget(label_surname);

        label_password = new QLabel(groupBox);
        label_password->setObjectName("label_password");

        verticalLayout->addWidget(label_password);


        horizontalLayout->addLayout(verticalLayout);

        verticalLayout_2 = new QVBoxLayout();
        verticalLayout_2->setObjectName("verticalLayout_2");
        lineEdit_name = new QLineEdit(groupBox);
        lineEdit_name->setObjectName("lineEdit_name");

        verticalLayout_2->addWidget(lineEdit_name);

        lineEdit_surname = new QLineEdit(groupBox);
        lineEdit_surname->setObjectName("lineEdit_surname");

        verticalLayout_2->addWidget(lineEdit_surname);

        lineEdit_password = new QLineEdit(groupBox);
        lineEdit_password->setObjectName("lineEdit_password");
        lineEdit_password->setEchoMode(QLineEdit::Password);

        verticalLayout_2->addWidget(lineEdit_password);


        horizontalLayout->addLayout(verticalLayout_2);

        verticalLayout_3 = new QVBoxLayout();
        verticalLayout_3->setObjectName("verticalLayout_3");
        pushButton_name = new QPushButton(groupBox);
        pushButton_name->setObjectName("pushButton_name");

        verticalLayout_3->addWidget(pushButton_name);

        pushButton_surname = new QPushButton(groupBox);
        pushButton_surname->setObjectName("pushButton_surname");

        verticalLayout_3->addWidget(pushButton_surname);

        pushButton_password = new QPushButton(groupBox);
        pushButton_password->setObjectName("pushButton_password");

        verticalLayout_3->addWidget(pushButton_password);


        horizontalLayout->addLayout(verticalLayout_3);


        gridLayout->addLayout(horizontalLayout, 0, 0, 1, 1);


        retranslateUi(Settings);

        QMetaObject::connectSlotsByName(Settings);
    } // setupUi

    void retranslateUi(QDialog *Settings)
    {
        Settings->setWindowTitle(QCoreApplication::translate("Settings", "Dialog", nullptr));
        groupBox->setTitle(QCoreApplication::translate("Settings", "Settings", nullptr));
        label_name->setText(QCoreApplication::translate("Settings", "Name:", nullptr));
        label_surname->setText(QCoreApplication::translate("Settings", "Surname:", nullptr));
        label_password->setText(QCoreApplication::translate("Settings", "Password:", nullptr));
        pushButton_name->setText(QCoreApplication::translate("Settings", "Save", nullptr));
        pushButton_surname->setText(QCoreApplication::translate("Settings", "Save", nullptr));
        pushButton_password->setText(QCoreApplication::translate("Settings", "Save", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Settings: public Ui_Settings {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SETTINGS_H
