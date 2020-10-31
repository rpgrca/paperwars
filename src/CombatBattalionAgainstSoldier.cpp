#include "CombatBattalionAgainstSoldier.h"
#include "Global.h"
#include "ActionType.h"
#include "Battalion.h"

bool CCombatBattalionAgainstSoldier::Round() {
    CAction *pAction = NULL;
    CCombat *pCombat = NULL;
    bool bResult = false;
    CGlobal *pInstance = NULL;
    CSoldier *pAttacker = NULL;
    CSoldier *pDefender = NULL;
    CBattalion *pBattalion = NULL;
    unsigned long lIndex = 0;
    

    if ((m_pAttacker != NULL) && (m_pDefender != NULL)) {
        pBattalion = dynamic_cast<CBattalion *>(m_pAttacker);
        pDefender = dynamic_cast<CSoldier *>(m_pDefender);
        m_pActions->Clear();
        pInstance = CGlobal::Instance();

        pCombat = pInstance->GetCombatManager()->Create(enCOMBATTYPE_SOLDIER_AGAINST_SOLDIER);
        for (lIndex = 0; (lIndex < pBattalion->GetCount()) && pInstance->GetSoldierServices()->IsAlive(pDefender); lIndex++) {
            pAttacker = pBattalion->GetAt(lIndex);
            pCombat->SetAttacker(pAttacker);
            pCombat->SetDefender(pDefender);
            pCombat->Round();
            if (! pInstance->GetSoldierServices()->IsAlive(pAttacker))
                bResult = true;
        }

        if (! pInstance->GetSoldierServices()->IsAlive(pDefender))
            bResult = true;

        for (lIndex = 0; lIndex < pCombat->GetActions(false)->GetCount(); lIndex++) {
            pAction = pCombat->GetActions(false)->GetAt(lIndex);

            m_pActions->Add(pAction);
            m_pAllActions->Add(pAction);
        }

        pInstance->GetCombatManager()->Delete(pCombat);
    }

    return (bResult);
}
