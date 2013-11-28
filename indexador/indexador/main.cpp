#include "mainwindow.h"
#include "addquerido.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    AddQuerido q;

    QObject::connect(&w, SIGNAL(addQ()), &q, SLOT(show()));

    QObject::connect(&q, SIGNAL(go(QString)), &w, SLOT(on_go(QString)));



    w.show();

    return a.exec();
}
