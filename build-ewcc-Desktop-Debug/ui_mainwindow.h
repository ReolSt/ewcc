/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 4.8.7
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QGridLayout>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include <QtGui/QLineEdit>
#include <QtGui/QMainWindow>
#include <QtGui/QPushButton>
#include <QtGui/QTabWidget>
#include <QtGui/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralWidget;
    QGridLayout *gridLayout;
    QLabel *twitch_icon;
    QLineEdit *channelEdit;
    QPushButton *joinButton;
    QPushButton *closeButton;
    QTabWidget *ircTabWidget;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->resize(571, 635);
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QString::fromUtf8("centralWidget"));
        gridLayout = new QGridLayout(centralWidget);
        gridLayout->setSpacing(6);
        gridLayout->setContentsMargins(11, 11, 11, 11);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        twitch_icon = new QLabel(centralWidget);
        twitch_icon->setObjectName(QString::fromUtf8("twitch_icon"));
        QFont font;
        font.setPointSize(12);
        font.setBold(false);
        font.setItalic(false);
        font.setWeight(50);
        twitch_icon->setFont(font);

        gridLayout->addWidget(twitch_icon, 0, 0, 1, 1);

        channelEdit = new QLineEdit(centralWidget);
        channelEdit->setObjectName(QString::fromUtf8("channelEdit"));
        QFont font1;
        font1.setPointSize(11);
        channelEdit->setFont(font1);

        gridLayout->addWidget(channelEdit, 0, 1, 1, 1);

        joinButton = new QPushButton(centralWidget);
        joinButton->setObjectName(QString::fromUtf8("joinButton"));
        joinButton->setFont(font);

        gridLayout->addWidget(joinButton, 0, 2, 1, 1);

        closeButton = new QPushButton(centralWidget);
        closeButton->setObjectName(QString::fromUtf8("closeButton"));
        closeButton->setEnabled(true);
        closeButton->setFont(font);

        gridLayout->addWidget(closeButton, 0, 3, 1, 1);

        ircTabWidget = new QTabWidget(centralWidget);
        ircTabWidget->setObjectName(QString::fromUtf8("ircTabWidget"));
        ircTabWidget->setEnabled(true);
        QFont font2;
        font2.setPointSize(12);
        ircTabWidget->setFont(font2);
        ircTabWidget->setTabShape(QTabWidget::Triangular);
        ircTabWidget->setIconSize(QSize(16, 16));

        gridLayout->addWidget(ircTabWidget, 1, 0, 1, 4);

        MainWindow->setCentralWidget(centralWidget);

        retranslateUi(MainWindow);

        ircTabWidget->setCurrentIndex(-1);


        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "MainWindow", 0, QApplication::UnicodeUTF8));
        twitch_icon->setText(QApplication::translate("MainWindow", "Twitch", 0, QApplication::UnicodeUTF8));
        joinButton->setText(QApplication::translate("MainWindow", "Join", 0, QApplication::UnicodeUTF8));
        closeButton->setText(QApplication::translate("MainWindow", "Close", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
