#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "CFileOperations.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_pushButton_clicked()
{
    CFileOperations fileOperations("All files (*.*);; Log_file (*.dlt)");

    fileOperations.selectFilesForAnalysis();
}
