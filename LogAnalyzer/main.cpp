#include "mainwindow.h"
#include <QApplication>

// idea: to have during the initialization of the data: the types of filters, rows/cols(defined);

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    w.show();

    return a.exec();
}
