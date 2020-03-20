#include "filterconfiguration.h"
#include "ui_filterconfiguration.h"

FilterConfiguration::FilterConfiguration(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::FilterConfiguration)
{
    ui->setupUi(this);
}

FilterConfiguration::~FilterConfiguration()
{
    delete ui;
}
