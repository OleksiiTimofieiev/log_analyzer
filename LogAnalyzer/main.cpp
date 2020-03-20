#include "mainwindow.h"
#include <QApplication>
#include <QDesktopWidget>

#include "CFileOperations.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    CDataContainer dataContainer;

    QDesktopWidget dw;
    MainWindow w(dataContainer);

    w.show();
    return a.exec();
}
