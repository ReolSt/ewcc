#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QTimer>
#include <QPixmap>
#include <QTextBrowser>
#include <QScrollBar>
#include <QFont>
#include <iostream>
#include <fstream>
#include <thread>
#include "user_info.h"
#include "mutex_data.h"
MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    set_timer(200);
    // IF YOU INSERT UI CODE HERE, IT WILL CAUSE SEGFAULT
    ui->setupUi(this);
    // UI CODE HERE
    ui->ircTabWidget->setStyleSheet("QTabWidget::pane { border: 0; }");
    ui->twitch_icon->setText("<img src=':/img/twitch_icon.png' width='34' height='34'>");
}
MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::set_timer(uint ms) {
    QTimer *refresh_timer = new QTimer;
    connect(refresh_timer,SIGNAL(timeout()),this,SLOT(on_timer()));
    refresh_timer->start(ms);
}

void MainWindow::on_timer() {    
    auto &irc_context_list = mutex_irc_context_list.list();
     mutex_irc_context_list.access([&]() {
         int icl_size = irc_context_list.size();
         for(int i=0;i<icl_size;i++) {
             QTextBrowser *tb=(QTextBrowser*)ui->ircTabWidget->widget(i);
             irc_context_list[i]->access([&]() {
                 auto &ic = irc_context_list[i]->data();
                 for(auto &i : ic->output_buffer()) {
                     QString html_str =
                             "<img src=':/img/twitch_icon.png' width='16' height='16'>" +
                             QString::fromUtf8(i.c_str()) + "<br>";
                     tb->append(html_str);
                 }
                 ic->clear_buffer();
             });
         }
     });
}

void MainWindow::on_joinButton_clicked()
{
    QString channel="#" + ui->channelEdit->text();
    auto &irc_context_list = mutex_irc_context_list.list();
    auto *ic = new IRC_Context(channel.toStdString());
    ic->create_thread();
    mutex_irc_context_list.access([&]() {
        irc_context_list.push_back(new MutexData<IRC_Context*>(ic));
    });
    QWidget *newtab = new QTextBrowser();
    newtab->setFont(QFont("Noto Sans",12));
    ui->ircTabWidget->addTab(newtab,channel);
    ui->ircTabWidget->setTabText(ui->ircTabWidget->count()-1,channel);
    ui->channelEdit->clear();
}

void MainWindow::on_closeButton_clicked()
{
    int ci=ui->ircTabWidget->currentIndex();
    auto &irc_context_list = mutex_irc_context_list.list();
    auto *mutex_irc_context = irc_context_list[ci];
    mutex_irc_context_list.access([&]() {
        irc_context_list.erase(irc_context_list.begin()+ci);
    });
    mutex_irc_context->access([&]() {
        mutex_irc_context->data()->end_loop();
    });
    delete mutex_irc_context;
    ui->ircTabWidget->removeTab(ci);
}

void MainWindow::on_sendButton_clicked()
{
    int ci=ui->ircTabWidget->currentIndex();
    QString channel = ui->ircTabWidget->tabText(ci);
    QString text = ui->chatEdit->text();
    auto *mutex_irc_context = mutex_irc_context_list.list()[ci];
    mutex_irc_context->access([&]() {        
        mutex_irc_context->data()->privmsg(channel.toUtf8().data(),
                                           text.toUtf8().data());
    });    
    ui->chatEdit->clear();    
}
