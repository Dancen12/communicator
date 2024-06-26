#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "server.h"

QT_BEGIN_NAMESPACE
namespace Ui {
class MainWindow;
}
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
    void setNumberOfClientsLabel(int);
private slots:
    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

    void addLog(const QString&);
private:
    Ui::MainWindow *ui;
    Server* server;
};
#endif // MAINWINDOW_H
