#ifndef SETTINGS_H
#define SETTINGS_H

#include <QDialog>
#include "currentuser.h"
#include "serverrequester.h"


namespace Ui {
class Settings;
}

class Settings : public QDialog
{
    Q_OBJECT

public:
    explicit Settings(const CurrentUser&, QWidget *parent = nullptr);
    ~Settings();

protected:
    CurrentUser user;
private slots:
    void on_pushButton_name_clicked();

    void on_pushButton_surname_clicked();

    void on_pushButton_password_clicked();

private:
    Ui::Settings *ui;
};

#endif // SETTINGS_H
