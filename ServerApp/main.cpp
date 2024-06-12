#include "mainwindow.h"
#include <stdexcept>
#include <QApplication>
#include <QFile>
#include <QMessageBox>



int main(int argc, char *argv[])
{

    QApplication a(argc, argv);
    QFile qss("serverTheme.qss");
    if(qss.open(QIODevice::ReadOnly))
    {
        QString ss = qss.readAll();
        a.setStyleSheet(ss);
    }
    qss.close();
    try {

        MainWindow w;
        w.show();
        return a.exec();

    } catch (std::exception& exc) {
        QMessageBox::critical(nullptr,"Exception",exc.what());
    }
    return -1;
}
