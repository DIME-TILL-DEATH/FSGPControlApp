#ifndef CONTROLGUI_H
#define CONTROLGUI_H

#include <QObject>
#include <QDebug>

#include "fsgp_command_frame.h"

class ControlGui : public QObject
{
    Q_OBJECT

    Q_PROPERTY(quint8 KP READ KP WRITE setKP NOTIFY KPChanged FINAL)
    Q_PROPERTY(quint8 NPO READ NPO WRITE setNPO NOTIFY NPOChanged FINAL)
    Q_PROPERTY(quint8 NKCH READ NKCH WRITE setNKCH NOTIFY NKCHChanged FINAL)
    Q_PROPERTY(bool SBR_OCH READ SBR_OCH WRITE setSBR_OCH NOTIFY SBR_OCHChanged FINAL)
    Q_PROPERTY(bool REG READ REG WRITE setREG NOTIFY REGChanged FINAL)
    Q_PROPERTY(bool CDO READ CDO WRITE setCDO NOTIFY CDOChanged FINAL)
    Q_PROPERTY(bool PBL READ PBL WRITE setPBL NOTIFY PBLChanged FINAL)
    Q_PROPERTY(bool PF READ PF WRITE setPF NOTIFY PFChanged FINAL)
    Q_PROPERTY(bool AKP READ AKP WRITE setAKP NOTIFY AKPChanged FINAL)
    Q_PROPERTY(bool EKV READ EKV WRITE setEKV NOTIFY EKVChanged FINAL)
    Q_PROPERTY(bool NLCHM READ NLCHM WRITE setNLCHM NOTIFY NLCHMChanged FINAL)
    // Пилот-сигнал
    Q_PROPERTY(bool PS READ PS WRITE setPS NOTIFY PS_changed FINAL)
    Q_PROPERTY(quint8 PS_type READ PS_type WRITE setPS_type NOTIFY PS_changed FINAL)
    Q_PROPERTY(quint8 PS_oslablenie READ PS_oslablenie WRITE setPS_oslablenie NOTIFY PS_changed FINAL)
    Q_PROPERTY(quint8 PS_polosa READ PS_polosa WRITE setPS_polosa NOTIFY PS_changed FINAL)
    Q_PROPERTY(bool PS_pnf_PS READ PS_pnf_PS WRITE setPS_pnf_PS NOTIFY PS_changed FINAL)
    Q_PROPERTY(quint16 PS_dalnost READ PS_dalnost WRITE setPS_dalnost NOTIFY PS_changed FINAL)
    Q_PROPERTY(quint16 PS_skorost READ PS_skorost WRITE setPS_skorost NOTIFY PS_changed FINAL)

public:
    explicit ControlGui(QObject *parent = nullptr);

    Q_INVOKABLE void sendFrame();

    quint8 KP() const;
    void setKP(quint8 newKP);

    quint8 NPO() const;
    void setNPO(quint8 newNPO);

    quint8 NKCH() const;
    void setNKCH(quint8 newNKCH);

    bool SBR_OCH() const;
    void setSBR_OCH(bool newSBR_OCH);

    bool REG() const;
    void setREG(bool newREG);

    bool PS() const;
    void setPS(bool newPS);

    bool CDO() const;
    void setCDO(bool newCDO);

    bool PBL() const;
    void setPBL(bool newPBL);

    bool PF() const;
    void setPF(bool newPF);

    bool AKP() const;
    void setAKP(bool newAKP);

    bool EKV() const;
    void setEKV(bool newEKV);

    quint8 ZI() const;
    void setZI(quint8 newZI);

    quint8 PS_oslablenie() const;
    void setPS_oslablenie(quint8 newPS_oslablenie);

    quint8 PS_type() const;
    void setPS_type(quint8 newPS_type);

    quint8 PS_polosa() const;
    void setPS_polosa(quint8 newPS_polosa);

    bool PS_pnf_PS() const;
    void setPS_pnf_PS(bool newPS_pnf_PS);

    quint16 PS_dalnost() const;
    void setPS_dalnost(quint16 newPS_dalnost);

    quint16 PS_skorost() const;
    void setPS_skorost(quint16 newPS_skorost);

    bool NLCHM() const;
    void setNLCHM(bool newNLCHM);

signals:
    void sgSendCommFrame(FSGP_Command_Frame frameData);
    void sgAckRecieved();

    void KPChanged();
    void NPOChanged();
    void NKCHChanged();
    void SBR_OCHChanged();
    void REGChanged();
    void CDOChanged();
    void PBLChanged();
    void PFChanged();
    void AKPChanged();
    void EKVChanged();
    void ZIChanged();

    void PS_changed();

    void NLCHMChanged();

private:
    quint8 m_KP{0};
    quint8 m_NPO{0};
    quint8 m_NKCH{0};
    bool m_SBR_OCH{false};
    bool m_REG{false};
    bool m_PS{false};
    bool m_CDO{false};
    bool m_PBL{false};
    bool m_PF{false};
    bool m_AKP{false};
    bool m_EKV{false};
    quint8 m_ZI{0};

    // Пилот
    quint8 m_PS_type;
    quint8 m_PS_oslablenie;
    quint8 m_PS_polosa;
    bool m_PS_pnf_PS;
    quint16 m_PS_dalnost;
    quint16 m_PS_skorost;
    bool m_NLCHM;
};

#endif // CONTROLGUI_H
