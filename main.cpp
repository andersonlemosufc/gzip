#include "mainwindow.h"
#include <QApplication>

#include "./compress/compress.h"
#include "./decompress/decompress.h"
#include <chrono>
#include <iostream>

using namespace std;
using namespace std::chrono;

int comp = 1;


QString getNome(int n, bool compress){
    QString aux = (compress) ? "entradas-comparativo" : "gz";
    QString rr = "/home/anderson/Documentos/tcc/"+aux+"/";
    if(n<10) rr+="000";
    else if(n<100) rr+="00";
    else if(n<1000) rr+="0";
    rr = (compress) ? rr.append(QString("%1.svg").arg(n)) : rr.append(QString("%1.gz").arg(n));
    return rr;
}

int main()
{

    int exe =5;
    high_resolution_clock::time_point t1, t2;
    QString name = "/home/anderson/Documentos/tcc/tempo" + QString("%1").arg(exe)+ ".txt";
    ofstream out(name.toStdString());
    for(int k=1;k<=3000;k++){
        t1 = high_resolution_clock::now();
        //Compress::compress(getNome(k, true));
        Decompress::decompress(getNome(k, false));
        t2 = high_resolution_clock::now();
        auto t = std::chrono::duration_cast<std::chrono::nanoseconds>(t2-t1).count();
        out << t << "\n";
    }
    out.close();

    return 0;
/*
    int op = 3;

    QString f1 = "Documentos/tmp/teste-xmill/a.xml";
    QString f2 = "Documentos/tmp/teste-xmill/books.xml";
    QString f3 = "Documentos/tmp/teste-xmill/brasil.svg";
    QString f4 = "Documentos/tmp/teste-xmill/big-books.xml";
    QString f5 = "Documentos/tmp/teste-xmill/sample.xml";
    QString f6 = "Documentos/tmp/teste-xmill/teste.xml";


    QString filename = (comp==1) ? "/home/anderson/" : (comp==2) ? "/home/anderson.silva/" : "";

    switch (op) {
        case 1: filename += f1; break;
        case 2: filename += f2; break;
        case 3: filename += f3; break;
        case 4: filename += f4; break;
        case 5: filename += f5; break;
        case 6: filename += f6; break;
    }

    Compress::compress(filename);
    Decompress::decompress(QString::fromStdString(Util::getOutputFilename(filename)));


    return 0;
    /*QApplication a(argc, argv);
    MainWindow w;
    w.show();

    return a.exec();*/
}
