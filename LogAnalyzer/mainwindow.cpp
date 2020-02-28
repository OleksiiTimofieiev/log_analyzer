#include "mainwindow.h"
#include "ui_mainwindow.h"

#include <iostream>
#include <QDebug>
#include <QThread>

MainWindow::MainWindow(CDataContainer & container, QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow),
    dataContainerObserver(container)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_actionOpen_triggered()
{
    static CFileOperations fileOperations("All files (*.*)"); //All files (*.*);; Log_file (*.dlt)
    bool    fileWasLoaded;

    fileOperations.readFromFile(dataContainerObserver, fileWasLoaded);
    (fileWasLoaded) ? QMessageBox::information(nullptr, tr("Status"), tr("Loaded the file.")) : QMessageBox::information(nullptr, tr("Status"), tr("File was not selected."));
    dataContainerObserver.printData();
}
