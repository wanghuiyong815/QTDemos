#include "udpserverandclient.h"
#include <QHostInfo>
#include <QDataStream>
#include <QDateTime>



UDPServerAndClient::UDPServerAndClient(QObject *parent) : QObject(parent)
{
}

void UDPServerAndClient::setServerInit()
{
    connect(&timer, SIGNAL(timeout()), this, SLOT(onServerSendBroadcast())); //定时发送
    timer.start(2000);
}

void UDPServerAndClient::setClientInit()
{
    udpSocketClient.bind(13999);   //建立监听
    connect(&udpSocketClient, SIGNAL(readyRead()), this, SLOT(onPendingDatagrams())); //接收准备
}

void UDPServerAndClient::onServerSendBroadcast()
{
    QByteArray datagram;
    QDataStream out(&datagram, QIODevice::WriteOnly);
    out.setVersion(QDataStream::Qt_5_4);
    out << QDateTime::currentDateTime() << QHostInfo::fromName(QHostInfo::localHostName()).addresses().last().toString();
    //发送主机可以用QHostAddress("127.0.0.1")替换
    udpSocketServer.writeDatagram(datagram, QHostAddress::Broadcast, 13999);  // UDP 发送数据
}

void UDPServerAndClient::onPendingDatagrams()
{
    QByteArray datagram;

    do{
        datagram.resize(udpSocketClient.pendingDatagramSize());
        udpSocketClient.readDatagram(datagram.data(), datagram.size());  //接收数据
    } while( udpSocketClient.hasPendingDatagrams() );

    QDateTime dateTime;
    QString lastIP;
    QDataStream in(&datagram, QIODevice::ReadOnly);
    in.setVersion(QDataStream::Qt_5_4);
    in >> dateTime >> lastIP;

    qDebug() <<"dateTime.date().toString():" << dateTime.date().toString()
             <<"ip:" << lastIP;
}
