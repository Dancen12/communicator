#include "settings.h"
#include "ui_settings.h"
#include <chrono>
#include <thread>
#include <QMessageBox>

Settings::Settings(const CurrentUser& userval, QWidget *parent)
    : QDialog(parent)
    , user(userval),ui(new Ui::Settings)
{
    ui->setupUi(this);
    ui->lineEdit_name->setText(user.personalInfo.name.c_str());
    ui->lineEdit_surname->setText(user.personalInfo.surname.c_str());
    ui->lineEdit_password->setText(user.safety.password.c_str());
    setWindowTitle("Settings");
}

Settings::~Settings()
{
    delete ui;
}

void Settings::on_pushButton_name_clicked()
{
    ServerRequester::getInstance()->changeName(user.userID,ui->lineEdit_name->text().toStdString());
    std::this_thread::sleep_for(std::chrono::milliseconds(100));
    QMessageBox::information(this,"Information","Name has been changed. To apply changes, log out.");
}


void Settings::on_pushButton_surname_clicked()
{
    ServerRequester::getInstance()->changeSurname(user.userID,ui->lineEdit_surname->text().toStdString());
    std::this_thread::sleep_for(std::chrono::milliseconds(100));
    QMessageBox::information(this,"Information","Surname has been changed. To apply changes, log out.");
}


void Settings::on_pushButton_password_clicked()
{
    ServerRequester::getInstance()->changePassword(user.userID,ui->lineEdit_password->text().toStdString());
    std::this_thread::sleep_for(std::chrono::milliseconds(100));
    QMessageBox::information(this,"Information","Password has been changed. To apply changes, log out.");
}

