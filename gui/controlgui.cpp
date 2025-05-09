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
    frame.CDO = m_CDO;
    frame.PBL = m_PBL;
    frame.PF = m_PF;
    frame.AKP = m_AKP;
    frame.EKV = m_EKV;
    frame.NLCHM = m_NLCHM;

    // Пилот
    frame.PS = m_PS;
    frame.TipPS = m_PS_type;
    frame.OslableniePS = m_PS_oslablenie;
    frame.PolosaPS = m_PS_polosa;
    frame.PnfPS = m_PS_pnf_PS;
    frame.DalnostPS = m_PS_dalnost;
    frame.SkorostPS = m_PS_skorost;

    qDebug() << "НКЧ: " << frame.NKCH << "КП:" << frame.KP << "Наклон:" << frame.NLCHM;
    qDebug() << "Тип ПС: " << frame.TipPS << "полоса ПС:" << frame.PolosaPS;

    emit sgSendCommFrame(frame);
    // emit sgSendCommFrame(frame);
    // emit sgSendCommFrame(frame);
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
    emit PS_changed();
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

quint8 ControlGui::PS_oslablenie() const
{
    return m_PS_oslablenie;
}

void ControlGui::setPS_oslablenie(quint8 newPS_oslablenie)
{
    if (m_PS_oslablenie == newPS_oslablenie)
        return;
    m_PS_oslablenie = newPS_oslablenie;
    emit PS_changed();
}

quint8 ControlGui::PS_type() const
{
    return m_PS_type;
}

void ControlGui::setPS_type(quint8 newPS_type)
{
    if (m_PS_type == newPS_type)
        return;
    m_PS_type = newPS_type;
    emit PS_changed();
}

quint8 ControlGui::PS_polosa() const
{
    return m_PS_polosa;
}

void ControlGui::setPS_polosa(quint8 newPS_polosa)
{
    if (m_PS_polosa == newPS_polosa)
        return;
    m_PS_polosa = newPS_polosa;
    emit PS_changed();
}

bool ControlGui::PS_pnf_PS() const
{
    return m_PS_pnf_PS;
}

void ControlGui::setPS_pnf_PS(bool newPS_pnf_PS)
{
    if (m_PS_pnf_PS == newPS_pnf_PS)
        return;
    m_PS_pnf_PS = newPS_pnf_PS;
    emit PS_changed();
}

quint16 ControlGui::PS_dalnost() const
{
    return m_PS_dalnost;
}

void ControlGui::setPS_dalnost(quint16 newPS_dalnost)
{
    if (m_PS_dalnost == newPS_dalnost)
        return;
    m_PS_dalnost = newPS_dalnost;
    emit PS_changed();
}

quint16 ControlGui::PS_skorost() const
{
    return m_PS_skorost;
}

void ControlGui::setPS_skorost(quint16 newPS_skorost)
{
    if (m_PS_skorost == newPS_skorost)
        return;
    m_PS_skorost = newPS_skorost;
    emit PS_changed();
}

bool ControlGui::NLCHM() const
{
    return m_NLCHM;
}

void ControlGui::setNLCHM(bool newNLCHM)
{
    if (m_NLCHM == newNLCHM)
        return;
    m_NLCHM = newNLCHM;
    emit NLCHMChanged();
}
