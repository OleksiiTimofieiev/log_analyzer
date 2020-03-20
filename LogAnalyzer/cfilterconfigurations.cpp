#include "cfilterconfigurations.h"

CFilterConfigurations::CFilterConfigurations()
{

}

void CFilterConfigurations::addFilter(const QColor &color, const QString &filterLine)
{
    listOfFilters.push_back(FilterData{color, filterLine});
}

void CFilterConfigurations::deleteFilter(const QString &filterLine)
{
    qDebug() << "deleteFilter -> " << filterLine;
    for (int i = 0; i < listOfFilters.size(); i++)
    {
        if (listOfFilters[i].mFilterLine == filterLine)
        {
            listOfFilters.remove(i);
        }
    }
}

void CFilterConfigurations::setColor(const QColor &color, const QString &filterLine)
{
    for (int i = 0; i < listOfFilters.size(); i++)
    {
        if (listOfFilters[i].mFilterLine == filterLine)
        {
            listOfFilters[i].mColor = color;
        }
    }
}

void CFilterConfigurations::clear()
{
    listOfFilters.clear();
}

// TODO: delete filter
