#include "mainwindow.h"
#include <QMessageBox>
#include <stdexcept>
#include <QApplication>

void myTerminate();


int main(int argc, char *argv[])
{
    std::set_terminate(&myTerminate);
    QApplication a(argc, argv);
    QFile qss("appTheme.qss");
    if(qss.open(QIODevice::ReadOnly))
    {
        QString ss = qss.readAll();
        a.setStyleSheet(ss);
    }
    qss.close();


    try {
        MainWindow w;

        w.begin();
        return a.exec();
    } catch (std::exception& exc) {
        QMessageBox::critical(nullptr,"ERROR",exc.what());
    }
    return -1;
}

void myTerminate()
{
    ServerRequester::getInstance()->disconnectSer();
    exit(-1);
}
