/********************************************************************************
** Form generated from reading UI file 'registerwindow.ui'
**
** Created by: Qt User Interface Compiler version 6.7.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_REGISTERWINDOW_H
#define UI_REGISTERWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QDialog>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_RegisterWindow
{
public:
    QGroupBox *groupBox;
    QWidget *layoutWidget;
    QVBoxLayout *verticalLayout_5;
    QHBoxLayout *horizontalLayout;
    QVBoxLayout *verticalLayout_4;
    QLabel *label_name;
    QLabel *label_surname;
    QLabel *label_dateOfBirth;
    QLabel *label_email;
    QLabel *label_password;
    QLabel *label_repeatPassword;
    QVBoxLayout *verticalLayout_3;
    QLineEdit *lineEdit_name;
    QLineEdit *lineEdit_surname;
    QLineEdit *lineEdit_dateOfBirth;
    QLineEdit *lineEdit_email;
    QLineEdit *lineEdit_password;
    QLineEdit *lineEdit_repeatPassword;
    QHBoxLayout *horizontalLayout_2;
    QVBoxLayout *verticalLayout_2;
    QCheckBox *checkBox_termsOfUse;
    QCheckBox *checkBox_privacePolicy;
    QVBoxLayout *verticalLayout;
    QPushButton *pushButton;
    QPushButton *pushButton_back;

    void setupUi(QDialog *RegisterWindow)
    {
        if (RegisterWindow->objectName().isEmpty())
            RegisterWindow->setObjectName("RegisterWindow");
        RegisterWindow->resize(397, 305);
        groupBox = new QGroupBox(RegisterWindow);
        groupBox->setObjectName("groupBox");
        groupBox->setGeometry(QRect(9, 9, 379, 287));
        layoutWidget = new QWidget(groupBox);
        layoutWidget->setObjectName("layoutWidget");
        layoutWidget->setGeometry(QRect(13, 30, 344, 244));
        verticalLayout_5 = new QVBoxLayout(layoutWidget);
        verticalLayout_5->setObjectName("verticalLayout_5");
        verticalLayout_5->setContentsMargins(0, 0, 0, 0);
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName("horizontalLayout");
        verticalLayout_4 = new QVBoxLayout();
        verticalLayout_4->setObjectName("verticalLayout_4");
        label_name = new QLabel(layoutWidget);
        label_name->setObjectName("label_name");

        verticalLayout_4->addWidget(label_name);

        label_surname = new QLabel(layoutWidget);
        label_surname->setObjectName("label_surname");

        verticalLayout_4->addWidget(label_surname);

        label_dateOfBirth = new QLabel(layoutWidget);
        label_dateOfBirth->setObjectName("label_dateOfBirth");

        verticalLayout_4->addWidget(label_dateOfBirth);

        label_email = new QLabel(layoutWidget);
        label_email->setObjectName("label_email");

        verticalLayout_4->addWidget(label_email);

        label_password = new QLabel(layoutWidget);
        label_password->setObjectName("label_password");

        verticalLayout_4->addWidget(label_password);

        label_repeatPassword = new QLabel(layoutWidget);
        label_repeatPassword->setObjectName("label_repeatPassword");

        verticalLayout_4->addWidget(label_repeatPassword);


        horizontalLayout->addLayout(verticalLayout_4);

        verticalLayout_3 = new QVBoxLayout();
        verticalLayout_3->setObjectName("verticalLayout_3");
        lineEdit_name = new QLineEdit(layoutWidget);
        lineEdit_name->setObjectName("lineEdit_name");

        verticalLayout_3->addWidget(lineEdit_name);

        lineEdit_surname = new QLineEdit(layoutWidget);
        lineEdit_surname->setObjectName("lineEdit_surname");

        verticalLayout_3->addWidget(lineEdit_surname);

        lineEdit_dateOfBirth = new QLineEdit(layoutWidget);
        lineEdit_dateOfBirth->setObjectName("lineEdit_dateOfBirth");

        verticalLayout_3->addWidget(lineEdit_dateOfBirth);

        lineEdit_email = new QLineEdit(layoutWidget);
        lineEdit_email->setObjectName("lineEdit_email");

        verticalLayout_3->addWidget(lineEdit_email);

        lineEdit_password = new QLineEdit(layoutWidget);
        lineEdit_password->setObjectName("lineEdit_password");
        lineEdit_password->setEchoMode(QLineEdit::Password);

        verticalLayout_3->addWidget(lineEdit_password);

        lineEdit_repeatPassword = new QLineEdit(layoutWidget);
        lineEdit_repeatPassword->setObjectName("lineEdit_repeatPassword");
        lineEdit_repeatPassword->setEchoMode(QLineEdit::Password);

        verticalLayout_3->addWidget(lineEdit_repeatPassword);


        horizontalLayout->addLayout(verticalLayout_3);


        verticalLayout_5->addLayout(horizontalLayout);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName("horizontalLayout_2");
        verticalLayout_2 = new QVBoxLayout();
        verticalLayout_2->setObjectName("verticalLayout_2");
        checkBox_termsOfUse = new QCheckBox(layoutWidget);
        checkBox_termsOfUse->setObjectName("checkBox_termsOfUse");

        verticalLayout_2->addWidget(checkBox_termsOfUse);

        checkBox_privacePolicy = new QCheckBox(layoutWidget);
        checkBox_privacePolicy->setObjectName("checkBox_privacePolicy");

        verticalLayout_2->addWidget(checkBox_privacePolicy);


        horizontalLayout_2->addLayout(verticalLayout_2);

        verticalLayout = new QVBoxLayout();
        verticalLayout->setObjectName("verticalLayout");
        pushButton = new QPushButton(layoutWidget);
        pushButton->setObjectName("pushButton");

        verticalLayout->addWidget(pushButton);

        pushButton_back = new QPushButton(layoutWidget);
        pushButton_back->setObjectName("pushButton_back");

        verticalLayout->addWidget(pushButton_back);


        horizontalLayout_2->addLayout(verticalLayout);


        verticalLayout_5->addLayout(horizontalLayout_2);


        retranslateUi(RegisterWindow);

        QMetaObject::connectSlotsByName(RegisterWindow);
    } // setupUi

    void retranslateUi(QDialog *RegisterWindow)
    {
        RegisterWindow->setWindowTitle(QCoreApplication::translate("RegisterWindow", "Dialog", nullptr));
        groupBox->setTitle(QCoreApplication::translate("RegisterWindow", "Registration", nullptr));
        label_name->setText(QCoreApplication::translate("RegisterWindow", "Name:", nullptr));
        label_surname->setText(QCoreApplication::translate("RegisterWindow", "Surname:", nullptr));
        label_dateOfBirth->setText(QCoreApplication::translate("RegisterWindow", "Date of birth:", nullptr));
        label_email->setText(QCoreApplication::translate("RegisterWindow", "Email:", nullptr));
        label_password->setText(QCoreApplication::translate("RegisterWindow", "Password:", nullptr));
        label_repeatPassword->setText(QCoreApplication::translate("RegisterWindow", "Repeat password:", nullptr));
        checkBox_termsOfUse->setText(QCoreApplication::translate("RegisterWindow", "I accept the terms of use of the application", nullptr));
        checkBox_privacePolicy->setText(QCoreApplication::translate("RegisterWindow", "I accept the privace policy", nullptr));
        pushButton->setText(QCoreApplication::translate("RegisterWindow", "Sign in", nullptr));
        pushButton_back->setText(QCoreApplication::translate("RegisterWindow", "Back", nullptr));
    } // retranslateUi

};

namespace Ui {
    class RegisterWindow: public Ui_RegisterWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_REGISTERWINDOW_H
