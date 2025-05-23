#include "fsgp.h"

#include <QtEndian>

FSGP::FSGP()
{
    m_ipAddr.setAddress("10.0.0.121");
}

QHostAddress FSGP::ipAddr() const
{
    return m_ipAddr;
}

QByteArray FSGP::formCommFrame(FSGP_Command_Frame &data)
{
    QByteArray rawFrame;

    FrameHeader frameHeader{0};

    quint16 outDataLen = sizeof(FrameHeader) + sizeof(DatagramHeader) + sizeof(FSGP_Command_Frame); //112;

    frameHeader.structData.signature = qToBigEndian<quint16>(FRAME_SIGNATURE);
    frameHeader.structData.RTK = 0;
    frameHeader.structData.TK = FSGP_COMMAND_FRAME;
    frameHeader.structData.RK = qToBigEndian(outDataLen - FRAME_HEADER_SIZE);
    frameHeader.structData.RF128_PF = qToBigEndian<quint16>(outDataLen/16 | (1<<15));
    frameHeader.structData.SCH = (data.index & 0xFFFF0000) >> 16;
    frameHeader.structData.NF = 0;

    rawFrame.append((const char*)&(frameHeader.rawData[0]), FRAME_HEADER_SIZE);

    DatagramHeader datagramHeader{0};

    datagramHeader.structData.LAYOUT = 4;
    datagramHeader.structData.LAYOUT_SIZE128 = 3;
    datagramHeader.structData.RTK = 0;
    datagramHeader.structData.TK = FSGP_COMMAND_FRAME;
    datagramHeader.structData.RK = qToBigEndian(outDataLen - FRAME_HEADER_SIZE);

    datagramHeader.structData.CTRL_OFFSET128 = qToBigEndian(FSGP_COMM_FRAME_CTRL_OFFSET128);
    datagramHeader.structData.CTRL_SIZE128 = qToBigEndian(FSGP_COMM_FRAME_CTRL_SIZE128);
    datagramHeader.structData.SYNC_OFFSET128 = qToBigEndian(FSGP_COMM_FRAME_SYNC_OFFSET128);
    datagramHeader.structData.SYNC_SIZE128 = qToBigEndian(FSGP_COMM_FRAME_SYNC_SIZE128);;
    datagramHeader.structData.HEAD_AUX_OFFSET128 = qToBigEndian(FSGP_COMM_FRAME_AUX_DATA_OFFSET128);
    datagramHeader.structData.HEAD_AUX_SIZE128 = qToBigEndian(FSGP_COMM_FRAME_AUX_DATA_SIZE128);
    datagramHeader.structData.SIGNAL_OFFSET128 = qToBigEndian(FSGP_COMM_FRAME_SIGNAL_OFFSET128);
    datagramHeader.structData.SIGNAL_SIZE128 =  qToBigEndian(FSGP_COMM_FRAME_SIGNAL_SIZE128);

    rawFrame.append((const char*)&(datagramHeader.rawData[0]), DATAGRAM_HEADER_SIZE);

    FSGP_Command_Frame_union unionFrame;

    unionFrame.structData = data;

    rawFrame.append((const char*)&(unionFrame.rawData[0]), FSGP_COMM_FRAME_SIZE);

    return rawFrame;
}

void FSGP::setIpAddr(const QHostAddress &newIpAddr)
{
    m_ipAddr = newIpAddr;
}
