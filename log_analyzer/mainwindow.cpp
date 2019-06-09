#include "mainwindow.h"
#include "ui_mainwindow.h"

#include <QFileDialog> /* choose file from the dialog */
#include <QMessageBox> /* show message */
#include <QDir> /* use home path */
#include <QtDebug>

void    readFile(QString filename)
{
    QFile   mFile(filename);

    if (!mFile.open(QFile::ReadOnly | QFile::Text))
    {
        qDebug() << "could not open the file";

        return ;
    }

    QTextStream in(&mFile);

    while (!in.atEnd())
    {
       QString line = in.readLine();
//       qDebug() << line;

//       QStringList x;
//       QString line = in.readLine();
//               while (!line.isNull()) {
//                   QRegExp sep("\\s*/*");

//                   x =  line.split(sep);
//       QRegExp sep("(\\s+|/)");

//       then x will have every number. => regex to spaces withot [ AUDIOFU situation]

       QStringList pieces = line.split( " " );
       QString neededWord = pieces.value( 0 );

       qDebug() << neededWord;
    }

    mFile.close();
}

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
    QString filter = "All file (*.*) ;; DLT file (*.dlt)"; /* filters can be used -> mod to dlt file  DLT file (*.dlt)*/
    QString file_name = QFileDialog::getOpenFileName(this, "Open a file", QDir::homePath(), filter);

//    QMessageBox::information(this, "...", file_name);

    readFile(file_name);
}
