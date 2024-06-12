#include "registerwindow.h"
#include "ui_registerwindow.h"
#include"serverrequester.h"

RegisterWindow::RegisterWindow(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::RegisterWindow)
{
    ui->setupUi(this);
    setWindowTitle("DancenChat");
}

RegisterWindow::~RegisterWindow()
{
    delete ui;
}

void RegisterWindow::on_RegisterWindow_rejected()
{
    QCoreApplication::quit();
}

bool RegisterWindow:: checkUserInput()
{

    QString name = ui->lineEdit_name->text();
    QString surname = ui->lineEdit_surname->text();
    QString dateOfBirth = ui->lineEdit_dateOfBirth->text();
    QString email = ui->lineEdit_email->text();
    QString password = ui->lineEdit_password->text();
    QString repeatedPassword = ui->lineEdit_repeatPassword->text();
    if(name.isEmpty() || surname.isEmpty() || dateOfBirth.isEmpty() || email.isEmpty() || password.isEmpty() || repeatedPassword.isEmpty())
    {
        QMessageBox::warning(this, "Warning", "No field can be empty!");
        return false;
    }
    if(password!=repeatedPassword)
    {
        QMessageBox::warning(this, "Warning", "Passwords are not the same!");
        return false;
    }
    QString dateFormat = "yyyy-MM-dd";
    if(!QDate::fromString(dateOfBirth,dateFormat).isValid())
    {
        QMessageBox::warning(this, "Warning", "Date should have YYYY-MM-DD format!");
        return false;
    }
    if(!(ui->checkBox_privacePolicy->isChecked() && ui->checkBox_termsOfUse->isChecked()))
    {
        QMessageBox::warning(this,"Warning","You have to accept check boxes!");
        return false;
    }
    return true;

}


void RegisterWindow::on_pushButton_clicked()
{
    if(checkUserInput())
    {
        auto email = ui->lineEdit_email->text();
        if(!ServerRequester::getInstance()->emailExist(email.toStdString()))
        {
            CurrentUser user;
            user.personalInfo.name = ui->lineEdit_name->text().toStdString();
            user.personalInfo.surname = ui->lineEdit_surname->text().toStdString();
            user.personalInfo.dateOfBirth = ui->lineEdit_dateOfBirth->text().toStdString();
            user.safety.password = ui->lineEdit_password->text().toStdString();
            user.contacts.email = ui->lineEdit_email->text().toStdString();
            //user.additionalInfo.bio  = in future;
            ServerRequester::getInstance()->signInUser(user.safety.password,user.personalInfo.name,user.personalInfo.surname,user.personalInfo.dateOfBirth,"",user.contacts.email,user.additionalInfo.bio);
            QMessageBox::information(this,"Welcome","Welcome in our application. We wish you all the best.");
            emit registered(user);
        }
        else
        {
            QMessageBox::warning(this,"Warning","Email already exist on our server");
        }
    }
}


void RegisterWindow::on_pushButton_back_clicked()
{
    emit back();
}

