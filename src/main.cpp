#include <QApplication>
#include "Fenetre/FenetreParametre.h"
#include <QTextCodec>
using namespace std;


int main(int argc, char *argv[])
{
    QTextCodec::setCodecForCStrings(QTextCodec::codecForName("UTF-8"));
    QTextCodec::setCodecForTr(QTextCodec::codecForName("UTF-8"));
    QTextCodec::setCodecForLocale(QTextCodec::codecForName("UTF-8"));

    QApplication a(argc, argv);
    FenetreParametre f;
    return a.exec();
}

