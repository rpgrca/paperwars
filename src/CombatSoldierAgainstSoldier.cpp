#include "CombatSoldierAgainstSoldier.h"
#include "Global.h"
#include "ActionType.h"

bool CCombatSoldierAgainstSoldier::Round() {
    bool bResult = false;
    CGlobal *pInstance = NULL;
    CAction *pAction = NULL;
    CActionDamage *pActionDamage = NULL;
    long lAttack = 0;
    CSoldier *pAttacker = NULL;
    CSoldier *pDefender = NULL;

    if ((m_pAttacker != NULL) && (m_pDefender != NULL)) {
        pAttacker = dynamic_cast<CSoldier *>(m_pAttacker);
        pDefender = dynamic_cast<CSoldier *>(m_pDefender);
        m_pActions->Clear();
        pInstance = CGlobal::Instance();

        pAction = pInstance->GetActionManager()->Create(enACTIONTYPE_WAIT);
        pAction->SetObject(pAttacker);
        m_pActions->Add(pAction);
        m_pAllActions->Add(pAction);
        pAction = pInstance->GetActionManager()->Create(enACTIONTYPE_WAIT);
        pAction->SetObject(pDefender);
        m_pActions->Add(pAction);
        m_pAllActions->Add(pAction);
        if (pInstance->GetSoldierServices()->IsAlive(pAttacker) && (pInstance->GetSoldierServices()->IsAlive(pDefender))) {
            lAttack = pInstance->GetSoldierServices()->CalculateAttack(pAttacker, pDefender);

            pAction = pInstance->GetActionManager()->Create(enACTIONTYPE_HIGH_ATTACK);
            pAction->SetObject(pAttacker);
            m_pActions->Add(pAction);
            m_pAllActions->Add(pAction);
            if (lAttack > 0) {
                pAction = pInstance->GetActionManager()->Create(enACTIONTYPE_LOW_BLOCK);
                pAction->SetObject(pDefender);
                m_pActions->Add(pAction);
                m_pAllActions->Add(pAction);
                pInstance->GetSoldierServices()->Hurt(pDefender, lAttack);
                pActionDamage = dynamic_cast<CActionDamage *>(pInstance->GetActionManager()->Create(enACTIONTYPE_DAMAGE));
                pActionDamage->SetDamage(lAttack);
                pActionDamage->SetObject(pDefender);
                m_pActions->Add(pActionDamage);
                m_pAllActions->Add(pActionDamage);

                if (! pInstance->GetSoldierServices()->IsAlive(pDefender)) {
                    pAction = pInstance->GetActionManager()->Create(enACTIONTYPE_DESTRUCTION);
                    pAction->SetObject(pDefender);
                    m_pActions->Add(pAction);
                    m_pAllActions->Add(pAction);
                    bResult = true;
                }
            }
            else {
                pAction = pInstance->GetActionManager()->Create(enACTIONTYPE_HIGH_BLOCK);
                pAction->SetObject(pDefender);
                m_pActions->Add(pAction);
                m_pAllActions->Add(pAction);
            }

            if (! bResult) {
                pAction = pInstance->GetActionManager()->Create(enACTIONTYPE_WAIT);
                pAction->SetObject(pAttacker);
                m_pActions->Add(pAction);
                m_pAllActions->Add(pAction);
                pAction = pInstance->GetActionManager()->Create(enACTIONTYPE_WAIT);
                pAction->SetObject(pDefender);
                m_pActions->Add(pAction);
                m_pAllActions->Add(pAction);
                lAttack = pInstance->GetSoldierServices()->CalculateAttack(pDefender, pAttacker);
                pAction = pInstance->GetActionManager()->Create(enACTIONTYPE_LOW_ATTACK);
                pAction->SetObject(pDefender);
                m_pActions->Add(pAction);
                m_pAllActions->Add(pAction);
                if (lAttack > 0) {
                    pAction = pInstance->GetActionManager()->Create(enACTIONTYPE_HIGH_BLOCK);
                    pAction->SetObject(pAttacker);
                    m_pActions->Add(pAction);
                    m_pAllActions->Add(pAction);
                    pInstance->GetSoldierServices()->Hurt(pAttacker, lAttack);
                    pActionDamage = dynamic_cast<CActionDamage *>(pInstance->GetActionManager()->Create(enACTIONTYPE_DAMAGE));
                    pActionDamage->SetDamage(lAttack);
                    pActionDamage->SetObject(pAttacker);
                    m_pActions->Add(pActionDamage);
                    m_pAllActions->Add(pActionDamage);

                    if (! pInstance->GetSoldierServices()->IsAlive(pAttacker)) {
                        pAction = pInstance->GetActionManager()->Create(enACTIONTYPE_DESTRUCTION);
                        pAction->SetObject(pAttacker);
                        m_pActions->Add(pAction);
                        m_pAllActions->Add(pAction);
                        bResult = true;
                    }
                }
                else {
                    pAction = pInstance->GetActionManager()->Create(enACTIONTYPE_LOW_BLOCK);
                    pAction->SetObject(pAttacker);
                    m_pActions->Add(pAction);
                    m_pAllActions->Add(pAction);
                }
            }
        }
    }

    return (bResult);
}
