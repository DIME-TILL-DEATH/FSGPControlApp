#ifndef FSGP_H
#define FSGP_H

#include <stdint.h>
#include <QHostAddress>

#include "fsgp_command_frame.h"

class FSGP
{
public:
    FSGP();

    uint16_t controlPort = 40003;
    uint16_t fdkPort = 40002;
    static constexpr uint16_t ackPort = 20004;

    QHostAddress ipAddr() const;

    static QByteArray formCommFrame(FSGP_Command_Frame& data);

    void setIpAddr(const QHostAddress &newIpAddr);

private:
    QHostAddress m_ipAddr;
};

#endif // FSGP_H
