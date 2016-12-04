#ifndef DECOMPRESS_H
#define DECOMPRESS_H

#include <QString>
#include <fstream>
#include <./util/util.h>
#include <./compress/zlib/easyzlib.h>

#define BUFFER_SIZE int(4194304) //4 megas

class Decompress
{
public:
    Decompress(QString filename);
    ~Decompress();
    static int uncompress(char **uncompressed, char *data, long len);
    static void decompress(QString filename);
    void decompress();

private:
    QString filename;
};

#endif // DECOMPRESS_H
