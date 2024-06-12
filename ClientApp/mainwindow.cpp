#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->listWidget_search->hide();
    ui->pushButton_close->hide();
    beginWindow =nullptr;
    settingsWindow =nullptr;
    fileManager = nullptr;
    currentUser = nullptr;
    chat = nullptr;
    ServerRequester::getInstance()->connectToMessages(this);
    setWindowTitle("DancenChat");

}

void MainWindow::begin()
{
    hide();
    beginWindow = new BeginWindow(this);
    beginWindow->show();
    connect(beginWindow,&BeginWindow::logged, this, &MainWindow::beginFinished);
}

void MainWindow::beginFinished(CurrentUser curUser)
{
    delete beginWindow;
    beginWindow = nullptr;
    currentUser = new CurrentUser(curUser);
    loudUsers();
    ui->label_name->setText(QString(currentUser->personalInfo.name.c_str()) + ' ' +QString(currentUser->personalInfo.surname.c_str()));
    ui->groupBox_chat->setTitle("Chat name");
    ui->label_id->setText(std::to_string(curUser.userID).c_str());
    show();
}

MainWindow::~MainWindow()
{
    ServerRequester::getInstance()->disconnectSer();
    delete ui;
    delete beginWindow;
    delete fileManager;
    delete currentUser;
    delete settingsWindow;
    if(chat)
    {
        chat->end();
        delete chat;
    }
}

User MainWindow::userFromList(int id)
{
    for(auto& u: users)
    {
        if(u.userID==id)
        {
            return u;
        }
    }
    User u;
    return u;
}

void MainWindow:: userToTop(const User& user)
{
    users.remove(user);
    users.push_front(user);
    reloudUsersList();
}

void MainWindow:: reloudUsersList()
{
    ui->listWidget_users->clear();
    for(auto& x : users)
    {
        QString str (x.personalInfo.name.c_str());
        str+=' ' + x.personalInfo.surname +'.' + std::to_string(x.userID);
        ui->listWidget_users->addItem(new QListWidgetItem(str, ui->listWidget_users));
    }
}

void MainWindow:: loudUsers()
{
    users = ServerRequester::getInstance()->getUsers(currentUser->userID);
    reloudUsersList();
}

void MainWindow::on_pushButton_clicked()
{
    //LogOut
    if(chat)
    {
        chat->end();
        delete chat;
        chat = nullptr;
    }
    if(currentUser)
    {
        delete currentUser;
        currentUser = nullptr;
    }
    ServerRequester::getInstance()->disconnectSer();
    begin();
}


void MainWindow::on_listWidget_users_itemClicked(QListWidgetItem *item)
{
    User chosenUser = itemToUser(item);
    if (chat)
    {
        chat->end();
        delete chat;
        chat = nullptr;
    }
    chat = new SingleChat(*currentUser,chosenUser,this);

    connect(chat,&IChat::showMessagesSignal, this, &MainWindow::showMessages);
    connect(chat,&IChat::setChatDescriptionSignal,this,&MainWindow::setChatDescription);
    connect(chat,&IChat::setChatNameSignal,this,&MainWindow::setChatName);
    connect(chat,&IChat::updateMessagesSignal,this,&MainWindow::updateMessages);
    connect(chat,&IChat::clearChat,this,&MainWindow::clearChat);
    SingleChat* singleChat = dynamic_cast<SingleChat*>(chat);
    connect(this,&MainWindow::sendMessage,singleChat,&SingleChat::sentMessage);
    connect(this,&MainWindow::newMessageForChat,singleChat,&SingleChat::newMessage);

    chat->start();
}

User MainWindow::itemToUser(QListWidgetItem *item)
{
    QString str(item->text());
    auto list = str.split('.');
    auto nameAndSurname = list.at(0).split(' ');
    User chosenUser;
    chosenUser.userID = list.at(1).toInt();
    chosenUser.personalInfo.name = nameAndSurname.at(0).toStdString();
    chosenUser.personalInfo.surname = nameAndSurname.at(1).toStdString();
    return chosenUser;
}

void MainWindow::showMessages(std::list<Imessage*> messages)
{
    for(auto& mess : messages)
    {
        ui->listWidget_chat->addItem(new QListWidgetItem(*mess,ui->listWidget_chat));
    }
}
void MainWindow:: clearChat()
{
    ui->listWidget_chat->clear();
}

void MainWindow::newMessageArrived(QString messagePack)
{
    auto message = messagePack.split('/');
    //mess[0]=tag
    int sender_id = message.at(1).toInt();
    int receiver_id = message.at(2).toInt();
    std::string date = message.at(3).toStdString();
    std::string content = message.at(4).toStdString();
    User u = userFromList(sender_id);

    if(u.userID != sender_id)
    {
        loudUsers();
    }
    else
    {
        if(chat)
        {
            SingleChat* singleChat = dynamic_cast<SingleChat*>(chat);
            if(singleChat->receiver.userID==sender_id)
            {
                emit newMessageForChat(new TextMessage(u,date,content));
            }
        }
            userToTop(u);
    }
}

void MainWindow::updateMessages(std::list<Imessage*> messages)
{
    for(auto& mess : messages)
    {
        auto item = new QListWidgetItem(*mess,ui->listWidget_chat);
        ui->listWidget_chat->addItem(item);
        ui->listWidget_chat->scrollToItem(item);
    }
}
void MainWindow::setChatDescription(std::string description)
{
   //in future
}
void MainWindow::setChatName(std::string chatName)
{
    ui->groupBox_chat->setTitle(chatName.c_str());
}


void MainWindow::on_pushButton_search_clicked()
{
    ui->listWidget_search->clear();
    auto nameAndSurname = ui->lineEdit_search->text().split(' ');
    auto result = ServerRequester::getInstance()->serchUser(nameAndSurname.value(0).toStdString(),nameAndSurname.value(1).toStdString());
    for(auto& user : result)
    {
        QString userOnList(user.personalInfo.name.c_str());
        userOnList+= ' ' + user.personalInfo.surname + '.' + std::to_string(user.userID);
        ui->listWidget_chat->addItem(new QListWidgetItem(userOnList,ui->listWidget_search));
    }

    ui->listWidget_search->show();
    ui->pushButton_close->show();
}


void MainWindow::on_pushButton_close_clicked()
{
    ui->lineEdit_search->clear();
    ui->listWidget_search->clear();
    ui->listWidget_search->hide();
    ui->pushButton_close->hide();
}


void MainWindow::on_listWidget_search_itemClicked(QListWidgetItem *item)
{
    ui->lineEdit_search->clear();
    ui->listWidget_search->hide();
    ui->pushButton_close->hide();
    on_listWidget_users_itemClicked(item);
}

bool MainWindow:: isUserOnList(int user_id)
{
    for(auto& u: users)
    {
        if(u.userID==user_id)
        {
            return true;
        }
    }
    return false;
}


void MainWindow::on_pushButton_send_clicked()
{
    auto message =  ui->lineEdit_messageInput->text();
    if(!message.isEmpty())
    {
        if(chat)
        {
            SingleChat* singleChat = dynamic_cast<SingleChat*>(chat);
            if(isUserOnList(singleChat->receiver.userID))
            {
                users.push_front(singleChat->receiver);
            }
            userToTop(singleChat->receiver);
            Imessage*  mess = new TextMessage(*currentUser,QDateTime::currentDateTime().toString("yyyy-MM-dd hh:mm:ss").toStdString(),message.toStdString());
            emit sendMessage(mess);
        }
        else
        {
            QMessageBox::information(this,"Message","Chat no chosen");
        }
         ui->lineEdit_messageInput->clear();
    }
}


void MainWindow::on_lineEdit_messageInput_returnPressed()
{
    on_pushButton_send_clicked();
}


void MainWindow::on_pushButton_settings_clicked()
{
    settingsWindow = new Settings(*currentUser,this);
    settingsWindow->show();
}

