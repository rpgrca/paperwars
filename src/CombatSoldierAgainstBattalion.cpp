#include "CombatSoldierAgainstBattalion.h"
#include "Global.h"
#include "ActionType.h"
#include "Battalion.h"

bool CCombatSoldierAgainstBattalion::Round() {
    CAction *pAction = NULL;
    CCombat *pCombat = NULL;
    bool bResult = false;
    CGlobal *pInstance = NULL;
    CSoldier *pAttacker = NULL;
    CSoldier *pDefender = NULL;
    CBattalion *pBattalion = NULL;
    unsigned long lIndex = 0;
    

    if ((m_pAttacker != NULL) && (m_pDefender != NULL)) {
        pAttacker = dynamic_cast<CSoldier *>(m_pAttacker);
        pBattalion = dynamic_cast<CBattalion *>(m_pDefender);
        m_pActions->Clear();
        pInstance = CGlobal::Instance();

        pCombat = pInstance->GetCombatManager()->Create(enCOMBATTYPE_SOLDIER_AGAINST_SOLDIER, pAttacker);
        for (lIndex = 0; (lIndex < pBattalion->GetCount()) && pInstance->GetSoldierServices()->IsAlive(pAttacker); lIndex++) {
            pDefender = pBattalion->GetAt(lIndex);
            pCombat->SetDefender(pDefender);
            pCombat->Round();
            if (! pInstance->GetSoldierServices()->IsAlive(pDefender))
                bResult = true;
        }

        if (! pInstance->GetSoldierServices()->IsAlive(pAttacker))
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
