#include "util.h"

Util::Util()
{

}

QString Util::getWithoutExtension(QString filename)
{
    int k = filename.lastIndexOf("/");
    for(int t=filename.length();k<t;k++){
        if(filename[k]=='.') break;
    }
    return filename.left(k);
}

std::string Util::getOutputFilename(QString filename)
{
    return Util::getWithoutExtension(filename).replace("/entradas-comparativo/", "/gz/").toStdString()+".gz";
}

std::string Util::getDecompressedFilename(QString filename)
{
    return Util::getWithoutExtension(filename).replace("/gz/", "/decompressed/").toStdString()+".dgz";
}


