#include "mainwindow.h"
#include <QApplication>
#include <cstdio>

int main(int argc, char *argv[])
{
    QApplication mainApplication(argc, argv);
    MainWindow mainWindow;
    mainWindow.show();

    return mainApplication.exec();
}
