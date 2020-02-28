#ifndef CFILEOPERATIONS_H
#define CFILEOPERATIONS_H

#include <QFileDialog>
#include <QMessageBox>
#include <QDir>
#include <QTextStream>

#include "CDataContainer.h"

class CFileOperations
{
    public:
        CFileOperations(const QString & filter);
        virtual     ~CFileOperations();
    public:
        QString        selectFileForAnalysis(void);
        void           readFromFile(CDataContainer & dataContainer, bool &fileWasLoaded);
    private:
        QString     mFilter;
};

#endif // CFILEOPERATIONS_H
