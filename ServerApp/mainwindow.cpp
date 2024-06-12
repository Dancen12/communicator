#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "serverlogger.h"
#include "dbmanager.h""

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->label_ip->setText(IPADRESS);
    ui->label_port->setText(std::to_string(PORT).c_str());
    ui->label_connectedHostNr->setText("0");
    setWindowTitle("DancenServer");
    connect(ServerLogger::getInstance(),&ServerLogger::addToList,this,&MainWindow::addLog);
    DBManager::getInstance();//in constructor of DBManager we checking the connection
}

MainWindow::~MainWindow()
{
    delete ui;
    if(server)
    {
        delete server;
    }
    auto dbm = DBManager::getInstance();
    delete dbm;
}

void MainWindow::on_pushButton_clicked()
{
    server = Server::getInstance();
    server->setMainWindowPtr(this);
    server->process();
}


void MainWindow::on_pushButton_2_clicked()
{

    if(server)
    {
        server->stop();
        server = nullptr;
    }
}

void MainWindow::addLog(const QString& log)
{
    auto item = new QListWidgetItem(log,ui->listWidget_logs);
    ui->listWidget_logs->addItem(item);
}

void MainWindow:: setNumberOfClientsLabel(int nr)
{
    ui->label_connectedHostNr->setText(std::to_string(nr).c_str());
}

