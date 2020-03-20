#ifndef CFILTERCONFIGURATIONS_H
#define CFILTERCONFIGURATIONS_H

#include <QString>
#include <QVector>
#include <QColor>
#include <QDebug>

struct FilterData
{
    QColor      mColor;
    QString     mFilterLine;

    FilterData(QColor color, QString filterLine): mColor(color), mFilterLine(filterLine) {};
};

class CFilterConfigurations
{
public:
    CFilterConfigurations();
    void    addFilter(const QColor &color, const QString & filterLine);
    void    deleteFilter(const QString & filterLine);
    void    setColor(const QColor &color, const QString & filterLine);
    void    clear();
private:
    QVector <FilterData> listOfFilters;

};

#endif // CFILTERCONFIGURATIONS_H
