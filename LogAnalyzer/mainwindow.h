#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QTextStream>
#include <QMessageBox>

#include "CDataContainer.h"
#include "CFileOperations.h"

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

private:
    Ui::MainWindow *ui;
    CDataContainer & dataContainerObserver;
};

#endif // MAINWINDOW_H
