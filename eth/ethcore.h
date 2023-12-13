#ifndef ETHCORE_H
#define ETHCORE_H

#include <QObject>
#include <QUdpSocket>

#include "fsgp.h"

class EthCore : public QObject
{
    Q_OBJECT
public:
    explicit EthCore(QObject *parent = nullptr);

    void sendCommFrame(FSGP_Command_Frame frameData);
    qint64 writeData(const FSGP& targetUPPM, QByteArray msg);

    void setHostAddress(QHostAddress ipAddr);
    void setDstIp(QHostAddress ipAddr);
    void setDstPort(quint16 dstPort);

signals:
    void sgItfConnected(bool result);
    void sgAckRecieved();

private:
    QUdpSocket* udpSocket;
    FSGP targetFSGP;

    void readPendingDatagrams();

    QHostAddress m_dstAddress;
    quint16 m_dstPort;

    quint32 index{0};
};

#endif // ETHCORE_H
