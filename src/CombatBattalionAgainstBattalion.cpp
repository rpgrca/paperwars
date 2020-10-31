#include "CombatBattalionAgainstBattalion.h"
#include "Global.h"
#include "Soldier.h"
#include "Battalion.h"

bool CCombatBattalionAgainstBattalion::Round() {
    CAction *pAction = NULL;
    CCombat *pCombat = NULL;
    bool bResult = false;
    CGlobal *pInstance = NULL;
    CSoldier *pAttacker = NULL;
    CSoldier *pDefender = NULL;
    CBattalion *pAttackingBattalion = NULL;
    CBattalion *pDefendingBattalion = NULL;
    unsigned long lMinimum = 0;
    unsigned long lMaximum = 0;
    unsigned long lIndex = 0;

    if ((m_pAttacker != NULL) && (m_pDefender != NULL)) {
        pAttackingBattalion = dynamic_cast<CBattalion *>(m_pAttacker);
        pDefendingBattalion = dynamic_cast<CBattalion *>(m_pDefender);

        if (pAttackingBattalion->GetCount() > pDefendingBattalion->GetCount()) {
            lMinimum = pDefendingBattalion->GetCount();
            lMaximum = pAttackingBattalion->GetCount();
        }
        else
            if (pAttackingBattalion->GetCount() < pDefendingBattalion->GetCount()) {
                lMinimum = pAttackingBattalion->GetCount();
                lMaximum = pDefendingBattalion->GetCount();
            }
            else {
                lMinimum = pAttackingBattalion->GetCount();
                lMaximum = lMinimum;
            }

        m_pActions->Clear();
        pInstance = CGlobal::Instance();
        pCombat = pInstance->GetCombatManager()->Create(enCOMBATTYPE_SOLDIER_AGAINST_SOLDIER);

        for (lIndex = 0; lIndex < lMinimum; lIndex++) {
            pAttacker = pAttackingBattalion->GetAt(lIndex);
            pDefender = pDefendingBattalion->GetAt(lIndex);

            pCombat->SetAttacker(pAttacker);
            pCombat->SetDefender(pDefender);
            bResult |= pCombat->Round();
        }

        if (lMinimum != lMaximum) {
            if (pAttackingBattalion->GetCount() > pDefendingBattalion->GetCount()) {
                for (lIndex = lMinimum; lIndex < lMaximum; lIndex++) {
                    pAttacker = pAttackingBattalion->GetAt(lIndex);
                    pDefender = pDefendingBattalion->GetRandomSoldier();

                    pCombat->SetAttacker(pAttacker);
                    pCombat->SetDefender(pDefender);
                    bResult |= pCombat->Round();
                }
            }
            else {
                for (lIndex = lMinimum; lIndex < lMaximum; lIndex++) {
                    pAttacker = pAttackingBattalion->GetRandomSoldier();
                    pDefender = pDefendingBattalion->GetAt(lIndex);

                    pCombat->SetAttacker(pAttacker);
                    pCombat->SetDefender(pDefender);
                    bResult |= pCombat->Round();
                }
            }
        }

        for (lIndex = 0; lIndex < pCombat->GetActions(false)->GetCount(); lIndex++) {
            pAction = pCombat->GetActions(false)->GetAt(lIndex);

            m_pActions->Add(pAction);
            m_pAllActions->Add(pAction);
        }

        pInstance->GetCombatManager()->Delete(pCombat);
    }

    return (bResult);

}
