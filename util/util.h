#ifndef UTIL_H
#define UTIL_H

#include <QString>
#include <QDebug>

class Util
{
public:
    Util();
    static QString getWithoutExtension(QString filename);
    static std::string getOutputFilename(QString filename);
    static std::string getDecompressedFilename(QString filename);
};

#endif // UTIL_H
