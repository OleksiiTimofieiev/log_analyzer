#include "mainwindow.h"
#include "ui_mainwindow.h"

#include <QFileDialog>
#include <QMessageBox>
#include <QDir>

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
    /* Filter the possible formats */
    QString filter = "All files (*.*);; Log_file (*.dlt)";

    /* Open the file/files */
    QStringList filenames = QFileDialog::getOpenFileNames(this,"",QDir::currentPath(), filter) ;
    if( !filenames.isEmpty() )
    {
        for (int i =0;i<filenames.count();i++)
            QMessageBox::information(this, "..", filenames.at(i));
    }
}
