#include "mainwindow.h"
#include <QApplication>
#include "udpserverandclient.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    w.show();

    UDPServerAndClient u;
    u.setServerInit();

    return a.exec();
}
