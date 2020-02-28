#include "mainwindow.h"
#include <QApplication>

#include "CFileOperations.h"

// idea: to have during the initialization of the data: the types of filters, rows/cols(defined), default folder to open;
// create the file

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    CDataContainer dataContainer;

    MainWindow w(dataContainer);

    w.show();
    return a.exec();
}
