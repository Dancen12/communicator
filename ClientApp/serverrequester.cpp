#include "serverrequester.h"
#include "mainwindow.h"

ServerRequester * ServerRequester::pInstance = nullptr;
std::mutex ServerRequester:: mtx;


ServerRequester::ServerRequester(QObject *parent)
    : QObject{parent}
{
    socket = new QTcpSocket(this);
    connect(socket,&QTcpSocket::connected,this,&ServerRequester::connected);
    connect(socket,&QTcpSocket::disconnected,this,&ServerRequester::disconnected);
    connect(socket, QOverload<QAbstractSocket::SocketError>::of(&QAbstractSocket::errorOccurred), this, &ServerRequester::onErrorOccurred);
    connect(socket,&QTcpSocket::readyRead,this,&ServerRequester::newDataCome);
}

ServerRequester* ServerRequester::getInstance(QObject *parent )
{
    mtx.lock();
    if(!pInstance)
    {
        pInstance = new ServerRequester(parent);
    }
    mtx.unlock();
    pInstance->connectSer();
    pInstance->socket->waitForConnected();
    return pInstance;
}
ServerRequester::~ServerRequester()
{
}

void ServerRequester::connectSer()
{
    if (socket->state() == QAbstractSocket::UnconnectedState) {
        socket->connectToHost(SERVERIP, SERVERPORT);
    } else {
       // qWarning() << "Socket is already connected or connecting.";
    }
}
void ServerRequester::disconnectSer()
{
    if(socket)
    {
        if(socket->state()==QAbstractSocket::ConnectedState)
        {
            socket->write("3 ");
            socket->flush();
            std::this_thread::sleep_for(std::chrono::milliseconds(100));
            socket->disconnectFromHost();
            delete socket;
            socket = nullptr;
        }
    }
    if(pInstance)
    {
        delete pInstance;
        pInstance = nullptr;
    }
}

void ServerRequester::connected()
{
    //qDebug("Connected to host");
}
void ServerRequester::disconnected()
{
    //qDebug("Disconnected from host");
}

void ServerRequester:: newDataCome()
{
    mtx.lock();
    auto newData = socket->peek(100);//zmiejszyc potem
    if(newData.size()>=3)// 3 because tag <m> has 3 characters
    {

        if (newData[0] == '<' && newData[1] == 'm' && newData[2] == '>')
        {
            std::string str = socket->readAll().toStdString();
            mtx.unlock();
            emit newMessage(QString(str.c_str()));
        }
    }
    mtx.unlock();
}


void ServerRequester::onErrorOccurred(QAbstractSocket::SocketError socketError)
{
    throw std::runtime_error(socket->errorString().toStdString());
}

bool ServerRequester::isCorrectLogin(const std::string& login, const std::string& password)
{
    std::string message("1 ");//functionID, two bytes
    message+=login + ' ' + password;
    socket->write(message.c_str());
    socket->waitForReadyRead();
    QByteArray answer =  socket->readAll();
    QString temp(answer[0]);
    return temp.toInt();
}

QStringList ServerRequester:: getUserData(const std::string& email)
{
    std::string message("2 ");
    message += email;
    socket->write(message.c_str());
    socket->waitForReadyRead();
    QString answer =  socket->readAll();
    return answer.split('/');
}

std::list<User> ServerRequester:: getUsers(int userID)
{
    std::string message("4 ");
    message+= std::to_string(userID);
    socket->write(message.c_str());
    socket->waitForReadyRead();
    QString answer = socket->readAll();
    std::list<User> users;
    if(answer!=EMPTYROW)
    {
        auto list = answer.split('\n');
        for(auto& x : list)
        {
            auto userData =  x.split('/');
            User user;
            user.userID = userData.value(0).toInt();
            user.personalInfo.name = userData.value(1).toStdString();
            user.personalInfo.surname = userData.value(2).toStdString();
            users.push_back(user);
        }
        //usuniecie usera z indexem 0;
        users.pop_back();
    }

    return users;
}

std::list<Imessage*> ServerRequester:: GetMessagesNewerThanDate(int sender_id,int receiver_id, const std::string& date)
{
    std::string message("5 ");
    message+= std::to_string(sender_id)+'/'+std::to_string(receiver_id)+'/'+date;
    socket->write(message.c_str());
    socket->waitForReadyRead();
    QString answer = socket->readAll();
    std::list<Imessage*> messages;
    if(answer!=EMPTYROW)
    {
         auto list = answer.split('\n');
         for(auto& x : list)
         {
             auto userData =  x.split('/');
             User user;
             user.userID = userData.value(0).toInt();
             user.personalInfo.name = userData.value(1).toStdString();
             user.personalInfo.surname = userData.value(2).toStdString();
             std::string postDate = userData.value(3).split('T').join(' ').toStdString();
             std::string content = userData.value(4).toStdString();
             messages.push_back(new TextMessage(user,postDate,content));
         }
         //usuniecie pustej wiadomosci
         messages.pop_back();
    }
    return messages;
}

std::list<User> ServerRequester:: serchUser(const std::string& name, const std::string& surname)
{
    std::string message("6 ");
    message+= name + '/' + surname;
    socket->write(message.c_str());
    socket->waitForReadyRead();
    QString answer= socket->readAll();
    std::list<User> users;
    if(answer!=EMPTYROW)
    {
        auto list = answer.split('\n');
        for(auto& x : list)
        {
            auto userData =  x.split('/');
            User user;
            user.userID = userData.value(0).toInt();
            user.personalInfo.name = userData.value(1).toStdString();
            user.personalInfo.surname = userData.value(2).toStdString();
            users.push_back(user);
        }
        //zdjecie zerowego usera
        users.pop_back();
    }
    return users;
}

std::string ServerRequester:: lastUpdateMessages(int sender_id, int receiver_id)
{
    std::string message("7 ");
    message+= std::to_string(sender_id) +'/'+ std::to_string(receiver_id);
    socket->write(message.c_str());
    socket->waitForReadyRead();
    QString answer = socket->readAll();
    if(answer==EMPTYROW)
    {
        answer = "1000-01-01";
    }
    return answer.toStdString();
}


void ServerRequester::connectToMessages(MainWindow* mainWindow)
{
    connect(this,&ServerRequester::newMessage,mainWindow,&MainWindow::newMessageArrived);
}

void ServerRequester::sendMessage(int sender_id, int receiver_id,const std::string& date, const std::string& content)
{
    std::string message("8 ");
    message+= std::to_string(sender_id) +'/'+ std::to_string(receiver_id)+'/'+date+'/'+content;
    socket->write(message.c_str());
    socket->flush();
}

bool ServerRequester:: emailExist(const std::string& email )
{

    std::string message("9 ");
    message+= email;
    socket->write(message.c_str());
    socket->flush();
    socket->waitForReadyRead();
    QString answer = socket->readAll();
    if(answer=='1')
    {
        return true;
    }
    return false;
}

void ServerRequester::signInUser(const std::string& pass,const std::string& name, const std::string& surname,
                const std::string& dateOfBirth, const std::string& phone, const std::string& email,
                const std::string& bio)
{
    std::string message("10");
    message += pass +  '/' + name + '/' + surname + '/'
               + dateOfBirth + '/' + phone + '/' + email + '/' + bio;
    socket->write(message.c_str());
    socket->flush();
}

void ServerRequester::changePassword(int userID, const std::string& password)
{
    std::string message("11");
    message+=std::to_string(userID) + '/' + password;
    socket->write(message.c_str());
    socket->flush();
    socket->waitForBytesWritten(message.length());
}
void ServerRequester::changeName(int userID, const std::string& name)
{
    std::string message("12");
    message+=std::to_string(userID) + '/' + name;
    socket->write(message.c_str());
    socket->flush();
    socket->waitForBytesWritten(message.length());
}
void ServerRequester::changeSurname(int userID, const std::string& surname)
{
    std::string message("13");
    message+=std::to_string(userID) + '/' + surname;
    socket->write(message.c_str());
    socket->flush();
    socket->waitForBytesWritten(message.length());
}
