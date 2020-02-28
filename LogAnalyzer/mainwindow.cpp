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

void MainWindow::on_pushButton_clicked()
{
    static CFileOperations fileOperations("All files (*.*)"); //All files (*.*);; Log_file (*.dlt)

    QMessageBox::information(nullptr, "Status", "Please, select the file.");
    fileOperations.readFromFile(dataContainerObserver);
    QMessageBox::information(this, tr("Status"), tr("Loaded the file."));
}
