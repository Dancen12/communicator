/********************************************************************************
** Form generated from reading UI file 'beginwindow.ui'
**
** Created by: Qt User Interface Compiler version 6.7.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_BEGINWINDOW_H
#define UI_BEGINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QVBoxLayout>

QT_BEGIN_NAMESPACE

class Ui_BeginWindow
{
public:
    QGroupBox *groupBox;
    QGridLayout *gridLayout;
    QVBoxLayout *verticalLayout_5;
    QHBoxLayout *horizontalLayout;
    QVBoxLayout *verticalLayout_2;
    QLabel *label;
    QLabel *label_2;
    QVBoxLayout *verticalLayout;
    QLineEdit *lineEdit_login;
    QLineEdit *lineEdit_password;
    QHBoxLayout *horizontalLayout_2;
    QVBoxLayout *verticalLayout_4;
    QSpacerItem *horizontalSpacer;
    QLabel *label_3;
    QVBoxLayout *verticalLayout_3;
    QPushButton *pushButton_login;
    QPushButton *pushButton_signin;

    void setupUi(QDialog *BeginWindow)
    {
        if (BeginWindow->objectName().isEmpty())
            BeginWindow->setObjectName("BeginWindow");
        BeginWindow->resize(451, 308);
        groupBox = new QGroupBox(BeginWindow);
        groupBox->setObjectName("groupBox");
        groupBox->setGeometry(QRect(70, 60, 311, 191));
        gridLayout = new QGridLayout(groupBox);
        gridLayout->setObjectName("gridLayout");
        verticalLayout_5 = new QVBoxLayout();
        verticalLayout_5->setObjectName("verticalLayout_5");
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName("horizontalLayout");
        verticalLayout_2 = new QVBoxLayout();
        verticalLayout_2->setObjectName("verticalLayout_2");
        label = new QLabel(groupBox);
        label->setObjectName("label");

        verticalLayout_2->addWidget(label);

        label_2 = new QLabel(groupBox);
        label_2->setObjectName("label_2");

        verticalLayout_2->addWidget(label_2);


        horizontalLayout->addLayout(verticalLayout_2);

        verticalLayout = new QVBoxLayout();
        verticalLayout->setObjectName("verticalLayout");
        lineEdit_login = new QLineEdit(groupBox);
        lineEdit_login->setObjectName("lineEdit_login");
        lineEdit_login->setEnabled(true);
        lineEdit_login->setBaseSize(QSize(0, 0));

        verticalLayout->addWidget(lineEdit_login);

        lineEdit_password = new QLineEdit(groupBox);
        lineEdit_password->setObjectName("lineEdit_password");
        lineEdit_password->setEchoMode(QLineEdit::Password);

        verticalLayout->addWidget(lineEdit_password);


        horizontalLayout->addLayout(verticalLayout);


        verticalLayout_5->addLayout(horizontalLayout);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName("horizontalLayout_2");
        verticalLayout_4 = new QVBoxLayout();
        verticalLayout_4->setObjectName("verticalLayout_4");
        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Minimum);

        verticalLayout_4->addItem(horizontalSpacer);

        label_3 = new QLabel(groupBox);
        label_3->setObjectName("label_3");

        verticalLayout_4->addWidget(label_3);


        horizontalLayout_2->addLayout(verticalLayout_4);

        verticalLayout_3 = new QVBoxLayout();
        verticalLayout_3->setObjectName("verticalLayout_3");
        pushButton_login = new QPushButton(groupBox);
        pushButton_login->setObjectName("pushButton_login");

        verticalLayout_3->addWidget(pushButton_login);

        pushButton_signin = new QPushButton(groupBox);
        pushButton_signin->setObjectName("pushButton_signin");

        verticalLayout_3->addWidget(pushButton_signin);


        horizontalLayout_2->addLayout(verticalLayout_3);


        verticalLayout_5->addLayout(horizontalLayout_2);


        gridLayout->addLayout(verticalLayout_5, 0, 0, 1, 1);


        retranslateUi(BeginWindow);

        QMetaObject::connectSlotsByName(BeginWindow);
    } // setupUi

    void retranslateUi(QDialog *BeginWindow)
    {
        BeginWindow->setWindowTitle(QCoreApplication::translate("BeginWindow", "Dialog", nullptr));
        groupBox->setTitle(QString());
        label->setText(QCoreApplication::translate("BeginWindow", "Login:", nullptr));
        label_2->setText(QCoreApplication::translate("BeginWindow", "Password:", nullptr));
        label_3->setText(QCoreApplication::translate("BeginWindow", "Don't have an account?", nullptr));
        pushButton_login->setText(QCoreApplication::translate("BeginWindow", "Log in", nullptr));
        pushButton_signin->setText(QCoreApplication::translate("BeginWindow", "Sign up", nullptr));
    } // retranslateUi

};

namespace Ui {
    class BeginWindow: public Ui_BeginWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_BEGINWINDOW_H
