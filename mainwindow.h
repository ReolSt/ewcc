#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QVector>
#include <thread>
#include <vector>
#include "IRC.h"
#include "IRC_context.h"
#include "mutex_data.h"
#include "mutex_list.h"
namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();
signals:
    void timeout();
private slots:
    void on_timer();
    void on_joinButton_clicked();
    void on_closeButton_clicked();

private:
    void set_timer(uint ms);
    Ui::MainWindow *ui;
    MutexStdVector<MutexData<IRC_Context*>*> mutex_irc_context_list;
};

#endif // MAINWINDOW_H
