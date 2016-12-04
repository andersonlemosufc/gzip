#ifndef COMPRESS_H
#define COMPRESS_H

#include <QString>
#include <fstream>
#include "./util/util.h"
#include "./compress/zlib/easyzlib.h"

#define BUFFER_SIZE int(4194304)//4 megas

class Compress
{
public:
    Compress(QString filename);
    ~Compress();
    static void compress(QString filename);
    static int compress(char **compressed, char *data, long len);
    char* getBytes(int n);
    void compress();

private:
    QString filename;
};

#endif // COMPRESS_H
