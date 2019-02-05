#include "mainwindow.h"
#include <QApplication>
int main(int argc, char *argv[])
{
    QApplication app(argc, argv);
    MainWindow win;
    app.setStyle("plastique");
    win.setWindowTitle("ewcc");
    win.show();
    return app.exec();
}
