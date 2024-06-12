#include "beginwindow.h"
#include "ui_beginwindow.h"

BeginWindow::BeginWindow(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::BeginWindow)
{
    ui->setupUi(this);
    registerWindow = nullptr;
    setWindowTitle("DancenChat");
}


BeginWindow::~BeginWindow()
{
    delete ui;
    delete registerWindow;
}

void BeginWindow::on_pushButton_login_clicked()
{
    ServerRequester* sr = ServerRequester::getInstance();
    bool temp = sr->isCorrectLogin(ui->lineEdit_login->text().toStdString(),ui->lineEdit_password->text().toStdString());
    if(temp)
    {
        QMessageBox::information(this,"Logged","Welcome Back!");
        auto userData = sr->getUserData(ui->lineEdit_login->text().toStdString());
        CurrentUser currentUser;
        currentUser.userID = userData.value(0).toInt();
        currentUser.personalInfo.name = userData.value(1).toStdString();
        currentUser.personalInfo.surname = userData.value(2).toStdString();
        currentUser.additionalInfo.bio = userData.value(3).toStdString();
        currentUser.safety.key = userData.value(4).toInt();
        currentUser.contacts.email = ui->lineEdit_login->text().toStdString();
        hide();
        emit logged(currentUser);
    }
    else
    {
        QMessageBox::warning(this,"Login failed","Login or password is incorrect");
    }
}


void BeginWindow::on_pushButton_signin_clicked()
{
    ui->lineEdit_login->clear();
    ui->lineEdit_password->clear();
    registerWindow = new RegisterWindow(this);
    connect(registerWindow,&RegisterWindow::registered,this,&BeginWindow::registered);
    connect(registerWindow,&RegisterWindow::back,this,&BeginWindow::backFromRegistration);
    hide();
    registerWindow ->show();
}


void BeginWindow::on_BeginWindow_rejected()
{
    QCoreApplication::quit();
}

void BeginWindow:: registered(CurrentUser curUser)
{
    delete registerWindow;
    registerWindow = nullptr;
    auto userData = ServerRequester::getInstance()->getUserData(curUser.contacts.email);
    curUser.userID = userData.value(0).toInt();
    curUser.personalInfo.name = userData.value(1).toStdString();
    curUser.personalInfo.surname = userData.value(2).toStdString();
    curUser.additionalInfo.bio = userData.value(3).toStdString();
    curUser.safety.key = userData.value(4).toInt();
    curUser.contacts.email = ui->lineEdit_login->text().toStdString();
    emit logged(curUser);
}

void BeginWindow:: backFromRegistration()
{
    show();
    delete registerWindow;
    registerWindow = nullptr;

}

