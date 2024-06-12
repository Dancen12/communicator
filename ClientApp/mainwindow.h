#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "beginwindow.h"
#include "filemanager.h"
#include "currentuser.h"
#include <QListWidget>
#include <QListWidgetItem>
#include "singlechat.h"
#include "settings.h"


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
    void begin();
public slots:
    void beginFinished(CurrentUser curUser);
    void showMessages(std::list<Imessage*> messages);
    void updateMessages(std::list<Imessage*> messages);
    void setChatDescription(std::string description);
    void setChatName(std::string chatName);
    void clearChat();
    void newMessageArrived(QString);
signals:
    void sendMessage(Imessage* message);
    void newMessageForChat(Imessage* message);
private slots:
    void on_pushButton_clicked();

    void on_listWidget_users_itemClicked(QListWidgetItem *item);

    void on_pushButton_search_clicked();

    void on_pushButton_close_clicked();

    void on_listWidget_search_itemClicked(QListWidgetItem *item);

    void on_pushButton_send_clicked();

    void on_lineEdit_messageInput_returnPressed();

    void on_pushButton_settings_clicked();

private:
    Ui::MainWindow *ui;
    BeginWindow* beginWindow;
    Settings* settingsWindow;
    FileManager* fileManager;
    CurrentUser* currentUser;
    std::list<User> users;
    IChat* chat;

    void reloudUsersList();
    void userToTop(const User& user);
    User userFromList(int id);
    void initUser();
    void loudUsers();
    User itemToUser(QListWidgetItem *item);
    bool isUserOnList(int user_id);
};
#endif // MAINWINDOW_H
