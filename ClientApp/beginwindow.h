#ifndef BEGINWINDOW_H
#define BEGINWINDOW_H

#include <QDialog>
#include <QMessageBox>
#include "registerwindow.h"
#include "currentuser.h"
#include "serverrequester.h"
namespace Ui {
class BeginWindow;
}

class BeginWindow : public QDialog
{
    Q_OBJECT

public:
    explicit BeginWindow(QWidget *parent = nullptr);
    ~BeginWindow();

private slots:
    void on_pushButton_login_clicked();
    void on_pushButton_signin_clicked();
    void on_BeginWindow_rejected();
    void registered(CurrentUser curUser);
    void backFromRegistration();
signals:
    void logged(CurrentUser curUser);

private:
    Ui::BeginWindow *ui;
    RegisterWindow * registerWindow;

};

#endif // BEGINWINDOW_H
