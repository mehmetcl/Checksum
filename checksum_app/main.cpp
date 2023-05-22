#include "mainwindow.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    w.setWindowTitle("CheckSum App");
    w.setWindowIcon(QIcon(":/icon/window_icon.ico"));
    w.show();
    return a.exec();
}
