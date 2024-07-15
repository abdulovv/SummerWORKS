#include "startscreen.h"
#include <QFile>
#include <QApplication>

void initialization(){
    const QString STATSPATH = "D:\\GITHUB\\SummerWORKS\\Stats.txt";
    QFile statsFile(STATSPATH);
    statsFile.open(QIODevice::WriteOnly);
    QString beginStats = "R1000+D100+H100+F100+A20\n";

    QTextStream stream(&statsFile);
    stream << beginStats;

    statsFile.close();
}

int main(int argc, char *argv[]){
    initialization();
    QApplication a(argc, argv);
    StartScreen w;
    w.show();
    return a.exec();
}
