#ifndef CFILEOPERATIONS_H
#define CFILEOPERATIONS_H

#include <QFileDialog>
#include <QMessageBox>
#include <QDir>

class CFileOperations
{
    public:
        CFileOperations(const QString & filter);
        virtual     ~CFileOperations();
    public:
        void        selectFilesForAnalysis(void);
    private:
        QString     mFilter;
        QStringList mFilenames;
};

#endif // CFILEOPERATIONS_H
