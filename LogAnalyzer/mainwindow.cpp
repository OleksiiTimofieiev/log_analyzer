#include "mainwindow.h"
#include "ui_mainwindow.h"

#include <iostream>
#include <QDebug>
#include <QThread>
#include <QInputDialog>
#include <QColor>
#include <QColorDialog>

// view => show all with filtered (add all lines) || show filtered (add lines with color);
// if color is already the same, skip finding step (finding in the string the key string);
// use lambda, enum class

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

void MainWindow::on_addFilter_clicked()
{
    bool ok;
    QString text = QInputDialog::getText(this, tr("Please, type the necessary filter"),
                                         tr("Filtering string:"), QLineEdit::Normal,
                                         QDir::home().dirName(), &ok);
    if (ok && !text.isEmpty())
    {
        ui->listWidget->addItem(text);
        filterConfigurations.addFilter("", text);
    }
}

void MainWindow::on_deleteFilters_clicked()
{
    QList<QListWidgetItem*> items = ui->listWidget->selectedItems();

    if (items.size() > 0)
    {
        foreach(QListWidgetItem * item, items)
        {
            filterConfigurations.deleteFilter(item->text());
            delete ui->listWidget->takeItem(ui->listWidget->row(item));
        }
    }
}

void MainWindow::on_actionDelete_all_filters_triggered()
{
     ui->listWidget->clear();
     filterConfigurations.clear();
}

void MainWindow::on_listWidget_itemDoubleClicked(QListWidgetItem *item)
{
    QColorDialog dialog;

    QColor color = dialog.getColor();

    item->setBackground(color);
    filterConfigurations.setColor(color, item->text());
}

void MainWindow::on_actionAdd_color_triggered()
{
    QList<QListWidgetItem*> items = ui->listWidget->selectedItems();

    if (items.size() > 0)
    {
        QColorDialog dialog;

        QColor color = dialog.getColor();

        foreach(QListWidgetItem * item, items)
        {
            item->setBackground(color);
            filterConfigurations.setColor(color, item->text());
        }
    }
}
