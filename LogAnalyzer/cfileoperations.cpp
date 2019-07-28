#include "cfileoperations.h"

CFileOperations::CFileOperations(const QString & filter)
{
    mFilter = filter;
}

CFileOperations::~CFileOperations()
{

}

void    CFileOperations::selectFilesForAnalysis(void)
{
    /* Select the file/files */
    QStringList filenames = QFileDialog::getOpenFileNames(nullptr, "", QDir::currentPath(), mFilter) ;

    if( !filenames.isEmpty() )
    {
        for (int i = 0;i < filenames.count(); i++)
            QMessageBox::information(nullptr, "", filenames.at(i));
    }
}
