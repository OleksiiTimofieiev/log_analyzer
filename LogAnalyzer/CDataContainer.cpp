#include "CDataContainer.h"
#include <QDebug>

CDataContainer::CDataContainer(){}

void CDataContainer::onLineReceived(const QString &lineFromFile)
{
    dataReadFromFile.push_back(lineFromFile);
}

void CDataContainer::onNewFile()
{
    if (dataReadFromFile.size())
    {
        dataReadFromFile.clear();
    }
}
