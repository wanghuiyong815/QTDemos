#ifndef UDPSERVERANDCLIENT_H
#define UDPSERVERANDCLIENT_H

#include <QObject>
#include <QUdpSocket>
#include <QTimer>

class UDPServerAndClient : public QObject
{
    Q_OBJECT
public:
    explicit UDPServerAndClient(QObject *parent = 0);

    void setServerInit();
    void setClientInit();
private slots:
    void onServerSendBroadcast();
    void onPendingDatagrams();
private:
    QUdpSocket udpSocketServer;
    QUdpSocket udpSocketClient;
    QTimer timer;
};

#endif // UDPSERVERANDCLIENT_H
