#ifndef CDATACONTAINER_H
#define CDATACONTAINER_H

#include <QList>


class CDataContainer
{
public:
    CDataContainer();
public:
    void    onLineReceived(const QString & lineFromFile);
    void    onNewFile(void);
private:
    QList<QString> dataReadFromFile;
};

#endif // CDATACONTAINER_H
