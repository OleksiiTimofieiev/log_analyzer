#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QTextStream>
#include <QMessageBox>
#include <QListWidgetItem>

#include "CDataContainer.h"
#include "CFileOperations.h"
#include "cfilterconfigurations.h"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT
public:
    explicit MainWindow(CDataContainer & dataContainer, QWidget *parent = nullptr);
    ~MainWindow();
private slots:
    void on_actionOpen_triggered();
    void on_addFilter_clicked();

    void on_deleteFilters_clicked();

    void on_actionDelete_all_filters_triggered();

    void on_listWidget_itemDoubleClicked(QListWidgetItem *item);

private:
    Ui::MainWindow *ui;
    CDataContainer & dataContainerObserver;
    CFilterConfigurations filterConfigurations;
};

#endif // MAINWINDOW_H
