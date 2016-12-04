#include "compress.h"

using namespace std;

Compress::Compress(QString filename)
{
    this->filename = filename;
}

Compress::~Compress()
{

}

int Compress::compress(char **compressed, char *data, long len)
{

    long nDestLen = EZ_COMPRESSMAXDESTLENGTH(len);
    *compressed = new char[nDestLen];
    int nErr = ezcompress( reinterpret_cast<unsigned char*>(*compressed), &nDestLen,
                           reinterpret_cast<unsigned char*>(data), len );
    if ( nErr == EZ_BUF_ERROR ) {
      delete[] *compressed;
      *compressed = new char[nDestLen]; // enough room now
      nErr = ezcompress( reinterpret_cast<unsigned char*>(*compressed), &nDestLen,
                           reinterpret_cast<unsigned char*>(data), len );
    }
    return (int)(nDestLen);
}

char *Compress::getBytes(int n)
{
    char* bytes = new char[4];
    bytes[0] = (n >> 24) & 0xFF;
    bytes[1] = (n >> 16) & 0xFF;
    bytes[2] = (n >> 8) & 0xFF;
    bytes[3] = n & 0xFF;
    return bytes;
}


void Compress::compress(QString filename)
{
    Compress *c = new Compress(filename);
    c->compress();
    delete c;
    qDebug() << "gziped " << filename;
}

void Compress::compress()
{

    ifstream in(filename.toStdString());
    ofstream out(Util::getOutputFilename(filename));
    char* dataOut;
    char* buffer = new char[BUFFER_SIZE];
    while(!in.eof()){
        in.read(buffer, BUFFER_SIZE);
        int tam = in.gcount();
        long tamOut = compress(&dataOut, buffer, tam);
        out.write(getBytes(tamOut), sizeof(int));
        out.write(dataOut, tamOut);
        delete[] dataOut;
    }
    out.close();
    in.close();
    delete[] buffer;
}

