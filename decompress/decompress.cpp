#include "decompress.h"

using namespace std;

Decompress::Decompress(QString filename)
{
    this->filename = filename;
}

Decompress::~Decompress()
{

}


int Decompress::uncompress(char **uncompressed, char *data, long len)
{
    long nDestLen = EZ_UNCOMPRESSMAXDESTLENGTH(len);
    *uncompressed = new char[nDestLen];
    int nErr = ezuncompress( reinterpret_cast<unsigned char*>(*uncompressed), &nDestLen,
                           reinterpret_cast<unsigned char*>(data), len );
    if ( nErr == EZ_BUF_ERROR ) {
      delete[] *uncompressed;
      *uncompressed = new char[nDestLen]; // enough room now
        //qDebug() << "a " << nDestLen;
      nErr = ezuncompress( reinterpret_cast<unsigned char*>(*uncompressed), &nDestLen,
                           reinterpret_cast<unsigned char*>(data), len );
      //qDebug() << "b " << nDestLen;
    }
    return (int)(nDestLen);
}

void Decompress::decompress(QString filename)
{
    Decompress *d = new Decompress(filename);
    d->decompress();
    delete d;
    qDebug() << "ungziped " << filename;
}

void Decompress::decompress()
{
    ifstream in(filename.toStdString());
    ofstream out(Util::getDecompressedFilename(filename));
    char* dataOut;
    while(!in.eof()){
        int sInt = sizeof(int);
        char *size = new char[sInt];
        in.read(size, sInt);
        if(in.gcount()<4) break;
        int len = int((unsigned char)(size[0]) << 24 |(unsigned char)(size[1]) << 16 | (unsigned char)(size[2]) << 8 | (unsigned char)(size[3]));
        char* buffer = new char[len];
        in.read(buffer, len);
        int tam = in.gcount();
        int tamOut = uncompress(&dataOut, buffer, tam);
        out.write(dataOut, tamOut);
        delete[] dataOut;
        delete[] size;
        delete[] buffer;
    }
    out.close();
    in.close();
}
