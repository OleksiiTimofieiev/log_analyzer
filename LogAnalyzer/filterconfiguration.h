#ifndef FILTERCONFIGURATION_H
#define FILTERCONFIGURATION_H

#include <QDialog>

namespace Ui {
class FilterConfiguration;
}

class FilterConfiguration : public QDialog
{
    Q_OBJECT

public:
    explicit FilterConfiguration(QWidget *parent = nullptr);
    ~FilterConfiguration();

private:
    Ui::FilterConfiguration *ui;
};

#endif // FILTERCONFIGURATION_H
