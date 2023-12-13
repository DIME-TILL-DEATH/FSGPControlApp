#include "controlgui.h"

ControlGui::ControlGui(QObject *parent)
    : QObject{parent}
{

}


void ControlGui::sendFrame()
{
    FSGP_Command_Frame frame{0};

    frame.KP = m_KP;
    frame.NPO = m_NPO;
    frame.NKCH = m_NKCH;
    frame.SBR_OCH = m_SBR_OCH;
    frame.REG = m_REG;
    frame.PS = m_PS;
    frame.CDO = m_CDO;
    frame.PBL = m_PBL;
    frame.PF = m_PF;
    frame.AKP = m_AKP;
    frame.EKV = m_EKV;
    frame.ZI = m_ZI;
    frame.OSL_PS = m_OSL_PS;

    qDebug() << "НКЧ: " << frame.NKCH;

    emit sgSendCommFrame(frame);
}

quint8 ControlGui::KP() const
{
    return m_KP;
}

void ControlGui::setKP(quint8 newKP)
{
    if (m_KP == newKP)
        return;
    m_KP = newKP;
    emit KPChanged();
}

quint8 ControlGui::NPO() const
{
    return m_NPO;
}

void ControlGui::setNPO(quint8 newNPO)
{
    if (m_NPO == newNPO)
        return;
    m_NPO = newNPO;
    emit NPOChanged();
}

quint8 ControlGui::NKCH() const
{
    return m_NKCH;
}

void ControlGui::setNKCH(quint8 newNKCH)
{
    if (m_NKCH == newNKCH)
        return;
    m_NKCH = newNKCH;
    emit NKCHChanged();
}

bool ControlGui::SBR_OCH() const
{
    return m_SBR_OCH;
}

void ControlGui::setSBR_OCH(bool newSBR_OCH)
{
    if (m_SBR_OCH == newSBR_OCH)
        return;
    m_SBR_OCH = newSBR_OCH;
    emit SBR_OCHChanged();
}

bool ControlGui::REG() const
{
    return m_REG;
}

void ControlGui::setREG(bool newREG)
{
    if (m_REG == newREG)
        return;
    m_REG = newREG;
    emit REGChanged();
}

bool ControlGui::PS() const
{
    return m_PS;
}

void ControlGui::setPS(bool newPS)
{
    if (m_PS == newPS)
        return;
    m_PS = newPS;
    emit PSChanged();
}

bool ControlGui::CDO() const
{
    return m_CDO;
}

void ControlGui::setCDO(bool newCDO)
{
    if (m_CDO == newCDO)
        return;
    m_CDO = newCDO;
    emit CDOChanged();
}

bool ControlGui::PBL() const
{
    return m_PBL;
}

void ControlGui::setPBL(bool newPBL)
{
    if (m_PBL == newPBL)
        return;
    m_PBL = newPBL;
    emit PBLChanged();
}

bool ControlGui::PF() const
{
    return m_PF;
}

void ControlGui::setPF(bool newPF)
{
    if (m_PF == newPF)
        return;
    m_PF = newPF;
    emit PFChanged();
}

bool ControlGui::AKP() const
{
    return m_AKP;
}

void ControlGui::setAKP(bool newAKP)
{
    if (m_AKP == newAKP)
        return;
    m_AKP = newAKP;
    emit AKPChanged();
}

bool ControlGui::EKV() const
{
    return m_EKV;
}

void ControlGui::setEKV(bool newEKV)
{
    if (m_EKV == newEKV)
        return;
    m_EKV = newEKV;
    emit EKVChanged();
}

quint8 ControlGui::ZI() const
{
    return m_ZI;
}

void ControlGui::setZI(quint8 newZI)
{
    if (m_ZI == newZI)
        return;
    m_ZI = newZI;
    emit ZIChanged();
}

quint8 ControlGui::OSL_PS() const
{
    return m_OSL_PS;
}

void ControlGui::setOSL_PS(quint8 newOSL_PS)
{
    if (m_OSL_PS == newOSL_PS)
        return;
    m_OSL_PS = newOSL_PS;
    emit OSL_PSChanged();
}
