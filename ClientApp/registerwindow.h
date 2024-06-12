#ifndef REGISTERWINDOW_H
#define REGISTERWINDOW_H

#include <QDialog>
#include <QMessageBox>
#include <QDate>
#include "currentuser.h"

namespace Ui {
class RegisterWindow;
}

class RegisterWindow : public QDialog
{
    Q_OBJECT

public:
    explicit RegisterWindow(QWidget *parent = nullptr);
    ~RegisterWindow();

private slots:
    void on_RegisterWindow_rejected();
    void on_pushButton_clicked();
    void on_pushButton_back_clicked();

signals:
    void registered(CurrentUser currentUser);
    void back();
private:
    Ui::RegisterWindow *ui;
    bool checkUserInput();
};

#endif // REGISTERWINDOW_H
